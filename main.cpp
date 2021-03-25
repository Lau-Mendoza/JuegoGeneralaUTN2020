#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "tpintegrador.h"
#include "rlutil.h"
#include <time.h>


int main()
{
    rlutil::setColor(15);
    srand(time(NULL));
    system("cls");
    cuadro_inicio();
    cout<<endl;
    gotoxy (1, 16);
    system("pause");
    system ("cls");
    menu_inicio();

    return 0;
}
