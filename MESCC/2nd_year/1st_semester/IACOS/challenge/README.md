# ISEP-MESCC
## IACOS

### Note
This set of instructions only works in systems with Linux Debian (developed and tested in Linux Ubuntu 22.04).
### Prepare Docker Image
- On a terminal run:
    - Allow docker image to open GUI of applications (in this case Gazebo and RVIZ)
        ```bash
        export DISPLAY=:1.0 && xhost +local:docker
        ```
    - Download and start Docker image
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


###
```bash
./data/scripts/first_setup.bash
```

```bash
./data/scripts/init.bash
```

> Setup
```bash
colcon build --symlink-install
```

> Launch Gazebo and car
```bash
ros2 launch my_bot launch launch_sim.launch.py
```

```bash
ros2 launch my_bot launch_sim.launch.py world:=/data/world/road.world
```

> Additional
```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

```bash
ros2 topic echo /cmd_vel
```




```bash
export DISPLAY=:1.0 && xhost +local:docker && docker exec -it iacos bash
```