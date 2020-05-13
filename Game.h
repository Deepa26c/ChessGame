#ifndef GAME_H
#define GAME_H

/////////Qt grphics include/////////
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
////My class includes//////////
#include "Board.h"
#include "ChessPiece.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);


    void drawHolder(int x,int y,QColor color);
    void drawChessBoard();
    void displayWhite();
    void displayBlack();
    void placeDeadPlace(ChessPiece *piece);

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    ChessPiece *pieceToMove;

    QString getTurn();
    void setTurn(QString value);
    void changeTurn();

    ChessBox *sq[8][8];
    QGraphicsTextItem *check;

    QList <ChessPiece *> alivePiece;
    void displayMainMenu();

    void gameOver();
    void removeAll();


public slots:
    void start();


private:
    QGraphicsScene *gameScene;
    QList <ChessPiece *> whiteDead;
    QList <ChessPiece *> blackDead;


    QGraphicsRectItem *deadHolder;
    QString turn;
    Board *chess;

    QList <QGraphicsItem *> listGrap;

    QGraphicsTextItem * turnDisplay;




};

#endif // GAME_H
