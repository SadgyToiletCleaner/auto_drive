#!/bin/bash
# ROS2 Planning Course 环境配置脚本

# 设置安装目录
export ROS2_PLANNING_COURSE_INSTALL=/home/alientek/auto_drive/planning_with_ROS2_course/install

# Source ROS2 工作空间
if [ -f "$ROS2_PLANNING_COURSE_INSTALL/setup.bash" ]; then
    source $ROS2_PLANNING_COURSE_INSTALL/setup.bash
else
    echo "警告: setup.bash 不存在于 $ROS2_PLANNING_COURSE_INSTALL"
fi

# 添加库路径
export LD_LIBRARY_PATH=$ROS2_PLANNING_COURSE_INSTALL/planning/lib:$LD_LIBRARY_PATH

# 打印当前环境状态
echo "✅ ROS2 Planning Course 环境已加载"
echo "   ROS2_PLANNING_COURSE_INSTALL = $ROS2_PLANNING_COURSE_INSTALL"