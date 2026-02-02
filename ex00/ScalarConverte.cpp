#include "ScalarConverte.hpp"


bool ScalarConverte::isChar(std::string input)
{
    if(input.length() != 1 || !std::isprint(input[0]) || std::isdigit(input[0]))
        return false;
    return true;
}

bool ScalarConverte::isInt(std::string input)
{
    for (std::string::size_type i = 0; i < input.length(); i++)
    {
        if(input[0] == '-' || input[1] == '+')
            i++;
        if(!std::isdigit(input[i]))
            return false;
    }
    return true; 
}

bool ScalarConverte::isFloat(std::string input)
{
    bool digit = false;
    bool dot = false;
    int len = input.size();
    int i = 0;
    if(input == "nanf" || input == "+inff" || input == "-inff")
        return true;
    if(len < 2 || input[len - 1] != 'f')
        return false;
    if(input[0] == '.')
        return false;
    if(input[i] == '+' || input[i] == '-')
        i++;
    if(i < len - 1 && input[i] == '.')
        return false; 
    while(i < len - 1)
    {
        if(std::isdigit(input[i]))
            digit = true;
        else if(input[i] == '.')
        {
            if(dot)
                return false;
            dot = true;
        }
        else
            return false;
        i++;
    }
    return digit;
}

bool ScalarConverte::isDouble(std::string input)
{
    bool digit = false;
    bool dot = false;
    int len = input.size();
    int i = 0;
    if(input == "nan" || input == "+inf" || input == "-inf")
        return true;
    if(len < 1 || input[len - 1] == '.')
        return false;
    if(input[i] == '+' || input[i] == '-')
        i++;
    if(i < len - 1 && input[i] == '.' && len == i + 1)
        return false; 
    while(i < len)
    {
        if(std::isdigit(input[i]))
            digit = true;
        else if(input[i] == '.')
        {
            if(dot)
                return false;
            dot = true;
        }
        else
            return false;
        i++;
    }
    return digit;    
}

void ScalarConverte::ConvertChar(std::string input)
{
    char c = input[0];
    if(std::isprint(c))
        std::cout<<"char: " << c << std::endl;
    else
        std::cout<<"::char: " << "Non displayable" << std::endl;
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    std::cout<<"int: " << i <<std::endl;
    std::cout<<"float: " << f << "f" << std::endl;
    std::cout<<"double: " << d << std::endl;
}

void ScalarConverte::ConvertInt(std::string input)
{
    errno = 0;
    char *end = NULL;
    long number = std::strtol(input.c_str(), &end, 10);
    if(errno == ERANGE || *end != '\0')
    {
        std::cout<< "char: impossible\n";
        std::cout<< "int: impossible\n";
        std::cout<< "float: impossible\n";
        std::cout<< "double: impossible\n";
        return; 
    }
    if(number >= 32 && number <= 126)
        std::cout<<"char: " << static_cast<char>(number) <<std::endl;
    else if(number < -128 || number > 127)
        std::cout<<"char: impossible" << std::endl;
    else
        std::cout<< "char: non displayable" <<std::endl;
    if(number < INT_MIN || number > INT_MAX)
        std::cout<<"int: impossible"<<std::endl;
    else
        std::cout<<"int: " << static_cast<int>(number)<<std::endl;
    std::cout<<"float: " <<std::fixed << std::setprecision(1)
        << static_cast<float>(number) << "f" << std::endl;
    std::cout<< "double: " << std::fixed << std::setprecision(1)
        << static_cast<double>(number) << std::endl;
}

void ScalarConverte::ConvertDouble(std::string input)
{
    errno = 0;
    char *end = NULL;
    double number = std::strtod(input.c_str(), &end);
    if(errno == ERANGE || *end != '\0')
    {
        std::cout<< "char: impossible\n";
        std::cout<< "int: impossible\n";
        std::cout<< "float: impossible\n";
        std::cout<< "double: impossible\n";
        return; 
    }
    if(std::isinf(number) || std::isnan(number))
    {
        std::cout<< "char: impossible"<<std::endl;
        std::cout<< "int: impossible"<<std::endl;
        std::cout<< "float: "<< input << "f" <<std::endl;
        std::cout<< "double: "<< input << std::endl;
        return ;
    }
    if(number >= 32 && number <= 126)
        std::cout<< "char: " << static_cast<char>(number) <<std::endl;
    else if (number < -128 || number > 127)
        std::cout<< "char: non displayable" <<std::endl;
    else
        std::cout <<"char: non diplayable" <<std::endl;
    if(number < INT_MIN || number > INT_MAX)
        std::cout<< "Int: impossible" <<std::endl;
    else
        std::cout<< "Int: " << static_cast<int>(number) <<std::endl;
    std::cout<< "float: " << std::fixed << std::setprecision(1)
        <<static_cast<double>(number) << "f" << std::endl;
    std::cout<< "double: " << std::fixed << std::setprecision(1)
        << static_cast<double>(number) << std::endl;
}

void ScalarConverte::ConvertFloat(std::string input)
{
    if(input == "+inff" || input == "-inff" || input == "nanf")
    {
        std::cout <<"char: imposible" << std::endl;
        std::cout<< "int: impossible" << std::endl;
        std::cout<< "float: " << input <<std::endl;
        std::cout<< "double: " << input.substr(0, input.length() - 1)
            <<std::endl;
        return ;
    }
    errno = 0;
    char *end = NULL;
    double number = std::strtod(input.c_str(), &end);
    if(errno == ERANGE || *end != '\0')
    {
        std::cout<< "char: impossible\n";
        std::cout<< "int: impossible\n";
        std::cout<< "float: impossible\n";
        std::cout<< "double: impossible\n";
        return; 
    }
    if(number >= 32 && number <= 126)
        std::cout<<"char: " <<static_cast<char>(number) << std::endl;
    else if(number < -128 || number > 127)
        std::cout<< "char: impossible" <<std::endl;
    else
        std::cout <<"char: non diplayable" <<std::endl;
    if(number < INT_MIN || number > INT_MAX)
        std::cout<< "Int: impossible" <<std::endl;
    else
        std::cout<< "Int: " << static_cast<int>(number) <<std::endl;
    std::cout<< "float: " << std::fixed << std::setprecision(1)
        <<static_cast<double>(number) << "f" << std::endl;
    std::cout<< "double: " << std::fixed << std::setprecision(1)
        << static_cast<double>(number) << std::endl;
}

void ScalarConverte::Impossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverte::convert(std::string input)
{
    if(ScalarConverte::isChar(input))
        ConvertChar(input);
    else if(ScalarConverte::isInt(input))
        ConvertInt(input);
    else if(ScalarConverte::isDouble(input))
        ConvertDouble(input);
    else if(ScalarConverte::isFloat(input))
        ConvertFloat(input);
    else
        ScalarConverte::Impossible();
}