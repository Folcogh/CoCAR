#ifndef THREADVISIONCONTROL_HPP
#define THREADVISIONCONTROL_HPP

#include <QProcess>
#include <QThread>

// Enumeration describing the different states of the VC executable
typedef enum {
    VC_STATE_STOPPED,
    VC_STATE_STARTING,
    VC_STATE_RUNNING,
    VC_STATE_STOPPING
} VC_STATE;

// This class hosts and manage the VC5 process.
// It runs in its own thread, child of the MainWindow's one.
// It is designed to communicate only with queued signals/slots,
// to avoid the multi-thread problems when calling external functions

class ThreadVisionControl: public QThread
{
  public:
    ThreadVisionControl(QObject* parent);
    ~ThreadVisionControl();
    void run() override;

  signals:
    void VCprocessStarting();
    void VCprocessRunning();
    void VCprocessStopped();
    // TODO intercepter QProcess::errorOccured


  private:
    VC_STATE  VCstate;
    QProcess* VCprocess;
    bool      FirstRun;
};

#endif // THREADVISIONCONTROL_HPP
