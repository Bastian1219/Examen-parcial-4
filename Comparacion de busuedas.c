#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50000
#define NUM_EJECUCIONES 100


int busquedaSecuencial(int lista[], int n, int x) 
{
    for (int i = 0; i < n; i++) 
	{
        if (lista[i] == x) 
		{
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(int lista[], int inicio, int fin, int x) 
{
    while (inicio <= fin) 
	{
        int mitad = inicio + (fin - inicio) / 2;

        if (lista[mitad] == x) 
		{
            return mitad;
        }

        if (lista[mitad] < x) 
		{
            inicio = mitad + 1;
        } 
		else 
		{
            fin = mitad - 1;
        }
    }
    return -1;
}


void generarLista(int lista[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        lista[i] = i;
    }
}

int main() {
    srand(time(NULL));

    int lista[ARRAY_SIZE];
    generarLista(lista, ARRAY_SIZE);

    float tiemposSecuencial[NUM_EJECUCIONES];
    float tiemposBinaria[NUM_EJECUCIONES];

    float tiempoMasCortoSecuencial = -1;
    float tiempoMasLargoSecuencial = -1;
    float tiempoPromedioSecuencial = 0;

    float tiempoMasCortoBinaria = -1;
    float tiempoMasLargoBinaria = -1;
    float tiempoPromedioBinaria = 0;

    for (int ejecucion = 0; ejecucion < NUM_EJECUCIONES; ejecucion++) {
        int numeroAleatorio = rand() % ARRAY_SIZE;
        

        clock_t inicioSecuencial = clock();
        int resultadoSecuencial = busquedaSecuencial(lista, ARRAY_SIZE, numeroAleatorio);
        clock_t finSecuencial = clock();
        float tiempoSecuencial = ((float)(finSecuencial - inicioSecuencial) * 1000) / CLOCKS_PER_SEC;

        tiemposSecuencial[ejecucion] = tiempoSecuencial;

        
        if (tiempoMasCortoSecuencial == -1 || tiempoSecuencial < tiempoMasCortoSecuencial) 
		{
            tiempoMasCortoSecuencial = tiempoSecuencial;
        }
        if (tiempoMasLargoSecuencial == -1 || tiempoSecuencial > tiempoMasLargoSecuencial) 
		{
            tiempoMasLargoSecuencial = tiempoSecuencial;
        }
        tiempoPromedioSecuencial += tiempoSecuencial;

        
        clock_t inicioBinaria = clock();
        int resultadoBinaria = busquedaBinaria(lista, 0, ARRAY_SIZE - 1, numeroAleatorio);
        clock_t finBinaria = clock();
        float tiempoBinaria = ((float)(finBinaria - inicioBinaria) * 1000) / CLOCKS_PER_SEC;

        tiemposBinaria[ejecucion] = tiempoBinaria;

        
        if (tiempoMasCortoBinaria == -1 || tiempoBinaria < tiempoMasCortoBinaria) 
		{
            tiempoMasCortoBinaria = tiempoBinaria;
        }
        if (tiempoMasLargoBinaria == -1 || tiempoBinaria > tiempoMasLargoBinaria) 
		{
            tiempoMasLargoBinaria = tiempoBinaria;
        }
        tiempoPromedioBinaria += tiempoBinaria;
        printf("Ejecucion %d - Busqueda Secuencial: %f ms, Busqueda Binaria: %f ms\n", ejecucion + 1, tiempoSecuencial, tiempoBinaria);
    }

    tiempoPromedioSecuencial /= NUM_EJECUCIONES;
    tiempoPromedioBinaria /= NUM_EJECUCIONES;

    
    printf("Busqueda Secuencial:\n");
    printf("Tiempo mas corto: %f ms\n", tiempoMasCortoSecuencial);
    printf("Tiempo promedio: %f ms\n", tiempoPromedioSecuencial);
    printf("Tiempo mas largo: %f ms\n\n", tiempoMasLargoSecuencial);

    printf("Busqueda Binaria:\n");
    printf("Tiempo mas corto: %f ms\n", tiempoMasCortoBinaria);
    printf("Tiempo promedio: %f ms\n", tiempoPromedioBinaria);
    printf("Tiempo mas largo: %f ms\n", tiempoMasLargoBinaria);

    return 0;
}


