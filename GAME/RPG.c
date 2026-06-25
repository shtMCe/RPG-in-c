#include <stdio.h>
#include <string.h>

typedef struct sHeroi {
	char NOME[50];
	int VIDA;
	int ATAQUE;
	int DEFESA;
	char HABILIDADE[100];
} Heroi;

typedef struct sInimigo {
	char NOME[50];
	int VIDA;
	int ATAQUE;
	int DEFESA;
} Inimigo;

void EXIBE_HEROIS () {

	printf("1 - GAEL, O GUERREIRO\n");
	printf("VIDA: 120\n ATAQUE: 15\n DEFESA: 20\n");
	printf("HABILIDADE: Defesa de anjo\n");
	printf("------------------------------\n");

	printf("2 - LYRA, A MAGA\n");
	printf("VIDA: 80\n ATAQUE: 25\n DEFESA: 5\n");
	printf("HABILIDADE: Bola de fogo\n");
	printf("------------------------------\n");

	printf("3 - RAVEN, A ARQUEIRA\n");
	printf("VIDA: 95\n ATAQUE: 20\n DEFESA: 8\n");
	printf("HABILIDADE: Flecha dupla\n");
	printf("------------------------------\n");
}


int Batalha ( int vidaHeroi, int defesaHeroi, int ataqueVilao) {
	defesaHeroi *= 0.8;
	vidaHeroi -=  ataqueVilao - defesaHeroi;
	return vidaHeroi;
}

int main () {

	int TECLA_INICIO;

	do {
		printf("\n\n------------------------------\n");
		printf("------BEM VINDO AO JOGO-------\n");
		printf("------------------------------\n\n");
		printf("Aperte '1' para comecar: ");
		scanf("%d", &TECLA_INICIO);

		if (TECLA_INICIO != 1)
			printf("Tecla invalida, tente novamente");

	} while (TECLA_INICIO != 1);

	int ESCOLHA_HEROI;

	do {
		printf("------------------------------\n\n");
		printf("Escolha seu heroi:\n");

		EXIBE_HEROIS();
		scanf("%d", &ESCOLHA_HEROI);

	} while (ESCOLHA_HEROI > 3 || ESCOLHA_HEROI < 1);

	printf("Boa escolha guerreiro!\n");
    
    int ESCOLHA_LUGAR;
    
	do {
		printf("------------------------------\n\n");

		printf("Um mundo a explorar...\n");
		printf("1 - Vila Eldoria\n");
		printf("2 - Floresta Sombria\n");
		printf("3 - Montanha de Ferro\n");
		printf("Qual sera seu caminho hoje?\n");

		scanf("%d", &ESCOLHA_LUGAR);
		
	} while (ESCOLHA_LUGAR > 3 || ESCOLHA_LUGAR < 1);
	
	if (ESCOLHA_LUGAR == 1) {
	    
	}
	else if (ESCOLHA_LUGAR == 2) {
	    
	}
	else if (ESCOLHA_LUGAR == 3) {
	    
	}
	
	
	
	//ESCOLHA 1 - GAEL
	if (ESCOLHA_HEROI == 1) {

	}

	//ESCOLHA 2 - LYRA
	else if (ESCOLHA_HEROI == 2) {

	}

	//ESCOLHA 3 - RAVEN
	else  {

	}


}