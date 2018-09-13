cmake_minimum_required(VERSION 2.8)

project('NCurseTest')

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED)

set(SOURCE_FILES main.cpp Screen.cpp Character.cpp Frame.cpp PerlinNoise.cpp)

find_package(Curses REQUIRED)

include_directories( ${CURSES_INCLUDE_DIR} )

add_executable(pro ${SOURCE_FILES})

target_link_libraries(pro ${CURSES_LIBRARIES})
