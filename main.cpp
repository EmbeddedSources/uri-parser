#include <iostream>
#include <UriParser.hpp>

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    std::string haystack = argv[1];
    string * http_parts;

    http_parts = parse_http_uri(haystack);

    std::cout << http_parts[0] << " " << http_parts[1] << " " << http_parts[2] << std::endl;
    return 0;
}
