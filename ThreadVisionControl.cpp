#include "ThreadVisionControl.hpp"

ThreadVisionControl::ThreadVisionControl(QObject* parent)
    : QThread(parent)
{}

ThreadVisionControl::run()
{
    exec();
}
