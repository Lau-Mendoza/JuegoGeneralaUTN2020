#include <iostream>
#include "tpintegrador.h"
#include <windows.h>
#include "rlutil.h"
#include <cstdlib>
#include <time.h>
using namespace std;
using namespace rlutil;

///Muestro el menu con las opciones de juego.
int menu_inicio(){
    int opciones;
    do{
        for(int i=1; i<=36; i++){
            gotoxy(i+22,1); cout <<(char)205;
        }
        for(int i=1; i<=36; i++){
            gotoxy(i+22,13);
            cout <<(char)205<<endl;
        }
        for(int i=1; i<=11; i++){
            gotoxy(22,i+1);
            cout <<(char)186 <<endl;
        }
            for(int i=1; i<=11; i++){
            gotoxy(59,i+1);
            cout <<(char)186 <<endl;
        }
        gotoxy(26,3);
        cout<<"Elija un modo de juego"<<endl<<endl;
        gotoxy(26,5);
        cout<<"1) Opcion UN jugador"<< endl<<endl;
        gotoxy(26,7);
        cout<<"2) Opcion DOS jugadores"<<endl<<endl;
        gotoxy(26,9);
        cout<<"3) Opcion Puntuacion mas alta"<<endl<<endl;
        gotoxy(26,11);
        cout<<"Ingrese su opcion: ";
        cin>> opciones;

        switch(opciones){
            case 1:{
                system("cls");
                un_jugador();
            break;
            }
            case 2:{
                system("cls");
                dos_jugadores();
            break;
            }
            case 3:{
                system ("cls");
                gotoxy (20, 4);
                cout<< "Coming soon....."<<endl << endl;
                gotoxy (1, 20);
                system ("pause");
            break;
            }
            default:{
                system ("cls");
                cout << "ERROR: Solo puedes elegir entre las opciones disponibles."<<endl;
                system ("pause");
                system ("cls");
            }
        }
    }
    while(opciones>3 || opciones < 1);
}

/// Muestro el cuadro de arranque con la presentacion.
///Utilizo Gotoxy para darle ubicacion.
void cuadro_inicio(){
    for(int i=1; i<=33; i++){
        gotoxy(i+25,1); cout <<(char)205;
    }
    gotoxy(26,3);
    cout<< "     WELCOME TO THE GENERALA    ";
    gotoxy(26,4);
    cout<<"    Created by Emi, Pao y Lau   "<<endl;
    for(int i=1; i<=33; i++){
        gotoxy(i+25,6);
        cout <<(char)205<<endl;
    }
    for(int i=1; i<=4; i++){
        gotoxy(25,i+1);
        cout <<(char)186 <<endl;
    }
    for(int i=1; i<=4; i++){
        gotoxy(59,i+1);
        cout <<(char)186 <<endl;
    }
}
///Asigno los valores de la primera tirada al vector de dados.
void tirar_dados(int dados[], int t, bool AZAR){
    if(AZAR==true){
        for(int i=0; i<t; i++){
            dados[i] = rand()%6+1;
            dibujarDado(i+1, dados[i]);
        }
        /*mostrar_dados(dados, 5);*/
    }else{
        for(int i=0; i<t;i++){
        locate(1,13);
        cout<<"Ingrese el valor del dado "<<i+1<<": "<<endl;
        cin>>dados[i];
        dibujarDado(i+1, dados[i]);
        }

        //system ("pause");
        //system("cls");

        /*mostrar_dados(dados, 5);*/
    }

}

/// Muestro los valores de la primera tirada.
void mostrar_dados(int dados[], int t){
    for(int i=0; i<t; i++){
        cout<<"Dado "<<i+1<<": "<<dados[i]<<"     ";
    }
    cout<<endl<<"-------------------------------------"<<endl;
}
void dos_jugadores(){
    const bool AZAR=true;
    int vPuntosUno[10], vBanderaUno[10], vPuntosDos[10], vBanderaDos[10], ptosJugUno, ptosJugDos;
    vPuntajes(vPuntosUno, 10);
    banderas_jugadas(vBanderaUno, 10);
    vPuntajes(vPuntosDos, 10);
    banderas_jugadas(vBanderaDos, 10);
    char name_uno[25], name_dos[25];
    gotoxy(27,4);
    cout<<"NICKNAME DEL PRIMER JUGADOR: ";
    cuadros_dosjugadores();
    gotoxy(55,4);
    cin>>name_uno;
    system("cls");
    gotoxy(27,4);
    cout<<"NICKNAME DEL SEGUNDO JUGADOR: ";
    cuadros_dosjugadores();
    gotoxy(56,4);
    cin>>name_dos;
    system("cls");
    int turno;
    char jugar='s';
    while(jugar=='s'||jugar=='S'){
        int contV=0;
        int rondas=1;
        turno = rand()%2;
        while(rondas<=10){
            if(turno==0){
                contV++;
                turno=1;
                jugador_uno(rondas, name_uno, vPuntosUno, vBanderaUno, AZAR);
            }else{
                contV++;
                turno=0;
                jugador_dos(rondas, name_dos, vPuntosDos, vBanderaDos, AZAR);
            }
            if (contV%2==0){
            rondas++;
            }
            system("cls");
        }

        ptosJugUno=puntaje_total(vPuntosUno, 10 , v[]);
        ptosJugDos=puntaje_total(vPuntosDos, 10, v[]);
        if(ptosJugUno>ptosJugDos){
            gotoxy (15,2);
            cout<<"******************************************************************"<<endl;
            gotoxy (15,4);
            cout<<"             "<<name_uno<<" GANASTE LA PARTIDA CON "<<ptosJugUno<<" PUNTOS             "<<endl;
            gotoxy (15,6);
            cout<<"      "<<name_dos<<" BIEN JUGADO TERMINASTE LA PARTIDA CON "<<ptosJugDos<<" PUNTOS      "<<endl;
            gotoxy (15,8);
            cout<<"******************************************************************"<<endl;
        }else{
            if(ptosJugDos>ptosJugUno){
                gotoxy (15,2);
                cout<<"******************************************************************"<<endl;
                gotoxy (15,4);
                cout<<"             "<<name_dos<<" GANASTE LA PARTIDA CON "<<ptosJugDos<<" PUNTOS             "<<endl;
                gotoxy (15,6);
                cout<<"      "<<name_uno<<" BIEN JUGADO TERMINASTE LA PARTIDA CON "<<ptosJugUno<<" PUNTOS      "<<endl;
                gotoxy (15,8);
               cout<<"******************************************************************"<<endl;
            }else{
                 gotoxy (15,2);
               cout<<"******************************************************************"<<endl;
                gotoxy (15,4);
                cout<<"               "<<"HAN EMPATADO CON UN TOTAL DE: "<<ptosJugDos<<" PUNTOS               "<<endl;
                gotoxy (15,8);
                cout<<"******************************************************************"<<endl;
            }
        }
        gotoxy (1,10);
        system("pause");
        system("cls");
        cout<<"Desean jugar de nuevo? S/N: ";
        cin>>jugar;
        rlutil::cls();
    }

}
void jugador_uno(int rondas, char name_uno[25], int vPuntosUno[10], int vBanderaUno[10], bool AZAR){

    int dados[5];
    int cant[6], resultado, puntaje;
    gotoxy (1,1);
    cout<<"RONDA NUMERO: "<<rondas<<endl;
    gotoxy(27,2);
    cout<<"------------MODALIDAD DOS JUGADORES------------"<<endl<<endl;
    gotoxy(27,4);
    cout<<"            ES EL TURNO DE "<<name_uno<<endl<<endl;

    bool servida=false;
    tirar_dados(dados, 5, AZAR);
    cant_dados(dados, 5, cant);
    mostrar_cant(cant, 6);
    servida=generala_servida(cant, 6, vBanderaUno);
    if(servida==true){
        rlutil::cls();
        gotoxy(27,3);
        cout<<"GENERALA SERVIDA!! GANASTE LA PARTIDA!!";
        gotoxy(37,5);
        cout<<" EN "<<rondas<<" RONDA/S"<<endl<<endl;
        cuadros_dosjugadores();
        gotoxy(1,10);
        system ("pause");
        system ("cls");
        menu_inicio();
    }
    else{
        tirar_again(dados, 5);
        cant_dados(dados, 5, cant);
        puntaje = jugadas(cant, 6, vBanderaUno, dados);
        cargar_puntajes(vPuntosUno, 10, puntaje);
        gotoxy(1, 15);
        cout<<name_uno<<" Tu puntuacion esta ronda fue de: "<<puntaje<<endl;
        system("pause");
    }

}

void jugador_dos(int rondas, char name_dos[25], int vPuntosDos[10], int vBanderaDos[10], bool AZAR){
    int dados[5];
    int cant[6], resultado, puntaje;
    gotoxy (1,1);
    cout<<"RONDA NUMERO: "<<rondas<<endl;
    gotoxy(27,2);
    cout<<"------------MODALIDAD DOS JUGADORES-----------"<<endl<<endl;
    gotoxy(27,4);
    cout<<"            ES EL TURNO DE "<<name_dos<<endl<<endl;

    int servida=0;
    tirar_dados(dados, 5, AZAR);
    cant_dados(dados, 5, cant);
    mostrar_cant(cant, 6);
    servida=generala_servida(cant, 6, vBanderaDos);
    if(servida==1){
        rlutil::cls();
        gotoxy(27,3);
        cout<<"GENERALA SERVIDA!! GANASTE LA PARTIDA!!";
        gotoxy(37,5);
        cout<<" EN "<<rondas<<" RONDA/S"<<endl<<endl;
        cuadros_dosjugadores();
        gotoxy(1,10);
        system ("pause");
        system ("cls");
        menu_inicio();
    }
    else{
        tirar_again(dados, 5);
        cant_dados(dados, 5, cant);
        puntaje = jugadas(cant, 6, vBanderaDos, dados);
        cargar_puntajes(vPuntosDos, 10, puntaje);
        gotoxy(1, 15);
        cout<<name_dos<<" Tu puntuacion esta ronda fue de: "<<puntaje<<endl;
        system("pause");
    }

}
void un_jugador(){
    const bool AZAR=false;
    char jugar='S';
    while(jugar=='S'|| jugar=='s'){
        int dados[5];
        char name[25];
        int vPuntos[10], cant[6], resultado, puntaje, vBandera[10], rondas=0;
        vPuntajes(vPuntos, 10);
        banderas_jugadas(vBandera, 10);
        gotoxy(27,4);
        cout<<"ELIJA SU NICKNAME: ";
        cuadros();
        gotoxy(46,4);
        cin>>name;
        system("cls");
        gotoxy(27, 4);
        cout<<"------------MODALIDAD UN JUGADOR--------------"<<endl<<endl;;
        while(rondas!=10){
            int servida;
            rondas++;
            cout<<endl;
            cout<<"  RONDA NUMERO:  "<<rondas<<endl;
            cout<<"  JUGADOR:  "<<name<<endl;
            cout << "PUNTAJE:  " << resultado << endl;
            tirar_dados(dados, 5, AZAR);
            cant_dados(dados, 5, cant);
            /*mostrar_cant(cant, 6);*/
            servida=generala_servida(cant, 6, vBandera);
            if(servida==true){
                rlutil::cls();
                gotoxy(27,3);
                cout<<"GENERALA SERVIDA!! GANASTE LA PARTIDA!!";
                gotoxy(37,5);
                cout<<" EN "<<rondas<<" RONDA/S"<<endl<<endl;
                cuadros_dosjugadores();
                gotoxy(1,10);
                cout<<"Desea jugar de nuevo? S/N: ";
                cin>>jugar;
                if(jugar=='S'|| jugar=='s'){
                    system("cls");
                    menu_inicio();
                }
                else {
                        rlutil::cls();
                        abort();
                }
            }
            else{
                gotoxy(4, 15);
                tirar_again(dados, 5);
                cant_dados(dados, 5, cant);
                puntaje = jugadas(cant, 6, vBandera, dados);
                cargar_puntajes(vPuntos, 10, puntaje);
                gotoxy(1,15);
                cout<<"Tu puntuacion esta ronda fue de: "<<puntaje<<endl<<endl;
                resultado = puntaje_total(vPuntos, 10);
                cout<<name<<" TU PUNTAJE ACUMULADO ES: "<<resultado<<endl<<endl;
                system("pause");
                system("cls");
            }
        }
        resultado = puntaje_total(vPuntos, 10, v[]);
        gotoxy(30,3);
        cout<<name<<" TU PUNTAJE TOTAL ES: "<<resultado<<"PUNTOS"<<endl;
        gotoxy(37,5);
        cout<<"    EN "<<rondas<<" RONDAS"<<endl<<endl;
        cuadros_dosjugadores();
        gotoxy(1,10);
        cout<<"Desea jugar de nuevo? S/N: ";
        cin>>jugar;
        system("cls");
    }

}
void mostrar_cant(int cant[], int t){
    for(int i=0; i<t; i++){
        ///cout<<cant[i]<<endl;
    }
}

int cant_dados(int dados[], int t, int cant[]){

    for(int i=0;i<6;i++){
        cant[i]=0;
    }

    for(int i=0; i<t; i++){
        if(dados[i]==1){
            cant[0]++;
        }
        else{
            if(dados[i]==2){
                cant[1]++;
            }
            else{
                if(dados[i]==3){
                    cant[2]++;
                }
                else{
                    if(dados[i]==4){
                        cant[3]++;
                    }
                    else{
                        if(dados[i]==5){
                            cant[4]++;
                        }
                        else{
                            if(dados[i]==6){
                                cant[5]++;
                            }
                        }
                    }
                }
            }
        }
    }
}
///JUGADAS
int jugadas(int cant[], int t, int b[], int dados[]){
    ///GENERALA
    if(b[9]==0){
        for(int i=0;i<t;i++){
            if(cant[i]==5){
                b[9]=1;
                return 50;
            }
        }
    }
    int impar;
    impar = impares (dados, 5);
    if (impar==0){
        return 0;
    }
    ///POKER
    if(b[8]==0){
        for(int i=0;i<t;i++){
            if(cant[i]==4){
                b[8]=1;
                return 40;
            }
        }
    }
    ///FULL
    if(b[7]==0){
        for(int i=0;i<t;i++){
            if(cant[i]==3){
                for(int j=0;j<6;j++){
                    if(cant[j]==2){
                        b[7]=1;
                        return 30;
                    }
                }
            }
        }
    }
    ///ESCALERA
    if(b[6]==0){
        if((cant[0]==0 && cant[5]==1) || (cant[0]==1 && cant[5] == 0)){
            int cont=0;
            for(int i=0;i<t;i++){
                if(cant[i]==1){
                    cont++;
                }
            }
            if(cont==5){
                b[6]=1;
                return 25;
            }
        }
    }
    ///JUGADAS POR NUMERO
    int maxCant=cant[0], numMaxCant=1, puntaje=0;

    for(int i=1; i<6; i++){
        if(b[i]==0){
            if(cant[i]>maxCant){
                maxCant=cant[i];
                numMaxCant=i+1;
            }else{
                if((cant[i]==maxCant)&&(i+1>numMaxCant)){
                    maxCant=cant[i];
                    numMaxCant=i+1;
                }
            }
        }
    }
    if((numMaxCant==6)&&(b[5]==0)){
        puntaje=maxCant*numMaxCant;
        b[5]=1;
        return puntaje;
    }
    else{
        if((numMaxCant==5)&&(b[4]==0)){
            puntaje=maxCant*numMaxCant;
            b[4]=1;
            return puntaje;
        }
        else{
            if((numMaxCant==4)&&(b[3]==0)){
                puntaje=maxCant*numMaxCant;
                b[3]=1;
                return puntaje;
            }
            else{
                if((numMaxCant==3)&&(b[2]==0)){
                    puntaje=maxCant*numMaxCant;
                    b[2]=1;
                    return puntaje;
                }
                else{
                    if((numMaxCant==2)&&(b[1]==0)){
                        puntaje=maxCant*numMaxCant;
                        b[1]=1;
                        return puntaje;
                    }
                    else{
                        if((numMaxCant==1)&&(b[0]==0)){
                            puntaje=maxCant*numMaxCant;
                            b[0]=0;
                            return puntaje;
                        }
                    }
                }
            }
        }
    }
}


int impares (int v[], int t){
    int impar=0, par=0, mayor;
    for (int i=0; i<5; i++){
    if (v[i]%2!=0){
        impar++;
    }
    else par++;
        }
        if (impar>par){
            return 2;
        }
        else return 1;
        }



///pongo el vector puntajes en 0 para poder cargarlo
void vPuntajes(int v[], int t){
    for(int i=0;i<t;i++){
        v[i]=0;
    }
}
///le guardo los puntajes de las jugadas solamente si la posicion del vector es igual a 0.
void cargar_puntajes(int v[], int t, int puntaje){
    for(int i=0; i<t;i++){
        if(v[i]==0){
            v[i]= puntaje;
            return;
        }
    }
}

///Acumulo los puntajes para luego sacar el maximo.
int puntaje_total(int v[], int t, v[]){
    int total=0, multiplico;
    for(int i=0; i<t; i++){
        total+=v[i];
        multiplico= impares (dados, 5);
        total=total*multiplico;
    }
    return total;
}
void banderas_jugadas(int v[], int t){
    for(int i=0; i<10;i++){
        v[i]=0;
    }
}

void tirar_again(int dados[], int t){
    char tirar;
    int tirada=1, cant, dado;
    gotoxy(1, 11);
    cout<<"Desea tirar de nuevo? S/N: ";
    cin>>tirar;
    cout<<endl;
    while((tirar=='s'||tirar=='S')&&(tirada<=2)){
        cout<<endl;
        gotoxy (1, 1);
        cout<<"TIRO NUMERO "<<tirada+1<<endl <<endl;
        gotoxy (1, 14);
        cout<<"CUANTOS DADOS DESEA VOLVER A TIRAR?: ";
        cin>>cant;
        /*system ("cls");*/
        while (cant < 1 || cant >5) {
            for(int i=0; i<t; i++){
                dibujarDado(i+1, dados[i]);
            }
            gotoxy (1, 14);
            cout << "ERROR. DEBES ELEGIR DE 1 A 5." <<endl <<endl << "ELIJA DE NUEVO CUANTOS DADOS DESEA TIRAR: " ;
            cin >>cant;
            system ("cls");
        }
        for(int i=0; i<t; i++){
            dibujarDado(i+1, dados[i]);
        }
        cout<<endl;
        gotoxy (1, 1);
        cout<<"TIRO NUMERO "<<tirada+1<<endl <<endl;
        /*system ("pause");
        system ("cls");*/
        int band[6];
        for(int i=0; i<6; i++){
            band[i]=0;
        }
        for(int i=0;i<cant;i++){
            gotoxy(1, 15+i);
            cout<<"ELIJA UN DADO DEL 1 AL 5 PARA VOLVER A TIRAR: ";
            cin>>dado;
            cout<<endl;
            /*while (dado < 1 || dado >5) {
            cout << "ERROR. DEBES ELEGIR DE 1 A 5." << endl <<endl << "INGRESA DE NUEVO: ";
            cin >> dado;
            }*/
            verificacion(dados, 5, dado, band);
            cout<<endl;
        }
        system("cls");
        for(int i=0; i<t; i++){
            dibujarDado(i+1, dados[i]);
        }
        tirada++;
        if(tirada<3){
            gotoxy(1, 14);
            cout<<"Desea tirar de nuevo? S/N: ";
            cin>>tirar;
        }
    }
}

    void verificacion(int dados[], int t, int dado, int band[]){
    bool bandera=false;
    while(bandera==false){
        if(dado==1){
            if(band[0]==0){
                dados[0]=rand()%6+1;
                bandera=true;
                band[0]=1;
            }
            else{
                while(dado==1){
                    cout<<"ya eligio este dado, elija otro: ";
                    cin>>dado;
                }
            }
        }
        else{
            if(dado==2){
                if(band[1]==0){
                    dados[1]=rand()%6+1;
                    bandera=true;
                    band[1]=1;
                }
                else{
                    while(dado==2){
                        cout<<"ya eligio este dado, elija otro: ";
                        cin>>dado;
                    }
                }
            }
            else{
                if(dado==3){
                    if(band[2]==0){
                        dados[2]=rand()%6+1;
                        bandera=true;
                        band[2]=1;
                    }
                    else{
                        while(dado==3){
                            cout<<"ya eligio este dado, elija otro: ";
                            cin>>dado;
                        }
                    }
                }
                else{
                    if(dado==4){
                        if(band[3]==0){
                            dados[3]=rand()%6+1;
                            bandera=true;
                            band[3]=1;
                        }
                        else{
                            while(dado==4){
                                cout<<"ya eligio este dado, elija otro: ";
                                cin>>dado;
                            }
                        }
                    }
                    else{
                        if(dado==5){
                            if(band[4]==0){
                                dados[4]=rand()%6+1;
                                bandera=true;
                                band[4]=1;
                            }
                            else{
                                while(dado==5){
                                    cout<<"ya eligio este dado, elija otro: ";
                                    cin>>dado;
                                }
                            }
                        }
                        else{
                            while(dado>5||dado<1){
                                cout << "ERROR. DEBES ELEGIR DE 1 A 5." << endl <<endl << "INGRESA DE NUEVO: ";
                                cin >> dado;
                            }
                        }
                    }
                }
            }
        }
    }
}


///
int generala_servida(int cant[], int t, int b[]){
    bool servida=false;
    if(b[9]==0){
        for(int i=0; i<t;i++){
            if(cant[i]==5){
                servida= true;
            }
        }
        return servida;
    }
}

void cuadros(){
    for(int i=1; i<=33; i++){
        gotoxy(i+25,1); cout <<(char)205;
    }
    for(int i=1; i<=33; i++){
        gotoxy(i+25,7);
        cout <<(char)205<<endl;
    }
    for(int i=1; i<=5; i++){
        gotoxy(25,i+1);
        cout <<(char)186 <<endl;
    }
    for(int i=1; i<=5; i++){
        gotoxy(59,i+1);
        cout <<(char)186 <<endl;
    }
}
void cuadros_dosjugadores(){
    for(int i=1; i<=40; i++){
        gotoxy(i+25,1); cout <<(char)205;
    }
    for(int i=1; i<=40; i++){
        gotoxy(i+25,7);
        cout <<(char)205<<endl;
    }
    for(int i=1; i<=5; i++){
        gotoxy(25,i+1);
        cout <<(char)186 <<endl;
    }
    for(int i=1; i<=5; i++){
        gotoxy(66,i+1);
        cout <<(char)186 <<endl;
    }
}
const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐
const char *UI_CROSS = "\xC5"; // 197 - ┼
const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─
const char *UI_HORIZONTAL_LINE_TOP = "\xC1"; // 193 - ┴
const char *UI_HORIZONTAL_LINE_BOTTOM = "\xC2"; // 194 - ┬";
const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │
const char *UI_VERTICAL_LINE_LEFT = "\xC3"; // 195 - ├
const char *UI_VERTICAL_LINE_RIGHT = "\xB4"; // 180 - ┤

void recuadro(int x, int y, int ancho, int alto){
    /// Reemplazar éstos códigos por los de Windows para correr en Windows.
    const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
    const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
    const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
    const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐
    const char *UI_CROSS = "\xC5"; // 197 - ┼
    const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─
    const char *UI_HORIZONTAL_LINE_TOP = "\xC1"; // 193 - ┴
    const char *UI_HORIZONTAL_LINE_BOTTOM = "\xC2"; // 194 - ┬";
    const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │
    const char *UI_VERTICAL_LINE_LEFT = "\xC3"; // 195 - ├
    const char *UI_VERTICAL_LINE_RIGHT = "\xB4"; // 180 - ┤


    /// Borramos el espacio del recuadro
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            setBackgroundColor(5);
            locate(i, j);
            cout << " ";

        }
    }
    setColor(WHITE);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){
        locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;
    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
        locate(x, i);
        cout << UI_VERTICAL_LINE;
        locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    /// Vértices
    locate(x, y);
    cout << UI_TOP_LEFT;
    locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
}

void dibujarDado(int nroDado, int valor){
    const int Y = 5;
    const int ALTO = 4;
    const int INI = 15;
    const int X = INI + (nroDado * 10);
    const int ANCHO = 8;

    /// Ubicaciones del punto
    const int CENTRO_X = X + ANCHO/2;
    const int CENTRO_Y = Y + ALTO/2;
    const int IZQUIERDA = CENTRO_X - 2;
    const int ARRIBA = CENTRO_Y - 1;
    const int DERECHA= CENTRO_X + 2;
    const int ABAJO= CENTRO_Y + 1;


    recuadro(X, Y, ANCHO, ALTO);

    /// Dibujar los puntos
    const char *DOT = "*";

    setColor(WHITE);
    switch(valor){
        case 1:
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 2:
            if (nroDado%2 == 0){
                locate(IZQUIERDA, ARRIBA);
                cout << DOT;
                locate(DERECHA, ABAJO);
                cout << DOT;
            }
            else{
                locate(DERECHA, ARRIBA);
                cout << DOT;
                locate(IZQUIERDA, ABAJO);
                cout << DOT;
            }
        break;
        case 3:
            if (nroDado%2 == 0){
                locate(IZQUIERDA, ARRIBA);
                cout << DOT;
                locate(DERECHA, ABAJO);
                cout << DOT;
            }
            else{
                locate(DERECHA, ARRIBA);
                cout << DOT;
                locate(IZQUIERDA, ABAJO);
                cout << DOT;
            }
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 4:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
        break;
        case 5:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 6:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
            locate(DERECHA, CENTRO_Y);
            cout << DOT;
            locate(IZQUIERDA, CENTRO_Y);
            cout << DOT;
        break;
    }
    resetColor();
    setBackgroundColor(BLACK);
}
