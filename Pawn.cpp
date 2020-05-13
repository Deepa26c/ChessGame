#include "Pawn.h"
#include "Game.h"
#include <typeinfo>
#include "King.h"


extern Game *game;
Pawn::Pawn(QString team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
    firstMove = true;
}
void Pawn::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Images/pawnwhite.png"));
    else
        setPixmap(QPixmap(":/Images/pawnblack.png"));
}

///location is chessbox QList in chesspiece class

void Pawn::moves(){
    location.clear();

    int row = this->getCurrentBox()->rowl;
    int col = this->getCurrentBox()->colL;


    if(this->getSide() == "WHITE")
    {
        if(col>0 && row>0 && game->sq[row-1][col-1]->getChessPieceColor() == "BLACK"){
            location.append(game->sq[row-1][col-1]);
            boxSetting(location.last());
        }
        if(col<7 && row>0 && game->sq[row-1][col+1]->getChessPieceColor() == "BLACK")
        {
            location.append(game->sq[row-1][col+1]);
            boxSetting(location.last());
        }
        if(row>0 && (!game->sq[row-1][col]->getHasChessPiece())){
            location.append(game->sq[row-1][col]);
            boxSetting(location.last());
            if(firstMove && !game->sq[row-2][col]->getHasChessPiece()){
                location.append(game->sq[row-2][col]);
                boxSetting(location.last());
            }
        }

    }
    else
    {
        if(col>0 && row<7 && game->sq[row+1][col-1]->getChessPieceColor() == "WHITE"){
            location.append(game->sq[row+1][col-1]);
            boxSetting(location.last());
        }
        if(col<7 && row<7 && game->sq[row+1][col+1]->getChessPieceColor() == "WHITE"){
            location.append(game->sq[row+1][col+1]);
            boxSetting(location.last());
        }
        if(row<7 && (!game->sq[row+1][col]->getHasChessPiece())){
            location.append(game->sq[row+1][col]);
            boxSetting(location.last());
            if(firstMove && !game->sq[row+2][col]->getHasChessPiece()){
                location.append(game->sq[row+2][col]);
                boxSetting(location.last());
            }
        }
    }

}
