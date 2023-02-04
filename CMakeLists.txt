cmake_minimum_required(VERSION 3.0.0)
project(CarCustomiser VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

add_executable(CarCustomiser main.cpp Car.cpp carMenu.cpp customiseMenu.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
