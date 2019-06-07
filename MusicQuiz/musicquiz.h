#ifndef MUSICQUIZ_H
#define MUSICQUIZ_H
#include <QVector>
#include <QtAlgorithms>
#include <QSound>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QStandardPaths>
#include <QTime>
#include <QString>

//#include "mainwindow.h"

class MusicQuiz {
public:
    MusicQuiz();
    void Stop();
    bool isFirstTime();
    void setFirstTime(bool firstTime);
    bool WasUsed(int RandomNumber);
    void DeleteMelody();
    void CleanInfo();
    QString getNumberOfPossibleAnswer();
    void setNumberOfPossibleAnswer(const QString &&num);

    QString getNNumberOfTrueAnswer();
    void setNumberOfTrueAnswer(const QString &&num);

    void CheckAnswer();
    void PlayRandomSong();

    int getQuantityOFSongs();
    int getCountLevel();
    void setCountLevel(int countLevel);

    int getCountGood();
    void setCountGood(int count);

    int getCountBad();
    void setCountBad(int count);

    QString getResultMassage();
    void setResultMassage(const QString &&text);


    QString getTmpResultMassage();
    void setTmpResultMassage(const QString &&text);

    void cleanResultMassage();

    void saveResult();

private:
    int QuantityOFSongs;
    int CountLevel;
    int CountGood;
    int CountBad;

    bool UsedNumber;
    bool FirstTime;

    QVector<int> usedNumbers;

    QString NumberOfPossibleAnswer;
    QSound* melody;
    QString NumberOfTrueAnswer;

    QString TmpResultMassage;
    QString ResultMassage;

public:
    QString ResultForSave;
    QString timeForNameOfFile;

};

#endif // MUSICQUIZ_H
