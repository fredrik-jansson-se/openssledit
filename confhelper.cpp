#include <boost/log/trivial.hpp>

#include "confhelper.h"

namespace ConfHelper {
    kv_t to_map(STACK_OF(CONF_VALUE)* cv) {
        kv_t res;

        auto size = sk_CONF_VALUE_num(cv);

        for (int i = 0; i < size; ++i) {
            auto val = sk_CONF_VALUE_value(cv, i);
            res.emplace(val->name, val->value);
            BOOST_LOG_TRIVIAL(trace) << val->name << " = " << val->value;
        } 

        return res;
    }
}

