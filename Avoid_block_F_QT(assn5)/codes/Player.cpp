#include"Player.h"
#include"F.h"
#include"A.h"
#include<QGraphicsScene>
#include<QDebug>
#include<QKeyEvent>
#include<stdlib.h>

void Player::keyPressEvent(QKeyEvent *event)
{
    //플레이어가 입력한 키에 따라 플레이어의 위치를 옮김
   if(event->key()==Qt::Key_Left){
       if(pos().x()>0)
       setPos(x()-10,y());
       getCircle()->setPos(x(),y());
   }
   else if(event->key()==Qt::Key_Right){
       if(pos().x()+30<800)
       setPos(x()+10,y());
       getCircle()->setPos(x(),y());
   }
}

QGraphicsEllipseItem *Player::getCircle()
{
    return circle;
}

void Player::setCircle(QGraphicsEllipseItem * arg)
{
    circle=arg;
}

void Player::spawn()
{
    //random으로 F와 A생성
     int random_number=rand()%(2);
    if(random_number==0) //F생성
     {
        F* f=new F();
        scene()->addItem(f);
        //글자생성
        scene()->addItem(f->getText());
        //빨간상자 생성
        QPen redPen(Qt::red);
        redPen.setWidth(6);
         QPainter painter;
         f->setBox(scene()->addRect(f->x(),f->y(),40,40,redPen));
    }
    else //A생성
    {
        A* a=new A();
        scene()->addItem(a);
        //글자생성
        scene()->addItem(a->getText());
        //빨간상자 생성
        QPen redPen(Qt::blue);
        redPen.setWidth(6);
        QPainter painter;
        a->setBox(scene()->addRect(a->x(),a->y(),40,40,redPen));
    }

}
