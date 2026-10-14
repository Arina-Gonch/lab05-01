#include "Base.h" 
#include <string> 

class Fish : public Base 
{
private:
    std::string breed; 
    std::string color; 
    std::string foodType; 

public:
    Fish(); 
    Fish(const std::string& breed, const std::string& color, const std::string& foodType); 
    Fish(const Fish& other); 
    ~Fish() override; 

    std::string getBreed() const; 
    std::string getColor() const; 
    std::string getFoodType() const; 

    void setBreed(const std::string& value); 
    void setColor(const std::string& value); 
    void setFoodType(const std::string& value); 

    std::string getType() const override; 
    void print(std::ostream& out) const override; 
    void edit() override; 
    void save(std::ostream& out) const override;
    Base* clone() const override; 
};

