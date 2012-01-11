#include <iostream>
#include <UriParser.hpp>


int main(int argc, const char *argv[])
{
    if (argc < 2) return 1;
    std::string haystack = argv[1];
    http::url parsed = http::ParseHttpUrl(haystack);
    std::cout << parsed.protocol << " "
              << parsed.user << " "
              << parsed.password << " "
              << parsed.host << " "
              << parsed.port << " "
              << parsed.path << " "
              << parsed.search << std::endl;
    return 0;
}
