#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QGraphicsPixmapItem>
#include "ChessBox.h"

#include <QGraphicsSceneMouseEvent>

class ChessBox;

class ChessPiece:public QGraphicsPixmapItem
{
public:
    ChessPiece(QString team = "",QGraphicsItem *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setCurrentBox(ChessBox *box);

    ChessBox *getCurrentBox();

    QString getSide();
    void setSide(QString value);
    virtual void setImage() = 0;

    bool getIsPlaced();
    void setIsPlaced(bool value);
    QList<ChessBox*> moveLocation();
    void decolor();


    ///////////////////
    virtual void moves() = 0;

    bool firstMove;

    bool boxSetting(ChessBox *box);

protected:
    ChessBox *curBox;
    QString side;
    bool isPlaced;
    QList <ChessBox *> location;

};

#endif // CHESSPIECE_H
