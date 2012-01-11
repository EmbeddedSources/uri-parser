#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

namespace http {
    struct url {
        std::string protocol, user, password, host, path, search;
        int port;
    };

    std::string tail_slice(std::string &subject, std::string delimiter, bool keep_delim=false) {
        // Chops off the delimiter and everything that follows (destructively)
        // returns everything after the delimiter
        int delimiter_location = subject.find(delimiter);
        int delimiter_length = delimiter.length();
        std::string output = "";

        if (delimiter_location < std::string::npos) {
            int start = keep_delim ? delimiter_location : delimiter_location + delimiter_length;
            int end = subject.length() - start;

            output = subject.substr(start, end);
            subject = subject.substr(0, delimiter_location);
        }

        return output;
    }

    std::string head_slice(std::string &subject, std::string delimiter) {
        // Chops off the delimiter and everything that precedes (destructively)
        // returns everthing before the delimeter
        int delimiter_location = subject.find(delimiter);
        int delimiter_length = delimiter.length();
        std::string output = "";

        if (delimiter_location < std::string::npos) {
            output = subject.substr(0, delimiter_location);
            subject = subject.substr(delimiter_location + delimiter_length, subject.length() - (delimiter_location + delimiter_length));
        }

        return output;
    }

    int extract_port(std::string &hostport) {
        int port;
        std::string portstring = tail_slice(hostport, ":");
        try { port = atoi(portstring.c_str()); }
        catch (exception e) { port = -1; }
        return port;
    }

    std::string extract_path(std::string &in) { return tail_slice(in, "/", true); }
    std::string extract_protocol(std::string &in) { return head_slice(in, "://"); }
    std::string extract_search(std::string &in) { return tail_slice(in, "?"); }
    std::string extract_user(std::string &userpass) { return head_slice(userpass, ":"); }
    std::string extract_userpass(std::string &in) { return head_slice(in, "@"); }

    url parse_http_url(std::string &in) {
        url ret;
        ret.protocol = extract_protocol(in);
        ret.search = extract_search(in);
        ret.path = extract_path(in);
        std::string userpass = extract_userpass(in);
        ret.user = extract_user(userpass);
        ret.password = userpass;
        ret.port = extract_port(in);
        ret.host = in;

        return ret;
    }
}
