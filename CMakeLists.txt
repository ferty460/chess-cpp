cmake_minimum_required(VERSION 4.0)
project(chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess main.cpp
        piece/Piece.cpp
        piece/header/Piece.h
        core/Color.h
        core/Coordinates.cpp
        core/Coordinates.h
        core/File.h
        board/Board.cpp
        board/Board.h
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
        render/ConsoleBoardRenderer.cpp
        render/ConsoleBoardRenderer.h
        core/CoordinatesShift.cpp
        core/CoordinatesShift.h
        core/Game.cpp
        core/Game.h
        core/InputCoordinates.cpp
        core/InputCoordinates.h
        board/BoardFactory.cpp
        board/BoardFactory.h
        piece/PieceFactory.cpp
        piece/header/PieceFactory.h
        utils/BoardUtils.cpp
        utils/BoardUtils.h
        piece/LongRangePiece.cpp
        piece/header/LongRangePiece.h
        piece/header/IBishop.h
        piece/IBishop.cpp
        piece/Irook.cpp
        piece/header/IRook.h
        board/Move.cpp
        board/Move.h
        checker/GameState.h
        checker/GameStateChecker.h
        checker/StalemateGameChecker.cpp
        checker/StalemateGameChecker.h
        checker/CheckmateGameChecker.cpp
        checker/CheckmateGameChecker.h)
