#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

namespace http {
    struct uri {
        string protocol, user, password, host, path, search;
        int port;
    };

    string tail_slice(string &subject, string delimiter, bool keep_delim=false) {
        // Chops off the delimiter and everything that follows (destructively)
        // returns everything after the delimiter
        int delimiter_location = subject.find(delimiter);
        int delimiter_length = delimiter.length();
        string output = "";

        if (delimiter_location < string::npos) {
            int start = keep_delim ? delimiter_location : delimiter_location + delimiter_length;
            int end = subject.length() - start;

            output = subject.substr(start, end);
            subject = subject.substr(0, delimiter_location);
        }

        return output;
    }

    string head_slice(string &subject, string delimiter) {
        // Chops off the delimiter and everything that precedes (destructively)
        // returns everthing before the delimeter
        int delimiter_location = subject.find(delimiter);
        int delimiter_length = delimiter.length();
        string output = "";

        if (delimiter_location < string::npos) {
            output = subject.substr(0, delimiter_location);
            subject = subject.substr(delimiter_location + delimiter_length, subject.length() - (delimiter_location + delimiter_length));
        }

        return output;
    }

    int extract_port(string &hostport) {
        int port;
        string portstring = tail_slice(hostport, ":");
        try { port = atoi(portstring.c_str()); }
        catch (exception e) { port = -1; }
        return port;
    }

    string extract_path(string &in) { return tail_slice(in, "/", true); }
    string extract_protocol(string &in) { return head_slice(in, "://"); }
    string extract_search(string &in) { return tail_slice(in, "?"); }
    string extract_user(string &userpass) { return head_slice(userpass, ":"); }
    string extract_userpass(string &in) { return head_slice(in, "@"); }

    uri * whole_thing(string &in) {
        uri * ret = new uri;
        ret->protocol = extract_protocol(in);
        ret->search = extract_search(in);
        ret->path = extract_path(in);
        string userpass = extract_userpass(in);
        ret->user = extract_user(userpass);
        ret->password = userpass;
        ret->port = extract_port(in);
        ret->host = in;

        return ret;
    }







}
