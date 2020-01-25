cmake_minimum_required(VERSION 3.15)
project(Roguelike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncursesw -fsanitize=address -g -Wall")

add_executable(${PROJECT_NAME} main.cpp Models/Map.h Models/Characters/Character.h Models/Point.h Models/Characters/Knight.h Models/Characters/Wall.h Models/Game.h Models/Characters/Floor.h Models/Characters/Princess.h Models/Characters/Zombie.h Models/Collider.h Models/Characters/Knight.cpp Models/Characters/Zombie.cpp Models/Characters/Dragon.cpp Models/Characters/Dragon.h Models/CharacterFactory.h Models/CharactersLogic.h Models/CharactersLogic.cpp Models/Characters/Bullet.cpp Models/Characters/Bullet.h Models/Settings/Settings.h Models/Settings/Settings.cpp Models/Characters/Aid.h Models/Windows/MainMenuWindow.h Models/Windows/PauseMenuWindow.h Models/Windows/PauseMenuWindow.cpp Models/Windows/MessageWindow.cpp Models/Windows/MessageWindow.h)

link_directories(/usr/include/)
target_link_libraries(${PROJECT_NAME} ncurses)