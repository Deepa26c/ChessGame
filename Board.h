#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsRectItem>
#include "ChessPiece.h"

class Board{
public:
    Board();
    void drawBoxes(int x,int y);

    void setUpWhite();
    void setUpBlack();

    void addPiece();
    void reset();


private:
    QList <ChessPiece *> white;
    QList <ChessPiece *> black;
};

#endif // BOARD_H
