#include <boost/log/trivial.hpp>
#include "ca.h"

namespace {
    const std::string default_ca = "default_ca";
} 

CASettings::CASettings(CONF* conf)
{
    auto casect_values = NCONF_get_section(conf, "ca");
    if (sk_CONF_VALUE_num(casect_values) == 0) {
        BOOST_LOG_TRIVIAL(trace) << "No ca section";
        return;
    }

    auto keys = ConfHelper::to_map(casect_values);

    if (!keys.count("default_ca")) {
        BOOST_LOG_TRIVIAL(trace) << "No default_ca";
        return;
    }

    // Find default_ca section naming the CA section
    ca_section_name = keys["default_ca"];
    BOOST_LOG_TRIVIAL(debug) << "CA section named: \"" << ca_section_name << "\"";

    values = ConfHelper::to_map(NCONF_get_section(conf, ca_section_name.c_str()));

}

Menu::Item CASettings::createMenu(CASettings& settings) {
    Menu mnu("CA settings");
    return {"CA", mnu};
}
