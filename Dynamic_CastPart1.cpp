#include <iostream>

using namespace std;

class Base
{
    public:
        virtual ~Base()
        {
            
        }
};
class Derived : public Base 
{

};

int main()
{
    // Create a pointer to a derived class object
    Derived* derived = new Derived();
    // Base* base = new Base();

    // Use dynamic_cast to convert the pointer to a base class pointer
    Base* base = dynamic_cast<Base*>(derived);
    // Derived* derived = dynamic_cast<Derived*>(base);

    // Check if the conversion was successful
    if (base != nullptr)
    {
        // The conversion was successful
        cout << "Conversion was successful"<<endl;
    }
    else
    {
        // The conversion was not successful
        cout << "The conversion was not successful"<<endl;
    }

    return 0;
}