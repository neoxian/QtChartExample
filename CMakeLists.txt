
cmake_minimum_required(VERSION 3.6)

project(ChartExample)

set(CMAKE_PREFIX_PATH "c:\\Qt\\5.15.0\\msvc2019_64")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Gui Charts REQUIRED)

file(GLOB Source "*.cpp" "*.h")

add_executable(ChartExample ${Source})
target_link_libraries(ChartExample Qt5::Core Qt5::Widgets Qt5::Charts)

add_custom_command(TARGET ChartExample POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:ChartExample>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:ChartExample>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:ChartExample>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Charts> $<TARGET_FILE_DIR:ChartExample>
    )

add_custom_command(TARGET ChartExample POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory 
              "${PROJECT_SOURCE_DIR}/../../qtdlls/$<CONFIGURATION>"
              $<TARGET_FILE_DIR:ChartExample>)

      add_custom_command(TARGET ChartExample POST_BUILD
        COMMAND ${CMAKE_PREFIX_PATH}/bin/windeployqt.exe $<TARGET_FILE:ChartExample>
        COMMENT "Running windeplayqt.exe to generate all the things the executable needs"
        VERBATIM
        )

