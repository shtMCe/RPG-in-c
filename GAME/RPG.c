#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <locale.h>

/*a próxima biblioteca foi ultilizada depois de pesquisas
para as pausas funcionarem em alguns sistemas operacionais*/
#ifdef _WIN32
    #include <windows.h>
    #define pausa(segundos) Sleep(segundos * 1000)
#else
    #include <unistd.h>
    #define pausa(segundos) sleep(segundos)
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
    int DEFESA;
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

void LUTA ( Inimigo i, Heroi h ) {
    
}

int main() {

    Heroi heroiescolhido;

    heroiescolhido.moedas = 100;

    setlocale(LC_ALL, "");

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

    int ESCOLHA_HEROI;

    do {
        printf("------------------------------\n\n");
        printf("Escolha seu herói:\n");

        EXIBE_HEROIS();
        scanf("%d", &ESCOLHA_HEROI);

    } while (ESCOLHA_HEROI > 3 || ESCOLHA_HEROI < 1);

    printf("Boa escolha guerreiro(a)!\n");

    // ESCOLHA 1 - GAEL
    if (ESCOLHA_HEROI == 1) {
        strcpy(heroiescolhido.NOME, "GAEL");
        heroiescolhido.VIDA = 120;
        heroiescolhido.ATAQUE = 15;
        heroiescolhido.DEFESA = 20;
        strcpy(heroiescolhido.HABILIDADE, "Defesa de anjo");
    }

    // ESCOLHA 2 - LYRA
    else if (ESCOLHA_HEROI == 2) {
        strcpy(heroiescolhido.NOME, "LYRA");
        heroiescolhido.VIDA = 80;
        heroiescolhido.ATAQUE = 25;
        heroiescolhido.DEFESA = 5;
        strcpy(heroiescolhido.HABILIDADE, "Bola de fogo");
    }

    // ESCOLHA 3 - RAVEN
    else if (ESCOLHA_HEROI == 3) {
        strcpy(heroiescolhido.NOME, "RAVEN");
        heroiescolhido.VIDA = 95;
        heroiescolhido.ATAQUE = 20;
        heroiescolhido.DEFESA = 8;
        strcpy(heroiescolhido.HABILIDADE, "Flecha dupla");
    }

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

        printf("------------------------------\n");

        printf("Após essa escolha, veja a situação do seu herói:\n");

        IMPRIME_SITU(heroiescolhido.VIDA, heroiescolhido.moedas);

        printf("------------------------------\n");

        sleep(2);

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
        
        printf("------------------------------\n");
        printf("NÍVEL 1 FINALIZADO\n");
        printf("------------------------------\n\n");
    }

    // ESCOLHA 2 - Floresta Sombria
    else if (ESCOLHA_LUGAR == 2) {
        
        printf("*andando\n");
        printf("*olhando as colinas e as montanhas através de uma fresta da árvore\n");
        sleep(2);
        printf("*quando você volta seu olhar a frente se depara com uma figura...\n");
        printf("%s: 'Uma fada, não sabia que ainda estão aqui após a guerra dorparia'\n", heroiescolhido.NOME);
        sleep(1);
        printf("GENARI: 'Viajante da floresta? Tome cuidado, as criaturas estão rondando hoje'\n");
        printf("------------------------------\n");
        
        int escolha3;
        
        do {
            printf("Qual será sua decisão?\n1- Continuar andando    2- Voltar e escolher outro lugar\n");
            scanf("%d", &escolha3);
            
        } while (escolha3 < 1 || escolha3 > 2);
        
        //continuar andando
        if (escolha3 == 1) {
            printf("*andando\n");
            printf("");
        }
        
        //voltar para escolher outro lugar 
        else {
            printf("*voltando\n");
            printf("*aparece Britus (um monstro com aparência de largato gigante)\n");
            printf("BRITUS: 'ora..ora...ora...se não é o(a) %stodo mundo pode as 14?\n", heroiescolhido.NOME);
            printf("BRITUS: 'já ouvi falar muito sobre você, e agora você está aqui HAHAHA\n'");
            sleep(2);
            printf("BRITUS: 'prepare-se para morrer!\n'");
            printf("------------------------------\n");
            
        }

    }

    // ESCOLHA 3 - Montanha de Ferro
    else if (ESCOLHA_LUGAR == 3) {

    }

    return 0;
}