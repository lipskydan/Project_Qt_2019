#include "view.h"
#include "ui_mainwindow.h"



View::View()
{
    qDebug() << "View run";
}

void View::PrintTest(Ui::MainWindow *ui)
{
    ui->lineTrueAnswer->setText("This is a test View");
}

void View::HideAll(Ui::MainWindow *ui)
{
    if (ui->pushButton1->isVisible()) ui->pushButton1->hide();
    if (ui->pushButton2->isVisible()) ui->pushButton2->hide();
    if (ui->pushButton3->isVisible()) ui->pushButton3->hide();
    if (ui->pushButton4->isVisible()) ui->pushButton4->hide();
    if (ui->pushButton5->isVisible()) ui->pushButton5->hide();
    if (ui->pushButton6->isVisible()) ui->pushButton6->hide();

}

void View::StartWindow(Ui::MainWindow *ui)
{
    ui->pushButtonStop->hide();
    ui->pushButtonReplay->hide();
    ui->pushButtonSaveScore->hide();
    ui->pushButton1->hide();
    ui->pushButton2->hide();
    ui->pushButton3->hide();
    ui->pushButton4->hide();
    ui->pushButton5->hide();
    ui->pushButton6->hide();
    ui->labelResult->hide();
    ui->lineTrueAnswer->hide();
//    ui->labelLevel->hide();
}

void View::PlayWindow(Ui::MainWindow *ui)
{
    ui->pushButtonPlay->hide();
    ui->pushButtonStop->show();
    ui->pushButton1->show();
    ui->pushButton2->show();
    ui->pushButton3->show();
    ui->pushButton4->show();
    ui->pushButton5->show();
    ui->pushButton6->show();
}

void View::StopWindow(Ui::MainWindow *ui)
{
    ui->labelLevel->clear();
    ui->labelResult->clear();

    ui->pushButtonReplay->hide();
    ui->pushButton1->hide();
    ui->pushButton2->hide();
    ui->pushButton3->hide();
    ui->pushButton4->hide();
    ui->pushButton5->hide();
    ui->pushButton6->hide();
    ui->pushButtonStop->hide();

    ui->pushButtonPlay->show();
    ui->labelResult->hide();
    ui->pushButtonSaveScore->hide();
}

void View::ReplayWindow(Ui::MainWindow *ui)
{
    ui->labelResult->clear();
    if (ui->labelResult->isVisible()) ui->labelResult->hide();
    ui->labelLevel->clear();

    ui->pushButtonPlay->click();
    ui->pushButton1->show();
    ui->pushButton2->show();
    ui->pushButton3->show();
    ui->pushButton4->show();
    ui->pushButton5->show();
    ui->pushButton6->show();

    ui->pushButtonReplay->hide();
    ui->pushButtonSaveScore->hide();
}

void View::ResultWindow(Ui::MainWindow *ui, MusicQuiz *mquiz)
{
    ui->labelResult->show();
    ui->pushButtonReplay->show();
    ui->pushButtonSaveScore->show();

    mquiz->setResultMassage("Good is " + QString::number(mquiz->getCountGood()) + ", Bad is " + QString::number(mquiz->getCountBad()) + "\n");
    mquiz->setResultMassage(mquiz->getTmpResultMassage());

    ui->labelResult->setText("Put on \"Save\" to see a result");

    mquiz->ResultForSave = mquiz->getResultMassage();
    mquiz->cleanResultMassage();
}

void View::showCurrentLevel(Ui::MainWindow *ui, MusicQuiz *mquiz)
{
    if (mquiz->getCountLevel() > mquiz->getQuantityOFSongs()){
        ui->labelLevel->setText(QString::number(mquiz->getQuantityOFSongs()) + "/" + QString::number(mquiz->getQuantityOFSongs()));
    }else{
        ui->labelLevel->setText(QString::number(mquiz->getCountLevel()) + "/" + QString::number(mquiz->getQuantityOFSongs()));
    }
}


void View::HideButtonByName(Ui::MainWindow *ui, QString nameOfButton)
{
    if (nameOfButton == "1"){
         ui->pushButton1->hide();
    }else if(nameOfButton == "2"){
         ui->pushButton2->hide();
    }else if (nameOfButton == "3") {
         ui->pushButton3->hide();
    }else if (nameOfButton == "4") {
        ui->pushButton4->hide();
    }else if (nameOfButton == "5") {
         ui->pushButton5->hide();
    }else if (nameOfButton == "6") {
         ui->pushButton6->hide();
    }else{
        qDebug() << "Button????";
    }
}
























