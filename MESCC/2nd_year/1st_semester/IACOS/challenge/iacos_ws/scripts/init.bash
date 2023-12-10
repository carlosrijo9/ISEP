echo "Starting..."

echo "[1/7] Building Gazebo Sim"
cd /data/workspace/src/my_bot
colcon build --symlink-install

echo "[2/7] Building ROS implementation"
cd ../../../controller/
colcon build

cd

echo "[3/7] Source ROS"
source /opt/ros/foxy/setup.bash

echo "[4/7] Source Gazebo Sim"
source /data/workspace/install/setup.bash

echo "[4/7] Source ROS implementation"
source /data/controller/install/setup.bash

echo "[5/7] Source ROS"
source /opt/ros/foxy/setup.bash

echo "[7/7] Source Gazebo"
source /usr/share/gazebo/setup.bash

echo "Finished..."
