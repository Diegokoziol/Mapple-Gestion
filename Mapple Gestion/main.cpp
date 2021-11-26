#include "UI/MenuPrincipal.h"

#include "Managers/BalanceManager.h"

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    cout << BalanceManager::guardarNuevo(2021,11);
    system("pause");
    IniciarUI();
    return 0;
}
