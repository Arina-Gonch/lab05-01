#include "Base.h" 

Base::Base() 
{
    std::cout << "Создан базовый объект." << std::endl; 
}

Base::Base(const Base& other) 
{
    (void)other; 
    std::cout << "Выполнено копирование базового объекта." << std::endl; 
}

Base::~Base() 
{
    std::cout << "Уничтожена базовая часть объекта." << std::endl; 
}

std::ostream& operator<<(std::ostream& out, const Base& animal) 
{
    animal.print(out); 
    return out; 
}