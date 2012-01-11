#include <iostream>
#include <string>


using namespace std;

bool has_protocol(std::string uri) {
    return uri.find("://") < std::string::npos;
}

bool has_path(std::string uri) {
    return uri.find("/") < std::string::npos;
}


string * parse_http_uri(string in) {
    string * ret = new string[3];
    int last_spot = 0;
    int length = 0;
    
    if (has_protocol(in)) {
        length = in.find("://") + 3;
        ret[0] = in.substr (last_spot, length);
        last_spot += length;
    }

    if (has_path(in)) {
        length = in.find("/", last_spot) - last_spot;
        ret[1] = in.substr (last_spot, length);
        last_spot += length;
        ret[2] = in.substr (last_spot, in.length() - last_spot);
    } else {
        ret[1] = in.substr (last_spot, in.length() - last_spot);
    }

    return ret;
}

//namespace http {
    //bool has_protocol(std::string uri) {
        //return uri.find("://") < std::string::npos;
    //}

    //struct uri {
        //std::string protocol;
        //std::string authentication;
        //std::string host;
        //int port;
        //std::string path;

        //bool parse_uri(std::string uri_string) {
            ////*******************************************************************
            //// Purpose: Split the uri atom into its consituent quarks
            //// Input: 
            //// Output: 
            ////*******************************************************************

            //int last_spot = 0;
            //int length = 0;

            //if (has_protocol(uri_string)) {
                //length = uri_string.find("://") + 3;
                //protocol = uri_string.substr (last_spot, length);
            //}

            //length = uri_string.find(":", last_spot) - last_spot;
            //host = uri_string.substr (last_spot, length);
            //last_spot = last_spot + length;

            //return 0;
        //}
    //};
//}
