#include <iostream>
#include <UriParser.hpp>

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    string haystack = argv[1];

    string protocol = http::extract_protocol(haystack);
    string search = http::extract_search(haystack);
    string path = http::extract_path(haystack);
    string userpass = http::extract_userpass(haystack);
    string user = http::extract_user(userpass);
    string password = userpass;
    int port = http::extract_port(haystack);
    string host = haystack;


    for (int i = 0; i < 1; i++) {
        std::cout << protocol << " "
                  << user << " "
                  << password << " "
                  << host << " "
                  << port << " "
                  << path << " "
                  << search
                  << std::endl;
    }

    return 0;
}
