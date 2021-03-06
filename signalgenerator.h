#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>
#include <QTimer>
#include <QtMath>

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    SignalGenerator(QObject *parent = 0);
    SignalGenerator(QObject *parent, double* generatedSignalPointer);
    ~SignalGenerator();
    void setTimeBase(double time);
    void setParameters(double amplitude, double constant, double stdDeviation);
    void setGeneratedValuePointer(double* genVal);
//    QTimer* getTimer();
private:

    double amplitude;
    double constant;
    double interval;
    double timeBase;
    double stdDeviation;
protected:
    QTimer timer;
    double *currentValuePtr;
    int currentTime;

public slots:
    void onTimerTimeout();
};

#endif // SIGNALGENERATOR_H
