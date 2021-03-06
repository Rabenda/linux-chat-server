cmake_minimum_required(VERSION 3.12)
project(linux-chat-server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
message("optional: -std=c++11")

include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Boost COMPONENTS system regex REQUIRED)
find_package(OpenSSL)
message(${CMAKE_INCLUDE_PATH})

set(HEADER_FILES
    "serverconfig.hpp"
    "chatserver.hpp"
    "chatmessage.hpp"
    "chatconnection.hpp")
set(SOURCES_FILES
    "main.cpp"
    "chatserver.cpp"
    "chatmessage.cpp"
    "chatconnection.cpp")

add_executable(${PROJECT_NAME} ${SOURCES_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
