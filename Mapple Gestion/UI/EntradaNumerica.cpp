#include "EntradaNumerica.h"
#include <iostream>
using namespace std;

void EntradaNumerica(int &n)
{
    while(!(cin >> n))
    {
        cin.clear();
        cin.ignore();
    }
}
void EntradaNumerica(float &n)
{
    while(!(cin >> n))
    {
        cin.clear();
        cin.ignore();
    }
}
