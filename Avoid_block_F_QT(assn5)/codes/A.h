#ifndef A_H
#define A_H

#include <QGraphicsTextItem>
#include<QPainter>
#include<QObject>
#include<QPaintDevice>
#include"TextA.h"

class A:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    A();
    TextA* getText(); //getter함수
    void setBox(QGraphicsRectItem *); //setter함수
    QGraphicsRectItem* getBox(); //getter함수
    ~A(){}
public slots:
    void move(); //A의 움직임을 담당
private:
     TextA* text; //text오브젝트
     QGraphicsRectItem* box;//상자 테두리 오브젝트
};

#endif // A_H
