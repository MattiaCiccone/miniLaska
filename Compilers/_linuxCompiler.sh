#!/bin/bash
gcc -ansi -pedantic-errors "../BACKEND/Sources/board.c" "../BACKEND/Sources/errors.c" "../BACKEND/Sources/moves.c" "../BACKEND/Sources/pawn.c" "../BACKEND/Sources/validation.c" "../UI/Sources/UI.c" "../UI/Sources/UIBoard.c" "../main.c" -o2 -o "../bin/Unix/main" -lm
