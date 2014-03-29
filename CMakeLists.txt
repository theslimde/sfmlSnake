project(sfmlSnake)

set(SOURCE_FILES main.cpp)

add_executable(snake ${SOURCE_FILES})

target_link_libraries(snake sfml-system sfml-graphics sfml-window)
