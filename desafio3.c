#include <stdio.h>
#include <windows.h>
struct Empresa {
    char Produto[50];
    int quantidade;
    char localizacao[100];
    int valor;
};

void main() {
	SetConsoleOutputCP(CP_UTF8);
	struct Empresa empresa1[5] ={
	 {"Cadeira",50, "Armazém A",150.00},
	 {"Mesa",30 , "Galpão A",300.00},
	 {"Computador",20, "Armazém B",1200.00},
	 {"Impressora",10, "Galpão A",500.00},
	 {"Monitor",20, "Armazém B",800.00}
};
    FILE *arquivo = fopen("inventorio.csv", "w");
    if(arquivo == NULL){
    	printf("Erro ao abrir arquivo\n");
    	return 0;
	}
    fprintf(arquivo,"Produto; Quantidade; Localização; Valor Unitário\n");
    for(int i = 0; i < 5; i++)
   fprintf(arquivo, "%s; %d; %s; %d\n", empresa1[i].Produto,empresa1[i].quantidade,empresa1[i].localizacao,empresa1[i].valor);
	fclose(arquivo);
	printf("Arquivo criado com sucesso");
	getch();

}
