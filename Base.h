#include <iostream> 
#include <string>   
#include <iosfwd>   // ќбъ€вл€ем классы потоков без подключени€ полной реализации.

class Base 
{
public:
    Base(); 
    Base(const Base& other); 
    virtual ~Base(); 

    virtual std::string getType() const = 0; 
    virtual void print(std::ostream& out) const = 0;
    virtual void edit() = 0; 
    virtual void save(std::ostream& out) const = 0; 
    virtual Base* clone() const = 0; 

    friend std::ostream& operator<<(std::ostream& out, const Base& animal); // ѕерегружаем оператор вывода.
};
