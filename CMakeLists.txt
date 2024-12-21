cmake_minimum_required(VERSION 3.30)
project(threadpool)
set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}
        test_th.cpp
        # threadpool.cppm
)