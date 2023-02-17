#ifndef WIDGET_H
#define WIDGET_H
#include "pirthread.h"
#include <QWidget>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

    public:
        explicit Widget(QWidget *parent = 0);
        ~Widget();
        PirThread *pirThread;

    private:
        Ui::Widget *ui;
    	int m_nMouseClick_X_Coordinate;
    	int m_nMouseClick_Y_Coordinate;

    public slots:
        void onPirNumberChanged(int);

    private slots:
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
	void on_pushButton_Close_clicked();
    	void mousePressEvent(QMouseEvent *event);
    	void mouseMoveEvent(QMouseEvent *event);

};
#endif 
