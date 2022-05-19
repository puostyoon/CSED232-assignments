#ifndef F_H
#define F_H
#include <QGraphicsTextItem>
#include<QPainter>
#include<QObject>
#include<QPaintDevice>
#include"TextF.h"
#include<QGraphicsScene>

class F:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    F();
    ~F(){}
    TextF* getText(); //getter함수
    void setBox(QGraphicsRectItem *); //setter함수
    QGraphicsRectItem* getBox(); //getter함수
public slots:
    void move(); //F의 움직임을 담당
private:
     TextF* text; //text오브젝트
     QGraphicsRectItem* box;//상자 테두리 오브젝트
};

#endif // F_H
