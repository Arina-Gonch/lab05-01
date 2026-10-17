#include "Base.h" 
#include <string> 

class Cat : public Base 
{
private:
    std::string breed; 
    std::string color;
    std::string owner; 
    std::string nickname; 

public:
    Cat(); 
    Cat(const std::string& breed, const std::string& color, const std::string& owner, const std::string& nickname); 
    Cat(const Cat& other); 
    ~Cat() override; 

    std::string getBreed() const; 
    std::string getColor() const; 
    std::string getOwner() const; 
    std::string getNickname() const; 

    void setBreed(const std::string& value); 
    void setColor(const std::string& value); 
    void setOwner(const std::string& value); 
    void setNickname(const std::string& value); 

    std::string getType() const override; 
    void print(std::ostream& out) const override; 
    void edit() override; 
    void save(std::ostream& out) const override; 
    Base* clone() const override; 
};

