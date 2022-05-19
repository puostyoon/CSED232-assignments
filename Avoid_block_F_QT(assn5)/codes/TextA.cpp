#include"TextA.h"
#include<QFont>

TextA::TextA(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //draw the text
    setPlainText(QString("A"));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}
