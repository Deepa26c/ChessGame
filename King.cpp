#include "King.h"
#include "Game.h"
#include "Pawn.h"

extern Game *game;
King::King(QString team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void King::setImage(){
    if(side == "WHITE")
        setPixmap(QPixmap(":/Images/kingw.png"));
    else
        setPixmap(QPixmap(":/Images/kingb.png"));           ////////wrong folder name was not displaying the black king
}

void King::moves(){

    location.clear();
    int row = this->getCurrentBox()->rowl;
    int col = this->getCurrentBox()->colL;
    QString team = this->getSide();

    if(col > 0 && row > 0 && !(game->sq[row-1][col-1]->getChessPieceColor() == team)) {
        location.append(game->sq[row-1][col-1]);
        game->sq[row-1][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col < 7 && row > 0 && !(game->sq[row-1][col+1]->getChessPieceColor() == team)) {
        location.append(game->sq[row-1][col+1]);
        game->sq[row-1][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(row>0 && !(game->sq[row-1][col]->getChessPieceColor() == team)) {
        location.append(game->sq[row-1][col]);
        game->sq[row-1][col]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(row<7 && !(game->sq[row+1][col]->getChessPieceColor() == team)) {
        location.append(game->sq[row+1][col]);
        game->sq[row+1][col]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col>0 && !(game->sq[row][col-1]->getChessPieceColor() == team)) {
        location.append(game->sq[row][col-1]);
        game->sq[row][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col<7 && !(game->sq[row][col+1]->getChessPieceColor() == team)) {
        location.append(game->sq[row][col+1]);
        game->sq[row][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col > 0 && row < 7  && !(game->sq[row+1][col-1]->getChessPieceColor() == team)) {
        location.append(game->sq[row+1][col-1]);
        game->sq[row+1][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col < 7 && row < 7 && !(game->sq[row+1][col+1]->getChessPieceColor() == team)) {
        location.append(game->sq[row+1][col+1]);
        game->sq[row+1][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
}
