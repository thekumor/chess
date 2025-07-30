cmake_minimum_required(VERSION 3.10)

project(chess)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_STANDARD_LIBRARIES "")

file(GLOB chessSrc
	"src/chess/*.h"
	"src/chess/*cpp"
)

add_executable(${CMAKE_PROJECT_NAME} ${chessSrc})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
	$<INSTALL_INTERFACE:src>
)

target_link_libraries(${CMAKE_PROJECT_NAME} user32 gdi32)