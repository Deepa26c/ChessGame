#include "Board.h"
#include "ChessBox.h"
#include "Game.h"
#include "Queen.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"

extern Game *game;

Board::Board()
{
    setUpBlack();
    setUpWhite();
}

void Board::drawBoxes(int x, int y)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            ChessBox *box = new ChessBox();
            game->sq[i][j] = box;
            box->rowl = i;
            box->colL = j;
            box->setPos(x+100*j,y+100*i);
            if((i+j)%2 == 0)
                box->setOriginalColor(Qt::lightGray);
            else
                box->setOriginalColor(Qt::gray);
            game->addToScene(box);
        }
    }
}

void Board::addPiece(){
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            ChessBox *box = game->sq[i][j];
            if(i<2)
            {
                static int k;
                box->placePiece(black[k]);
                game->alivePiece.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i>5)
            {
                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);
                game->addToScene(white[h++]);
            }
        }
     }
}

void Board::setUpWhite()
{
    ChessPiece *piece;
    for(int i=0;i<8;i++){
        piece = new Pawn("WHITE");
        white.append(piece);
    }
    piece = new Rook("WHITE");
    white.append(piece);
    piece = new Knight("WHITE");
    white.append(piece);
    piece = new Bishop("WHITE");
    white.append(piece);
    piece = new Queen("WHITE");
    white.append(piece);
    piece = new King("WHITE");
    white.append(piece);
    piece = new Bishop("WHITE");
    white.append(piece);
    piece = new Knight("WHITE");
    white.append(piece);
    piece = new Rook("WHITE");
    white.append(piece);
}

void Board::setUpBlack()
{
    ChessPiece *piece;
    piece = new Rook("BLACK");
    black.append(piece);
    piece = new Knight("BLACK");
    black.append(piece);
    piece = new Bishop("BLACK");
    black.append(piece);
    piece = new Queen("BLACK");
    black.append(piece);
    piece = new King("BLACK");
    black.append(piece);
    piece = new Bishop("BLACK");
    black.append(piece);
    piece = new Knight("BLACK");
    black.append(piece);
    piece = new Rook("BLACK");
    black.append(piece);
    for(int i=0;i<8;i++){
        piece = new Pawn("BLACK");
        black.append(piece);
    }
}

void Board::reset()
{
    int k=0;
    int h=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            ChessBox *box = game->sq[i][j];
            box->setHasChessPiece(false);
            box->setChessPieceColor("NONE");
            box->currentPiece = NULL;
            if(i<2)
            {
                box->placePiece(black[k]);
                black[k]->setIsPlaced(true);
                black[k]->firstMove = true;
                game->alivePiece.append(black[k++]);
            }
            if(i>5)
            {
                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                white[h]->firstMove = true;
                game->alivePiece.append(white[h++]);
            }
        }
    }
}

