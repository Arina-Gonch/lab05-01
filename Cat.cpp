#include "Cat.h" 
#include <iostream> 
#include <stdexcept> .
#include <iomanip> 

Cat::Cat() : Base(), breed("Не указана"), color("Не указан"), owner("Не указан"), nickname("Без клички") 
{
    std::cout << "[Конструктор Cat] Создана кошка без параметров." << std::endl; 
}

Cat::Cat(const std::string& breed, const std::string& color, const std::string& owner, const std::string& nickname) 
    : Base(), breed(breed), color(color), owner(owner), nickname(nickname) 
{
    std::cout << "[Конструктор Cat с параметрами] Создана кошка." << std::endl;
}

Cat::Cat(const Cat& other) 
    : Base(other), breed(other.breed), color(other.color), owner(other.owner), nickname(other.nickname) 
{
    std::cout << "[Конструктор копирования Cat] Создана копия кошки." << std::endl; 
}

Cat::~Cat() 
{
    std::cout << "[Деструктор Cat] Уничтожается объект кошки." << std::endl; 
}

std::string Cat::getBreed() const { return breed; } 
std::string Cat::getColor() const { return color; } 
std::string Cat::getOwner() const { return owner; } 
std::string Cat::getNickname() const { return nickname; } 

void Cat::setBreed(const std::string& value) { breed = value; } 
void Cat::setColor(const std::string& value) { color = value; } 
void Cat::setOwner(const std::string& value) { owner = value; } 
void Cat::setNickname(const std::string& value) { nickname = value; } 

std::string Cat::getType() const { return "Cat"; } 

void Cat::print(std::ostream& out) const 
{
    out << "Тип: кошка\n"; 
    out << "Порода: " << breed << '\n'; 
    out << "Окрас: " << color << '\n'; 
    out << "ФИО владельца: " << owner << '\n'; 
    out << "Кличка: " << nickname << '\n'; 
}

void Cat::edit() 
{
    std::string value; 

    std::cout << "Новая порода: "; 
    if (!std::getline(std::cin >> std::ws, value) || value.empty()) throw std::runtime_error("Некорректная порода кошки."); 
    setBreed(value); 

    std::cout << "Новый окрас: "; 
    if (!std::getline(std::cin, value) || value.empty()) throw std::runtime_error("Некорректный окрас кошки.");
    setColor(value); 

    std::cout << "ФИО владельца: "; 
    if (!std::getline(std::cin, value) || value.empty()) throw std::runtime_error("ФИО владельца не может быть пустым."); 
    setOwner(value); 

    std::cout << "Кличка кошки: "; 
    if (!std::getline(std::cin, value) || value.empty()) throw std::runtime_error("Кличка кошки не может быть пустой.");
    setNickname(value); 
}

void Cat::save(std::ostream& out) const 
{
    out << std::quoted(breed) << ' ' << std::quoted(color) << ' ' << std::quoted(owner) << ' ' << std::quoted(nickname) << '\n'; 
}

Base* Cat::clone() const 
{
    return new Cat(*this); 
}