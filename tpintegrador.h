#ifndef TPINTEGRADOR_H_INCLUDED
#define TPINTEGRADOR_H_INCLUDED

int menu_inicio();
void un_jugador();
void cuadro_inicio();
///Asigno valores al vector de dados.
void tirar_dados(int [], int, bool);
///Muestro los valores de los dados.
void mostrar_dados(int [], int);
/// Cuento cantidad de dados repetidos para luego elegir jugada.
int cant_dados(int [], int, int []);
///pongo el vector puntajes en 0
void vPuntajes(int [], int);
///asigno los valores de los puntajes
void cargar_puntajes(int [], int, int);
///chequeo que jugada salio
int jugadas(int [], int, int [], int []);
///acumulo todos los valores del vector puntajes
int puntaje_total(int [], int);
///vector de banderas para jugadas
void banderas_jugadas(int [], int);
///volver a tirar?
void tirar_again(int [], int);
///generala servida
int generala_servida(int [], int, int []);
///funcion nombre
char nombre(char, int);
///mostrar cantidades para probar
void mostrar_cant(int [], int);
///cuadro con gotoxy
void cuadros();
///funcion juego para 2 jugadores
void dos_jugadores();
///funcion primer jugador
void jugador_uno(int, char[], int [], int [], bool);
///funcion segundo jugador
void jugador_dos(int, char[], int [], int [], bool);
///cuadros
void cuadros_dosjugadores();
///DIBUJO DE DADOS;
void dibujarDado(int , int);
///
void recuadro(int , int , int , int);
/// VERIFICACION PARA QUE NO SE REPITAN LOS DADOS
void verificacion(int[], int, int, int []);
///IMPARES
int impares (int [], int);






#endif // TPINTEGRADOR_H_INCLUDED
