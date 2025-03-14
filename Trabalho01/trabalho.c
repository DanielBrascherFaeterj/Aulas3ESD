#include <stdio.h>
#include <string.h>

#define TAM 5
#define TAM_NOME 64

struct tat{
	int tempo,cod;
	char nome[TAM_NOME];
};
typedef struct tat tAtleta;

void obtemAtleta(int num,  tAtleta *atleta){

	printf("\nDigite o nome do %dº atleta: ",num);
	scanf("%s", &(*atleta).nome);

	printf("\nDigite o código do %dº atleta:",num);
	scanf("%i",& (*atleta).cod);  // (*atleta).cod   pode ser escrito como atleta->cod
	
	printf("\nDigite o tempo do %dº atleta:",num);
	scanf("%i",&atleta->tempo);
	return;
}

tAtleta leAtleta(int num){
	tAtleta atleta;
	printf("\nDigite o código do %dº atleta:",num);
	scanf("%i",&atleta.cod);
	
	printf("\nDigite o tempo do %dº atleta:",num);
	scanf("%i",&atleta.tempo);
	return atleta;
}

int main(void) {
	tAtleta vAtletas[TAM];

	int tempo_horas, tempo_minutos;
	int maiorTempo = -1, qtMaior= 0, contador, op;
	
    
    for(contador=0;contador<TAM;contador++){
        //atleta=leAtleta(contador+1);
        obtemAtleta(contador+1, &vAtletas[contador]);

		horario(vAtletas[contador].tempo,&tempo_horas, &tempo_minutos);
	 	printf("\nTempo do %dº atleta foi %02i:%02ih", contador + 1, tempo_horas,tempo_minutos);

	}

	ordenarAtletasBolha(vAtletas);

	//exibir(vAtletas);

	return 0;
}

int divisaoInteira(int dividendo, int divisor, int* quoc, int*resto){
    
    if (divisor==0)
        if (dividendo==0)
            return -1;
        else
            return 0;
    else{
        *quoc= dividendo/divisor;
        *resto=dividendo%divisor;
        return 1;
    }
    
}

void horario(int tempo, int *horas, int *minutos) {
	divisaoInteira(tempo,60, horas,minutos);
	return;
}

void exibir(tAtleta atleta[]){
	int i;
	for(i=0;i<TAM;i++){
		printf("\n%s\n", atleta[i].nome);
		printf("%d", atleta[i].tempo);
	}
}

void ordenarAtletasBolha(tAtleta atletas[]){
	int i, j;
	tAtleta temp;

	for(i=0;i<TAM-1;i++){
		for(j=0;j<TAM-i-1;j++){
			if(atletas[j].tempo > atletas[j+1].tempo){
				temp = atletas[j];
				atletas[j] = atletas[j+1];
				atletas[j+1] = temp;
			}
			else if(atletas[j].tempo == atletas[j+1].tempo && strcmp(atletas[j].nome, atletas[j+1].nome) > 0){
				temp = atletas[j];
				atletas[j] = atletas[j+1];
				atletas[j+1] = temp;
			}
		}
	}

}
