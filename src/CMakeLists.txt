cmake_minimum_required(VERSION 3.26)
project(Supermarket_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(Supermarket_system
        main.cpp
        head.h
        login/WelcomePage.h
        login/WelcomePage.cpp
        users.cpp
        goods.cpp
        sellLog.cpp
        display.cpp
        function.cpp
)