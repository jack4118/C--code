#include <iostream>

using namespace std;

class Base
{
    public:
    virtual void print()
    {
        cout << "Base prnt" << endl;
    }

    void work()
    {
        cout << "Base do work..." << endl;
    }
};

class Derived : public Base
{
    public:
        virtual void print()
        {
            cout << "Derived print!" << endl;
        }
        
        void work()
        {
            cout << "Derived do work..." << endl;
        }
};

int main()
{
    Base* pBase = new Derived();
    pBase->print();
    pBase->work();

    Derived* pDerived = dynamic_cast<Derived*>(pBase); //向下转换成功， 成功返回Derived
    if(pDerived != nullptr)
    {
        cout<<"Start"<<endl;
        pDerived->print();
        pDerived->work();
    }
    else
    {
        cout<<"Its Null"<<endl;
    }

    Base *pRealBase = new Base();
    pDerived = dynamic_cast<Derived*>(pRealBase); //向下转换失败，返回nullptr指针
    if (pDerived != nullptr)
    {
        cout<<"Second Start"<<endl;
        pDerived->print();
        pDerived->work();
    }
    else
    {
        cout<<"Its Null"<<endl;
    }

    Base base;
    Base& refBase = base;
    try
    {
        Derived refDerived = dynamic_cast<Derived&>(refBase);
    }
    catch(const std::exception& e)
    {
        cout << "first try failed, reason: " << e.what() << endl;
    }
    
    Derived derived;
    Base& refBaseNew = derived;
    try
    {
        Derived refDerived = dynamic_cast<Derived&>(refBaseNew);
    }
    catch(const std::exception& e)
    {
        cout << "Second try failed: reason: " << e.what() << endl;
    }
    

    getchar();
    return 0;
}