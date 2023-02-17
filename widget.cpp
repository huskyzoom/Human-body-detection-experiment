#include "widget.h"
#include "ui_widget.h"
#include <stdio.h>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    pirThread = new PirThread(this);
    connect(pirThread,SIGNAL(PirNumberChanged(int)),this,SLOT(onPirNumberChanged(int)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void Widget::onPirNumberChanged(int Number){
    if (Number ==1){
    	ui->textEdit->append("people");

    }
    else if(Number ==0){
	ui->textEdit->append("no people");
	}
}

void Widget::on_pushButton_clicked()
{
    pirThread->Stop = false;
    pirThread->start();
}

void Widget::on_pushButton_2_clicked()
{
    pirThread->Stop = true;
}
void Widget::on_pushButton_Close_clicked()
{
    this->close();
}

