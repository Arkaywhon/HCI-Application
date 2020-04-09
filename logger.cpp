#include "logger.h"

using namespace std::chrono;

Logger::Logger()
{

    succCount = 0, failCount = 0;

    QString curDir = QCoreApplication::applicationDirPath();
    file = new QFile(curDir + "/outputLog.txt");
    if(!file->exists()) qDebug() << file->fileName() << " not found";

    if(file->open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text)){

        QTextStream txtStream(file);
        file->seek(file->size()); // start writing from the end of the file

        qDebug() << "Check " << curDir << " for the outputLog.txt file";
        qDebug() << "Writing to file";

        txtStream << "=== New Framework Bootup Detected ===";
    }else{
        qDebug() << "Could not write to file";
    }
}

Logger::~Logger(){
    file->close();
}

void Logger::beginTimeLog(){
    startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
}

double Logger::endTimeLog(){

    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    milliseconds timeTaken = currentTime - startTime;
    return timeTaken.count()/1000.0; // return time taken in seconds
}

void Logger::pushData(int r, double t){

    file->seek(file->size());

    QTextStream ts(file);

    if(r)
        ts << "#S, ";
    else
        ts << "#F, ";
    ts << "Time Taken: " << QString::number(t) << "\n";
}

void Logger::logSuccess(){
    pushData(1, endTimeLog());
    succCount += 1;
}

void Logger::logFailure(){
    pushData(0, endTimeLog());
    failCount += 1;
}
