#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <openssl/conf.h>

namespace ConfHelper {
    using kv_t = std::unordered_map<std::string, std::string>;
    kv_t to_map(STACK_OF(CONF_VALUE)*);
}
