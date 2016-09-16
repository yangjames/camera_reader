cmake_minimum_required(VERSION 2.8.3)
project(camera_reader)

find_package(OpenCV 3.1.0 REQUIRED)
find_package(catkin REQUIRED
  roscpp
  )

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  )

add_executable(camera_reader src/camera_reader.cpp)

target_link_libraries(camera_reader
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
  )

install(TARGETS camera_reader
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )
