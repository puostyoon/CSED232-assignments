#ifndef END_H
#define END_H

#include <QDialog>

namespace Ui {
class End;
}

class End : public QDialog
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::End *ui;
};

#endif // END_H
