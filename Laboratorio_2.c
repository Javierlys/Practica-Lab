#include <stdio.h>
#include <stdlib.h>

void leerPolinomio(int grado, int *polinomio) {
    for (int i = 0; i <= grado; i++) {
        printf("Coeficiente de x^%d: ", i);
        scanf("%d", &polinomio[i]);
    }
}

void sumarPolinomios(int gradoMaximo, int *resultado, int **polinomios, int numPolinomios) {
    for (int i = 0; i < numPolinomios; i++) {
        for (int j = 0; j <= gradoMaximo; j++) {
            resultado[j] += polinomios[i][j];
        }
    }
}

void imprimirPolinomio(int grado, int *polinomio) {
    int primerTermino = 1;
    for (int i = grado; i >= 0; i--) {
        if (polinomio[i] != 0) {
            if (!primerTermino && polinomio[i] > 0) {
                printf(" + ");
            }
            if (i == 0) {
                printf("%d", polinomio[i]);
            } else if (i == 1) {
                printf("%dx", polinomio[i]);
            } else {
                printf("%dx^%d", polinomio[i], i);
            }
            primerTermino = 0;
        }
    }
    printf("\n");
}

void imprimirMatriz(int numPolinomios, int gradoMaximo, int **polinomios) {
    printf("Matriz de coeficientes:\n");
    for (int i = 0; i < numPolinomios; i++) {
        for (int j = 0; j <= gradoMaximo; j++) {
            printf("%d ", polinomios[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numPolinomios, gradoMaximo;

    printf("Ingrese el numero de polinomios: ");
    scanf("%d", &numPolinomios);

    printf("Ingrese el mayor grado aceptado para los polinomios: ");
    scanf("%d", &gradoMaximo);

    // Crear una matriz de coeficientes
    int **polinomios = (int **)malloc(numPolinomios * sizeof(int *));
    for (int i = 0; i < numPolinomios; i++) {
        polinomios[i] = (int *)calloc(gradoMaximo + 1, sizeof(int));
    }

    // Leer los coeficientes de cada polinomio
    for (int i = 0; i < numPolinomios; i++) {
        printf("Ingrese los coeficientes del polinomio %d:\n", i + 1);
        leerPolinomio(gradoMaximo, polinomios[i]);
    }

    // Imprimir la matriz de coeficientes
    imprimirMatriz(numPolinomios, gradoMaximo, polinomios);

    // Crear el polinomio resultado
    int *resultado = (int *)calloc(gradoMaximo + 1, sizeof(int));
    sumarPolinomios(gradoMaximo, resultado, polinomios, numPolinomios);

    // Imprimir el polinomio resultado
    printf("La suma de los polinomios es: ");
    imprimirPolinomio(gradoMaximo, resultado);

    // Liberar la memoria
    for (int i = 0; i < numPolinomios; i++) {
        free(polinomios[i]);
    }
    free(polinomios);
    free(resultado);

    return 0;
}