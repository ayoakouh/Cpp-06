#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP

#include <iostream>
#include<string>
#include<cmath>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cerrno>

class ScalarConverte {
    private :
        ScalarConverte();
        ScalarConverte(const ScalarConverte& other);
        ScalarConverte& operator=(const ScalarConverte& other);
        ~ScalarConverte();
    public : 
        static void convert(std::string input);
        static bool isChar(std::string input);//
        static void ConvertChar(std::string input);

        static bool isInt(std::string input);//
        static void ConvertInt(std::string input);

        static bool isFloat(std::string input);//
        static void ConvertFloat(std::string input);

        static bool isDouble(std::string input);//
        static void ConvertDouble(std::string input);

        static void Impossible();
};

#endif