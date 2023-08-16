#ifndef CSETTINGS_HPP
#define CSETTINGS_HPP

#include <QSettings>

#define SETTING_VC_RUNTIME_LOCATION "VC_RuntimeLocation"
#define DEFAULT_VC_RUNTIME_LOCATION "C:/blabla/runtime.exe"

#define SETTING_VC_AUTOSTART "VC_Autostart"
#define DEFAULT_VC_AUTOSTART true

class CSettings : public QSettings
{
    // Singleton stuff

  public:
    static CSettings* instance();
    static void       release();

  private:
    static CSettings* csettings;
    CSettings();
    ~CSettings();

    // </>

  public:
};

#endif // CSETTINGS_HPP
