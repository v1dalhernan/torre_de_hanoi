
//#include "pch.h"
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>//usada para convertir string a entero (atoi)
#include <ctime>//fecha del sistema
#include <math.h>// libreria usada para calcular un exponente
#include<windows.h> // para el decanzo de la Pc, también sirve para demorar el proceso 
using namespace std;

string auxiliar_de_movimiento = "";// guarda los movimientos realizados en el pop para poder ser agregados en la pila de respaurar_movimiento
int contador_de_movimientos = 0;// cuanta en cuantos movimientos el ususario resuleve el puzle
int codigo = 0; //define el error a la hora de mover
bool reset_ = false;//activa el protocolo de resteado del programa pararegresar al menu principal
//estructura de la pila
int hanoi[] = { 9,8,7,6,5,4,3,2,1 };//columna a
int hanoi1[] = { 9,0,0,0,0,0,0,0,0 };//columna b
int hanoi2[] = { 9,0,0,0,0,0,0,0,0 };//columna c

//pila donde se guarda los movimientos que se hicieron(max 2)
string restaurar_movimiento[3][2] = {
	{"0","0"},
	{"0","0"},
	{"0","0"},

};

int tope = 8;//indica hasta donde se dibujara el tablero y el numero max de fichas a usar
int toped = 8;//tope de la columna a
int toped4 = 0;//tope de la funcion que permite regresar el movimiento
int toped1 = 0;//tope de la columna b
int toped2 = 0;//tope de la columna c
bool n = true;//ayuda para definir el toped y el tope
int control_hanoi = 4;//define la columna elegida para poder mover
int variable_auxiliar = 0;//almacena la ficha que se esta moviendo


int disc = 0; // discos de la recusividad que permite que se muevan las fichas 


///////////////////////funciones para el movimiento del las piezas///////////////////////////////////////

//esta funcion evalua si el insertar la ficha en la posicion deseada es valida o no

void push(string elegir_cola) {

	if ((elegir_cola == "a" || elegir_cola == "A") && ((hanoi[toped]) > variable_auxiliar) && (variable_auxiliar != 0)) {
		toped++;
		hanoi[toped] = variable_auxiliar;
		variable_auxiliar = 0;

	}
	else if ((elegir_cola == "b" || elegir_cola == "B") && ((hanoi1[toped1]) >= variable_auxiliar) && (variable_auxiliar != 0)) {
		toped1++;
		hanoi1[toped1] = variable_auxiliar;
		variable_auxiliar = 0;

	}
	else if ((elegir_cola == "c" || elegir_cola == "C") && ((hanoi2[toped2]) >= variable_auxiliar) && (variable_auxiliar != 0)) {
		toped2++;
		hanoi2[toped2] = variable_auxiliar;
		variable_auxiliar = 0;

	}
	else {
		codigo = 5;

	}

}
// esta funcion estrae de la pila la ficha que deseamos mover (si esta vacia la pila nos dara un error)
void pop(string elegir_cola) {
	variable_auxiliar = 0;
	if ((elegir_cola == "a" || elegir_cola == "A") && toped != 0) {
		variable_auxiliar = hanoi[toped];
		hanoi[toped] = 0;
		--toped;
	}
	else if ((elegir_cola == "b" || elegir_cola == "B") && toped1 != 0) {
		variable_auxiliar = hanoi1[toped1];
		hanoi1[toped1] = 0;
		--toped1;
	}
	else if ((elegir_cola == "c" || elegir_cola == "C") && (toped2 != 0)) {
		variable_auxiliar = hanoi2[toped2];
		hanoi2[toped2] = 0;
		--toped2;
	}


	else {
		variable_auxiliar = 0;
		codigo = 4;
		//error
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////



//esta matriz es la matris representativa, es decir, los cambios que se realizan en las pilas son reflejados rn esta matriz
//dependiendo del tope los valores que posee esta matriz se ira cambiando
string posibilidad[16][3] = {
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},
	{"         |||         ","         |||         ","         |||         "},


};
//esta funcion se encarga de realizar los cambios en la matriz que vemos arriba
void dibujar_pieza(int tope) {
	//este bucle se repite en funcion del numero de piezas con las que se esta jugando
	//debido a las propiedades del juego el numero de posiciones posibles por fichas es igual
	// 9-(el numero que posee la ficha)
	for (int x = 1; tope >= x; x++) {

		if (hanoi[x] == 8 || hanoi1[x] == 8 || hanoi2[x] == 8) {
			if (hanoi[x] == 8) {
				control_hanoi = 0;
			}
			if (hanoi1[x] == 8) {
				control_hanoi = 1;
			}
			if (hanoi2[x] == 8) {
				control_hanoi = 2;
			}
			if (x == 1) {
				posibilidad[15][control_hanoi] = "|         8         |";
				posibilidad[14][control_hanoi] = "---------------------";
			}

			control_hanoi = 4;

		}
		if (hanoi[x] == 7 || hanoi1[x] == 7 || hanoi2[x] == 7) {
			if (hanoi[x] == 7) {
				control_hanoi = 0;
			}
			if (hanoi1[x] == 7) {
				control_hanoi = 1;
			}
			if (hanoi2[x] == 7) {
				control_hanoi = 2;
			}
			if (x == 1) {
				posibilidad[15][control_hanoi] = "  |       7       |  ";
				posibilidad[14][control_hanoi] = "  -----------------  ";
			}
			else if (x == 2) {
				posibilidad[13][control_hanoi] = "  |       7       |  ";
				posibilidad[12][control_hanoi] = "  -----------------  ";
			}


			control_hanoi = 4;

		}
		if (hanoi[x] == 6 || hanoi1[x] == 6 || hanoi2[x] == 6) {
			if (hanoi[x] == 6) {
				control_hanoi = 0;
			}
			if (hanoi1[x] == 6) {
				control_hanoi = 1;
			}
			if (hanoi2[x] == 6) {
				control_hanoi = 2;
			}
			if (x == 1) {
				posibilidad[15][control_hanoi] = "   |      6      |   ";
				posibilidad[14][control_hanoi] = "   ---------------   ";
			}
			else if (x == 2) {
				posibilidad[13][control_hanoi] = "   |      6      |   ";
				posibilidad[12][control_hanoi] = "   ---------------   ";
			}
			else if (x == 3) {

				posibilidad[11][control_hanoi] = "   |      6      |   ";
				posibilidad[10][control_hanoi] = "   ---------------   ";
			}

			control_hanoi = 4;
		}
		if (hanoi[x] == 5 || hanoi1[x] == 5 || hanoi2[x] == 5) {
			if (hanoi[x] == 5) {
				control_hanoi = 0;
			}
			if (hanoi1[x] == 5) {
				control_hanoi = 1;
			}
			if (hanoi2[x] == 5) {
				control_hanoi = 2;
			}
			if (x == 1) {
				posibilidad[15][control_hanoi] = "    |     5     |    ";
				posibilidad[14][control_hanoi] = "    -------------    ";
			}
			else if (x == 2) {
				posibilidad[13][control_hanoi] = "    |     5     |    ";
				posibilidad[12][control_hanoi] = "    -------------    ";
			}
			else if (x == 3) {
				posibilidad[11][control_hanoi] = "    |     5     |    ";
				posibilidad[10][control_hanoi] = "    -------------    ";
			}
			else if (x == 4) {
				posibilidad[9][control_hanoi] = "    |     5     |    ";
				posibilidad[8][control_hanoi] = "    -------------    ";
			}

			control_hanoi = 4;
		}
		if (hanoi[x] == 4 || hanoi1[x] == 4 || hanoi2[x] == 4) {
			if (hanoi[x] == 4) {
				control_hanoi = 0;
			}
			if (hanoi1[x] == 4) {
				control_hanoi = 1;
			}
			if (hanoi2[x] == 4) {
				control_hanoi = 2;
			}
			if (x == 1) {
				posibilidad[15][control_hanoi] = "     |    4    |     ";
				posibilidad[14][control_hanoi] = "     -----------     ";
			}
			else if (x == 2) {
				posibilidad[13][control_hanoi] = "     |    4    |     ";
				posibilidad[12][control_hanoi] = "     -----------     ";
			}
			else if (x == 3) {
				posibilidad[11][control_hanoi] = "     |    4    |     ";
				posibilidad[10][control_hanoi] = "     -----------     ";
			}
			else if (x == 4) {
				posibilidad[9][control_hanoi] = "     |    4    |     ";
				posibilidad[8][control_hanoi] = "     -----------     ";
			}
			else if (x == 5) {
				posibilidad[7][control_hanoi] = "     |    4    |     ";
				posibilidad[6][control_hanoi] = "     -----------     ";
			}

			control_hanoi = 4;

		}
		if (hanoi[x] == 3 || hanoi1[x] == 3 || hanoi2[x] == 3) {
			if (hanoi[x] == 3) {
				control_hanoi = 0;
			}
			if (hanoi1[x] == 3) {
				control_hanoi = 1;
			}
			if (hanoi2[x] == 3) {
				control_hanoi = 2;
			}
			if (x == 1) {
				posibilidad[15][control_hanoi] = "      |   3   |      ";
				posibilidad[14][control_hanoi] = "      ---------      ";
			}
			else if (x == 2) {
				posibilidad[13][control_hanoi] = "      |   3   |      ";
				posibilidad[12][control_hanoi] = "      ---------      ";
			}
			else if (x == 3) {
				posibilidad[11][control_hanoi] = "      |   3   |      ";
				posibilidad[10][control_hanoi] = "      ---------      ";
			}
			else if (x == 4) {
				posibilidad[9][control_hanoi] = "      |   3   |      ";
				posibilidad[8][control_hanoi] = "      ---------      ";
			}
			else if (x == 5) {
				posibilidad[7][control_hanoi] = "      |   3   |      ";
				posibilidad[6][control_hanoi] = "      ---------      ";
			}
			else if (x == 6) {
				posibilidad[5][control_hanoi] = "      |   3   |      ";
				posibilidad[4][control_hanoi] = "      ---------      ";
			}

			control_hanoi = 4;

		}
		if (hanoi[x] == 2 || hanoi1[x] == 2 || hanoi2[x] == 2) {
			if (hanoi[x] == 2) {
				control_hanoi = 0;
			}
			if (hanoi1[x] == 2) {
				control_hanoi = 1;
			}
			if (hanoi2[x] == 2) {
				control_hanoi = 2;
			}
			if (x == 1) {
				posibilidad[15][control_hanoi] = "       |  2  |       ";
				posibilidad[14][control_hanoi] = "       -------       ";
			}
			else if (x == 2) {
				posibilidad[13][control_hanoi] = "       |  2  |       ";
				posibilidad[12][control_hanoi] = "       -------       ";
			}
			else if (x == 3) {
				posibilidad[11][control_hanoi] = "       |  2  |       ";
				posibilidad[10][control_hanoi] = "       -------       ";
			}
			else if (x == 4) {
				posibilidad[9][control_hanoi] = "       |  2  |       ";
				posibilidad[8][control_hanoi] = "       -------       ";
			}
			else if (x == 5) {
				posibilidad[7][control_hanoi] = "       |  2  |       ";
				posibilidad[6][control_hanoi] = "       -------       ";
			}
			else if (x == 6) {
				posibilidad[5][control_hanoi] = "       |  2  |       ";
				posibilidad[4][control_hanoi] = "       -------       ";
			}
			else if (x == 7) {
				posibilidad[3][control_hanoi] = "       |  2  |       ";
				posibilidad[2][control_hanoi] = "       -------       ";
			}

			control_hanoi = 4;
		}
		if (hanoi[x] == 1 || hanoi1[x] == 1 || hanoi2[x] == 1) {
			if (hanoi[x] == 1) {
				control_hanoi = 0;
			}
			if (hanoi1[x] == 1) {
				control_hanoi = 1;
			}
			if (hanoi2[x] == 1) {
				control_hanoi = 2;
			}
			if (x == 1) {
				posibilidad[15][control_hanoi] = "        | 1 |        ";
				posibilidad[14][control_hanoi] = "        -----        ";
			}
			else if (x == 2) {
				posibilidad[13][control_hanoi] = "        | 1 |        ";
				posibilidad[12][control_hanoi] = "        -----        ";
			}
			else if (x == 3) {
				posibilidad[11][control_hanoi] = "        | 1 |        ";
				posibilidad[10][control_hanoi] = "        -----        ";
			}
			else if (x == 4) {
				posibilidad[9][control_hanoi] = "        | 1 |        ";
				posibilidad[8][control_hanoi] = "        -----        ";
			}
			else if (x == 5) {
				posibilidad[7][control_hanoi] = "        | 1 |        ";
				posibilidad[6][control_hanoi] = "        -----        ";
			}
			else if (x == 6) {
				posibilidad[5][control_hanoi] = "        | 1 |        ";
				posibilidad[4][control_hanoi] = "        -----        ";
			}
			else if (x == 7) {
				posibilidad[3][control_hanoi] = "        | 1 |        ";
				posibilidad[2][control_hanoi] = "        -----        ";
			}
			else if (x == 8) {
				posibilidad[1][control_hanoi] = "        | 1 |        ";
				posibilidad[0][control_hanoi] = "        -----        ";
			}
			control_hanoi = 4;
		}
		if (hanoi[x] == 0 || hanoi1[x] == 0 || hanoi2[x] == 0) {

			if (hanoi[x] == 0) {
				control_hanoi = 0;
				if (x == 1) {
					posibilidad[15][control_hanoi] = "         |||         ";
					posibilidad[14][control_hanoi] = "         |||         ";
				}
				else if (x == 2) {
					posibilidad[13][control_hanoi] = "         |||         ";
					posibilidad[12][control_hanoi] = "         |||         ";
				}
				else if (x == 3) {

					posibilidad[11][control_hanoi] = "         |||         ";
					posibilidad[10][control_hanoi] = "         |||         ";
				}
				else if (x == 4) {
					posibilidad[9][control_hanoi] = "         |||         ";
					posibilidad[8][control_hanoi] = "         |||         ";
				}
				else if (x == 5) {
					posibilidad[7][control_hanoi] = "         |||         ";
					posibilidad[6][control_hanoi] = "         |||         ";
				}
				else if (x == 6) {
					posibilidad[5][control_hanoi] = "         |||         ";
					posibilidad[4][control_hanoi] = "         |||         ";
				}
				else if (x == 7) {
					posibilidad[3][control_hanoi] = "         |||         ";
					posibilidad[2][control_hanoi] = "         |||         ";
				}
				else if (x == 8) {
					posibilidad[1][control_hanoi] = "         |||         ";
					posibilidad[0][control_hanoi] = "         |||         ";
				}
				control_hanoi = 4;
			}
			if (hanoi1[x] == 0) {
				control_hanoi = 1;
				if (x == 1) {
					posibilidad[15][control_hanoi] = "         |||         ";
					posibilidad[14][control_hanoi] = "         |||         ";
				}
				else if (x == 2) {
					posibilidad[13][control_hanoi] = "         |||         ";
					posibilidad[12][control_hanoi] = "         |||         ";
				}
				else if (x == 3) {

					posibilidad[11][control_hanoi] = "         |||         ";
					posibilidad[10][control_hanoi] = "         |||         ";
				}
				else if (x == 4) {
					posibilidad[9][control_hanoi] = "         |||         ";
					posibilidad[8][control_hanoi] = "         |||         ";
				}
				else if (x == 5) {
					posibilidad[7][control_hanoi] = "         |||         ";
					posibilidad[6][control_hanoi] = "         |||         ";
				}
				else if (x == 6) {
					posibilidad[5][control_hanoi] = "         |||         ";
					posibilidad[4][control_hanoi] = "         |||         ";
				}
				else if (x == 7) {
					posibilidad[3][control_hanoi] = "         |||         ";
					posibilidad[2][control_hanoi] = "         |||         ";
				}
				else if (x == 8) {
					posibilidad[1][control_hanoi] = "         |||         ";
					posibilidad[0][control_hanoi] = "         |||         ";
				}
				control_hanoi = 4;
			}
			if (hanoi2[x] == 0) {
				control_hanoi = 2;
				if (x == 1) {
					posibilidad[15][control_hanoi] = "         |||         ";
					posibilidad[14][control_hanoi] = "         |||         ";
				}
				else if (x == 2) {
					posibilidad[13][control_hanoi] = "         |||         ";
					posibilidad[12][control_hanoi] = "         |||         ";
				}
				else if (x == 3) {

					posibilidad[11][control_hanoi] = "         |||         ";
					posibilidad[10][control_hanoi] = "         |||         ";
				}
				else if (x == 4) {
					posibilidad[9][control_hanoi] = "         |||         ";
					posibilidad[8][control_hanoi] = "         |||         ";
				}
				else if (x == 5) {
					posibilidad[7][control_hanoi] = "         |||         ";
					posibilidad[6][control_hanoi] = "         |||         ";
				}
				else if (x == 6) {
					posibilidad[5][control_hanoi] = "         |||         ";
					posibilidad[4][control_hanoi] = "         |||         ";
				}
				else if (x == 7) {
					posibilidad[3][control_hanoi] = "         |||         ";
					posibilidad[2][control_hanoi] = "         |||         ";
				}
				else if (x == 8) {
					posibilidad[1][control_hanoi] = "         |||         ";
					posibilidad[0][control_hanoi] = "         |||         ";
				}
				control_hanoi = 4;
			}

		}
	}
	control_hanoi = 4;

}
//para tablero de puntuaciones

//es esta estructura se guardan los datos de los jugadores
struct tablero {
	string nombre;
	string fecha;
	int puntaje;
}a1[16];


//funcion regresar 2 movimientos atras
//guardar los valores
void regresar_f(string movimiento_de_pop, string push) {
	//esta parte del codigo hace que el al estar  la pila llena(la que guarda los movimientos)
	// se borra el moviento mas antiguo (de forma logica) y se cambia por el ultimo ingresado 
	if (toped4 == 2) {
		restaurar_movimiento[0][0] = restaurar_movimiento[1][0];
		restaurar_movimiento[0][1] = restaurar_movimiento[1][1];
		restaurar_movimiento[1][0] = restaurar_movimiento[2][0];
		restaurar_movimiento[1][1] = restaurar_movimiento[2][1];

		toped4--;
	}
	//se inserta el ultimo movimento
	//se define como moviento hacer un pop y despues un push
	//se guarda de donde viene la ficha y hacia a donde va
	toped4++;
	restaurar_movimiento[toped4][1] = push;
	restaurar_movimiento[toped4][0] = movimiento_de_pop;

}
//hacer el mvimiento
void regresar() {
	//esta funcion es la que permite regresar atras los movimientos hachos
	//funciona haciendo la operacion inversa, es decir, si el usuario hizo pop y luego push
	//esta funcion hace lo contrario siempre y cuando se hallan eho mas de un movimiento y el tope
	//sea diferente de 0
	if ((contador_de_movimientos != 0) && toped4 != 0) {
		pop(restaurar_movimiento[toped4][1]);
		push(restaurar_movimiento[toped4][0]);
		toped4--;
	}
	else {
		codigo = 6;
	}
}

// funcion error

void error() {
	//dependiendo del error producido en el codigo se envia uno de los siguientes mensajes
	cout << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	if (codigo == 1) {
		cout << "la opcion que has elegido no es valida" << endl;
	}
	else if (codigo == 2) {
		cout << "la opcion elegida no es valida" << endl << "debe elegir un numero del 3 al 8" << endl;
	}
	else if (codigo == 3) {
		cout << "la columna que has intentado elegir no existe" << endl;
	}
	else if (codigo == 4) {
		cout << "la columna selecionada esta vacia" << endl;
	}
	else if (codigo == 5) {
		cout << "no se puede colocar una pieza grande sobre una pequenna" << endl;
		cout << "o la celda elegida no existe, por favor revise su entrada" << endl;
	}
	else if (codigo == 6) {
		cout << "para desacer un movimiento debes moverte primero" << endl;
		cout << "recuerde que solo puede retrocerder 2 movimientos" << endl;
	}
	cout << "--------------------------------------------------------" << endl;
	codigo = 0;

}
//esta funcion dibuja lo que esta almacenado en el arreglo de posiblidad

void torre() {
	cout << "\t" << "                       " << posibilidad[0][0] << "                       " << posibilidad[0][1] << "                       " << posibilidad[0][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[1][0] << "                       " << posibilidad[1][1] << "                       " << posibilidad[1][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[2][0] << "                       " << posibilidad[2][1] << "                       " << posibilidad[2][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[3][0] << "                       " << posibilidad[3][1] << "                       " << posibilidad[3][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[4][0] << "                       " << posibilidad[4][1] << "                       " << posibilidad[4][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[5][0] << "                       " << posibilidad[5][1] << "                       " << posibilidad[5][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[6][0] << "                       " << posibilidad[6][1] << "                       " << posibilidad[6][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[7][0] << "                       " << posibilidad[7][1] << "                       " << posibilidad[7][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[8][0] << "                       " << posibilidad[8][1] << "                       " << posibilidad[8][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[9][0] << "                       " << posibilidad[9][1] << "                       " << posibilidad[9][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[10][0] << "                       " << posibilidad[10][1] << "                       " << posibilidad[10][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[11][0] << "                       " << posibilidad[11][1] << "                       " << posibilidad[11][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[12][0] << "                       " << posibilidad[12][1] << "                       " << posibilidad[12][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[13][0] << "                       " << posibilidad[13][1] << "                       " << posibilidad[13][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[14][0] << "                       " << posibilidad[14][1] << "                       " << posibilidad[14][2] << "                       " << endl;
	cout << "\t" << "                       " << posibilidad[15][0] << "                       " << posibilidad[15][1] << "                       " << posibilidad[15][2] << "                       " << endl;
	cout << "\t" << "=============================================================================================================================================================" << endl;
	cout << "\t" << "=============================================================================================================================================================" << endl;
	cout << "\t" << "================================ A ========================================= B ========================================= C ==================================" << endl;
	cout << "\t" << "=============================================================================================================================================================" << endl;
	cout << "\t" << "=============================================================================================================================================================" << endl;

}
//dibujar el titulo del juego
void tablerot(int opcionp) {
	//dependiendo de la opcion elegida personaliza el titulo que se mostrara 
	//hay uno por cada sona del juego
	string hola = "";
	if (opcionp == 1) {
		hola = "nuevo juego";
	}
	else if (opcionp == 2) {
		hola = "automata";
	}
	else if (opcionp == 3) {
		hola = "automata";
	}
	else if (opcionp == 4) {
		hola = "tabla de posiciones";
	}
	cout << "====================================================================== " << hola << " ======================================================================" << endl << endl << endl << endl;
}
//dubujar el tablero
void tablero_de_hanoi(int numero_de_piezas, int piezas) {
	tablerot(piezas);
	if (numero_de_piezas == 3) {
		//esta parte del codigo define cuantas piezas vana ser usadas
		//solo se entra al while una vez (al iniciar el juego)
		while (n) {
			tope = 3;
			toped = 3;
			n = false;

		}

		//dibujo del tablero
		cout << endl << endl;
		dibujar_pieza(tope);
		torre();
	}
	else if (numero_de_piezas == 4) {
		//dibujo del tablero
		while (n) {
			tope = 4;
			toped = 4;
			n = false;
		}

		//dibujo del tablero
		cout << endl << endl;
		dibujar_pieza(tope);
		torre();
	}
	else if (numero_de_piezas == 5) {
		//dibujo del tablero
		while (n) {
			tope = 5;
			toped = 5;
			n = false;
		}

		//dibujo del tablero
		cout << endl << endl;
		dibujar_pieza(tope);
		torre();
	}
	else if (numero_de_piezas == 6) {
		//dibujo del tablero
		while (n) {
			tope = 6;
			toped = 6;
			n = false;
		}

		//dibujo del tablero
		cout << endl << endl;
		dibujar_pieza(tope);
		torre();
	}
	else if (numero_de_piezas == 7) {
		//dibujo del tablero
		while (n) {
			tope = 7;
			toped = 7;
			n = false;
		}

		//dibujo del tablero
		cout << endl << endl;
		dibujar_pieza(tope);
		torre();
	}
	else if (numero_de_piezas == 8) {
		//dibujo del tablero
		while (n) {
			tope = 8;
			toped = 8;
			n = false;
		}

		//dibujo del tablero
		cout << endl << endl;
		dibujar_pieza(tope);
		torre();
	}


}
// Metodo Automata por recursividad
void Recursividad(int num, string A, string C, string B) {
	if (num == 1) {
		system("cls");
		pop(A);
		push(C);
		tablero_de_hanoi(disc, 3);
		Sleep(200);
	}
	else {
		Recursividad(num - 1, A, B, C);
		system("cls");
		pop(A);
		push(C);
		tablero_de_hanoi(disc, 3);
		Sleep(200);
		Recursividad(num - 1, B, C, A);
	}
	// tablero_de_hanoi(num,3);

}
//dibujar el menu de inicio
void menu() {
	cout << "============================================================ torre de hanoi ============================================================" << endl << endl << endl << endl;
	cout << "dijite el numero que corresponde a la opcion deseada" << endl;
	cout << "[1] nuevo juego" << endl;
	cout << "[2] automata (pila)" << endl;
	cout << "[3] automata (recursividad)" << endl;
	cout << "[4] tabla de puntuaciones" << endl;
	cout << "[5] salir" << endl;
}
//regresa todas las variables a su estado inicial
void reset() {
	hanoi[0] = 0;
	hanoi[1] = 0;
	hanoi[2] = 0;
	hanoi[3] = 0;
	hanoi[4] = 0;
	hanoi[5] = 0;
	hanoi[6] = 0;
	hanoi[7] = 0;
	hanoi[8] = 0;
	hanoi1[0] = 9;
	hanoi1[1] = 0;
	hanoi1[2] = 0;
	hanoi1[3] = 0;
	hanoi1[4] = 0;
	hanoi1[5] = 0;
	hanoi1[6] = 0;
	hanoi1[7] = 0;
	hanoi1[8] = 0;
	hanoi2[0] = 9;
	hanoi2[1] = 0;
	hanoi2[2] = 0;
	hanoi2[3] = 0;
	hanoi2[4] = 0;
	hanoi2[5] = 0;
	hanoi2[6] = 0;
	hanoi2[7] = 0;
	hanoi2[8] = 0;
	toped4 = 0;
	restaurar_movimiento[0][0] = "0";
	restaurar_movimiento[0][1] = "0";
	restaurar_movimiento[1][0] = "0";
	restaurar_movimiento[1][1] = "0";
	restaurar_movimiento[2][0] = "0";
	restaurar_movimiento[2][1] = "0";
	auxiliar_de_movimiento = "";

	dibujar_pieza(8);
	hanoi[0] = 9;
	hanoi[1] = 8;
	hanoi[2] = 7;
	hanoi[3] = 6;
	hanoi[4] = 5;
	hanoi[5] = 4;
	hanoi[6] = 3;
	hanoi[7] = 2;
	hanoi[8] = 1;
	n = true;
	toped = 8;
	tope = 8;
	contador_de_movimientos = 0;
	toped1 = 0;
	toped2 = 0;
	control_hanoi = 4;
	variable_auxiliar = 0;
	disc = 0; // Utilizada para la recursividad

}

//permite resolver el juego en forma recursiva(resolucion manual)

void resolver_usuario_recursivo(string elegir_cola,int respuestan,int respuestap) {	

	//si la ficha elegida es correcta
	if (variable_auxiliar != 0) {
				//si no hay error se suma el movimiento y se guarda el movimiento hecho
				if (codigo == 0) {
					auxiliar_de_movimiento = elegir_cola;
					contador_de_movimientos++;
				}
				//si se desa salor
				if (elegir_cola == "salir") {
					reset_ = true;
					
				}
				tablero_de_hanoi(respuestan, respuestap);
				cout << endl << endl;
				cout << "-------------------------------------------------------" << endl;
				cout << "si desea regresar al menu escriba: salir" << endl;
				cout << "-------------------------------------------------------" << endl;


				//si hay un error
				if (codigo != 0) {
					error();

				}
				cout << endl << endl << "inserte la posicion donde se desea mover la ficha: ";
				cin >> elegir_cola;
				push(elegir_cola);
				//si la entada es valida(si es valida variable_auxilar toma el valor de la ficha que se desa mover
				regresar_f(auxiliar_de_movimiento, elegir_cola);
				system("cls");
				resolver_usuario_recursivo(elegir_cola, respuestan, respuestap);
	}
	//mientras el juego aun no este resuleto	
	else if (toped2 < tope) {
		auxiliar_de_movimiento = "";
		//si se escribe salir en cualquier momento del codigo se cerrara este while reseteara todo y
		if (elegir_cola == "salir") {
			reset_ = true;
			tope = 11;
		}
		//se dibuja el tablero de juego
		tablero_de_hanoi(respuestan, respuestap);

		//si se comete un error
		if (codigo != 0) {
			error();
		}
		cout << endl << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "si desea regresar al menu escriba: salir" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "si desea desacer el movimiento anterior escriba: r" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << endl << endl << "eliga la columna donde esta la ficha a mover: ";

		cin >> elegir_cola;
		system("cls");
		//se evalua la entrada para saber si la entrada es valida
		if ((elegir_cola == "a" || elegir_cola == "A") || (elegir_cola == "b" || elegir_cola == "B") || (elegir_cola == "c" || elegir_cola == "C")) {
			pop(elegir_cola);
			
			system("cls");
			resolver_usuario_recursivo( elegir_cola, respuestan, respuestap);
			
			

		}
		//regresar 2 movimientos atras
		if (elegir_cola == "r") {
			system("cls");
			codigo = 0;
			regresar();
			resolver_usuario_recursivo(elegir_cola, respuestan, respuestap);

		}
		//si el usuario desea regresar al menu anterior
		else if (elegir_cola == "salir" || reset_ == true) {
			reset_ = true;
			tope = 11;
		}
		
	}


	else {
		//si se comete un error(si no se cumple significa que el juego acabo)
			if (tope != toped2) {
				codigo = 3;
				resolver_usuario_recursivo(elegir_cola, respuestan, respuestap);
			}
			system("cls");
		}
		
}

//permite calcular el numero optimos de movimientos para resolver la torre de hanoi
//y retoorna el puntaje ontenido en funcion de ello
int calcular_puntaje(int movimientos, int numero_de_discos) {
	int r;
	r = pow(2, numero_de_discos) - 1;
	////se pierde 1000 puntos por cada movimiento mas que el numero maximo de movimientos
	int puntaje = 100000 - 1000 * (movimientos - r);
	return puntaje;
}
void imprimir_tabla_de_puntuaciones(int contador) {

	for (int x = 0; x != 5 + contador; x++) {
		cout << "=======================================================" << endl;
		cout << "\t" << "nombre: " << a1[x].nombre << endl;
		cout << "\t" << "fecha: " << a1[x].fecha << endl;
		cout << "\t" << "puntaje: " << a1[x].puntaje << endl;
		cout << endl << endl;
	}
}

int main() {
	///////////////fecha/////////////////////////////
	char date[10];
	_strdate(date);
	//////////////////////////////////////////////////
	string fecha = date;//se guarda la fecha del dia

	/////////permite blindar(evita que el programa se bugee al introducir letras en lugar de numeros en los menus///////////////
	string respuestap_1;
	string respuestan_1;
	string n_1;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int puntaje_obtenido;
	int respuestap;	//elegir el modo (solo,automata...)
	int respuestan;//elegir el numero de discos
	string elegir_cola;//letra de la torre
	int contador = 0; //(guardar el nombre y el puntaje) provisional
	int elegir_tablerok = 0;//permite elegir entre recursividad o pila
	int n;//permite elegir el numero de discos en las partes de automata
	
	//////////////////valores predefinidos de la estructura////////////////////////////////
	a1[0].nombre = "Saitama";
	a1[0].fecha = "04/23/01";
	a1[0].puntaje = 10000;
	a1[1].nombre = "Yundai";
	a1[1].fecha = "10/06/04";
	a1[1].puntaje = 9000;
	a1[2].nombre = "Yusei";
	a1[2].fecha = "04/02/08";
	a1[2].puntaje = 8000;
	a1[3].nombre = "Yuma";
	a1[3].fecha = "04/11/11";
	a1[3].puntaje = 9000;
	a1[4].nombre = "Yuya";
	a1[4].fecha = "04/06/14";
	a1[4].puntaje = 8700;

	//este while marca el inicio del programa
	while (true) {
		//para evitar ssobrepasar el volumen maximo permitido
		if (contador > 15) {
			contador--;
		}
		system("cls");
		//se dibuja el menu principal
		menu();
		//si se ha cometido un error se activa este if y envia el mensaje correspondiente
		if (codigo != 0) {
			error();
		}
		cout << "[usuario]:";
		cin >> respuestap_1;
		//la respuesta de usuario es trasformada de string a int
		respuestap = atoi(respuestap_1.c_str());
		system("cls");

		//si la respuesta es 1 se activa el juego
		if (respuestap == 1) {
			//se dinja el titulo y se pide el nombre
			tablerot(respuestap);
			cout << endl << endl;
			cout << "escriba su nombre:";
			cin >> a1[contador + 5].nombre;
			a1[contador + 5].fecha = fecha;
			contador++;  //prepara la estructura para agregar el siguiente nombre apenas el juego se reinicie
			system("cls");

			//cuerpo del juego que el usuario juega
			while (true) {
				//ganar o salir
				if (toped2 == tope || reset_ == true) {
					system("cls");
					//ganar
					if (toped2 == tope) {
						puntaje_obtenido = calcular_puntaje(contador_de_movimientos, respuestan);
						a1[contador + 4].puntaje = puntaje_obtenido;
						tablero_de_hanoi(respuestan, respuestap);
						cout << a1[contador + 4].nombre << "  FELICIDADES !!!..." << "has completado el puzle en: " << contador_de_movimientos << " movimientos " << "tu puntaje es de: " << puntaje_obtenido << endl;
						system("pause");
					}
					//salir
					else {
						//se borran los valores ingresados (nombre y demas datos) para evitar errores a la hora de mostar el tablero de puntuaciones
						a1[contador + 4].nombre = "";
						a1[contador + 4].fecha = "";
						a1[contador + 4].puntaje = 0;
						contador--;

					}
					reset_ = false;
					elegir_cola = "";
					reset();
					break;
				}
				else {
					
					
					tablerot(respuestap);
					cout << endl << endl;
					//si se ha cometido un error
					if (codigo != 0) {
						error();
					}
					cout << "elega una de las siguientes opciones:\n[1] pila\n[2] recursivo \n[usuario]: ";
					cin >> elegir_tablerok;
					
					system("cls");
					//si se elege pila
					if (elegir_tablerok == 1) {
						tablerot(respuestap);
						cout << endl << endl;
						//si se ha cometido un error
						if (codigo != 0) {
							error();
						}
						cout << "cuantas piezas va a utilizar(3-8): ";
						cin >> respuestan_1;
						respuestan = atoi(respuestan_1.c_str());
						system("cls");
						if (respuestan > 2 && respuestan < 9) {
							//mientras el juego no este resuelto 
							while (toped2 < tope) {
								auxiliar_de_movimiento = "";
								//si se escribe salir en cualquier momento del codigo se cerrara este while reseteara todo 
								if (elegir_cola == "salir") {
									reset_ = true;
									break;
								}
								//se dibuja el tablero de juego
								tablero_de_hanoi(respuestan, respuestap);

								//si se comete un error
								if (codigo != 0) {
									error();
								}
								cout << endl << endl;
								cout << "-------------------------------------------------------" << endl;
								cout << "si desea regresar al menu escriba: salir" << endl;
								cout << "-------------------------------------------------------" << endl;
								cout << "si desea desacer el movimiento anterior escriba: r" << endl;
								cout << "-------------------------------------------------------" << endl;
								cout << endl << endl << "eliga la columna donde esta la ficha a mover: ";

								cin >> elegir_cola;
								system("cls");
								//se evalua la entrada para saber si la entrada es valida
								if ((elegir_cola == "a" || elegir_cola == "A") || (elegir_cola == "b" || elegir_cola == "B") || (elegir_cola == "c" || elegir_cola == "C")) {
									pop(elegir_cola);
									system("cls");
									//si la entada es valida(si es valida variable_auxilar toma el valor de la ficha que se desa mover
									while (variable_auxiliar != 0) {
										//si no hay error se suma el movimiento y se guarda el movimiento hecho
										if (codigo == 0) {
											auxiliar_de_movimiento = elegir_cola;
											contador_de_movimientos++;
										}
										//si se desa salor
										if (elegir_cola == "salir") {
											reset_ = true;
											break;
										}
										tablero_de_hanoi(respuestan, respuestap);
										cout << endl << endl;
										cout << "-------------------------------------------------------" << endl;
										cout << "si desea regresar al menu escriba: salir" << endl;
										cout << "-------------------------------------------------------" << endl;


										//si hay un error
										if (codigo != 0) {
											error();
										}
										cout << endl << endl << "inserte la posicion donde se desea mover la ficha: ";
										cin >> elegir_cola;
										push(elegir_cola);
										regresar_f(auxiliar_de_movimiento, elegir_cola);
										system("cls");
									}

								}
								//si el usuario desea regresar al menu anterior
								else if (elegir_cola == "salir" || reset_ == true) {
									reset_ = true;
									break;
								}
								//si el jugador sea regresar atras sus movimientos se activa esto
								else if (elegir_cola == "r") {
									codigo = 0;
									regresar();

								}
								else {
									codigo = 3;
								}
								system("cls");
							}
						}
						//si el usuario elige un numero de discos entre 3 y 8
						//lo explicado aqui se aplica a todos los demas discos
						else {

							codigo = 2;
							system("cls");
						}
						

					}
					//si se elige recursividad
					else if (elegir_tablerok == 2) {
						while (true) {
							tablerot(respuestap);
							cout << endl << endl;
							//si se ha cometido un error
							if (codigo != 0) {
								error();
							}
							cout << "cuantas piezas va a utilizar(3-8): ";
							cin >> respuestan_1;
							respuestan = atoi(respuestan_1.c_str());
							system("cls");
							if (respuestan > 2 && respuestan < 9) {
								//juego
								resolver_usuario_recursivo(elegir_cola, respuestan, respuestap);
								break;
							}
							else {

								codigo = 2;
								system("cls");
							}
						}
					}
					else {
						codigo = 1;
						system("cls");
					}
				}
				


			}
		}
		else if (respuestap == 2) {
			//se activa la resolucion automatica con pilas dependiendo del algoritmo interactivo
			//y dependiendo del numero de fichas
			while (true) {

				system("cls");

				tablerot(2);
				if (codigo != 0) {
					error();
				}

				cout << "Los clavijas son A B C\n";
				cout << "Numero de discos (3-8 discos): ";
				cin >> n_1;
				n = atoi(n_1.c_str());
				if (n < 9 && n > 2) {
					system("cls");
					tablero_de_hanoi(n, 2);
					Sleep(200);
					while (true) {
						if (n % 2 == 0) {
							//////////////////////
							while (tope != toped2) {
								system("cls");
								tablero_de_hanoi(n, 2);
								Sleep(200);
								system("cls");
								pop("a");
								push("b");
								if (codigo != 0) {
									push("a");
									pop("b");
									push("a");
									codigo = 0;
								}
								tablero_de_hanoi(n, 2);
								Sleep(200);
								system("cls");
								break;
							}
							///////////////////////
							if (tope == toped2) {
								break;
							}
							/////////////////////
							pop("a");
							push("c");
							if (codigo != 0) {
								push("a");
								pop("c");
								push("a");
								codigo = 0;
							}
							tablero_de_hanoi(n, 2);
							Sleep(200);
							system("cls");
							//////////////////////
							pop("b");
							push("c");
							if (codigo != 0) {
								push("b");
								pop("c");
								push("b");
								codigo = 0;
							}
							tablero_de_hanoi(n, 2);
							Sleep(200);
							system("cls");
						}
						else {

							//////////////////////
							while (tope != toped2) {
								system("cls");
								tablero_de_hanoi(n, 2);
								Sleep(200);
								system("cls");
								pop("a");
								push("c");
								if (codigo != 0) {
									push("a");
									pop("c");
									push("a");
									codigo = 0;
								}
								tablero_de_hanoi(n, 2);
								Sleep(200);
								system("cls");
								break;
							}
							/////////////////////
							if (tope == toped2) {
								break;
							}
							/////////////////////
							pop("a");
							push("b");
							if (codigo != 0) {
								push("a");
								pop("b");
								push("a");
								codigo = 0;
							}
							tablero_de_hanoi(n, 2);
							Sleep(200);
							system("cls");
							//////////////////////
							pop("b");
							push("c");
							if (codigo != 0) {
								push("b");
								pop("c");
								push("b");
								codigo = 0;
							}
							tablero_de_hanoi(n, 2);
							Sleep(200);
							system("cls");
						}
					}
					tablero_de_hanoi(n, 2);
					//espacio para la pila automatica


					system("pause");
					reset();
					break;
				}
				else {
					codigo = 2;
				}
			}
		}
		else if (respuestap == 3) {  // ------------  Recursividad


			while (true) {

				system("cls");
				tablerot(3);
				if (codigo != 0) {
					error();
				}

				cout << "Los clavijas son A B C\n";
				cout << "Numero de discos (3-8 discos): ";
				cin >> n_1;
				n = atoi(n_1.c_str());
				if (n < 9 && n > 2) {
					disc = n;
					tablero_de_hanoi(n, 3);
					Sleep(230);
					Recursividad(n, "A", "C", "B");
					system("pause");
					reset();
					break;
				}
				else {
					codigo = 2;
				}
			}
		}
		else if (respuestap == 4) {
			//se imprime la tabla de puntuacones
			tablerot(4);
			imprimir_tabla_de_puntuaciones(contador);
			system("pause");
		}
		//permite cerrar el juego
		else if (respuestap == 5) {
			break;
		}
		else {

			codigo = 1;
			system("cls");
		}

	}

	return 0;
}

