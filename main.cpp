#include <iostream>
#include <UriParser.hpp>

int main(int argc, const char *argv[])
{
    http::uri google;
    std::string haystack = "www.google.com:80/path/to/something";
    google.parse_uri(haystack);

    std::cout << haystack<< std::endl;
    
    std::cout << "protocol (" << google.protocol << ")" << std::endl;
    std::cout << "host (" << google.host << ")" << std::endl;
    
    return 0;
}
