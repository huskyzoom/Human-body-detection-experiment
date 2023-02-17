#ifndef PIRTHREAD_H
#define PIRTHREAD_H

#include <QObject>
#include <QThread>
class PirThread : public QThread
{
    Q_OBJECT
    public:
    explicit PirThread(QObject* parent = 0);
    void run();
    bool Stop;
    signals:
        void PirNumberChanged(int);
    public slots:

};

#endif 
