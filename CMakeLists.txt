cmake_minimum_required(VERSION 3.19)
project(spotify-data-viewer LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(spotify-data-viewer
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    spotify/spotifylibrary.h spotify/spotifylibrary.cpp
    spotify/spotifytrack.h spotify/spotifytrack.cpp
    spotify/spotifyalbum.h spotify/spotifyalbum.cpp
    spotify/spotifyartist.h spotify/spotifyartist.cpp
    widgets/librarybrowserwidget.h widgets/librarybrowserwidget.cpp widgets/librarybrowserwidget.ui
    widgets/playlistbrowserwidget.h widgets/playlistbrowserwidget.cpp widgets/playlistbrowserwidget.ui
    widgets/librarytracksmodel.h widgets/librarytracksmodel.cpp
    widgets/libraryalbumsmodel.h widgets/libraryalbumsmodel.cpp
)

target_link_libraries(spotify-data-viewer
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS spotify-data-viewer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET spotify-data-viewer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
