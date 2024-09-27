cmake_minimum_required(VERSION 3.10)
project(Arm)

add_library(Arm STATIC  Arm.cpp)
# # 添加 MotorUnion 子目錄
# add_subdirectory(${CMAKE_SOURCE_DIR}/../MotorUnion ${CMAKE_BINARY_DIR}/MotorUnion)


target_sources(Arm
    PRIVATE
        "Arm.cpp"
)

set(OpenCV_DIR /usr/local/lib)
find_package(OpenCV REQUIRED)

# include_directories(${OpenCV_INCLUDE_DIRS})
target_include_directories(Arm PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Arm 
        ${OpenCV_LIBS}
        MotorUnion
        )

message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
