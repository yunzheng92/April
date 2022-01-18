cmake_minimum_required(VERSION 3.7.1)
project(April)


set(CMAKE_CXX_STANDARD 17)
set(spdlog_VERSION 1.9.2)
include_directories(${CMAKE_CURRENT_LIST_DIR}/3rdparty/spdlog-${spdlog_VERSION}/include)

find_package(Vulkan)

if(NOT Vulkan_FOUND)
    message("Not Found Vulkan")
    return()
else()
    message(STATUS "Vulkan_INCLUDE_DIRS : ${Vulkan_INCLUDE_DIRS}")
    message(STATUS "Vulkan_LIBRARY : ${Vulkan_LIBRARY}")
endif()


set(DEMO_SRC ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)

add_executable(demo ${DEMO_SRC})
target_compile_features(demo PRIVATE cxx_std_17)
target_include_directories(demo PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(demo PRIVATE ${Vulkan_LIBRARY})
if(MSVC)
  target_compile_options(demo PRIVATE /W4 /WX)
else()
  target_compile_options(demo PRIVATE -Wall -Wextra -pedantic -Werror)
endif()