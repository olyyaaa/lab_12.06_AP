// lab_12.06_AP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

struct Elem 
{
    Elem* link;
    char info;
};

int main() 
{
    srand(time(0)); 
    Elem* front = nullptr; 
    Elem* back = nullptr; 
    for (int i = 0; i < 20; i++)
    { 
        int operation = rand() % 2; 
        int numElements = rand() % 3 + 1; 
        if (operation == 0) 
        { 
            cout << "Adding " << numElements << " element(s): ";
            for (int j = 0; j < numElements; j++) 
            { 
                char element = 'A' + rand() % 26; 
                Elem* newElem = new Elem{ nullptr, element }; 
                if (back != nullptr) 
                { 
                    back->link = newElem; 
                }
                else 
                { 
                    front = newElem; 
                }
                back = newElem; 
                cout << element << " ";
            }
            cout << endl;
        }
        else
        { 
            cout << "Removing " << numElements << " element(s): ";
            for (int j = 0; j < numElements; j++) 
            { 
                if (front != nullptr)
                { 
                    char element = front->info; 
                    Elem* temp = front; 
                    front = front->link; 
                    delete temp; 
                    if (front == nullptr) 
                    { 
                        back = nullptr;
                    }
                    cout << element << " ";
                }
            }
            cout << endl;
        }

        cout << "Queue state: ";
        Elem* temp = front;
        while (temp != nullptr) {
            cout << temp->info << " ";
            temp = temp->link;
        }
        cout << endl;

        this_thread::sleep_for(chrono::seconds(1)); 
    }

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
