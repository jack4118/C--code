#include <iostream>

using namespace std;

class MainClass
{
    public:
        virtual void foo()
        {

        }
};
class SubClass: public MainClass
{
    public:
        virtual void bar()
        {

        }
};

int main()
{
    // Failed Example
    // MainClass *b = new MainClass();

    //Successfully Example
    SubClass *b = new SubClass();

    // Failed Example
    // SubClass *d = dynamic_cast<SubClass*>(b);

    //Successfully Example
    MainClass *d = dynamic_cast<MainClass*>(b);

    if (d)
    {
        cout << "Successfully convert b to d!" << endl;
    }
    else
    {
        cout << "Failed to convert b to d!" << endl;
    }
}