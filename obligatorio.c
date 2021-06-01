#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearBuffer() {
    while(getchar() != '\n');
}

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
    printf("\n");
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
    int coin = rand()%2; //Variable que simula el giro de una coin con 2 resultados aleatorios posibles
    int xA = 0, yA = 9, xB = 9, yB = 0, xJug, yJug; //Posiciones de jugadores A, B y generico
    char comando; //Comando ingresado
    char bosque[10][10]; //Tablero de juego
    char jugador; //Jugador activo

    //Se colocan 10 arboles al azar
    //(Los arboles estan representados por los '0')

    generarBosque(bosque);
    
    //Inicializo a los jugadores A y B en sus posiciones iniciales
    
    posicionarJugadores(bosque);

    //Bucle del juego
    do { 
        //Imprimo el tablero de juego
        reloadBosque(bosque);

        //Simulo el giro de una coin para asignar turno aleatoriamente al jugador que va a iniciar el juego
        if(coin%2 == 0){
			jugador = 'A';
            xJug = xA;
            yJug = yA;
		}
		else{
			jugador = 'B';
            xJug = xB;
            yJug = yB;
		}

        printf("\nJuega %c", jugador);
        printf("\n(M)over o (T)irar flecha? (Tiro aun sin implementar): ");

        comando = getchar();
        clearBuffer();

        //Verificar que el comando sea valido
        if(comando != 'M' && comando != 'm' && comando != 'T' && comando != 't') {
            printf("\n\nComando invalido, intente de nuevo");
        }
        else if(comando == 'M' || comando == 'm') {

            //Consulta para donde desea mover el jugador
            printf("\nDireccion: (N)orte, (S)ur, (E)ste, (O)este?: ");

            comando = getchar();
            clearBuffer();

            //Verifica que el comando sea valido
			if(comando != 'N' && comando != 'n' && comando != 'S' && comando != 's' && comando != 'E' && comando != 'e' && comando != 'O' && comando != 'o') {
				printf("\n\nComando invalido, intente de nuevo");
			}
            else {
                switch (comando) {
                    case 'N':
					case 'n':
						if(yJug == 0 || bosque[xJug][yJug - 1] == '0' || bosque[xJug][yJug - 1] == 'A' || bosque[xJug][yJug - 1] == 'B'){
							printf("\nMovimiento invalido, intente de nuevo");
						}
						else{
							bosque[xJug][yJug - 1] = jugador;
							bosque[xJug][yJug] = ' ';
							yJug--;
							coin++;
						}
						break;
					case 'S':
					case 's':
						if(yJug == 9 || bosque[xJug][yJug + 1] == '0' || bosque[xJug][yJug + 1] == 'A' || bosque[xJug][yJug + 1] == 'B'){
							printf("\nMovimiento invalido, intente de nuevo");
						}
						else{
							bosque[xJug][yJug + 1] = jugador;
							bosque[xJug][yJug] = ' ';
							yJug++;
							coin++;
						}
						break;
					case 'E':
					case 'e':
						if(xJug == 9 || bosque[xJug + 1][yJug] == '0' || bosque[xJug + 1][yJug] == 'A' || bosque[xJug + 1][yJug] == 'B'){
							printf("\nMovimiento invalido, intente de nuevo");
						}
						else{
							bosque[xJug + 1][yJug] = jugador;
							bosque[xJug][yJug] = ' ';
							xJug++;
							coin++;
						}
						break;
					case 'O':
					case 'o':
						if(xJug == 0 || bosque[xJug - 1][yJug] == '0' || bosque[xJug - 1][yJug] == 'A' || bosque[xJug - 1][yJug] == 'B'){
							printf("\nMovimiento invalido, intente de nuevo");
						}	
						else{
							bosque[xJug - 1][yJug] = jugador;
							bosque[xJug][yJug] = ' ';
							xJug--;
							coin++;
						}
						break;
                }
                //Actualizar posicion de jugadores
                switch(jugador) {
					case 'A':
						xA = xJug;
						yA = yJug;
					break;
					case 'B':
						xB = xJug;
						yB = yJug;
					break;
				}
            }//(Fin else que ejecuta el movimiento)
        }
        
    }
    while(vidaA == 1 && vidaB == 1);

    return 0;
}