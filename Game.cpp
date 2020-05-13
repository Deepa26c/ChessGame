#include "Game.h"
#include "button.h"
#include <QPixmap>
#include "King.h"


Game::Game(QWidget *parent): QGraphicsView(parent)
{
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,900); //x,y,w,h

    setFixedSize(1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBackgroundBrush(brush);
    pieceToMove = NULL;

    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100,10);     //width():This property holds the width of the widget excluding any window frame,its also helps to fit on any screen size
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : WHITE");

    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,860);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",18));
    check->setPlainText("CHECK!");
    check->setVisible(true);
    setTurn("WHITE");

}

void Game::drawChessBoard()
{
    chess = new Board();
    drawHolder(0,0,Qt::lightGray);
    drawHolder(1100,0,Qt::lightGray);
    chess->drawBoxes(width()/2-400,50);
}

void Game::displayWhite()
{
    int j=0;
    int k=0;
    for(size_t i=0,n=whiteDead.size();i<n;i++)
    {
        if(j==4){
            k++;
            j=0;
        }
        whiteDead[i]->setPos(40+50*j++,100+50*2*k);
    }
}

void Game::displayBlack()
{
    int j=0;
    int k=0;
    for(size_t i=0,n=blackDead.size();i<n;i++)
    {
        if(j==4){
            k++;
            j=0;
        }
        blackDead[i]->setPos(40+50*j++,100+50*2*k);
    }
}

void Game::placeDeadPlace(ChessPiece *piece)
{
    if(piece->getSide() == "WHITE")
    {
        whiteDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
                if(g){

                    check->setPlainText("Black Won");
              //      gameOver();
                }
        displayWhite();
    }
    else
    {
        blackDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
                if(g){

                    check->setPlainText("White Won");
                //    gameOver();
                }
        displayBlack();
    }
    alivePiece.removeAll(piece);
}

void Game::addToScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);
}

QString Game::getTurn()
{
    return turn;
}

void Game::setTurn(QString value)
{
    turn = value;
}

void Game::changeTurn()
{
    if(getTurn() == "WHITE"){
        setTurn("BLACK");
    }
    else{
        setTurn("WHITE");
    }
    turnDisplay->setPlainText("Turn : " + getTurn());
}




void Game::start()
{
    for(size_t i=0, n=listGrap.size();i<n;i++)
    {
        removeFromScene(listGrap[i]);
    }
    addToScene(turnDisplay);

    QGraphicsTextItem* whitePiece = new QGraphicsTextItem();
    whitePiece->setPos(70,10);
    whitePiece->setZValue(1);
    whitePiece->setDefaultTextColor(Qt::white);
    whitePiece->setFont(QFont("",20));
    whitePiece->setPlainText("WHITE PIECE");
    addToScene(whitePiece);

    QGraphicsTextItem *blackPiece = new QGraphicsTextItem();
    blackPiece->setPos(1170,10);
    blackPiece->setZValue(1);
    blackPiece->setDefaultTextColor(Qt::black);
    blackPiece->setFont(QFont("",20));
    blackPiece->setPlainText("BLACK PIECE");
    addToScene(blackPiece);
    addToScene(check);
    chess->addPiece();                                            /////forgot call this function bcoz of which piece were not displyed in board
}

void Game::drawHolder(int x, int y, QColor color)
{
    deadHolder = new QGraphicsRectItem(x,y,300,900);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addToScene(deadHolder);
}

void Game::displayMainMenu()
{
    QGraphicsPixmapItem *p = new QGraphicsPixmapItem();
        p->setPixmap(QPixmap(":/Images/kingw.png"));
        p->setPos(420,170);
        addToScene(p);
        listGrap.append(p);

        QGraphicsPixmapItem *p1 = new QGraphicsPixmapItem();
        p1->setPixmap(QPixmap(":/Images/kingb.png"));
        p1->setPos(920,170);
        addToScene(p1);
        listGrap.append(p1);

    QGraphicsTextItem *titleText = new QGraphicsTextItem("Chess Pro");
    QFont titleFont("arial" , 50);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listGrap.append(titleText);

    Button * playButton = new Button("Play");
    int pxPos = width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 300;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    addToScene(playButton);
    listGrap.append(playButton);

    Button * quitButton = new Button("Quit");
    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 375;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    addToScene(quitButton);
    drawChessBoard();
    listGrap.append(quitButton);
}

void Game::removeAll(){
    QList<QGraphicsItem*> itemsList = gameScene->items();
    for(size_t i = 0, n = itemsList.size();i<n;i++) {
        if(itemsList[i]!=check)
          removeFromScene(itemsList[i]);
    }
}

