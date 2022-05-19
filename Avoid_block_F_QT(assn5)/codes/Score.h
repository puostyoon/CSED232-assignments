#ifndef SCORE_H
#define SCORE_H

#include<QGraphicsTextItem>

class Score:public QGraphicsTextItem{
public:
    Score(QGraphicsItem*parent=0);
    void increase(); //score 증가담당
    int getScore(); //getter
    ~Score(){}
private:
    int score; //현재 스코어
};

#endif // SCORE_H
