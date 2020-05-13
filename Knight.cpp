#include "Knight.h"
#include "Game.h"

extern Game *game;
Knight::Knight(QString team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Knight::setImage(){
    if(side == "WHITE")
        setPixmap(QPixmap(":/Images/horsew.png"));
    else
        setPixmap(QPixmap(":/Images/horseb.png"));
}

void Knight::moves(){
    int row = this->getCurrentBox()->rowl;
    int col = this->getCurrentBox()->colL;
    int i ,j;
    QString team  = this->getSide();

    //move in L to up left
    i = row - 2;
    j = col - 1;
    if(i >=0 && j>=0 && (game->sq[i][j]->getChessPieceColor() != team) ) {
        location.append(game->sq[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    //move in L to right
    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (game->sq[i][j]->getChessPieceColor() != team) ) {
        location.append(game->sq[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    
    //move down to left in L shape
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (game->sq[i][j]->getChessPieceColor() != team) ) {
        location.append(game->sq[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    
    //move down to right in L shape
    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (game->sq[i][j]->getChessPieceColor() != team) ) {
        location.append(game->sq[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }

    //move to left to up in L shape
    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (game->sq[i][j]->getChessPieceColor() != team) ) {
        location.append(game->sq[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    
    //move to left to down in L shape
    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (game->sq[i][j]->getChessPieceColor() != team) ) {
        location.append(game->sq[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    
    //move right side up in L shape
    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (game->sq[i][j]->getChessPieceColor() != team) ) {
        location.append(game->sq[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    
    //move right side up in L shape
    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (game->sq[i][j]->getChessPieceColor() != team) ) {
        location.append(game->sq[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }


}
