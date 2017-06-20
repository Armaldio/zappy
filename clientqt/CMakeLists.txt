cmake_minimum_required(VERSION 3.7)
project(clientqt)

# Force debug mode without parameters
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Programme Name
set(EXECUTABLE_NAME clientqt)

# Version C++
set(CMAKE_CXX_STANDARD 11)

# Add local cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

###
# Find SFML
###

find_package(SFML 2 REQUIRED audio graphics window system)

###
# Find QT
###

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

##
# Find Thread
##

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Sources
set(SOURCE_FILES
        src/main.cpp
        src/QSFML/QSFMLWidget.cpp
        src/RenderCanvas.cpp
        include/QSFML/QSFMLWidget.hpp
        include/RenderCanvas.hpp
        src/QSFML/KeyConverter.cpp
        include/QSFML/KeyConverter.hpp
        src/MainWindow.cpp
        include/MainWindow.hpp src/Scene/SceneManager.cpp include/Scene/SceneManager.hpp src/Scene/Scene.cpp include/Scene/Scene.hpp src/Scene/SplashScene.cpp include/Scene/SplashScene.hpp include/Singleton.hpp src/Game/Inventaire.cpp include/Game/Inventaire.hpp src/Scene/GameScene.cpp include/Scene/GameScene.hpp src/Game/Player.cpp include/Game/Player.hpp src/Game/Map.cpp include/Game/Map.hpp src/Game/MapSquare.cpp include/Game/MapSquare.hpp)

qt5_wrap_ui(UI_SRC src/UI/MainWindow.ui)

# Includes directory
include_directories(${CMAKE_BINARY_DIR} ${SFML_INCLUDE_DIR} "include")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES} ${UI_SRC} ${MOC_SRCS} ${RES_SOURCES} ${UI_HEADERS})

# Linkage
# build it (link libraries)
target_link_libraries(${EXECUTABLE_NAME} Qt5::Widgets)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(${EXECUTABLE_NAME} Threads::Threads)

if (UNIX)
    target_link_libraries(${EXECUTABLE_NAME} "-lX11")
endif(UNIX)