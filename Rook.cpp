#include "Rook.h"
#include "Game.h"

extern Game *game;
Rook::Rook(QString team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Rook::setImage(){
    if(side=="WHITE")
        setPixmap(QPixmap(":/Images/rookw.png"));
    else
        setPixmap(QPixmap(":/Images/rookb.png"));
}

void Rook::moves(){
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

    //For Down

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
}
