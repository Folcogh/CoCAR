#include "MainWindow.hpp"
#include "./ui_MainWindow.h"
#include "CSettings.hpp"
#include "Global.hpp"
#include <QCoreApplication>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // To ensure that VC starts only when the main window is alive, post an event to the event loop of this window.
    // When this event is handled (which means: the main window is alive), the thread which handles VC starts
    this->StartEvent = new QEvent(EVENT_MAIN_WINDOW_RUNNING);
    QCoreApplication::postEvent(this, this->StartEvent);

    // Window title
    setWindowTitle(QString("%1 - by %2").arg(APPLICATION_NAME, TP_SHORT_NAME));
}

MainWindow::~MainWindow()
{
    delete this->ThreadVC;
    delete this->StartEvent;
    delete ui;
    CSettings::release();
}

bool MainWindow::event(QEvent* event)
{
    if (event->type() == EVENT_MAIN_WINDOW_RUNNING) {
        this->ThreadVC = new ThreadVisionControl(this);
        this->ThreadVC->start();
        return true;
    }

    else {
        return QMainWindow::event(event);
    }
}
