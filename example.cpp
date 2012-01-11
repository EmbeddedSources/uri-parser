#include <iostream>
#include <UriParser.hpp>

using namespace std;

int main(int argc, const char *argv[])
{
    string temp;
    string haystack = "http://user:password@www.google.com:80/path?search";
    for (int i = 0; i < 1000000; i++) {
        http::uri * parsed = http::whole_thing(haystack);
        temp = parsed->host + char(i + 50);
        delete parsed;
    }

    return 0;
}
