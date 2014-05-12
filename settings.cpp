#include <boost/log/trivial.hpp>
#include <boost/algorithm/string/trim.hpp>
#include "settings.h"

Settings::Settings(CONF* conf)
: ca(conf) {
}

