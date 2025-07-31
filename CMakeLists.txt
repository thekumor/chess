cmake_minimum_required(VERSION 3.10)

# if(POLICY CMP0081)
# 	cmake_policy(SET CMP0081 NEW)
# endif()

project(chess)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_STANDARD_LIBRARIES "")

file(GLOB chessSrc
	"build/src/chess/*.h"
	"build/src/chess/*cpp"
)

add_executable(${CMAKE_PROJECT_NAME} ${chessSrc})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
	$<INSTALL_INTERFACE:src>
)

set(SDL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/vendor/SDL-3.2.18")

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${SDL_DIR}/include)
# target_link_directories(${CMAKE_PROJECT_NAME}
#	PRIVATE
#	"$<$<CONFIG:Debug>:${SDL_DIR}/lib-win32-x64/Debug>"
#	"$<$<CONFIG:Release>:${SDL_DIR}/lib-win32-x64/Release>"
#	"$<$<CONFIG:MinSizeRel>:${SDL_DIR}/lib-win32-x64/Release>"
#	"$<$<CONFIG:RelWithDebInfo>:${SDL_DIR}/lib-win32-x64/Release>"
# )
target_link_libraries(${CMAKE_PROJECT_NAME}
	PRIVATE
	user32 gdi32
	"$<$<CONFIG:Debug>:${SDL_DIR}/lib-win32-x64/Debug/sdl3.lib>"
	"$<$<CONFIG:Release>:${SDL_DIR}/lib-win32-x64/Release/sdl3.lib>"
	"$<$<CONFIG:MinSizeRel>:${SDL_DIR}/lib-win32-x64/Release/sdl3.lib>"
	"$<$<CONFIG:RelWithDebInfo>:${SDL_DIR}/lib-win32-x64/Release/sdl3.lib>"
)