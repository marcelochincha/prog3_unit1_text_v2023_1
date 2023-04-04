//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT1_TEXT_V2023_1_TEXT_H
#define PROG3_UNIT1_TEXT_V2023_1_TEXT_H

#include <iostream>
using namespace std;

class Text
{
    char *content = nullptr;
    int size = 0; 

    public:
        Text() = default;

        Text(const char* text);
        Text(const Text& other);
        Text(Text&& other) noexcept;

        Text& operator=(const Text& other);
        Text& operator=(Text&& other);
        Text& operator=(const std::string& other);



        friend ostream& operator<<(ostream& os, const Text& text);
        friend istream& operator>>(istream& is, Text& text);
    
};

istream& operator>>(istream& is, Text& text);
ostream& operator<<(ostream& os, const Text& text);

#endif //PROG3_UNIT1_TEXT_V2023_1_TEXT_H
