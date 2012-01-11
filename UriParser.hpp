#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

namespace http {
    string tail_slice(string &subject, string delimiter) {
        // Chops off the delimiter and everything that follows (destructively)
        // returns everything after the delimiter
        int delimiter_location = subject.find(delimiter);
        int delimiter_length = delimiter.length();
        string output = subject.substr(delimiter_location + delimiter_length, subject.length() - (delimiter_location + delimiter_length));
        subject = subject.substr(0, delimiter_location);
        return output;
    }

    string head_slice(string &subject, string delimiter) {
        int delimiter_location = subject.find(delimiter);
        int delimiter_length = delimiter.length();
        string output = subject.substr(0, delimiter_location);
        subject = subject.substr(delimiter_location + delimiter_length, subject.length() - (delimiter_location + delimiter_length));
        return output;
    }


    int extract_port(string &hostport) {
        int port;
        string portstring = tail_slice(hostport, ":");
        try { port = atoi(portstring.c_str()); }
        catch (std::exception e) { port = -1; }
        return port;
    }

    string extract_path(string &in) { return tail_slice(in, "/"); }
    string extract_protocol(string &in) { return head_slice(in, "://"); }
    string extract_search(string &in) { return tail_slice(in, "?"); }
    string extract_user(string &userpass) { return head_slice(userpass, ":"); }
    string extract_userpass(string &in) { return head_slice(in, "@"); }




}
