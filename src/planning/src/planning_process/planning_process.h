#ifndef PLANNING_PROCESS_H_
#define PLANNING_PROCESS_H_

#include "rclcpp/rclcpp.hpp"

namespace Planning
{
  class PlanningProcess : public rclcpp::Node // 规划总流程
  {
  public:
    // 构造函数
    PlanningProcess();
    //总流程
    bool process();
  private:
  };
}  // namespace Planning
#endif  // PLANNING_PROCESS_H_