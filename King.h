#ifndef KING_H
#define KING_H
#include "ChessPiece.h"

class King:public ChessPiece{
public:
    King(QString team,QGraphicsItem *parent=0);
    void setImage();
    void moves();

};

#endif // KING_H
