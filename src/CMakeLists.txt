cmake_minimum_required(VERSION 3.26)
project(Supermarket_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(Supermarket_system
        main.cpp
        head.h
        login/WelcomePage.h
        login/WelcomePage.cpp
        goods.cpp
        users/Customer.cpp
        users/Keeper.cpp
        users/Cashier.cpp
        users/Admin.cpp
        sellLog.cpp
        display.cpp
)