#include "Bishop.h"
#include "Game.h"

extern Game *game;
Bishop::Bishop(QString team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Bishop::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Images/bishopw.png"));
    else
        setPixmap(QPixmap(":/Images/bishopb.png"));
}

void Bishop::moves(){
    location.clear();
       int row = this->getCurrentBox()->rowl;
       int col = this->getCurrentBox()->colL;
       QString team = this->getSide();
       
    
        //for upper left move
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

        //For upper right move

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

         //For downward right move

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

          //For downward left move

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
