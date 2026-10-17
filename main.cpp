#include "Fish.h" 
#include "Bird.h" 
#include "Cat.h"
#include <iostream> 
#include <string> 
#include <limits> 
#include <stdexcept> 

std::string readText(const std::string& prompt)
{
    std::string value; 
    std::cout << prompt; 
    if (!std::getline(std::cin >> std::ws, value) || value.empty()) throw std::runtime_error("Необходимо ввести непустую строку."); 
    return value; 
}

int readInt(const std::string& prompt)
{
    int value; 
    std::cout << prompt; 
    if (!(std::cin >> value)) 
    {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        throw std::runtime_error("Ожидалось целое число."); 
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    return value; 
}