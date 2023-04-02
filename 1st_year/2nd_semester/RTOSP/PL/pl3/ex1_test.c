#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 3

int board[SIZE][SIZE];                             // the tic-tac-toe board
int player_turn = 1;                               // the player who plays next
int game_over = 0;                                 // whether the game is over or not
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // the mutex for accessing the board

// prints the current state of the board
void printBoard()
{
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[0][0] + '0', board[0][1] + '0', board[0][2] + '0');
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[1][0] + '0', board[1][1] + '0', board[1][2] + '0');
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[2][0] + '0', board[2][1] + '0', board[2][2] + '0');
    printf("   |   |   \n");
}

// Check the game result
int checkResult()
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        // check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];

        // check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];

        // checks if the game has ended in a tie
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
                return 0;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return 99;
}

// generates a random move for the given player
void generate_move(int player, int *row, int *col)
{
    do
    {
        *row = rand() % SIZE;
        *col = rand() % SIZE;
    } while (board[*row][*col] != 0);
    board[*row][*col] = player;
}

// the function executed by each player thread
void *player_thread(void *arg)
{
    int player = *(int *)arg;
    int winner = 0;

    while (!game_over)
    {
        if (player == player_turn)
        {
            pthread_mutex_lock(&mutex);

            if (!game_over)
            {
                int row, col;
                generate_move(player, &row, &col);
                printf("Player %d plays at row %d, col %d.\n", player, row, col);
                printBoard();
                
                winner = checkResult();

                if (winner == 99)
                {
                    printf("The game is a tie!\n");
                    game_over = 1;
                }
                else if (winner > 0)
                {
                    printf("Player %d wins!\n", winner);
                    game_over = 1;
                }
                else
                {
                    player_turn = (player_turn == 1) ? 2 : 1;
                }
            }

            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    pthread_t player1, player2;

    int player1_id = 1;
    int player2_id = 2;

    pthread_create(&player1, NULL, player_thread, &player1_id);
    pthread_create(&player2, NULL, player_thread, &player2_id);

    pthread_join(player1, NULL);
    pthread_join(player2, NULL);
    return 0;
}