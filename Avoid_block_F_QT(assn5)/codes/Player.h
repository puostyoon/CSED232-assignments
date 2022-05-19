#ifndef PLAYER_H
#define PLAYER_H

#include<QGraphicsEllipseItem>
#include<QObject>

class Player:public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event); //키를 눌렀을 때에 대한 이벤트를 처리
    QGraphicsEllipseItem* getCircle(); //getter함수
    void setCircle(QGraphicsEllipseItem*); //setter
    Player(){circle=nullptr;}
    ~Player(){}
public slots:
    void spawn(); //특정한 시간 때 마다 무작위로 A,F를 생성하는 함수
private:
     QGraphicsEllipseItem* circle;//플레이어 테두리 테두리 오브젝트
};

#endif // PLAYER_H

