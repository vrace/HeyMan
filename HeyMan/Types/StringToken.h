#ifndef HEYMAN_STRING_UTILS_H
#define HEYMAN_STRING_UTILS_H

#include <string>
#include <vector>

struct StringToken
{
    StringToken() = default;
    StringToken(const std::string &head, const std::string &tail);
    
    std::string head;
    std::string tail;
};

StringToken TokenlizeString(const std::string &str, const std::string &delimiters);

#endif
