#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"

class CommandToVelocity : public rclcpp::Node
{
public:
    CommandToVelocity() : Node("command_to_velocity")
    {
        // Subscribe to the /atc/orders topic
        orders_subscriber_ = this->create_subscription<std_msgs::msg::String>(
            "/atc/orders", 10, std::bind(&CommandToVelocity::orders_callback, this, std::placeholders::_1));

        // Publisher for /cmd_vel
        cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    }

private:
    void orders_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        geometry_msgs::msg::Twist twist;

        // Translate the command to a Twist message
        if (msg->data == "forward")
        {
            twist.linear.x = 1.0;
            twist.angular.z = 0.0;
        }
        else if (msg->data == "right")
        {
            twist.linear.x = 0.5;
            twist.angular.z = -3.5; // Negative angular.z for turning right
            
            cmd_vel_publisher_->publish(twist);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            twist.linear.x = 1.0;
            twist.angular.z = 0.0; // Negative angular.z for turning right
            // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            // twist.linear.x = 0.0;
            // twist.angular.z = 0.0; // Negative angular.z for turning right
        }
        else if (msg->data == "left")
        {
            twist.linear.x = 0.0;
            twist.angular.z = 0.15; // Positive angular.z for turning left
        }
        else if (msg->data == "stop")
        {
            twist.linear.x = 0.0;
            twist.angular.z = 0.0;
        }
	else if (msg->data == "construction_sign")
	{
		twist.linear.x = 0.75;
		twist.angular.z = 0.0;
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

