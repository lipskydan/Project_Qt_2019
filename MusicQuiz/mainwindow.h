#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QSound>
#include <QString>
#include <QSpinBox>
#include <QDebug>
#include <QVector>
#include <QtAlgorithms>

#include "musicquiz.h"
#include "view.h"


#include <QMainWindow>


namespace Ui {
class MainWindow;
class MusicQuiz;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
    void Check();
    void OpenScoreWindow();

private slots:
    void on_pushButtonPlay_clicked();
    void on_pushButtonStop_clicked();
    void on_pushButtonReplay_clicked();

    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();

    void on_pushButtonSaveScore_clicked();




private:
    Ui::MainWindow *ui;
    MusicQuiz *mquiz;
    View view;
};


#endif // MAINWINDOW_H
