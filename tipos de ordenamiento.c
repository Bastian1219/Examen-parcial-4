#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ordenamientoInsercion(int arreglo[], int n) 
{
    int i, j, clave;
    for (i = 1; i < n; i++) 
	{
        clave = arreglo[i];
        j = i - 1;

        while (j >= 0 && arreglo[j] > clave) 
		{
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = clave;
    }
}

void ordenamientoBurbuja(int lista[], int n) 
{
    int i, j, temp, bandera;

    for (i = 0; i < n; i++) 
	{
        bandera = 0;
        for (j = 0; j < n - i - 1; j++) 
		{
            if (lista[j] > lista[j + 1]) 
			{
                bandera = 1;
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
        if (bandera == 0) {
            break;
        }
    }
}

void quicksort(int lista[], int primero, int ultimo)
{
	int pivot, i, j, temp;
	if(primero < ultimo)
	{
		pivot = primero;
		i = primero;
		j = ultimo;
		while(i < j)
		{
			while(lista[i] <= lista[pivot] && i <= ultimo){i++;}
			while(lista[j] > lista[pivot] && j >= primero){j--;}
			if(i < j)
			{
				temp = lista[i];
				lista[i] = lista[j];
				lista[j] = temp;
			}
		}
		temp = lista[j];
		lista[j] = lista[pivot];
		lista[pivot] = temp;
		quicksort(lista, primero, j-1);
		quicksort(lista, j+1, ultimo);
	}
}


int main() {
    int n = 10000;
    srand(time(NULL));
    int lista[n];

    clock_t start_time, end_time;
    float elapsed_time;
    float tiempoMasCortoInsercion = -1, tiempoMasLargoInsercion = -1, tiempoPromedioInsercion = 0;
    float tiempoMasCortoBurbuja = -1, tiempoMasLargoBurbuja = -1, tiempoPromedioBurbuja = 0;
    float tiempoMasCortoQuicksort = -1, tiempoMasLargoQuicksort = -1, tiempoPromedioQuicksort = 0;

    for (int ejecucion = 0; ejecucion < 100; ejecucion++) 
	{
        for (int i = 0; i < n; i++) 
		{
            lista[i] = rand() % n;
        }

        
        int listaInsercion[n];
        for (int i = 0; i < n; i++) 
		{
            listaInsercion[i] = lista[i];
        }
        start_time = clock();
        ordenamientoInsercion(listaInsercion, n);
        end_time = clock();
        elapsed_time = ((float)(end_time - start_time) * 1000) / CLOCKS_PER_SEC;
        tiempoPromedioInsercion += elapsed_time;
        if (tiempoMasCortoInsercion == -1 || elapsed_time < tiempoMasCortoInsercion) 
		{
            tiempoMasCortoInsercion = elapsed_time;
        }
        if (tiempoMasLargoInsercion == -1 || elapsed_time > tiempoMasLargoInsercion) 
		{
            tiempoMasLargoInsercion = elapsed_time;
        }

        // Medir tiempo de ordenamiento burbuja
        int listaBurbuja[n];
        for (int i = 0; i < n; i++) 
		{
            listaBurbuja[i] = lista[i];
        }
        start_time = clock();
        ordenamientoBurbuja(listaBurbuja, n);
        end_time = clock();
        elapsed_time = ((float)(end_time - start_time) * 1000) / CLOCKS_PER_SEC;
        tiempoPromedioBurbuja += elapsed_time;
        if (tiempoMasCortoBurbuja == -1 || elapsed_time < tiempoMasCortoBurbuja) 
		{
            tiempoMasCortoBurbuja = elapsed_time;
        }
        if (tiempoMasLargoBurbuja == -1 || elapsed_time > tiempoMasLargoBurbuja) 
		{
            tiempoMasLargoBurbuja = elapsed_time;
        }

        // Medir tiempo de quicksort
        int listaQuicksort[n];
        for (int i = 0; i < n; i++) 
		{
            listaQuicksort[i] = lista[i];
        }
        start_time = clock();
        quicksort(listaQuicksort, 0, n - 1);
        end_time = clock();
        elapsed_time = ((float)(end_time - start_time) * 1000) / CLOCKS_PER_SEC;
        tiempoPromedioQuicksort += elapsed_time;
        if (tiempoMasCortoQuicksort == -1 || elapsed_time < tiempoMasCortoQuicksort) 
		{
            tiempoMasCortoQuicksort = elapsed_time;
        }
        if (tiempoMasLargoQuicksort == -1 || elapsed_time > tiempoMasLargoQuicksort) 
		{
            tiempoMasLargoQuicksort = elapsed_time;
        }
    }

    tiempoPromedioInsercion /= 100;
    tiempoPromedioBurbuja /= 100;
    tiempoPromedioQuicksort /= 100;

    printf("Ordenamiento por Insercion:\n");
    printf("Tiempo mas corto: %f milisegundos\n", tiempoMasCortoInsercion);
    printf("Tiempo promedio: %f milisegundos\n", tiempoPromedioInsercion);
    printf("Tiempo mas largo: %f milisegundos\n\n", tiempoMasLargoInsercion);

    printf("Ordenamiento Burbuja:\n");
    printf("Tiempo mas corto: %f milisegundos\n", tiempoMasCortoBurbuja);
    printf("Tiempo promedio: %f milisegundos\n", tiempoPromedioBurbuja);
    printf("Tiempo mas largo: %f milisegundos\n\n", tiempoMasLargoBurbuja);

    printf("Quicksort:\n");
    printf("Tiempo mas corto: %f milisegundos\n", tiempoMasCortoQuicksort);
    printf("Tiempo promedio: %f milisegundos\n", tiempoPromedioQuicksort);
    printf("Tiempo mas largo: %f milisegundos\n", tiempoMasLargoQuicksort);

    return 0;
}
