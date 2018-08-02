#ifndef ARDUINOPARSER_H
#define ARDUINOPARSER_H

#include <string>
#include <sstream>

class ArduinoParser
{
public:
    static bool parse_volumes( std::string in, float* volumes );
};

#endif // ARDUINOPARSER_H
