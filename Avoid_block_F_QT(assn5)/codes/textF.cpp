#include"TextF.h"
#include<QFont>

TextF::TextF(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //draw the text
    setPlainText(QString("F"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

