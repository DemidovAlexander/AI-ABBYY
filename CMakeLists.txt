cmake_minimum_required(VERSION 3.2)
project(AI_ABBYY)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CDynamicProgrammingStrategy.cpp
    CGame.cpp
    CMap.cpp
    CPlayerState.cpp
    CVector.cpp
    CStateArray.cpp
    main.cpp
)

add_executable(AI_ABBYY ${SOURCE_FILES} CStrategy.cpp CStrategy.h)