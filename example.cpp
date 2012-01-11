#include <iostream>
#include <UriParser.hpp>

int main(int argc, const char *argv[])
{
    std::string temp;
    std::string haystack = "http://user:password@www.google.com:80/path?search";
    for (int i = 0; i < 100; i++) {
        http::url parsed = http::parse_http_url(haystack);
        temp = parsed.host + char(i + 50);
        std::cout << temp[0];
    }
    std::cout << std::endl;

    return 0;
}
