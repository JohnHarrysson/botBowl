cmake_minimum_required(VERSION 3.0.0)
project(BotBowl VERSION 0.1.0)
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

include(CTest)
enable_testing()

add_executable(BotBowl ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
