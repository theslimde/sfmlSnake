project(sfmlSnake)

set(SOURCE_FILES main.cpp)
set(CMAKE_CXX_FLAGS "-std=c++1y -Wall -Wextra -Wpedantic")

add_executable(snake ${SOURCE_FILES})

target_link_libraries(snake sfml-system sfml-graphics sfml-window)
