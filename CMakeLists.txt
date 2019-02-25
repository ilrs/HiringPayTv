cmake_minimum_required(VERSION 3.5.1)
project(HiringPaytv)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_C_COMPILER "gcc")
set (CMAKE_CXX_COMPILER "g++")

include_directories(include)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wconversion -DNDEBUG -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wconversion -DNDEBUG -std=c++11")
set(CMAKE_BUILD_TYPE "debug")


add_executable(HiringPaytv 
	main.cpp
	src/Client.cpp
	src/JsonReader.cpp
	)

target_link_libraries(HiringPaytv
	cpprest
	boost_system
	ssl
	crypto
	)

add_executable(TestCase 
	test/TestCase.cpp
	src/Client.cpp
	src/JsonReader.cpp
	)

target_link_libraries(TestCase
	cpprest
	boost_system
	ssl
	crypto
	gtest
	gtest_main
	)