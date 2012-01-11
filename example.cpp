#include <iostream>
#include <UriParser.hpp>

int main(int argc, const char *argv[])
{
    std::string temp;
    std::string haystack = "http://user:password@www.google.com:80/path?search";
    for (int i = 0; i < 100000; i++) {
        http::url parsed = http::ParseHttpUrl(haystack);
        temp = parsed.host + char(i % 26 + 97);
        std::cout << temp[temp.length() - 1];
    }
    std::cout << std::endl;

    return 0;
}
