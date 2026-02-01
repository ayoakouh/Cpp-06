#include "ScalarConverte.hpp"


static bool ScalarConverte::isChar(std::string input)
{
    if(input.lenght() != 1 || !std::isprint(input[0]) || std::isdigit(input[0]))
        return false;
    return true;
}

static bool ScalarConverte::isInt(std::string input)
{
    if(input[0] == '-' || input[1] == '+')
        
}
