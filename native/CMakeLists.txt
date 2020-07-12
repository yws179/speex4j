cmake_minimum_required(VERSION 3.16)
project(native)

set(CMAKE_CXX_STANDARD 11)

link_libraries(speex)

add_library(
        decoder.c
        com_github_yws179_speex_SpeexDecoder.c
)

add_executable(native main.cpp decoder.c)