#import "Foundation/Foundation.h"
#include <string>

std::string ResourcePath(const std::string &name)
{
    NSBundle *bundle = [NSBundle mainBundle];
    NSString *path = [bundle pathForResource:[NSString stringWithUTF8String:name.c_str()]
                                      ofType:@""];

    return path ? std::string([path UTF8String]) : name;
}
