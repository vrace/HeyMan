#include "StringToken.h"
#include <algorithm>

StringToken::StringToken(const std::string &h, const std::string &t)
: head(h)
, tail(t)
{
    
}

StringToken TokenlizeString(const std::string &str, const std::string &delimiters)
{
    std::string::size_type start = str.find_first_not_of(delimiters);
    if (start == std::string::npos)
        return StringToken();
    
    std::string::size_type sep = str.find_first_of(delimiters, start);
    if (sep == std::string::npos)
    {
        return StringToken(str.substr(start), std::string());
    }
    else
    {
        return StringToken(str.substr(start, sep - start), str.substr(sep + 1));
    }
}
