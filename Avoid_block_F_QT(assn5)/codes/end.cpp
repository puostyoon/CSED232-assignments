#include "end.h"
#include "ui_end.h"

End::End(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);
}

End::~End()
{
    delete ui;
}

void End::on_buttonBox_accepted()
{
    exit(100);
}

