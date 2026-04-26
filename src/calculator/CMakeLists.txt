cmake_minimum_required(VERSION 3.16)

project(Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

if(NOT DEFINED CALC_NAME)
	set(CALC_NAME Calculator)
endif()

set(GUI_SOURCES
	gui/main.cpp
	gui/mainwindow.cpp
	gui/mainwindow.ui
)

add_library(calculator_engine STATIC
	engine/calculator_engine.cpp
)

add_executable(${CALC_NAME} ${GUI_SOURCES})

target_link_libraries(${CALC_NAME} PRIVATE
	calculator_engine
	Qt6::Widgets
	${MATH_LIB}
)

target_include_directories(${CALC_NAME} PRIVATE ${INCLUDE_DIR})
