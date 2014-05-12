#include <fstream>
#include <boost/log/trivial.hpp>

#include <openssl/conf.h>

#include "ca.h"
#include "menu.h"
#include "options.h"
#include "settings.h"

int main(int argc, const char* argv[]) {
    OPENSSL_load_builtin_modules();
    try {
        auto opt = Options::parse(argc, argv);

        auto config = std::unique_ptr<CONF, void(*)(CONF*)>(NCONF_new(nullptr), &NCONF_free);
        long errorline = -1;
        if (!NCONF_load(config.get(), opt.configFile.c_str(), &errorline)) {
            BOOST_LOG_TRIVIAL(error) << "Error in " << opt.configFile << " on line " << errorline << "\n";
            return 1;
        }

//        auto cfgFile = std::ifstream(opt.configFile);
//        Settings settings = Settings::parse(cfgFile);
        Settings settings(config.get());
//        parse(cfgFile);

        return 0;

        auto mnu = Menu("Main", 
                {
                CASettings::createMenu(settings.ca)
                });

        mnu();
    }
    catch (std::exception& e) {
        BOOST_LOG_TRIVIAL(fatal) << e.what();
    }
    return 0;
}
