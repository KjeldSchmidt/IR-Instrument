#include "arduinoparser.h"

bool ArduinoParser::parse_volumes( std::string in, float* volumes ) {
    int i = 0;
    std::string current_word;
    int current_num;
    std::istringstream iss( in, std::istringstream::in );

    while ( iss >> current_num ) {
        volumes[i] = std::min( (float) current_num / 500.0f, 1.0f);
        ++i;
    }

    return true;
}
