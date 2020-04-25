cmake_minimum_required(VERSION 3.15)
project(jvmti_examples)

set(CMAKE_CXX_STANDARD 14)

include_directories(${JAVA_INCLUDE_PATH})
include_directories(${JAVA_INCLUDE_PATH2})

SET(LIB_SRC jvmti_example.cpp)
ADD_LIBRARY(jvmti_example SHARED ${LIB_SRC})