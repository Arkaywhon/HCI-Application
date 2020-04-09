#include "logger.h"

using namespace std::chrono;

Logger::Logger()
{

    succCount = 0, failCount = 0;

    // initialize log file
    QString curDir = QCoreApplication::applicationDirPath();
    // create file-reference to "outputLog.txt" file
    // create the file if it doesn't already exist
    file = new QFile(curDir + "/outputLog.txt");
    // check if the file was created successfully and exists
    if(!file->exists()) qDebug() << file->fileName() << " not found";

    // open the file with specfied flags (reading, writing, and text processing)
    if(file->open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text)){

        // create txtStream used to write to file
        QTextStream txtStream(file);
        // start writing from the end of the file
        file->seek(file->size());

        qDebug() << "Check " << curDir << " for the outputLog.txt file";
        qDebug() << "Writing to file";

        txtStream << "=== New Framework Bootup Detected ===\n";
    }else{
        qDebug() << "Could not write to file";
    }
}

Logger::~Logger(){
    file->close();
}

// function sets the log's startTime for an event
void Logger::beginTimeLog(){
    startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
}

// function caculates how long an event took based on the startTime and the currentTime
// returns time in seconds reprsented as a double
double Logger::endTimeLog(){

    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    milliseconds timeTaken = currentTime - startTime;
    return timeTaken.count()/1000.0; // return time taken in seconds
}

// function handles the writing of the results to the log file
void Logger::pushData(int r, double t){

    file->seek(file->size());

    QTextStream ts(file);

    if(r)
        ts << "#S, ";
    else
        ts << "#F, ";
    ts << "Time Taken: " << QString::number(t) << "\n";
}

// function that is called if an account entry was succesful
void Logger::logSuccess(){
    pushData(1, endTimeLog());
    succCount += 1;
}

// function that is called if an account entry was unsuccesful
void Logger::logFailure(){
    pushData(0, endTimeLog());
    failCount += 1;
}
