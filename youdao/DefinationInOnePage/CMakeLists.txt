cmake_minimum_required (VERSION 2.8)

project(GeneratePage)

add_executable(${PROJECT_NAME}
	${CMAKE_SOURCE_DIR}/CssString.cpp
	${CMAKE_SOURCE_DIR}/GenerateDefinitionPage.cpp
	)

