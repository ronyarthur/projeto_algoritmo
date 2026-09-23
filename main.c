//INTEGRANTES1. 
// Rony Arthur Meireles Medeiros - RGM 384900212. 
// Mateus Moreira y Moreira Feitosa- RGM 387529053. 
// Petrus Alecsander da Silva Arimatea- RGM 38690497.
//Alexandre Tavares Da Silva Filho RGM- 03811058-0


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funcao1();
void funcao2();
void funcao3();
void funcao4();
void funcao5();

unsigned long long calcularFatorial(int numero);
int buscaBinaria(int vetor[], int n, int elemento);

int main() {
    int opcao;
    srand(time(NULL));

    do {
        printf("\n========================================\n");
        printf("           PROJETO AV01 - C\n");
        printf("========================================\n");
        printf("1 - Contagem de Ocorrencias Distintas\n");
        printf("2 - Analise de Pares em Matriz\n");
        printf("3 - Comparacao de Matrizes 3D\n");
        printf("4 - Processar Vetor\n");
        printf("5 - Busca Binaria em Vetor\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: funcao1(); break;
            case 2: funcao2(); break;
            case 3: funcao3(); break;
            case 4: funcao4(); break;
            case 5: funcao5(); break;
            case 0: printf("\nPrograma encerrado.\n"); break;
            default: printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void funcao1() {
    int n, k, tipoPreenchimento;

    printf("\n========================================\n");
    printf(" FUNCAO 1 - CONTAGEM DE OCORRENCIAS\n");
    printf("========================================\n");

    printf("\nDigite o tamanho do vetor principal: ");
    scanf("%d", &n);
    printf("Digite a quantidade de elementos a buscar: ");
    scanf("%d", &k);

    if (n <= 0 || k <= 0) {
        printf("\nTamanho invalido!\n");
        return;
    }

    int vetor[n];
    int buscados[k];

    printf("\nComo deseja preencher os vetores?\n");
    printf("1 - Manualmente\n");
    printf("2 - Automaticamente (aleatorio)\n");
    printf("Escolha: ");
    scanf("%d", &tipoPreenchimento);

    if (tipoPreenchimento == 1) {
        printf("\n--- VETOR PRINCIPAL ---\n");
        for (int i = 0; i < n; i++) {
            printf("vetor[%d]: ", i);
            scanf("%d", &vetor[i]);
        }

        printf("\n--- ELEMENTOS A SEREM BUSCADOS ---\n");
        for (int i = 0; i < k; i++) {
            printf("buscados[%d]: ", i);
            scanf("%d", &buscados[i]);
        }
    } else if (tipoPreenchimento == 2) {
        for (int i = 0; i < n; i++)
            vetor[i] = rand() % 10;

        for (int i = 0; i < k; i++)
            buscados[i] = rand() % 10;
    } else {
        printf("\nOpcao de preenchimento invalida!\n");
        return;
    }

    printf("\nVetor principal:\n[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("]\n");

    printf("\nElementos buscados:\n[ ");
    for (int i = 0; i < k; i++)
        printf("%d ", buscados[i]);
    printf("]\n");

    int total = 0;

    printf("\n--- RESULTADO ---\n");

    for (int i = 0; i < k; i++) {
        int ocorrencias = 0;

        for (int j = 0; j < n; j++) {
            if (buscados[i] == vetor[j])
                ocorrencias++;
        }

        printf("O numero %d apareceu %d vez(es).\n",
               buscados[i], ocorrencias);

        total += ocorrencias;
    }

    printf("\nTotal de ocorrencias: %d\n", total);
}

void funcao2() {
    int n, tipoPreenchimento, contador = 0;

    printf("\n========================================\n");
    printf(" FUNCAO 2 - ANALISE DE PARES EM MATRIZ\n");
    printf("========================================\n");

    printf("\nDigite o tamanho da matriz (n x n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nTamanho invalido!\n");
        return;
    }

    int matriz[n][n];

    printf("\nComo deseja preencher a matriz?\n");
    printf("1 - Manualmente\n");
    printf("2 - Automaticamente (aleatorio)\n");
    printf("Escolha: ");
    scanf("%d", &tipoPreenchimento);

    if (tipoPreenchimento == 1) {
        printf("\nDigite os valores da matriz:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("matriz[%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
            }
        }
    } else if (tipoPreenchimento == 2) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matriz[i][j] = rand() % 10;
    } else {
        printf("\nOpcao de preenchimento invalida!\n");
        return;
    }

    printf("\nMatriz criada:\n\n");

    for (int i = 0; i < n; i++) {
        printf("[ ");
        for (int j = 0; j < n; j++)
            printf("%3d ", matriz[i][j]);
        printf("]\n");
    }

    printf("\n--- ANALISE ---\n");

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int soma = matriz[i][j] + matriz[j][i];

            printf("A[%d][%d] + A[%d][%d] = %d + %d = %d",
                   i, j, j, i, matriz[i][j], matriz[j][i], soma);

            if (soma % 5 == 0) {
                contador++;
                printf(" -> multiplo de 5");
            }

            printf("\n");
        }
    }

    printf("\nTotal contado: %d\n", contador);
}

void funcao3() {
    int n, tipoPreenchimento;
    long long somaA = 0, somaB = 0;

    printf("\n========================================\n");
    printf(" FUNCAO 3 - COMPARACAO DE MATRIZES 3D\n");
    printf("========================================\n");

    printf("\nDigite o tamanho n dos arranjos (n x n x n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nTamanho invalido!\n");
        return;
    }

    int A[n][n][n];
    int B[n][n][n];

    printf("\nComo deseja preencher os arranjos?\n");
    printf("1 - Manualmente\n");
    printf("2 - Automaticamente (aleatorio)\n");
    printf("Escolha: ");
    scanf("%d", &tipoPreenchimento);

    if (tipoPreenchimento == 1) {
        printf("\n--- PREENCHENDO ARRANJO A ---\n");

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    printf("A[%d][%d][%d]: ", i, j, k);
                    scanf("%d", &A[i][j][k]);
                }

        printf("\n--- PREENCHENDO ARRANJO B ---\n");

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    printf("B[%d][%d][%d]: ", i, j, k);
                    scanf("%d", &B[i][j][k]);
                }
    } else if (tipoPreenchimento == 2) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    A[i][j][k] = rand() % 10;
                    B[i][j][k] = rand() % 10;
                }
    } else {
        printf("\nOpcao de preenchimento invalida!\n");
        return;
    }

    printf("\n========================================\n");
    printf("ARRANJO A\n");
    printf("========================================\n");

    for (int i = 0; i < n; i++) {
        printf("\nCamada %d:\n", i);
        for (int j = 0; j < n; j++) {
            printf("[ ");
            for (int k = 0; k < n; k++)
                printf("%3d ", A[i][j][k]);
            printf("]\n");
        }
    }

    printf("\n========================================\n");
    printf("ARRANJO B\n");
    printf("========================================\n");

    for (int i = 0; i < n; i++) {
        printf("\nCamada %d:\n", i);
        for (int j = 0; j < n; j++) {
            printf("[ ");
            for (int k = 0; k < n; k++)
                printf("%3d ", B[i][j][k]);
            printf("]\n");
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                somaA += A[i][j][k];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                somaB += B[i][j][k];

    printf("\n========================================\n");
    printf("RESULTADO\n");
    printf("========================================\n");

    printf("Soma dos elementos de A: %lld\n", somaA);
    printf("Soma dos elementos de B: %lld\n", somaB);

    if (somaA >= somaB) {
        printf("\nRetorno da funcao: 1\n");
        printf("A soma de A e maior ou igual a soma de B.\n");
    } else {
        printf("\nRetorno da funcao: 0\n");
        printf("A soma de A e menor que a soma de B.\n");
    }
}

unsigned long long calcularFatorial(int numero) {
    unsigned long long fatorial = 1;

    for (int i = 1; i <= numero; i++)
        fatorial = fatorial * i;

    return fatorial;
}

void funcao4() {
    int n, tipoPreenchimento;
    unsigned long long somatorio = 0;

    printf("\n========================================\n");
    printf(" FUNCAO 4 - PROCESSAR VETOR\n");
    printf("========================================\n");

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nTamanho invalido!\n");
        return;
    }

    int vetor[n];

    printf("\nComo deseja preencher o vetor?\n");
    printf("1 - Manualmente\n");
    printf("2 - Automaticamente (aleatorio)\n");
    printf("Escolha: ");
    scanf("%d", &tipoPreenchimento);

    if (tipoPreenchimento == 1) {
        printf("\nDigite os valores do vetor:\n");

        for (int i = 0; i < n; i++) {
            printf("vetor[%d]: ", i);
            scanf("%d", &vetor[i]);
        }
    } else if (tipoPreenchimento == 2) {
        for (int i = 0; i < n; i++)
            vetor[i] = rand() % 11;
    } else {
        printf("\nOpcao de preenchimento invalida!\n");
        return;
    }

    printf("\nVetor criado:\n[ ");

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    printf("]\n");

    printf("\n--- PROCESSAMENTO ---\n");

    for (int i = 0; i < n; i++) {
        if (vetor[i] % 2 == 0) {
            printf("%d e PAR -> soma %d\n", vetor[i], vetor[i]);
            somatorio += vetor[i];
        } else {
            unsigned long long fatorial = calcularFatorial(vetor[i]);

            printf("%d e IMPAR -> %d! = %llu\n",
                   vetor[i], vetor[i], fatorial);

            somatorio += fatorial;
        }
    }

    printf("\n========================================\n");
    printf("RESULTADO\n");
    printf("========================================\n");
    printf("Somatorio final: %llu\n", somatorio);
}

int buscaBinaria(int vetor[], int n, int elemento) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == elemento)
            return 1;

        if (vetor[meio] < elemento)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return 0;
}

void funcao5() {
    int n, tipoPreenchimento, totalEncontrados = 0;

    printf("\n========================================\n");
    printf(" FUNCAO 5 - BUSCA BINARIA EM VETOR\n");
    printf("========================================\n");

    printf("\nDigite o tamanho dos vetores: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nTamanho invalido!\n");
        return;
    }

    int A[n];
    int B[n];

    printf("\nComo deseja preencher os vetores?\n");
    printf("1 - Manualmente\n");
    printf("2 - Automaticamente (aleatorio)\n");
    printf("Escolha: ");
    scanf("%d", &tipoPreenchimento);

    if (tipoPreenchimento == 1) {
        printf("\n--- VETOR A (NAO ORDENADO) ---\n");

        for (int i = 0; i < n; i++) {
            printf("A[%d]: ", i);
            scanf("%d", &A[i]);
        }

        printf("\n--- VETOR B ---\n");
        printf("IMPORTANTE: digite B em ordem crescente.\n\n");

        for (int i = 0; i < n; i++) {
            printf("B[%d]: ", i);
            scanf("%d", &B[i]);
        }
    } else if (tipoPreenchimento == 2) {
        for (int i = 0; i < n; i++)
            A[i] = rand() % 100;

        B[0] = rand() % 10;

        for (int i = 1; i < n; i++)
            B[i] = B[i - 1] + (rand() % 5) + 1;
    } else {
        printf("\nOpcao de preenchimento invalida!\n");
        return;
    }

    printf("\nVetor A:\n[ ");

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("]\n");

    printf("\nVetor B (ordenado):\n[ ");

    for (int i = 0; i < n; i++)
        printf("%d ", B[i]);

    printf("]\n");

    printf("\n--- BUSCAS ---\n");

    for (int i = 0; i < n; i++) {
        int encontrado = buscaBinaria(B, n, A[i]);

        if (encontrado == 1) {
            printf("%d -> ENCONTRADO em B\n", A[i]);
            totalEncontrados++;
        } else {
            printf("%d -> NAO encontrado em B\n", A[i]);
        }
    }

    printf("\n========================================\n");
    printf("RESULTADO\n");
    printf("========================================\n");

    printf("Total de elementos de A encontrados em B: %d\n",
           totalEncontrados);
}
