cmake_minimum_required(VERSION 3.29)
project(planning)


# 新增这一行，消除CMP0148警告
cmake_policy(SET CMP0148 OLD)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 设置CMAKE的预编译指令，打开后找到CMAKE预先定义的宏变量，生成 compile_commands.json
# 然后让 c_cpp_properties.json 读取这个文件，防止预编译找不到cmake中定义的宏而报错
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置包名，让子目录节点安装时候使用
set(PLANNING_PACKAGE_NAME ${PROJECT_NAME})

# 包含头文件的目录
include_directories(
  /usr/include/eigen3
  src/common/config_reader
  src/common/math
  src/common/decision_center
  src/common/pnc_map_creator
  src/common/pnc_map_creator/pnc_map_straight
  src/common/pnc_map_creator/pnc_map_sturn
  src/global_planner
  src/global_planner/global_planner_normal
  src/local_planner
  src/local_planner/local_path
  src/local_planner/local_speeds
  src/reference_line
  src/vehicle_info/
  src/vehicle_info/main_car
  src/vehicle_info/obs_car
  src/planning_process
  src/move_cmd

)


# find dependencies 查找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(base_msgs REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(OsqpEigen REQUIRED)

#添加子目录
add_subdirectory(src/common)
add_subdirectory(src/decision_center)
add_subdirectory(src/global_planner)
add_subdirectory(src/local_planner)
add_subdirectory(src/move_cmd)
add_subdirectory(src/planning_process)
add_subdirectory(src/pnc_map_creator)
add_subdirectory(src/reference_line)
add_subdirectory(src/vehicle_info)

# 安装辅助目录
install(DIRECTORY
  config launch urdf rviz
  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
