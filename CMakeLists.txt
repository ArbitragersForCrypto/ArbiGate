cmake_minimum_required(VERSION 3.9)
project(arbitrage)

find_package(cpprestsdk REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED)

add_executable(bin/test1 src/test1.cpp)
target_link_libraries(test1 PRIVATE cpprestsdk::cpprest)