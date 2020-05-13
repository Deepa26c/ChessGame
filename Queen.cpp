#include "Queen.h"
#include "Game.h"

extern Game *game;
Queen::Queen(QString team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Queen::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Images/queenw.png"));
    else
        setPixmap(QPixmap(":/Images/queenb.png"));
}

void Queen::moves(){
    location.clear();
    int row = this->getCurrentBox()->rowl;
    int col = this->getCurrentBox()->colL;
    QString team = this->getSide();

    for(int i = row-1,j = col; i >= 0 ; i--) {
        if(game->sq[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->sq[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }
    for(int i = row+1,j = col; i <= 7 ; i++) {
        if(game->sq[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->sq[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }

    for(int i = row,j = col-1; j >= 0 ; j--) {
        if(game->sq[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->sq[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }
    for(int i = row,j = col+1; j <= 7 ; j++)
    {
        if(game->sq[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->sq[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }

    for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
        if(game->sq[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->sq[i][j]);
            if(boxSetting(location.last()) ){
                break;
            }
        }
    }

    for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
        if(game->sq[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->sq[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
    for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
        if(game->sq[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->sq[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
    for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
        if(game->sq[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->sq[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
}
