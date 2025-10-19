cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Для Apple Silicon
if(APPLE AND CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "arm64")
    set(CMAKE_APPLE_SILICON_PROCESSOR "arm64")
endif()


# Автоматически находим все исходники
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME}  ${SOURCES}
        src/Point.cpp
        src/Point.h
        src/Direction.cpp
        src/Direction.h
        src/Ansi.cpp
        src/Ansi.h
        src/TerminalRenderer.cpp
        src/TerminalRenderer.h
        src/InputHandler.cpp
        src/InputHandler.h)

# Настройки для отладки
set(CMAKE_BUILD_TYPE Debug)