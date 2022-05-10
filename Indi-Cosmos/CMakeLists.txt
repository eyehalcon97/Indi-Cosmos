cmake_minimum_required(VERSION 3.5)

project(Indi-Cosmos VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#Comando iniciar servidor
#indigo_server indigo_ccd_simulator


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)


set(TS_FILES Indi-Cosmos_es_ES.ts)




set(PROJECT_SOURCES
        mainwindow.ui
        main.cpp
        mainwindow.cpp
        mainwindow.h
        device.cpp
        device.h
        device.ui
        conectar.ui
        conectar.h
        conectar.cpp
        indigolib.h
        indigolib.cpp
        itemtexto.h
        itemtexto.cpp
        itemtexto.ui
        itemnumero.h
        itemnumero.cpp
        itemnumero.ui
        itemswitch.h
        itemswitch.cpp
        itemlight.h
        itemlight.cpp
        itemlight.ui
        itemblob.h
        itemblob.cpp
        itemblob.ui
        propiedad.h
        propiedad.cpp
        propiedad.ui





        images.qrc
        ${TS_FILES}
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Indi-Cosmos
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Indi-Cosmos APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Indi-Cosmos SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()

        add_executable(Indi-Cosmos
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Indi-Cosmos PRIVATE Qt${QT_VERSION_MAJOR}::Widgets indigo)



set_target_properties(Indi-Cosmos PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Indi-Cosmos)
endif()



