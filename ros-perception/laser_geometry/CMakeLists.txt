cmake_minimum_required(VERSION 3.5)

project(laser_geometry)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(Eigen3 REQUIRED)

# TODO(dhood): enable python support once ported to ROS 2
# catkin_python_setup()

include_directories(include
    ${rclcpp_INCLUDE_DIRS}
    ${sensor_msgs_INCLUDE_DIRS}
    ${tf2_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
)

add_library(laser_geometry SHARED src/laser_geometry.cpp)
target_link_libraries(laser_geometry
    ${rclcpp_LIBRARIES}
    ${sensor_msgs_LIBRARIES}
    ${tf2_LIBRARIES}
)

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(laser_geometry PRIVATE "LASER_GEOMETRY_BUILDING_LIBRARY")

ament_export_include_directories(include)
ament_export_interfaces(laser_geometry)
ament_export_libraries(laser_geometry)

install(
  TARGETS laser_geometry
  EXPORT laser_geometry
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(
  DIRECTORY include/
  DESTINATION include
)

if(BUILD_TESTING)
  # TODO(Martin-Idel-SI): replace this with ament_lint_auto() and/or add the copyright linter back
  find_package(ament_cmake_cppcheck REQUIRED)
  find_package(ament_cmake_cpplint REQUIRED)
  find_package(ament_cmake_lint_cmake REQUIRED)
  find_package(ament_cmake_uncrustify REQUIRED)
  ament_cppcheck()
  ament_cpplint()
  ament_lint_cmake()
  ament_uncrustify()

  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_cmake_gmock REQUIRED)

  ament_add_gtest(projection_test
    test/projection_test.cpp
    TIMEOUT 180)
  if(TARGET projection_test)
    target_link_libraries(projection_test laser_geometry)
  endif()
endif()

ament_package(CONFIG_EXTRAS laser_geometry-extras.cmake)
