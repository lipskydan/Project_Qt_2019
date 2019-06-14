#include "musicquiz.h"

MusicQuiz::MusicQuiz()
{
    qsrand(time(NULL));
    melody = nullptr;
    QuantityOFSongs = 5;
    CountLevel = 1;
    CountGood = 0;
    CountBad = 0;

    UsedNumber = false;
    FirstTime = true;

    NumberOfPossibleAnswer = "0";
    NumberOfTrueAnswer = "0";
}

void MusicQuiz::CleanInfo(){
    CountLevel = 1;
    CountGood = 0;
    CountBad = 0;
    usedNumbers.clear();
    //ui->lineTrueAnswer->clear();
}

void MusicQuiz::Stop() {
    if (melody){
        melody->stop();
    }

    FirstTime = true;
}

bool MusicQuiz::isFirstTime() {
    return FirstTime;
}

void MusicQuiz::setFirstTime(bool firstTime) {
    FirstTime = firstTime;
}

void MusicQuiz::DeleteMelody() {
    if (melody != nullptr){
        melody->stop();
        delete melody;
    }
}

void MusicQuiz::PlayRandomSong() {
    QString sound_name = "/Users/danial/Documents/GitHub/Project_Qt_2019/MusicQuiz/";

    //Users/danial/Documents/GitHub/Project_Qt_2019/MusicQuiz/musicquiz.cpp

    int RandomNumber = -1;

    do {
        RandomNumber = qrand() % QuantityOFSongs;
    } while(WasUsed(RandomNumber) == true);

    usedNumbers.push_back(RandomNumber);

    NumberOfTrueAnswer = QString::number(RandomNumber);

    if(RandomNumber == 0){
        sound_name += "01 Any Kind of Guy.wav";
    }else if(RandomNumber == 1){
        sound_name += "16 I Know.wav";
    }else if(RandomNumber == 2){
        sound_name += "11 Bohemian Rhapsody.wav";
    }else if(RandomNumber == 3){
        sound_name += "Te Amo.wav";
    }else {
        sound_name += "Diamonds.wav";
    }

    melody = new QSound(sound_name);
    melody->play();
}

QString MusicQuiz::getNumberOfPossibleAnswer() {
    return NumberOfPossibleAnswer;
}
void MusicQuiz::setNumberOfPossibleAnswer(const QString &&num) {
    NumberOfPossibleAnswer = num;
}

QString MusicQuiz::getNNumberOfTrueAnswer() {
    return NumberOfTrueAnswer;
}
void MusicQuiz::setNumberOfTrueAnswer(const QString &&num) {
    NumberOfTrueAnswer = num;
}

QString MusicQuiz::getResultMassage(){
    return ResultMassage;
}

void MusicQuiz::setResultMassage(const QString &&text){
    ResultMassage += text;
}

QString MusicQuiz::getTmpResultMassage(){
    return TmpResultMassage;
}

void MusicQuiz::setTmpResultMassage(const QString &&text){
    TmpResultMassage += text;
}

void MusicQuiz::cleanResultMassage(){
    ResultMassage = " ";
    TmpResultMassage = " ";
}

void MusicQuiz::saveResult(){
    QTime time = QTime::currentTime();
    timeForNameOfFile = time.toString("hh:mm:ss");
    QFile file("/Users/danial/Desktop/result_" + timeForNameOfFile + ".txt");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << ResultForSave;
    file.close();

    qDebug() << "File created \n";
}

void MusicQuiz::CheckAnswer() {
    TmpResultMassage += "Answer for question " + QString::number(CountLevel) + " was ";
    if (NumberOfPossibleAnswer == NumberOfTrueAnswer){
         TmpResultMassage += "correct \n";
         CountGood++;
    } else {
        TmpResultMassage += "wrong \n";
        CountBad++;
    }
    melody->stop();
//    qDebug() << "1";
}

int MusicQuiz::getQuantityOFSongs() {
    return QuantityOFSongs;
}

int MusicQuiz::getCountLevel() {
    return CountLevel;
}

void MusicQuiz::setCountLevel(int countLevel) {
    CountLevel = countLevel;
}

int MusicQuiz::getCountGood(){
    return CountGood;
}

void MusicQuiz::setCountGood(int count){
    CountGood = count;
}

int MusicQuiz::getCountBad(){
    return CountBad;
}

void MusicQuiz::setCountBad(int count){
    CountBad = count;
}

bool MusicQuiz::WasUsed(int RandomNumber){
    return std::find(usedNumbers.begin(), usedNumbers.end(), RandomNumber) != usedNumbers.end();
}

