#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarBosque(char matriz[10][10]) {

    int pos1, pos2, cantArboles = 0;

    while (cantArboles < 10) {
        pos1 = rand() % 9;
        if(pos1 == 0) {
            pos1++;
        }
        pos2 = rand() % 9;
        if(pos2 == 0) {
            pos2++;
        }
        if(matriz[pos1][pos2] != '0') {
            matriz[pos1][pos2] = '0';
            cantArboles++;
        }
    }
}

void posicionarJugadores(char matriz[10][10]) {

    int pos1, pos2;

	for(pos2 = 0; pos2 <= 9; pos2++) {
		
		for(pos1 = 0; pos1 <= 9; pos1++){
			
            if (pos1 == 0 && pos2 == 9) {
                matriz
			[pos1][pos2] = 'A';
            } 
            else if (pos1 == 9 && pos2 == 0) {
                matriz
			[pos1][pos2] = 'B';
            }
			else if(matriz
		[pos1][pos2] != '0') { 
				matriz
			[pos1][pos2] = ' ';
			}
		}
	}
}

void reloadBosque(char matriz[10][10]) {
    int pos1, pos2;

    for(pos2 = 0; pos2 <= 9; pos2++) {
		
	    for(pos1 = 0; pos1 <= 9; pos1++){ 
            printf("|%c ", matriz[pos1][pos2]);
        }
        printf("|\n");
    }
}

int main() {

    srand(time(NULL));

    int pos1, pos2, cantArboles = 0, vidaA = 1, vidaB = 1;
    int coin = rand()%2; //Variable que simula el giro de una moneda con 2 resultados aleatorios posibles
    char bosque[10][10];
    char jugador;

    //Se colocan 10 arboles al azar
    //(Los arboles estan representados por los '0')

    generarBosque(bosque);
    
    //Inicializo a los jugadores A y B en sus posiciones iniciales
    
    posicionarJugadores(bosque);

    //Bucle del juego
    do { 
        printf("\n");
        
        //Imprimo el tablero de juego
        
        reloadBosque(bosque);

        //Simulo el giro de una moneda para asignar turno aleatoriamente al jugador que va a iniciar el juego
        if(coin%2 == 0){
			jugador = 'A';
		}
		else{
			jugador = 'B';
		}

        printf("\nJuega %c", jugador);
        printf("\n(M)over o (T)irar flecha?: ");
    }
    while(vidaA == 0 || vidaB == 0);

    return 0;
}