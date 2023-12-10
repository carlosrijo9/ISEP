#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <iostream>


#define SLOW_SPEED 1
#define NORMAL_SPEED 2
#define ANGULAR_SPEED 2.5
#define LINEAR_TURN_SPEED 0.5
#define INVERT_SPEED 5.5

class CommandToVelocity : public rclcpp::Node
{
public:
    CommandToVelocity() : Node("command_to_velocity")
    {
        // Subscribe to the /atc/orders topic
        orders_subscriber_ = this->create_subscription<std_msgs::msg::String>(
            "/atc", 10, std::bind(&CommandToVelocity::orders_callback, this, std::placeholders::_1));

        // Publisher for /cmd_vel
        cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    }

private:
    void orders_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        geometry_msgs::msg::Twist twist;
    	// Print the received message to the console
    	RCLCPP_INFO(this->get_logger(), "Received message: %s", msg->data.c_str());


        // Translate the command to a Twist message
        if (msg->data == "Forward")
        {
            twist.linear.x = SLOW_SPEED;
            twist.angular.z = 0.0;
        }
        else if (msg->data == "Turn Right")
        {
            twist.linear.x = LINEAR_TURN_SPEED;
            twist.angular.z = -ANGULAR_SPEED; // Negative angular.z for turning right

            cmd_vel_publisher_->publish(twist);
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
            twist.linear.x = SLOW_SPEED;
            twist.angular.z = 0.0; // Negative angular.z for turning right
        }
        else if (msg->data == "Turn Left")
        {
            twist.linear.x = LINEAR_TURN_SPEED;
            twist.angular.z = ANGULAR_SPEED; // Positive angular.z for turning left

            cmd_vel_publisher_->publish(twist);
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
            twist.linear.x = SLOW_SPEED;
            twist.angular.z = 0.0; // Positive angular.z for turning left
        }
        else if (msg->data == "Stop")
        {
            twist.linear.x = 0.0;
            twist.angular.z = 0.0;
        }
        else if (msg->data == "Slow Down")
        {
            twist.linear.x = SLOW_SPEED;
            twist.angular.z = 0.0;
        }
        else if (msg->data == "construction_sign_end")
        {
            twist.linear.x = NORMAL_SPEED;
            twist.angular.z = 0.0;
        }
        else if (msg->data == "Invert")
        {
            twist.linear.x = LINEAR_TURN_SPEED;
            twist.angular.z = INVERT_SPEED; // Negative angular.z for turning right

            cmd_vel_publisher_->publish(twist);
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            twist.linear.x = SLOW_SPEED;
            twist.angular.z = 0.0; // Negative angular.z for turning right
        }

        // Publish the Twist message to /cmd_vel
        cmd_vel_publisher_->publish(twist);
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr orders_subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CommandToVelocity>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
