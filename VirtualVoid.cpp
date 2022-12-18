#include <iostream>

using namespace std;

class MainClass
{
    public:
        virtual void foo()
        {
            cout << "This is the Base version of foo()" << endl;
        }
};

class SubClass : public MainClass
{
    public:
        virtual void foo()
        {
            cout << "This is the Derived version of foo()" << endl;
        }
};

int main()
{
    MainClass *m = new MainClass();
    m->foo();

    SubClass *s = new SubClass();
    s->foo();
}