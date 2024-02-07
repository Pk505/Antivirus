cmake_minimum_required(VERSION 3.23)
project(Antivirus)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio)
add_executable(Antivirus main.cpp AVBase.cpp AVBase.h Signature.cpp Signature.h ScannerFunctions.cpp ScannerFunctions.h)
target_link_libraries(Antivirus sfml-graphics sfml-audio)