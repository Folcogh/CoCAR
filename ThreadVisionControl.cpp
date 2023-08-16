#include "ThreadVisionControl.hpp"
#include "CSettings.hpp"

ThreadVisionControl::ThreadVisionControl(QObject* parent)
    : QThread(parent)
    , VCstate(VC_STATE_STOPPED)
    , VCprocess(new QProcess)
    , FirstRun(true)
{
    // Set the VC process
    QString ProgramName = CSettings::instance()->value(SETTING_VC_RUNTIME_LOCATION).toString();
    VCprocess->setProgram(ProgramName);
}

ThreadVisionControl::~ThreadVisionControl()
{
    // Stop and delete the VC process
    this->VCprocess->kill();
    delete this->VCprocess;
}

void ThreadVisionControl::run()
{
    // Special handling of the thread bootstrap
    if (this->FirstRun) {
        // Not the first run anymore
        this->FirstRun = false;

        // Autostart VC according to global settings
        if (CSettings::instance()->value(SETTING_VC_AUTOSTART).toBool()) {
            this->VCprocess->start();
        }
    }

    // Handle events
    exec();
}
