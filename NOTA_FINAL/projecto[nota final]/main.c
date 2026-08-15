#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos del Método Mosler
typedef struct {
    // Fase 1
    char bien[100];
    char riesgo[100];
    char dano[100];

    // Fase 2 (Criterios del 1 al 5)
    int F; // Criterio de Función
    int S; // Criterio de Sustitución
    int P; // Criterio de Profundidad
    int E; // Criterio de Extensión
    int A; // Criterio de Agresión
    int V; // Criterio de Vulnerabilidad

    // Fase 3 (Cálculos)
    int I;  // Importancia del Suceso (F * S)
    int D;  // Daños Ocasionados (P * E)
    int C;  // Carácter del Riesgo (I + D)
    int Pb; // Probabilidad del Riesgo (A * V)
    int ER; // Cuantificación del Riesgo (C * Pb)

    // Fase 4
    char clasificacion[50];
} MetodoMosler;

// Función para solicitar una nota entre 1 y 5 con validación
int leerCriterio(const char *mensaje) {
    int valor;
    do {
        printf("%s (1 a 5): ", mensaje);
        if (scanf("%d", &valor) != 1) {
            while (getchar() != '\n'); // Limpiar buffer de entrada
            valor = 0;
        }
        if (valor < 1 || valor > 5) {
            printf("  [!] Valor inválido. Debe ingresar un número entero del 1 al 5.\n");
        }
    } while (valor < 1 || valor > 5);
    return valor;
}

// Función para limpiar el búfer después de leer cadenas
void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    MetodoMosler m;

    printf("==================================================\n");
    printf("     GESTIÓN DE RIESGOS - MÉTODO MOSLER           \n");
    printf("==================================================\n\n");

    // ----------------------------------------------------
    // FASE 1: Definición del Riesgo
    // ----------------------------------------------------
    printf("--- FASE 1: DEFINICIÓN DEL RIESGO ---\n");
    printf("Ingrese el Activo / Bien afectado: ");
    fgets(m.bien, sizeof(m.bien), stdin);
    m.bien[strcspn(m.bien, "\n")] = 0;

    printf("Ingrese el Riesgo a analizar: ");
    fgets(m.riesgo, sizeof(m.riesgo), stdin);
    m.riesgo[strcspn(m.riesgo, "\n")] = 0;

    printf("Ingrese la descripción del Daño: ");
    fgets(m.dano, sizeof(m.dano), stdin);
    m.dano[strcspn(m.dano, "\n")] = 0;

    // ----------------------------------------------------
    // FASE 2: Análisis del Riesgo
    // ----------------------------------------------------
    printf("\n--- FASE 2: ANÁLISIS DEL RIESGO (Ponderación 1 a 5) ---\n");
    m.F = leerCriterio("Criterio de Función (F)");
    m.S = leerCriterio("Criterio de Sustitución (S)");
    m.P = leerCriterio("Criterio de Profundidad (P)");
    m.E = leerCriterio("Criterio de Extensión (E)");
    m.A = leerCriterio("Criterio de Agresión (A)");
    m.V = leerCriterio("Criterio de Vulnerabilidad (V)");

    // ----------------------------------------------------
    // FASE 3: Evaluación del Riesgo
    // ----------------------------------------------------
    m.I  = m.F * m.S;
    m.D  = m.P * m.E;
    m.C  = m.I + m.D;
    m.Pb = m.A * m.V;
    m.ER = m.C * m.Pb;

    // ----------------------------------------------------
    // FASE 4: Cálculo y Clasificación del Riesgo
    // ----------------------------------------------------
    if (m.ER <= 250) {
        strcpy(m.clasificacion, "Muy Bajo");
    } else if (m.ER <= 500) {
        strcpy(m.clasificacion, "Pequeño");
    } else if (m.ER <= 750) {
        strcpy(m.clasificacion, "Normal");
    } else if (m.ER <= 1000) {
        strcpy(m.clasificacion, "Grande");
    } else {
        strcpy(m.clasificacion, "Elevado");
    }

    // ----------------------------------------------------
    // MOSTRAR RESULTADOS
    // ----------------------------------------------------
    printf("\n==================================================\n");
    printf("            INFORME FINAL DEL RIESGO              \n");
    printf("==================================================\n");
    printf("Bien / Activo:            %s\n", m.bien);
    printf("Riesgo:                   %s\n", m.riesgo);
    printf("Daño:                     %s\n", m.dano);
    printf("--------------------------------------------------\n");
    printf("Criterios: F=%d | S=%d | P=%d | E=%d | A=%d | V=%d\n",
            m.F, m.S, m.P, m.E, m.A, m.V);
    printf("--------------------------------------------------\n");
    printf("Importancia del Suceso (I = F * S): %d\n", m.I);
    printf("Daños Ocasionados     (D = P * E): %d\n", m.D);
    printf("Carácter del Riesgo   (C = I + D): %d\n", m.C);
    printf("Probabilidad          (Pb = A * V): %d\n", m.Pb);
    printf("--------------------------------------------------\n");
    printf("CUANTIFICACIÓN DEL RIESGO (ER = C * Pb): %d\n", m.ER);
    printf("CLASIFICACIÓN DEL RIESGO:                %s\n", m.clasificacion);
    printf("==================================================\n");

    return 0;
}
