#ifndef TIMER_H
#define TIMER_H

#include <QGraphicsTextItem>
#include<QObject>
#include<QGraphicsScene>

class Timer: public QGraphicsTextItem{
    Q_OBJECT
public:
    Timer(QGraphicsItem*parent=0);
    ~Timer(){}
    int getTime(); //getter
public slots:
    void decrease(); //매 일정한 시간마다 time이 줄어듦, timer을 줄어들게하는 함수
    int TimeOver(); //time이 0이 되었을 때 메시지 박스를 띄우고 화면을 clear하는 등의 처리를 함
private:
    double time; //현재 time
};

#endif // TIMER_H
