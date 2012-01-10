#include <iostream>
#include <string>

namespace http {
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
            
            int protocol_end = uri_string.find("://") + 3;
            protocol = uri_string.substr (0, protocol_end);


            return 0;
        }
    };
}
