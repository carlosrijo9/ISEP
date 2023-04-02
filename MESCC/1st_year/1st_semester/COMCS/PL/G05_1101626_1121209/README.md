# ISEP MESCC COMCS
## Practical Assignment - "A Sensor is not a sensor."
### Group 5
#### - Carlos Rijo  1101626
#### - Eduardo Maia 1121209
---

### Necessary Tools:
* GCC
* Python3
* Tkinter Python Library
  
  ```bash
  sudo apt install python3-tk
  ```

* PIP Library
  
  ```bash
  sudo apt install python3-pip
  ```

* ttkthemes Library
  
  ```bash
  sudo pip3 install ttkthemes
  ```

* Arduino IDE with esp32 extension 

### Requirements:
* Laptop x2
* Esp32 Dev Module x3
* DHT11 Sensor x3
* Jumper cables
* microUSB cable x3
* Connection and Credentials to an Wifi Network

### Execution:
1) Connect both Laptops to a known Wifi Network 

2) In Laptop_1
   1) Run:

      ```bash
      hostname -I
      ```

   2) Open Arduino IDE
      1) In device code change "host" variable to the IP Address given by previous command
      2) Flash the devices
   
   3) Run (in diferent windows):

      ```bash
      gcc -Wall main_server.c -o main_server
      gcc -Wall server1.c -o server1
      gcc -Wall server2.c -o server2
      gcc -Wall server3.c -o server3
      ```

      ```bash
      ./main_server
      ```

      ```bash
      ./server1
      ```

      ```bash
      ./server2
      ```

      ```bash
      ./server3
      ```
   
3) In Laptop_2 run:

      ```bash
      gcc -Wall tcp_client.c -o tcp_client
      python3 GUI.py
      ```
4) To test Client User Interface:
   1) Insert Laptop_1 IPv4 Address
   2) Insert 10999 as Port Number
   3) Click "Get" button to read temperature sensor readings
   4) Insert a positive number the field in front of "Set" button
   5) Click "Set" button do set the new data acquisition rate

Note: Make sure tcp_client executable is in the same folder as GUI.py

