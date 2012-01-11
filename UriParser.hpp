#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

namespace http {
    struct uri {

    };

    string tail_slice(string &subject, string delimiter) {
        // Chops off the delimiter and everything that follows (destructively)
        // returns everything after the delimiter
        int delimiter_location = subject.find(delimiter);
        int delimiter_length = delimiter.length();
        string output = subject.substr(delimiter_location + delimiter_length, subject.length() - (delimiter_location + delimiter_length));
        subject = subject.substr(0, delimiter_location);
        return output;
    }

    string extract_protocol(string &in) {
        int length = in.find("://");
        string protocol = in.substr(0, length);
        in = in.substr(length + 3, in.length() - length + 3);
        return protocol;
    }

    string extract_userpass(string &in) {
        int length = in.find("@");
        string user = in.substr(0, length);
        in = in.substr(length + 1, in.length() - length + 1);
        return user;
    }

    int extract_port(string &hostport) {
        int colon_location = hostport.find(":");
        int port;
        string portstring = hostport.substr(colon_location + 1, hostport.length() - colon_location + 1);
        try {
           port  = atoi(portstring.c_str());
        }
        catch (std::exception e) {
           port = 80;
        }

        hostport = hostport.substr(0, colon_location);
        return port;
    }

    string extract_user(string &userpass) {
        int colon_location = userpass.find(":");
        string user = userpass.substr(0, colon_location);
        userpass = userpass.substr(colon_location + 1, userpass.length() - colon_location + 1);
        return user;
    }
    
    string extract_search(string &in) {
        return tail_slice(in, "?");
    }

    string extract_path(string &in) {
        return tail_slice(in, "/");
    }




}
