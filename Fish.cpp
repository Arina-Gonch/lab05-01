
#include "Fish.h" 
#include <iostream> 
#include <stdexcept> 
#include <iomanip> 

Fish::Fish() : Base(), breed("Не указана"), color("Не указан"), foodType("Не указан") 
{
    std::cout << "[Конструктор Fish] Создана рыба без параметров." << std::endl; 
}

Fish::Fish(const std::string& breed, const std::string& color, const std::string& foodType) 
    : Base(), breed(breed), color(color), foodType(foodType) 
{
    std::cout << "[Конструктор Fish с параметрами] Создана рыба с параметрами." << std::endl; 
}

Fish::Fish(const Fish& other) 
    : Base(other), breed(other.breed), color(other.color), foodType(other.foodType) 
{
    std::cout << "[Конструктор копирования Fish] Создана копия рыбы." << std::endl; 
}

Fish::~Fish() 
{
    std::cout << "[Деструктор Fish] Уничтожается объект рыбы." << std::endl; 
}

std::string Fish::getBreed() const { return breed; } 
std::string Fish::getColor() const { return color; } 
std::string Fish::getFoodType() const { return foodType; } 

void Fish::setBreed(const std::string& value) { breed = value; } 
void Fish::setColor(const std::string& value) { color = value; } 
void Fish::setFoodType(const std::string& value) { foodType = value; } 

std::string Fish::getType() const { return "Fish"; } 

void Fish::print(std::ostream& out) const 
{
    out << "Тип: рыба\n"; 
    out << "Порода: " << breed << '\n'; 
    out << "Окрас: " << color << '\n'; 
    out << "Тип питания: " << foodType << '\n'; 
}

void Fish::edit() 
{
    std::string value; 

    std::cout << "Новая порода: "; 
    if (!std::getline(std::cin >> std::ws, value) || value.empty()) throw std::runtime_error("Некорректная порода рыбы."); 
    setBreed(value); 

    std::cout << "Новый окрас: "; 
    if (!std::getline(std::cin, value) || value.empty()) throw std::runtime_error("Некорректный окрас рыбы."); 
    setColor(value); 

    std::cout << "Новый тип питания: "; 
    if (!std::getline(std::cin, value) || value.empty()) throw std::runtime_error("Некорректный тип питания рыбы."); 
    setFoodType(value); 
}

void Fish::save(std::ostream& out) const 
{
    out << std::quoted(breed) << ' ' << std::quoted(color) << ' ' << std::quoted(foodType) << '\n'; 
}

Base* Fish::clone() const 
{
    return new Fish(*this); 
}
