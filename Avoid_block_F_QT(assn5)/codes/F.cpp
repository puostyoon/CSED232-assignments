#include"F.h"
#include"Player.h"
#include"end.h"
#include"Score.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<QDebug>
#include<stdlib.h>
#include<QFont>
#include<QMessageBox>
#include<windows.h>

void GameOver();
extern Score* score;

F::F()
{

    //맨 처음 f 생성 시 초기 위치 설정
    int random_number=rand()%(800-40);
    setPos(random_number,0);

    //상자 만들기
    setRect(0,0,40,40);

    //F라는 문자를 쓴다
    text=new TextF();
    text->setPos(this->x()+10,this->y()+7);

    //이동
    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);

}

TextF *F::getText()
{
    return text;
}

void F::setBox(QGraphicsRectItem* arg)
{
    box=arg;
}

void F::move(){
    //if f collides with player, end game, 그리고 화면을 claear하고 메시지화면도 띄움
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Player)){
            scene()->clear();
            QMessageBox messagebox;
            messagebox.setWindowTitle("End");
            messagebox.setText("Game Over");
            messagebox.setInformativeText("Score: "+QString::number(score->getScore()));
            messagebox.setStandardButtons(QMessageBox::Ok);
            messagebox.setDefaultButton(QMessageBox::Ok);
            //ok를 눌릴 경우
            if ( messagebox.exec() == QMessageBox::Ok )
               {
                   exit(100);
               }

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
QGraphicsRectItem* F::getBox(){
    return box;
}
