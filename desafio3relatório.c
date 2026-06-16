#include <stdio.h>
#include <windows.h>
#include <conio.h>
struct Empresa {
    char Produto[50];
    int quantidade;
    char localizacao[100];
    int valor;
};
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int valorTotal = 0;
    struct Empresa empresa1[5] = {
        {"Cadeira", 50, "Armazem A", 150},
        {"Mesa", 30, "Galpao A", 300},
        {"Computador", 20, "Armazem B", 1200},
        {"Impressora", 10, "Galpao A", 500},
        {"Monitor", 20, "Armazem B", 800}
    };
    FILE *arquivo = fopen("inventorio.csv", "r");
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado\n");
        getch();
        return 0;
    }
    fclose(arquivo);
    printf("Produto\t\tQuantidade\tLocalizacao\tValor\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t\t%d\t\t%s\t%d\n",
               empresa1[i].Produto,
               empresa1[i].quantidade,
               empresa1[i].localizacao,
               empresa1[i].valor);

        valorTotal += empresa1[i].quantidade * empresa1[i].valor;
    }
    printf("\nO valor total do estoque e: %d\n", valorTotal);
    getch();
    return 0;
}
