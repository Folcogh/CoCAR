#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ThreadVisionControl.hpp"
#include <QEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    bool event(QEvent* event) override;

  private:
    Ui::MainWindow*      ui;
    QEvent*              StartEvent;
    ThreadVisionControl* ThreadVC;
};
#endif // MAINWINDOW_HPP
