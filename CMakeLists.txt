cmake_minimum_required(VERSION 3.23)
project(AnimatedText)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnimatedText main.cpp values.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories("SFML-2.5.1/include")
target_link_libraries(AnimatedText sfml-system sfml-window sfml-graphics sfml-audio)
file(COPY "arial.ttf" DESTINATION "/")