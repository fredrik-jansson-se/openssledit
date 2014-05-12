#pragma once

#include <openssl/conf.h>

#include "confhelper.h"
#include "Menu.h"

struct CASettings {
    CASettings(CONF* conf);

    static Menu::Item createMenu(CASettings& settings);

private:
    std::string ca_section_name;
    ConfHelper::kv_t values;
};

