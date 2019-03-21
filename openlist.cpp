#include "openlist.h"
#include "ui_openlist.h"
#include <windows.h>
#include <QDebug>
#include <cstdlib>
#include <iostream>

openList::openList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::openList)
{
    ui->setupUi(this);
    QFile file("D:/setting.txt");
    QString str;
    QString name;
    QString comand;
    QPushButton* lbut;
//    QPushButton lButton(ui->verticalLayout);
    int firstSpace;
    int secondSpace;
    if(file.open(QIODevice::ReadOnly)) {
        for (str = ""+file.readLine(); str!="END"; str = ""+file.readLine())
        {

            firstSpace=str.indexOf(" ",0);
            name = str.mid(0,firstSpace);
            firstSpace=str.indexOf("$",0)+1;
            secondSpace=str.indexOf("$",firstSpace+1);
            comand = str.mid(firstSpace,secondSpace-firstSpace);
            names_.append(name);
            comands_.append(comand);
            lbut = new QPushButton(name);
            ui->verticalLayout->addWidget(lbut);
            connect(lbut, SIGNAL (clicked()), this, SLOT (handleButton()));
        }
        file.close();
    }

}
char* rus(const char* text)
{
    char *buffRus=new char[strlen(text)];
    CharToOemA(text, buffRus);
    return buffRus;
}
void openList::handleButton() {
    QPushButton* lbut = static_cast<QPushButton*>(sender());
    for(int i=0; i<names_.length();i++) {
        if(lbut->text()==names_[i]) {
            char * res = rus(comands_[i].toLocal8Bit().data());
            std::cout<<res<<std::endl;
            std::cout<<comands_[i].toLocal8Bit().data()<<std::endl;
            std::system(comands_[i].toLocal8Bit().data());
        }
    }

}
openList::~openList()
{
    delete ui;
}
