# ISEP - DDE - MESCC
## IACOS Project: ATC Signs Detection for Autonomous Vehicles in Roadwork Scenarios

Group:
- Carlos Rijo - 1101626
- João Fernandes - 1221973
- Mário Carneiro - 1170699
- 
### Note
This set of instructions only works in systems with Linux Debian (developed and tested in Linux Ubuntu 22.04).

### Prepare Docker Image
- On a terminal run:
    - Clone this repository
    - Enter MESCC_IACOS folder (created from the clone) and open a terminal inside the folder
    - Allow docker image to open GUI of applications (in this case Gazebo and RVIZ)
        ```bash
        export DISPLAY=:1.0 && xhost +local:docker
        ```
    - Download and start the Docker image
        ```bash
        docker run -it --net=host --device=/dev/dri/ --device=/dev/video0:/dev/video0 -e DISPLAY=$DISPLAY -v $(pwd)/iacos_ws:/data --name iacos althack/ros2:foxy-gazebo-2023-06-30
        ```
    - Command explication:
        ```bash
        docker run  # Runs a docker image and makes a docker container
        -it # Start interactive
        --net=host  #
        --device=/dev/dri/ # Allows access to the ??? (from local host)
        --device=/dev/video0:/dev/video0    # Allows access to the camera (from local host)
        -e DISPLAY=$DISPLAY # Allows container to open GUI applications (in local host screen)
        -v $(pwd)/iacos_ws:/data    # Makes a volume to share folders between container and local host
                                    # Inside Docker the folder is data (will be made in ./ directory)
                                    # Inside local host the folder is iacos_ws (will be made in the present working directory of the running terminal)
        --name iacos    # Name of docker container
        althack/ros2:foxy-gazebo-2023-06-30 # Name of docker image
        ```


### Initial Docker Container Preparations
- Inside Docker Container, on a terminal run:
    ```bash
    ./data/scripts/first_setup.bash
    ```
- Then run:
    ```bash
    ./data/scripts/init.bash
    ```

### Run Implementation
- Terminal 1 (Gazebo Simulation):
    ```bash
    ros2 launch my_bot launch_sim.launch.py world:=/data/world/road.world
    ```
- Terminal 2 (Controller Simulation):
    ```bash
    ros2 run atc_2_gazebo atc_2_gazebo
    ```
- Terminal 3 (OpenCV):
    ```bash
    ros2 run py_hand_gesture_publisher atc_publisher
    ```

### Run Implementation without OpenCV
- Terminal 1 (Gazebo Simulation):
    ```bash
    ros2 launch my_bot launch_sim.launch.py world:=/data/world/road.world
    ```
- Terminal 2 (Controller Simulation):
    ```bash
    ros2 run atc_2_gazebo atc_2_gazebo
    ```
- Terminal 3 (Send Topic):
    ```bash
    ros2 topic pub /atc/ std_msgs/msg/String "{data: '<order>'}" -1
    ```
    - Order options:
      - stop
      - forward
      - left
      - right
      - accelerate
      - slow down
      - invert
      - construction_sign_start
      - construction_sign_end
  
    - Example
        ```bash
        ros2 topic pub /atc/orders std_msgs/msg/String "{data: 'forward'}" -1
        ```
    - Alternative (send all topics in loop):
        ```bash
        ros2 run dummy_publisher dummy_publisher
        ```

### Additional Commands
- Run Docker container (new terminal)
    ```bash
    docker exec -it iacos bash
    ```
- Send movement to command to vehicle (topic /cmd_vel)
  - Linear movement 
    ```bash
    ros2 topic pub /cmd_vel geometry_msgs/Twist '{linear: {x: 1.0}}' -1
    ```
  - Angular movement 
    ```bash
    ros2 topic pub /cmd_vel geometry_msgs/Twist '{angular: {z: 1.0}}' -1
    ```
  - Linear and Angular movement 
    ```bash
    ros2 topic pub /cmd_vel geometry_msgs/Twist '{linear: {x: 1.0}, angular: {z: 1.0}}' -1
    ```

- Control the Vehicle using the keyboard
    ```bash
    ros2 run teleop_twist_keyboard teleop_twist_keyboard
    ```
- Show topic cmd_vel
    ```bash
    ros2 topic echo /cmd_vel
    ```
- Show topic odom
    ```bash
    ros2 topic echo /odom
    ```

- Open RVIZ simulation
    ```bash
    rviz2 -d /data/frame.rviz
    ```

### Helpful Commands
- Build code
    ```bash
    colcon build --symlink-install
    ```
- Source ROS
    ```bash
    source /opt/ros/foxy/setup.bash
    ```
- Source Gazebo
    ```bash
    source /usr/share/gazebo/setup.bash
    ```
- Source Gazebo implementation
    ```bash
    source /data/workspace/install/setup.bash
    ```
- Source ROS implementation
    ```bash
    source /data/publisher/install/setup.bash
    ```

