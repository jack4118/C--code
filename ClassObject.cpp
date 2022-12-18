#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>

using namespace std;

class ElectricBoxA{
    public:
    string LineA(string LineName)
    {
        string connector;
        string result = "";
        return result;
    }

    string LineB(string LineName)
    {
        string connector;
        string result = "";
        return result;
    }
};

int main()
{
    string LineName;
    ElectricBoxA Elec;
    // unsigned sleep(unsigned seconds);

    try
    {
        cout<<"Welcome to Connector!";
        cout<<"\n\t->LineA\n\t->LineB";
        cout<<"\nPlease Key in the line you want to connect: ";
        cin>>LineName;

         if (LineName == "LineA" || LineName == "LineB")
            {
                cout<<"\nConnecting ElectricBox A...";
                // cout.flush();
                // sleep(5);
                cout<<"\nConnected ElectricBox A Successfull!";

                if (LineName == "LineA")
                    {
                        Elec.LineA(LineName);
                    }
                else if (LineName == "LineB")
                    {
                        Elec.LineB(LineName);
                    }
            }
            else
            {
                throw LineName;
            }
    }catch (...)
        {
            cout<<"\nConnecting ElectricBox A...";
            cout<<"\nUnable to connect ElectricBox A, Please check your input:"<<LineName;
        }
    return 0;