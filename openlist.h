#ifndef OPENLIST_H
#define OPENLIST_H

#include <QMainWindow>
#include <QFile>
#include <QPushButton>

namespace Ui {
class openList;
}

class openList : public QMainWindow
{
    Q_OBJECT

public:
    explicit openList(QWidget *parent = 0);
    ~openList();
    QVector<QPushButton*> buttons;
    QVector<QString> comands_;
    QVector<QString> names_;

private slots:
 void handleButton();

private:
    Ui::openList *ui;
};

#endif // OPENLIST_H
