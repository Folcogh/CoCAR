#ifndef THREADVISIONCONTROL_HPP
#define THREADVISIONCONTROL_HPP

#include <QThread>

// This class hosts and manage the VC5 process.
// It runs in its own thread, child of the MainWindow's one.
// It is designed to communicate only with queued signals/slots,
// to avoid the multi-thread problems when calling external functions

class ThreadVisionControl : public QThread
{
public:
    ThreadVisionControl(QObject* parent);
    void run() override;

private:
};

#endif // THREADVISIONCONTROL_HPP
