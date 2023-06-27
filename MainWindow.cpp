#include "MainWindow.hpp"
#include <QCoreApplication>
#include "./ui_MainWindow.h"
#include "Global.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // To ensure that VC starts only when the main window is alive, post an event to the event loop of this window.
    // When this event is handled (which means: the main window is alive), the thread which handles VC starts
    this->StartEvent = new QEvent(EVENT_MAIN_WINDOW_RUNNING);
    QCoreApplication::postEvent(this, this->StartEvent);
}

MainWindow::~MainWindow()
{
    delete ThreadVC;
    delete StartEvent;
    delete ui;
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == EVENT_MAIN_WINDOW_RUNNING) {
        this->ThreadVC = new ThreadVisionControl(this);
        this->ThreadVC->start();
        return true;
    }

    else {
        return MainWindow::event(event);
    }
}
