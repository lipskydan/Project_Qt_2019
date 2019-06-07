#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mquiz(new MusicQuiz)
{
    ui->setupUi(this);

    view.PrintTest(ui);
    view.StartWindow(ui);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStop_clicked()
{
    mquiz->Stop();
    mquiz->CleanInfo();
//    view.CleanResult(ui, mquiz);

    view.StopWindow(ui);
}

void MainWindow::on_pushButtonReplay_clicked()
{
    mquiz->CleanInfo();

    mquiz->setResultMassage(" ");

    view.ReplayWindow(ui);

}

void MainWindow::on_pushButtonPlay_clicked()
{
    if (mquiz->isFirstTime()){
        view.PlayWindow(ui);
        ui->labelLevel->setText(QString::number(mquiz->getCountLevel()) + "/" + QString::number(mquiz->getQuantityOFSongs()));
        mquiz->setFirstTime(false);
    }

    mquiz->DeleteMelody();
    mquiz->PlayRandomSong();
}

void MainWindow::Check(){
    mquiz->CheckAnswer();

    view.showCurrentLevel(ui, mquiz);

    mquiz->setCountLevel(mquiz->getCountLevel() + 1);

    if (mquiz->getCountLevel() <= mquiz->getQuantityOFSongs()) {
        MainWindow::on_pushButtonPlay_clicked();
    }else{
        view.HideAll(ui);
        view.ResultWindow(ui, mquiz);
    }
}

void MainWindow::on_pushButton1_clicked()
{
    mquiz->setNumberOfPossibleAnswer("0");

    view.HideButtonByName(ui, "1");

    Check();
}

void MainWindow::on_pushButton2_clicked()
{
   mquiz->setNumberOfPossibleAnswer("1");
   view.HideButtonByName(ui, "2");
   Check();
}

void MainWindow::on_pushButton3_clicked()
{
   mquiz->setNumberOfPossibleAnswer("2");
   view.HideButtonByName(ui, "3");
   Check();
}

void MainWindow::on_pushButton4_clicked()
{
    mquiz->setNumberOfPossibleAnswer("3");
    view.HideButtonByName(ui, "4");
    Check();
}

void MainWindow::on_pushButton5_clicked()
{
    mquiz->setNumberOfPossibleAnswer("4");
    view.HideButtonByName(ui, "5");
    Check();
}

void MainWindow::on_pushButton6_clicked()
{
    mquiz->setNumberOfPossibleAnswer("5");
    view.HideButtonByName(ui, "6");
    Check();
}

void MainWindow::on_pushButtonSaveScore_clicked()
{
   mquiz->saveResult();
}

