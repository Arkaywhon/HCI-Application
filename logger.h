#ifndef LOGGER_H
#define LOGGER_H

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QCoreApplication>
#include <chrono>

class Logger
{
public:
    Logger();
    ~Logger();
    void beginTimeLog();
    double endTimeLog();
    void logSuccess();
    void logFailure();

private:
    int succCount, failCount;
    std::chrono::milliseconds startTime;
    QFile *file;

    void pushData(int, double);

};

#endif // LOGGER_H
