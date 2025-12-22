cmake_minimum_required(VERSION 3.5)

project(GenerativeNumbers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCES
    main.cpp
)

set(HEADERS
)

add_executable(GenerativeNumbers ${SOURCES} ${HEADERS})

install(TARGETS GenerativeNumbers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
