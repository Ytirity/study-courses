cmake_minimum_required(VERSION 3.5)

project(FirstTry LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./glad/include)
include_directories(./glad/src)

add_executable(FirstTry main.cpp
)

target_link_libraries(FirstTry -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl) #-lGL only needed? #-lglfw3 не видит
