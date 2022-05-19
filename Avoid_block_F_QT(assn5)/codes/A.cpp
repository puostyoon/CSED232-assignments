#include"A.h"
#include"Player.h"
#include"end.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<QDebug>
#include<stdlib.h>
#include<QFont>
#include<QMessageBox>
#include"Score.h"

void GameOver();
extern Score* score;

A::A()
{

    //맨 처음 f 생성 시 초기 위치 설정
    int random_number=rand()%(800-40);
    setPos(random_number,0);

    //상자 만들기
    setRect(0,0,40,40);

    //F라는 문자를 쓴다
    text=new TextA();
    text->setPos(this->x()+10,this->y()+7);

    //이동

    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);


}

TextA *A::getText()
{
    return text;
}

void A::setBox(QGraphicsRectItem* arg)
{
    box=arg;
}

void A::move(){
    //A가 player와 충돌하면 A를 삭제시키고 score를 증가시킨다.
    QList<QGraphicsItem*>colliding_items=collidingItems();

    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Player)){

            score->increase();
            //remove 'a'
            scene()->removeItem(text);
            scene()->removeItem(box);
            scene()->removeItem(this);
           //delete 'a'
            delete box;
            delete text;
            delete this;
            return;

        }
    }

    //이동, 위치를 10씩 증가시킴
    setPos(x(),y()+10);
    text->setPos(text->x(),text->y()+10);
    box->setPos(box->x(),box->y()+10);
    //grade가 화면을 넘어가면 grade 삭제
    if(pos().y()>800){
        scene()->removeItem(text);
        delete text;
        scene()->removeItem(box);
        delete box;
        scene()->removeItem(this);
        delete this;
    }
}
QGraphicsRectItem* A::getBox(){
    return box;
}
