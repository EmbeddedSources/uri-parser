#include <iostream>
#include <string>

namespace http {
    bool has_protocol(std::string uri) {
        return uri.find("://") < std::string::npos;
    }

    struct uri {
        std::string protocol;
        std::string authentication;
        std::string host;
        int port;
        std::string path;

        bool parse_uri(std::string uri_string) {
            //*******************************************************************
            // Purpose: Split the uri atom into its consituent quarks
            // Input: 
            // Output: 
            //*******************************************************************

            int last_spot = 0;
            int length = 0;

            if (has_protocol(uri_string)) {
                length = uri_string.find("://") + 3;
                protocol = uri_string.substr (last_spot, length);
            }

            length = uri_string.find(":", last_spot) - last_spot;
            host = uri_string.substr (last_spot, length);
            last_spot = last_spot + length;

            return 0;
        }
    };
}
