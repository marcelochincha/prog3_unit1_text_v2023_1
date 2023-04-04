//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <cstring>
#include "text.h"
using namespace std;

Text::Text(const char *text)
{
    this->size = strlen(text);
    this->content = new char[this->size + 1];
    strcpy(this->content, text);
}

Text::Text(const Text& other)
{
    if (this == &other) return;
    this->size = other.size;
    this->content = new char[this->size + 1];
    strcpy(this->content, other.content);
}

Text::Text(Text&& other) noexcept
{
    if (this == &other) return;
    this->size = other.size;
    this->content = other.content;

    other.content = nullptr;
    other.size = 0;
    
}

Text& Text::operator=(const Text& other)
{
    if (this == &other) return *this;
    delete[] this->content;

    this->size = other.size;
    this->content = new char[this->size + 1];
    strcpy(this->content, other.content);
    return *this;    
}

Text& Text::operator=(Text&& other)
{
    if (this == &other) return *this;
    delete[] this->content;

    this->size = other.size;
    this->content = other.content;
    
    other.content = nullptr;
    other.size = 0;

    return *this;
}

Text& Text::operator=(const std::string& other)
{

    delete[] this->content;

    this->size = other.size();
    this->content = new char[this->size + 1];
    strcpy(this->content, other.c_str());
}

istream& operator>>(std::istream& is, Text& text)
{
    string buffer;
    is >> buffer;

    text = buffer;
    return is;
}       

ostream& operator<<(std::ostream& os, const Text& text)
{
    os << text.content;
    return os;
}