#include "Bird.h"
#include <iostream> 
#include <stdexcept> 
#include <iomanip> 

Bird::Bird() : Base(), breed("Не указана"), color("Не указан"), food("Не указано"), habitat("Не указано") 
{
    std::cout << "[Конструктор Bird] Создана птица без параметров." << std::endl; 
}

Bird::Bird(const std::string& breed, const std::string& color, const std::string& food, const std::string& habitat) 
    : Base(), breed(breed), color(color), food(food), habitat(habitat) 
{
    std::cout << "[Конструктор Bird с параметрами] Создана птица." << std::endl; 
}

Bird::Bird(const Bird& other)
    : Base(other), breed(other.breed), color(other.color), food(other.food), habitat(other.habitat) 
{
    std::cout << "[Конструктор копирования Bird] Создана копия птицы." << std::endl; 
}

Bird::~Bird() 
{
    std::cout << "[Деструктор Bird] Уничтожается объект птицы." << std::endl; 
}

std::string Bird::getBreed() const { return breed; } 
std::string Bird::getColor() const { return color; } 
std::string Bird::getFood() const { return food; } 
std::string Bird::getHabitat() const { return habitat; } 

void Bird::setBreed(const std::string& value) { breed = value; } 
void Bird::setColor(const std::string& value) { color = value; } 
void Bird::setFood(const std::string& value) { food = value; } 
void Bird::setHabitat(const std::string& value) { habitat = value; } 

std::string Bird::getType() const { return "Bird"; } 

void Bird::print(std::ostream& out) const 
{
    out << "Тип: птица\n"; 
    out << "Порода: " << breed << '\n'; 
    out << "Окрас: " << color << '\n'; 
    out << "Чем питается: " << food << '\n'; 
    out << "Где обитает: " << habitat << '\n'; 
}

void Bird::edit() 
{
    std::string value; 

    std::cout << "Новая порода: "; 
    if (!std::getline(std::cin >> std::ws, value) || value.empty()) throw std::runtime_error("Некорректная порода птицы."); 
    setBreed(value); 

    std::cout << "Новый окрас: "; 
    if (!std::getline(std::cin, value) || value.empty()) throw std::runtime_error("Некорректный окрас птицы."); 
    setColor(value); 

    std::cout << "Чем питается: "; 
    if (!std::getline(std::cin, value) || value.empty()) throw std::runtime_error("Некорректное описание питания птицы."); 
    setFood(value); 

    std::cout << "Где обитает: "; 
    if (!std::getline(std::cin, value) || value.empty()) throw std::runtime_error("Некорректное место обитания птицы."); 
    setHabitat(value); 
}

void Bird::save(std::ostream& out) const 
{
    out << std::quoted(breed) << ' ' << std::quoted(color) << ' ' << std::quoted(food) << ' ' << std::quoted(habitat) << '\n';
}

Base* Bird::clone() const 
{
    return new Bird(*this);
}