#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#define SIZE 256
#define NR_DATA 5000
#define DEFAULT_NUM_THREADS 4
#define SEARCH_SIZE NR_DATA / 2
#define DELETE_SIZE NR_DATA / 2
#define MIN_RAND 0
#define MAX_RAND NR_DATA

int search_array[SEARCH_SIZE];
int delete_array[DELETE_SIZE];

typedef struct data
{
    int key;
    char data[SIZE];
} data;

typedef struct node
{
    data item;
    struct node *next;
    omp_lock_t lock; // Lock for this node
} node;

typedef struct linked_list
{
    node *head;
    omp_lock_t list_lock; // Lock for the linked list
} linked_list;

void initialize_linked_list(linked_list *list)
{
    list->head = NULL;
    omp_init_lock(&list->list_lock); // Initialize the list lock
}
void insert(linked_list *list, data item);
int search(linked_list *list, int key, data *result);
int delete(linked_list *list, int key);
void print_linked_list(linked_list *list);
void findDataToSearch();
void findDataToDelete();

int main(int argc, char *argv[])
{
    int num_threads = DEFAULT_NUM_THREADS;
    int data_found = 0;
    int data_deleted = 0;
    if (argc < 2)
    {
        printf("Number of threads was not specified. Will use default value: %d\n", DEFAULT_NUM_THREADS);
    }
    else
    {
        num_threads = atoi(argv[4]);
    }
    printf("Working with %d threads and struct size of %d\n", num_threads, NR_DATA);

    linked_list list;
    initialize_linked_list(&list);
    findDataToSearch();
    findDataToDelete();

    // INSERT
    printf("Insert Sequential... ");
    double begin = omp_get_wtime();
    for (int k_seq = 0; k_seq < NR_DATA; k_seq++)
    {
        data item;
        item.key = k_seq;
        sprintf(item.data, "Data %d ", NR_DATA - k_seq);
        insert(&list, item);
    }
    double end = omp_get_wtime();
    double insert_seq_time = (double)(end - begin);
    printf("done.\n");

    // SEARCH
    printf("\nSearch Sequential...\n");
    begin = omp_get_wtime();
    data result;
    for (int i_seq = 0; i_seq < SEARCH_SIZE; i_seq++)
    {
        if (search(&list, search_array[i_seq], &result))
        {
            // printf("Found: Key=%d, Data=%s\n", result.key, result.data);
            data_found++;
        }
        else
        {
            // printf("Key %d not found... \n", search_array[i_seq]);
        }
    }
    printf("Found %d Keys of %d\n", data_found, SEARCH_SIZE);
    end = omp_get_wtime();
    double search_seq_time = (double)(end - begin);

    // DELETE
    printf("\nDelete Sequential...\n");
    begin = omp_get_wtime();
    for (int j = 0; j < DELETE_SIZE; j++)
    {
        if (delete (&list, delete_array[j]))
        {
            // printf("Key %d deleted...\n", delete_array[j]);
            data_deleted++;
        }
        else
        {
            // printf("Key %d not found for deletion...\n", delete_array[j]);
        }
    }
    printf("Deleted %d Keys of %d\n", data_deleted, DELETE_SIZE);
    end = omp_get_wtime();
    double delete_seq_time = (double)(end - begin);

    // printf("Linked List Contents:\n");
    // print_linked_list(&list);

    data_found = 0;
    data_deleted = 0;
    printf("\nInsert Parallel... ");
    data item_par;
    begin = omp_get_wtime();
#pragma omp parallel for num_threads(num_threads)
    for (int k = 0; k < NR_DATA; k++)
    {
        item_par.key = k;
        sprintf(item_par.data, "Data %d ", NR_DATA - k);
        insert(&list, item_par);
    }
    end = omp_get_wtime();
    double insert_par_time = (double)(end - begin);
    printf("done.\n");

    // SEARCH
    printf("\nSearch Parallel...\n");
    begin = omp_get_wtime();
    data result_par;
#pragma omp parallel for num_threads(num_threads) reduction(+ : data_found)
    for (int i = 0; i < SEARCH_SIZE; i++)
    {
        if (search(&list, search_array[i], &result_par))
        {
            data_found++;
        }
    }
    printf("Found %d Keys of %d\n", data_found, SEARCH_SIZE);
    end = omp_get_wtime();
    double search_par_time = (double)(end - begin);

    // DELETE
    printf("\nDelete Parallel...\n");
    begin = omp_get_wtime();
#pragma omp parallel for num_threads(num_threads) reduction(+ : data_deleted)
    for (int j = 0; j < DELETE_SIZE; j++)
    {
        if (delete (&list, delete_array[j]))
        {
            data_deleted++;
        }
    }
    printf("Deleted %d Keys of %d\n", data_deleted, DELETE_SIZE);

    end = omp_get_wtime();
    double delete_par_time = (double)(end - begin);

    printf("\n|\t============== Performance =============\t|\n");
    printf("|        | Sequential Time\t| Parallel Time\t\t|\n");
    printf("| Insert |\t%f s\t|\t%f s\t|\n", insert_seq_time, insert_par_time);
    printf("| Search |\t%f s\t|\t%f s\t|\n", search_seq_time, search_par_time);
    printf("| Delete |\t%f s\t|\t%f s\t|\n", delete_seq_time, delete_par_time);

    // Clean up the linked list by freeing all allocated memory
    node *current = list.head;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

/************ Util. Functions *****************/
void insert(linked_list *list, data item)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    omp_init_lock(&new_node->lock);

    // Lock the list
    omp_set_lock(&list->list_lock);

    if (list->head == NULL || item.key < list->head->item.key)
    {
        new_node->next = list->head;
        list->head = new_node;
    }
    else
    {
        node *current = list->head;
        node *prev = NULL;
        while (current != NULL && current->item.key <= item.key)
        {
            prev = current;
            current = current->next;
        }
        new_node->next = current;
        prev->next = new_node;
    }

    // Unlock the list
    omp_unset_lock(&list->list_lock);
}

int search(linked_list *list, int key, data *result)
{
    node *current = list->head;
    while (current != NULL)
    {
        omp_set_lock(&current->lock);
        if (current->item.key == key)
        {
            *result = current->item;
            omp_unset_lock(&current->lock);
            return 1; // Found
        }
        omp_unset_lock(&current->lock);
        current = current->next;
    }
    return 0; // Not found
}

int delete(linked_list *list, int key)
{
    // Lock the list
    omp_set_lock(&list->list_lock);

    node *current = list->head;
    node *prev = NULL;
    while (current != NULL)
    {
        omp_set_lock(&current->lock);

        if (current->item.key == key)
        {
            if (prev == NULL)
            {
                list->head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Unlock the current node
            omp_unset_lock(&current->lock);

            // Free the current node
            free(current);

            // Unlock the list
            omp_unset_lock(&list->list_lock);

            return 1; // Deleted
        }

        // Unlock the current node
        omp_unset_lock(&current->lock);

        prev = current;
        current = current->next;
    }

    // Unlock the list
    omp_unset_lock(&list->list_lock);

    return 0; // Not found
}

void print_linked_list(linked_list *list)
{
    node *current = list->head;
    while (current != NULL)
    {
        printf("Key=%d, Data=%s\n", current->item.key, current->item.data);
        current = current->next;
    }
}

void findDataToSearch()
{
    for (int l = 0; l < SEARCH_SIZE; l++)
    {
        search_array[l] = MIN_RAND + rand() % (MAX_RAND - MIN_RAND + 1);
        // printf("\n%d", search_array[l]);
    }
}

void findDataToDelete()
{
    for (int m = 0; m < DELETE_SIZE; m++)
    {
        delete_array[m] = MIN_RAND + rand() % (MAX_RAND - MIN_RAND + 1);
        // printf("\n%d", delete_array[m]);
    }
}
