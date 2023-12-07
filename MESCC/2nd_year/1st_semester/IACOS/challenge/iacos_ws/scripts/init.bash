source /opt/ros/foxy/setup.bash
source ./usr/share/gazebo/setup.bash
cd /data/workspace/src/my_bot
colcon build --symlink-install
cd ../../
source ./data/workspace/install/setup.bash