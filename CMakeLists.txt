cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
PROJECT(test_algorithm)
message("Hello algorithm!")
set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(${SRC_ROOT}/tree CPP_FILES_IN_TREE)
set(
	SOURCE_FILES
	${CPP_FILES_IN_TREE}
	${SRC_ROOT}/main.cpp
)
add_subdirectory(${SRC_ROOT}/sort)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} libsort)