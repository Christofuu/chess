cmake_minimum_required(VERSION 3.21)
project(chess LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(chess src/main.cpp src/Board.cpp src/Board.h
        src/Tile.cpp
        src/Tile.h
        src/Piece.cpp
        src/Piece.h
        src/Game.cpp
        src/Game.h
        src/King.cpp
        src/King.h
        src/King.h
        src/NullPiece.cpp
        src/NullPiece.h
        src/NullPiece.h
        src/NullPiece.cpp)
target_link_libraries(chess PRIVATE sfml-graphics)
target_compile_features(chess PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET chess POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:chess> $<TARGET_FILE_DIR:chess> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS chess)
