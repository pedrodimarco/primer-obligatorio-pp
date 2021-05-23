#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int pos1, pos2, cantArboles = 0;
    char bosque[10][10];

    //Se colocan 10 arboles al azar
    //(Los arboles estan representados por los '0')

    while(cantArboles <= 9) {

        pos1 = rand() % 9;
        if(pos1 == 0) {
            pos1++;
        }
        pos2 = rand() % 9;
        if(pos2 == 0) {
            pos2++;
        }
        if(bosque[pos1][pos2] != '0') {
            bosque[pos1][pos2] = '0';
            cantArboles++;
        }
    }
    
    //Inicializo a los jugadores A y B en sus posiciones
    for(pos2 = 0; pos2 <= 9; pos2++) {
		
		for(pos1 = 0; pos1 <= 9; pos1++){
			
            if (pos1 == 0 && pos2 == 9) {
                bosque[pos1][pos2] = 'A';
            } 
            else if (pos1 == 9 && pos2 == 0) {
                bosque[pos1][pos2] = 'B';
            }
			else if(bosque[pos1][pos2] != '0') { 
				bosque[pos1][pos2] = ' ';
			}
		}
	}

    //Imprimo en pantalla el bosque/tablero
    for(pos2 = 0; pos2 <= 9; pos2++) {
		
		for(pos1 = 0; pos1 <= 9; pos1++){ 
            printf("|%c ", bosque[pos1][pos2]);
        }
        printf("|\n");
    }

    return 0;
}