cmake_minimum_required(VERSION 4.0)
project(chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess main.cpp
        piece/Piece.cpp
        piece/header/Piece.h
        header/Color.h
        Coordinates.cpp
        header/Coordinates.h
        header/File.h
        Board.cpp
        header/Board.h
        piece/Knight.cpp
        piece/header/Knight.h
        piece/Pawn.cpp
        piece/header/Pawn.h
        piece/Bishop.cpp
        piece/header/Bishop.h
        piece/Rook.cpp
        piece/header/Rook.h
        piece/Queen.cpp
        piece/header/Queen.h
        piece/King.cpp
        piece/header/King.h
        render/header/BoardRenderer.h
        render/ConsoleBoardRenderer.cpp
        render/header/ConsoleBoardRenderer.h)
