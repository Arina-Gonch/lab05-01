#include "Base.h" 
#include <string> 

class Bird : public Base 
{
private:
    std::string breed; 
    std::string color; 
    std::string food; 
    std::string habitat; 

public:
    Bird(); 
    Bird(const std::string& breed, const std::string& color, const std::string& food, const std::string& habitat); 
    Bird(const Bird& other); 
    ~Bird() override; 

    std::string getBreed() const; 
    std::string getColor() const; 
    std::string getFood() const; 
    std::string getHabitat() const; 

    void setBreed(const std::string& value); 
    void setColor(const std::string& value); 
    void setFood(const std::string& value); 
    void setHabitat(const std::string& value); 

    std::string getType() const override; 
    void print(std::ostream& out) const override; 
    void edit() override; 
    void save(std::ostream& out) const override; 
    Base* clone() const override; 
};
