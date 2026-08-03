#include "local_path_smoother.h"

namespace Planning
{
    LocalPathSmoother::LocalPathSmoother()
    {
        RCLCPP_INFO(rclcpp::get_logger("local_smooth"), "local_path_smooth created");
    }
}