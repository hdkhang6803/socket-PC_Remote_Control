cmake_minimum_required(VERSION 3.5)

project(PC_Remote_Control VERSION 0.1 LANGUAGES CXX)

#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainWindow.cpp
        mainWindow.h

        keystroke.h keystroke.cpp 

        server.h server.cpp
        client.h client.cpp
        clientWindow.h clientWindow.cpp
        clientInfo.cpp clientInfo.h
        serverWindow.h serverWindow.cpp 
        
#        keyboard_track.cpp keyboard_track.h
        audiorecorder.h audiorecorder.cpp
        audiowindow.h audiowindow.cpp
        fileExplorer.h fileExplorer.cpp 
	screenshot.cpp screenshot.h
        screendisplayer.cpp screendisplayer.h

        appswindow.h appswindow.cpp 

        FileNavButton.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PC_Remote_Control
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PC_Remote_Control APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PC_Remote_Control SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PC_Remote_Control
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PC_Remote_Control PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

find_package(Qt6 REQUIRED COMPONENTS Network)
target_link_libraries(PC_Remote_Control PRIVATE Qt6::Network)

find_package(Qt6 REQUIRED COMPONENTS Network)
target_link_libraries(PC_Remote_Control PRIVATE Qt6::Widgets)

find_package(Qt6 REQUIRED COMPONENTS Network)
target_link_libraries(PC_Remote_Control PRIVATE Qt6::Core)

find_package(Qt6 REQUIRED COMPONENTS Multimedia)
target_link_libraries(PC_Remote_Control PRIVATE Qt6::Multimedia)

set_target_properties(PC_Remote_Control PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS PC_Remote_Control
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PC_Remote_Control)
endif()
