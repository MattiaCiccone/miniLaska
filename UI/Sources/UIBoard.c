#include "..\\Headers\\UIBoard.h"

/*la cellSide deve essere un multiplo di TOWER_HEIGHT*/
void printBoard(PlayableBoard board, int cellSide)
{
    int boardRow, boardCol, UIRow, UICol;

    if(cellSide % TOWER_HEIGHT || cellSide < 0)
        return;
    
    printUpperSeparator(cellSide);
    for(boardRow = 0; boardRow < GRID_SIZE; boardRow++)
    {
        for(UIRow = 0; UIRow < cellSide; UIRow++)
        {
            printRowCoordinates(cellSide, UIRow, boardRow);

            printf("%c", VERTICAL_SIDE);
            for(boardCol = 0; boardCol < GRID_SIZE; boardCol++)
            {

                if(boardRow % 2 == boardCol % 2)
                {
                    char pawn = board[boardRow][boardCol / 2][TOWER_HEIGHT - 1 - (UIRow / (cellSide / TOWER_HEIGHT))];
                    printCellContent(pawn, cellSide);
                }
                else 
                    printCellContent(UNPLAYABLE_PAWN, cellSide);

                printf("%c", VERTICAL_SIDE);
            }
            printf("\n");
        }

        if(boardRow < GRID_SIZE - 1)
            printMidSeparator(cellSide);
        else
        {
            printLowerSeparator(cellSide);
            printColumnCoordinates(cellSide);
        }
    }

    
}



static void printRowCoordinates(int cellSide, int UIRow, int boardRow)
{
    if(UIRow == cellSide / 2)
        printf("\t%d", boardRow);
    else 
        printf("\t ");
}
static void printColumnCoordinates(int cellSide)
{
    int currentChar = 0;
    int boardCol;

    printf("\t ");
    for(boardCol = 0; boardCol < GRID_SIZE; boardCol++)
    {
        printf(" ");
        for(currentChar = 0; currentChar < cellSide; currentChar++)
        {
            if(currentChar == cellSide / 2)
                printf("%c", 'a' + boardCol);
            else 
                printf(" ");            
        }
    }

    printf("\n\n");
}
static void printHorizontalSeparator(int cellSide, char left, char intersection, char right)
{
    int i, j;

    printf("\t %c", left);
    for(i = 0; i < GRID_SIZE; i++)
    {
        for(j = 0; j < cellSide; j++)
            printf("%c", HORIZONTAL_SIDE);
        printf("%c", intersection);
    }

    printf("\b%c\n", right);
}
static void printUpperSeparator(int cellSide)
{
    unsigned char symbols[] = {0xc9, 0xcb, 0xbb};
    printHorizontalSeparator(
        cellSide, 
        TOP_LEFT_CORNER,
        TOP_INTERSECTION,
        TOP_RIGHT_CORNER);
}
static void printMidSeparator(int cellSide)
{
    unsigned char symbols[] = {0xcc, 0xce, 0xb9};
    printHorizontalSeparator(
        cellSide,
        MID_LEFT_SIDE,
        MID_INTERSECTION,
        MID_RIGHT_SIDE);
}
static void printLowerSeparator(int cellSide)
{
    unsigned char symbols[] = {0xc8, 0xca, 0xbc};
    printHorizontalSeparator(
        cellSide, 
        BOTTOM_LEFT_CORNER,
        BOTTOM_INTERSECTION,
        BOTTOM_RIGHT_CORNER);
}
static void printCellContent(char content, int cellSide)
{
    int i;
    for(i = 0; i < cellSide; i++)
        printf("%c", content);
}
