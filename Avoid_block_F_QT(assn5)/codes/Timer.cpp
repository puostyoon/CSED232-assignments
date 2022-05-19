#include"Timer.h"
#include"Score.h"
#include<QFont>
#include<QDebug>
#include<QMessageBox>

extern Score* score;

Timer::Timer(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    time=30;

    //draw the text
    setPlainText(QString("Time: ")+QString::number(time));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Timer::decrease(){
    time=time-0.01;
    setPlainText(QString("Time: ")+QString::number(time));

}

int Timer::TimeOver()
{
    //시간 종료되서 게임 끝날 때
    qDebug()<<"endgame";
    scene()->clear();
    //메시지 박스 생성
    QMessageBox messagebox;
    messagebox.setWindowTitle("End");
    messagebox.setText("Score: "+QString::number(score->getScore()));
    messagebox.setStandardButtons(QMessageBox::Ok);
    messagebox.setDefaultButton(QMessageBox::Ok);
    //ok를 눌릴 경우
    if ( messagebox.exec() == QMessageBox::Ok )
       {
           exit(100);
       }

    else
        return 0;

}

int Timer::getTime(){
    return time;
}
