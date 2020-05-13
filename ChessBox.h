#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include "ChessPiece.h"
#include <QGraphicsSceneMouseEvent>


class ChessPiece;
class ChessBox: public QGraphicsRectItem
{
public:
    ChessBox(QGraphicsItem *parent = 0);
    ~ChessBox();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);
    void placePiece(ChessPiece *piece);

    void resetOriginalColor();
    void setOriginalColor(QColor value);

    void setHasChessPiece(bool value,ChessPiece *piece=0);
    bool getHasChessPiece();


    QString getChessPieceColor();
    void setChessPieceColor(QString value);
    void checkForCheck();

    ChessPiece *currentPiece;


    int rowl;
    int colL;
private:
    QBrush brush;
    QColor originalColor;
    bool hasChessPiece;
    QString chessPieceColor;
};

#endif // CHESSBOX_H
