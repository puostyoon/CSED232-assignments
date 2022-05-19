#include "mainwindow.h"
#include <QApplication>
#include<QGraphicsScene>
#include"Player.h"
#include"Score.h"
#include"Timer.h"
#include<QGraphicsView>
#include<QTimer>
#include<QDebug>

Timer* Ctimer;
Score* score; //make health, score global variable so that can be accessed from anywhere.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void game(){
    //scene생성
    QGraphicsScene *scene=new QGraphicsScene();
    //player 생성
    Player* player=new Player();
    player->setRect(0,0,30,30);
    scene->addItem(player);
    //player의 색 설정
    QBrush brush(Qt::green);
    QPen pen;
    player->setCircle(scene->addEllipse(player->x(),player->y(),30,30,pen,brush));

    //create the score, Ctimer
    score=new Score();
    scene->addItem(score);
    Ctimer=new Timer();
    Ctimer->setPos(Ctimer->x(),Ctimer->y()+25);
    scene->addItem(Ctimer);
    //timer의 숫자가 점점 줄어듦
    QTimer* timer2=new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),Ctimer,SLOT(decrease()));
    timer2->start(10);

    //시간이 다 될때
    QTimer* timer3=new QTimer();
    QObject::connect(timer3,SIGNAL(timeout()),Ctimer,SLOT(TimeOver()));
    timer3->start(30000);

    //item focus설정
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView* view=new QGraphicsView(scene);
    //창 이름을 assignment5로 바꿈
    view->setWindowTitle("Assignment5");

    //스크롤 못하게 해서 크기 일정하게 유지
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //화면 보여줌 및 화면 크기 설정
    view->show();
    view->setFixedSize(800,800);
    scene->setSceneRect(0,0,800,800);

    //플레이어 초기 위치 설정(플레이어 색을 나타내는 오브젝트의 위치도 함께 설정함)
    player->setPos(view->width()/2-15,view->height()-player->rect().height());
    player->getCircle()->setPos(player->x(),player->y());

    //Spawn Grades
    QTimer* timer=new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(500);

}

void GameOver()
{
    //w.show();
}
