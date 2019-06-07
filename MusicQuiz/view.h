#ifndef VIEW_H
#define VIEW_H

//#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "musicquiz.h"
#include <QDebug>


class View
{
public:
    View();
    void PrintTest(Ui::MainWindow *ui);

    void StartWindow(Ui::MainWindow *ui);
    void PlayWindow(Ui::MainWindow *ui);
    void StopWindow(Ui::MainWindow *ui);
    void ReplayWindow(Ui::MainWindow *ui);
    void ResultWindow(Ui::MainWindow *ui, MusicQuiz *mquiz);

    void showCurrentLevel(Ui::MainWindow *ui, MusicQuiz *mquiz);

    void HideAll(Ui::MainWindow *ui);
    void HideButtonByName(Ui::MainWindow *ui, QString nameOfButton);

};

#endif // VIEW_H
