#pragma once

#include <istream>
#include <string>
#include <vector>

#include <openssl/conf.h>
#include "ca.h"

struct Settings {
    Settings(CONF* conf);

    CASettings ca;

};
