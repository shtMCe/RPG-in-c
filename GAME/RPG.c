#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*a próxima biblioteca foi ultilizada depois de pesquisas
para as pausas funcionarem em alguns sistemas operacionais*/
#ifdef _WIN32
#include <windows.h>
#define pausa(segundos) Sleep(segundos * 1000)
#else
#include <unistd.h>
#define pausa(segundos) sleep(segundos)
#endif

//após pesquisas descobri que essa funão pode limpar a tela
#ifdef _WIN32
#include <windows.h>
#define pausa(segundos) Sleep(segundos * 1000)

void limparTela() {
	system("cls");
}
#else
#include <unistd.h>

#define pausa(segundos) sleep(segundos)

void limparTela() {
	system("clear");
}
#endif

typedef struct sHeroi {
	char NOME[50];
	int VIDA;
	int ATAQUE;
	int DEFESA;
	char HABILIDADE[100];
	int moedas;
} Heroi;

typedef struct sInimigo {
	char NOME[50];
	int VIDA;
	int ATAQUE;
} Inimigo;

void EXIBE_HEROIS() {

	printf("1 - GAEL, O GUERREIRO\n");
	printf("VIDA: 120\nATAQUE: 15\nDEFESA: 20\n");
	printf("HABILIDADE: Defesa de anjo\n");
	printf("------------------------------\n");

	printf("2 - LYRA, A MAGA\n");
	printf("VIDA: 80\nATAQUE: 25\nDEFESA: 5\n");
	printf("HABILIDADE: Bola de fogo\n");
	printf("------------------------------\n");

	printf("3 - RAVEN, A ARQUEIRA\n");
	printf("VIDA: 95\nATAQUE: 20\nDEFESA: 8\n");
	printf("HABILIDADE: Flecha dupla\n");
	printf("------------------------------\n");
}

void IMPRIME_SITU(int x, int y) {
	printf("VIDA: %d\n", x);
	printf("MOEDAS: %d\n", y);
}

int LUTA ( int vida_inimigo, int ataque_inimigo, int vida_heroi, int ataque_heroi, int defesa_heroi ) {

	if (vida_inimigo > 0) {

		char teclabatalha;

		defesa_heroi *= 0.8;
		ataque_inimigo *= 0.8;
		vida_heroi -= ataque_inimigo;
		vida_inimigo -= ataque_heroi;


		printf("---------HERÓI-----------\n");
		printf("VIDA HERÓI: %d\n", vida_heroi);
		printf("DEFESA HERÓI: %d\n", defesa_heroi);
		printf("------------------------------\n");

		printf("---------INIMIGO-----------\n");
		printf("VIDA INIMIGO: %d\n", vida_inimigo);
		printf("------------------------------\n\n");

		return vida_inimigo;
	}

	else
		return 0;
}

int main() {

	Heroi heroiescolhido;

	Inimigo BRITUS;

	heroiescolhido.moedas = 100;

	setlocale(LC_ALL, "");

	char teclabatalha = '\0';

	int TECLA_INICIO;

	do {
		printf("\n\n------------------------------\n");
		printf("------BEM VINDO AO JOGO-------\n");
		printf("------------------------------\n\n");
		printf("Aperte '1' para começar: ");
		scanf("%d", &TECLA_INICIO);

		if (TECLA_INICIO != 1)
			printf("Tecla inválida, tente novamente\n");

	} while (TECLA_INICIO != 1);

	getchar();

	printf("Há muitos anos existia o Cristal de Dorparia,");
	sleep(2);
	printf("responsável por manter o equilíbrio entre as terras de Eldoria.\n");
	sleep(2);
	printf("Durante a Guerra de Dorparia, o cristal foi destruído em três fragmentos e espalhado pelo mundo.\n");
	sleep(3);
	printf("Agora um antigo senhor das trevas, Malthor, está reunindo esses fragmentos para dominar o reino.\n");
	sleep(3);
	printf("O herói é escolhido para encontrar os três fragmentos antes dele.\nCada mapa guarda um fragmento...\n");
	sleep(3);
	printf("Boa jornada! E não se esqueça: CADA MAPA GUARDA UM FRAGMENTO\n");
	sleep(3);

	limparTela();

	int ESCOLHA_HEROI;

	do {
		printf("------------------------------\n\n");
		printf("Escolha seu herói:\n");

		EXIBE_HEROIS();
		scanf("%d", &ESCOLHA_HEROI);

	} while (ESCOLHA_HEROI > 3 || ESCOLHA_HEROI < 1);

	printf("Boa escolha guerreiro(a)!\n");

	limparTela();

	// ESCOLHA 1 - GAEL
	if (ESCOLHA_HEROI == 1) {
		strcpy(heroiescolhido.NOME, "GAEL");
		heroiescolhido.VIDA = 120;
		heroiescolhido.ATAQUE = 40;
		heroiescolhido.DEFESA = 20;
		strcpy(heroiescolhido.HABILIDADE, "Defesa de anjo");
	}

	// ESCOLHA 2 - LYRA
	else if (ESCOLHA_HEROI == 2) {
		strcpy(heroiescolhido.NOME, "LYRA");
		heroiescolhido.VIDA = 80;
		heroiescolhido.ATAQUE = 45;
		heroiescolhido.DEFESA = 5;
		strcpy(heroiescolhido.HABILIDADE, "Bola de fogo");
	}

	// ESCOLHA 3 - RAVEN
	else if (ESCOLHA_HEROI == 3) {
		strcpy(heroiescolhido.NOME, "RAVEN");
		heroiescolhido.VIDA = 95;
		heroiescolhido.ATAQUE = 38;
		heroiescolhido.DEFESA = 8;
		strcpy(heroiescolhido.HABILIDADE, "Flecha dupla");
	}

	//CRIAÇÃO DO BRITUS (VILÃO FUTURO)
	strcpy(BRITUS.NOME, "BRITUS");
	BRITUS.VIDA = 10;
	BRITUS.ATAQUE = 8;

	int ESCOLHA_LUGAR;

	do {
		printf("------------------------------\n\n");

		printf("Um mundo a explorar...\n");
		printf("1 - Vila Eldoria\n");
		printf("2 - Floresta Sombria\n");
		printf("3 - Montanha de Ferro\n");
		printf("Qual será seu caminho hoje?\n");

		scanf("%d", &ESCOLHA_LUGAR);

	} while (ESCOLHA_LUGAR > 3 || ESCOLHA_LUGAR < 1);

	limparTela();

	// ESCOLHA 1 - Vila Eldoria
	if (ESCOLHA_LUGAR == 1) {

		int escolha1;

		printf("*Andando...*\n");
		sleep(2);

		printf("*Avista uma criança à frente*\n");
		sleep(2);

		printf("CRIANÇA: 'Olá bom moço(a), poderia me ajudar?'\n");

		do {
			printf("Qual sua escolha?\n");
			printf("1 - ajudar\n");
			printf("2 - ignorar\n");
			scanf("%d", &escolha1);

		} while (escolha1 > 2 || escolha1 < 1);

		if (escolha1 == 1) {
			printf("Parabéns!\n");
			printf("Seu herói ganhou 5 moedas\n");
			heroiescolhido.moedas += 5;
			sleep(2);
		}

		else if (escolha1 == 2) {
			printf("Era uma emboscada, assim que você não ajudou a criança...\n");
			printf("Alguns homens apareceram para te roubar.\n");
			printf("Você tentou lutar, mas perdeu 5 de vida e 5 moedas.\n");

			heroiescolhido.moedas -= 5;
			heroiescolhido.VIDA -= 5;
			sleep(2);
		}

		limparTela();

		printf("------------------------------\n");

		printf("Após essa escolha, veja a situação do seu herói:\n");

		IMPRIME_SITU(heroiescolhido.VIDA, heroiescolhido.moedas);

		printf("------------------------------\n");

		sleep(2);

		limparTela();

		printf("*Continuando sua caminhada...*\n");

		printf("%s: 'Estou com fome, vamos procurar algo para comer.'\n",
		       heroiescolhido.NOME);

		printf("Olhando ao redor, percebe uma loja de armas.\n");

		int escolha2;

		do {
			printf("Deseja entrar para comprar alguma arma?\n");
			printf("1 - Sim\n");
			printf("2 - Não\n");

			scanf("%d", &escolha2);

		} while (escolha2 > 2 || escolha2 < 1);

		if (escolha2 == 1) {

			printf("------------------------------\n");
			printf("SEM ARMAS DISPONÍVEIS NO NÍVEL 1!\n");
			printf("------------------------------\n");
		}

		limparTela();

		printf("Ao olhar para os lados, um brilho encontra seu olho.\n");
		sleep(2);
		printf("%s: 'O que será isso?'\n", heroiescolhido.NOME);
		sleep(2);
		printf("*andando em direção ao brilho.\n");
		sleep(2);
		printf("Algo está brilhando...\n");
        sleep(2);
        printf("------------------------------\n");
        printf("✨ VOCÊ ENCONTROU O CRISTAL! ✨\n");
        printf("------------------------------\n");
        
        sleep(2);
		limparTela();
		       
		printf("------------------------------\n");
		printf("NÍVEL 1 FINALIZADO\n");
		printf("------------------------------\n\n");
	}

	// ESCOLHA 2 - Floresta Sombria
	else if (ESCOLHA_LUGAR == 2) {

		printf("*andando\n");
		sleep(2);
		printf("*olhando as colinas e as montanhas através de uma fresta da árvore\n");
		sleep(2);
		printf("*quando você volta seu olhar a frente se depara com uma figura...\n");
		sleep(2);
		printf("%s: 'Uma fada, não sabia que ainda estão aqui após a guerra dorparia'\n", heroiescolhido.NOME);
		sleep(2);
		printf("FADA GENARI: 'Viajante da floresta?'\nFADA GENARI: 'Tome cuidado, as criaturas estão rondando hoje'\n");
		printf("------------------------------\n");

		int escolha3;

		sleep(2);

		do {

			printf("Qual será sua decisão?\n1- Continuar andando    2- Voltar e escolher outro lugar\n");
			scanf("%d", &escolha3);

		} while (escolha3 < 1 || escolha3 > 2);

		limparTela();

		//continuar andando
		if (escolha3 == 1) {
			printf("*andando\n");
			printf("");
			
			//batalha BRITUS
			printf("!!!!!!!!BATALHA!!!!!!!\n\n");
			printf("Aperte uma tecla para batalhar: ");
			getchar();
			scanf("%c", &teclabatalha);
			printf("\n");


			if ( teclabatalha != '\0') {

				while (BRITUS.VIDA > 0) {
					BRITUS.VIDA = LUTA (
					                  BRITUS.VIDA,
					                  BRITUS.ATAQUE,
					                  heroiescolhido.VIDA,
					                  heroiescolhido.ATAQUE,
					                  heroiescolhido.DEFESA);
				}

				if (BRITUS.VIDA <= 0)
					printf("Parabéns %s, você ganhou sua primeira batalha.\n\n", heroiescolhido.NOME);
		}

		//voltar para escolher outro lugar
		else {
			printf("*voltando\n");
			printf("*aparece Britus (um monstro com aparência de uma pedra gigante)\n");
			sleep(2);
			printf("BRITUS: 'ora..ora...ora...se não é o(a) %s'\n", heroiescolhido.NOME);
			sleep(2);
			printf("BRITUS: 'já ouvi falar muito sobre você, e agora você está aqui HAHAHA'\n");
			sleep(2);
			printf("BRITUS: 'prepare-se para morrer!'\n\n");
			sleep(2);
			printf("!!!!!!!!BATALHA!!!!!!!\n\n");
			printf("Aperte uma tecla para batalhar: ");
			getchar();
			scanf("%c", &teclabatalha);
			printf("\n");


			if ( teclabatalha != '\0') {

				while (BRITUS.VIDA > 0) {
					BRITUS.VIDA = LUTA (
					                  BRITUS.VIDA,
					                  BRITUS.ATAQUE,
					                  heroiescolhido.VIDA,
					                  heroiescolhido.ATAQUE,
					                  heroiescolhido.DEFESA);
				}

				if (BRITUS.VIDA <= 0)
					printf("Parabéns %s, você ganhou sua primeira batalha.\n\n", heroiescolhido.NOME);
			}
		}
		
		printf("*algo cai do bolso de BRITUS após sua violenta queda ao chão\n");
		sleep(2);
		printf("*você se aproxima e observa\n");
		sleep(2);
		printf("%s: 'Um saco de balas?'\n", heroiescolhido.NOME);
		sleep(2);
		printf("Porém, ao observar atentamente....\n");
		sleep(2);
		printf("%s: 'O CRISTAL! NÃO POSSO ACREDITAR.\n", heroiescolhido.NOME);
		sleep(2);
        printf("------------------------------\n");
        printf("✨ VOCÊ ENCONTROU O CRISTAL! ✨\n");
        printf("------------------------------\n");

		sleep(3);

		limparTela();

		printf("------FIM DO NÍVEL 1------\n");
	}

	// ESCOLHA 3 - Montanha de Ferro
	else if (ESCOLHA_LUGAR == 3) {

	}

	return 0;
}
