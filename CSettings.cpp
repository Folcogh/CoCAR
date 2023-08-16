#include "CSettings.hpp"
#include "Global.hpp"

//
// Singleton stuff
//

CSettings* CSettings::csettings = nullptr;

CSettings* CSettings::instance()
{
    if (csettings == nullptr) {
        csettings = new CSettings;
    }
    return csettings;
}

void CSettings::release()
{
    if (csettings != nullptr) {
        delete csettings;
        csettings = nullptr;
    }
}

// </>

CSettings::CSettings()
    : QSettings(ORGANISATION_NAME, APPLICATION_NAME)
{
    // Perform the initialization of all the keys here
    // to have them in only one location

    // VC runtime location
    value(SETTING_VC_RUNTIME_LOCATION, DEFAULT_VC_RUNTIME_LOCATION);

    // VC autostart at boot
    value(SETTING_VC_AUTOSTART, DEFAULT_VC_AUTOSTART);
}
