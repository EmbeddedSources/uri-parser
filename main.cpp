#include <iostream>
#include <UriParser.hpp>

int main(int argc, const char *argv[])
{
    http::uri google;
    google.parse_uri("http://user:password@www.google.com:80/path/to/something");

    std::cout << "protocol (" << google.protocol << ")" << std::endl;
    
    return 0;
}
