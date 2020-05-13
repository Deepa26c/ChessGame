#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook:public ChessPiece{
public:
    Rook(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void moves();
};

#endif // ROOK_H
