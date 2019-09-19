cmake_minimum_required(VERSION 3.0)

PROJECT(ProjectExample VERSION 0.1.0)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations")

ENABLE_TESTING()
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)

