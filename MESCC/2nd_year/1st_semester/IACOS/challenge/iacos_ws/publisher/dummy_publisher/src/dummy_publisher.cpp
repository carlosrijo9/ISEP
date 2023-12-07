#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <vector>

class CommandPublisher : public rclcpp::Node
{
public:
    CommandPublisher() : Node("command_publisher"), counter_(0)
    {
        // Publisher for /atc/orders
        publisher_ = this->create_publisher<std_msgs::msg::String>("/atc/orders", 10);

        // Timer to trigger publishing every 5 seconds
        timer_ = this->create_wall_timer(
            std::chrono::seconds(10),
            std::bind(&CommandPublisher::timer_callback, this));
    }

private:
    void timer_callback()
    {
        std_msgs::msg::String message;
        message.data = commands_[counter_ % commands_.size()];
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);

        counter_++;
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t counter_;
    std::vector<std::string> commands_ = {"right"};
    //std::vector<std::string> commands_ = {"forward", "right", "left", "stop", "construction_sign"};
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CommandPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

