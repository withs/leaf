cmake_minimum_required(VERSION 3.20)
project(leaf)
set (CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/ext/cex/cmake)

find_package(LibEvent REQUIRED)
list(APPEND LIBCEX_EXTERNAL_INCLUDES ${LIBEVHTP_INCLUDE_DIRS})
list(APPEND package_deps LibEvent)

find_package(LibEvhtp REQUIRED)
list(APPEND LIBCEX_EXTERNAL_INCLUDES ${LIBEVENT_INCLUDE_DIRS})
list(APPEND package_deps LibEvhtp)

include_directories(${LIBCEX_EXTERNAL_INCLUDES})

add_executable(${PROJECT_NAME} src/main.cc)

add_subdirectory(ext/cex)

target_include_directories(${PROJECT_NAME}
  PUBLIC ext/cex/include
)

target_link_libraries(${PROJECT_NAME} cex)
