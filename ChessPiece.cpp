#include "ChessPiece.h"
#include "Game.h"
#include "King.h"

extern Game *game;
ChessPiece::ChessPiece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this == game->pieceToMove){
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
        return;
     }
    if((!getIsPlaced()) || ((game->getTurn()!=this->getSide())&& (!game->pieceToMove))){
            return;
    }
    if(!game->pieceToMove){
            game->pieceToMove = this;
            game->pieceToMove->getCurrentBox()->setColor(Qt::red);
            game->pieceToMove->moves();
    }
    else if(this->getSide() != game->pieceToMove->getSide()){
            this->getCurrentBox()->mousePressEvent(event);
    }

}
void ChessPiece::decolor()
{
    for(size_t i=0,n=location.size();i<n;i++)
    {
        location[i]->resetOriginalColor();
    }
}
void ChessPiece::setCurrentBox(ChessBox *box)
{

    curBox = box;
}

ChessBox *ChessPiece::getCurrentBox()
{
    return curBox;
}

void ChessPiece::setSide(QString value)
{
    side = value;
}
QString ChessPiece::getSide()
{
    return  side;
}
bool ChessPiece::getIsPlaced()
{
    return isPlaced;
}
void ChessPiece::setIsPlaced(bool value)
{
    isPlaced = value;
}

QList <ChessBox *> ChessPiece::moveLocation(){
    return location;
}

bool ChessPiece::boxSetting(ChessBox *box)
{
    if(box->getHasChessPiece()) {
        King *q = dynamic_cast<King*>(location.last()->currentPiece);
        if(q){
            box->setColor(Qt::blue);
        }
        else
            box->setColor(Qt::green);
        return true;
    }
    else
        location.last()->setColor(Qt::darkGreen);
    return false;
}

