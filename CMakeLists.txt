cmake_minimum_required(VERSION 3.15)
project(Roguelike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses -fsanitize=address -g -Wall")

add_executable(${PROJECT_NAME} main.cpp Models/Map.h Models/Characters/Character.h Models/Point.h Models/Characters/Knight.h Models/Characters/Wall.h Models/Game.h Models/Characters/Floor.h)

link_directories(/usr/include/)
target_link_libraries(${PROJECT_NAME} ncurses)