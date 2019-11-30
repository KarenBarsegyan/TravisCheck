cmake_minimum_required(VERSION 2.8.3)

project(triangulation)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        tf
        tf2
        fsd_common_msgs
        fssim_common
)

catkin_package()

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${roscpp_INCLUDE_DIRS}
        ${rospy_INCLUDE_DIRS}
)

add_executable(teleop_recieve_send src/teleop_recieve_send.cpp)
target_link_libraries(teleop_recieve_send ${catkin_LIBRARIES})

add_executable(send_cone_coordinate src/send_cone_coordinate.cpp)
target_link_libraries(send_cone_coordinate ${catkin_LIBRARIES})
