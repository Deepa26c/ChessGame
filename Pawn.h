#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"
class Pawn:public ChessPiece
{
public:
    Pawn(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void moves();

};

#endif // PAWN_H
