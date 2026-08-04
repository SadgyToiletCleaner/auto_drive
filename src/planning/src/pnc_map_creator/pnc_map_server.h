#ifndef PNC_MAP_SERVER_H_
#define PNC_MAP_SERVER_H_

#include "rclcpp/rclcpp.hpp"
#include "pnc_map_creator_straight.h"
#include "pnc_map_creator_sturn.h"

namespace Planning
{
    class PNCMapServer : public rclcpp::Node // 地图服务器
    {
    public:
        PNCMapServer();
    private:

    };
}  // Planning
#endif  // PNC_MAP_SERVER_H_
