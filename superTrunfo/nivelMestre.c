#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[100];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularAtributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\n=== CARTA %d ===\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: R$ %.2f\n", carta.pib_per_capita);
}

// Função para exibir o menu de atributos disponíveis
void exibirMenuAtributos(int atributo_excluido) {
    printf("\nATRIBUTOS DISPONÍVEIS PARA COMPARAÇÃO:\n");
    if (atributo_excluido != 1) printf("1 - População\n");
    if (atributo_excluido != 2) printf("2 - Área\n");
    if (atributo_excluido != 3) printf("3 - PIB\n");
    if (atributo_excluido != 4) printf("4 - Pontos Turísticos\n");
    if (atributo_excluido != 5) printf("5 - Densidade Populacional\n");
    if (atributo_excluido != 6) printf("6 - PIB per capita\n");
    printf("0 - Cancelar e voltar\n");
    printf("Escolha um atributo: ");
}

// Função para obter o valor de um atributo específico
float obterValorAtributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontos_turisticos;
        case 5: return carta.densidade_populacional;
        case 6: return carta.pib_per_capita;
        default: return 0;
    }
}

// Função para obter o nome de um atributo
void obterNomeAtributo(int atributo, char *nome, char *unidade) {
    switch(atributo) {
        case 1:
            strcpy(nome, "População");
            strcpy(unidade, "habitantes");
            break;
        case 2:
            strcpy(nome, "Área");
            strcpy(unidade, "km²");
            break;
        case 3:
            strcpy(nome, "PIB");
            strcpy(unidade, "bilhões");
            break;
        case 4:
            strcpy(nome, "Pontos Turísticos");
            strcpy(unidade, "pontos");
            break;
        case 5:
            strcpy(nome, "Densidade Populacional");
            strcpy(unidade, "hab/km²");
            break;
        case 6:
            strcpy(nome, "PIB per capita");
            strcpy(unidade, "reais");
            break;
        default:
            strcpy(nome, "Atributo inválido");
            strcpy(unidade, "");
    }
}

// Função para comparar dois valores de um atributo
// Retorna 1 se o primeiro valor vencer, 2 se o segundo vencer, 0 se empate
int compararAtributo(float valor1, float valor2, int atributo) {
    // Para densidade populacional, menor valor vence
    if (atributo == 5) {
        if (valor1 < valor2) return 1;
        if (valor2 < valor1) return 2;
        return 0;
    }
    // Para outros atributos, maior valor vence
    if (valor1 > valor2) return 1;
    if (valor2 > valor1) return 2;
    return 0;
}

// Função principal para comparar cartas com dois atributos
void compararCartasComDoisAtributos(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    system("clear || cls");
    printf("\n==================================================\n");
    printf("       SUPER TRUNFO - COMPARAÇÃO AVANÇADA\n");
    printf("==================================================\n");
    
    // Obter valores e nomes dos atributos
    float valor1_atr1 = obterValorAtributo(carta1, atributo1);
    float valor2_atr1 = obterValorAtributo(carta2, atributo1);
    float valor1_atr2 = obterValorAtributo(carta1, atributo2);
    float valor2_atr2 = obterValorAtributo(carta2, atributo2);
    
    char nome_atr1[30], unidade_atr1[20];
    char nome_atr2[30], unidade_atr2[20];
    obterNomeAtributo(atributo1, nome_atr1, unidade_atr1);
    obterNomeAtributo(atributo2, nome_atr2, unidade_atr2);
    
    // Comparar cada atributo individualmente
    int resultado_atr1 = compararAtributo(valor1_atr1, valor2_atr1, atributo1);
    int resultado_atr2 = compararAtributo(valor1_atr2, valor2_atr2, atributo2);
    
    // Calcular soma dos atributos para cada carta
    float soma_carta1 = valor1_atr1 + valor1_atr2;
    float soma_carta2 = valor2_atr1 + valor2_atr2;
    
    // Exibir informações das cartas
    printf("\nCarta 1: %s (%s)\n", carta1.nome, carta1.estado);
    printf("  %s: %.2f %s\n", nome_atr1, valor1_atr1, unidade_atr1);
    printf("  %s: %.2f %s\n", nome_atr2, valor1_atr2, unidade_atr2);
    printf("  SOMA: %.2f\n", soma_carta1);
    
    printf("\nCarta 2: %s (%s)\n", carta2.nome, carta2.estado);
    printf("  %s: %.2f %s\n", nome_atr1, valor2_atr1, unidade_atr1);
    printf("  %s: %.2f %s\n", nome_atr2, valor2_atr2, unidade_atr2);
    printf("  SOMA: %.2f\n", soma_carta2);
    
    // Exibir resultados das comparações individuais
    printf("\nRESULTADOS PARCIAIS:\n");
    printf("  %s: %s\n", nome_atr1, 
           resultado_atr1 == 0 ? "Empate!" : 
           resultado_atr1 == 1 ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("  %s: %s\n", nome_atr2, 
           resultado_atr2 == 0 ? "Empate!" : 
           resultado_atr2 == 1 ? "Carta 1 venceu" : "Carta 2 venceu");
    
    // Determinar o vencedor final baseado na soma
    printf("\nRESULTADO FINAL:\n");
    if (soma_carta1 > soma_carta2) {
        printf("  Carta 1 (%s) VENCEU com maior soma de atributos (%.2f > %.2f)\n", 
               carta1.nome, soma_carta1, soma_carta2);
    } else if (soma_carta2 > soma_carta1) {
        printf("  Carta 2 (%s) VENCEU com maior soma de atributos (%.2f > %.2f)\n", 
               carta2.nome, soma_carta2, soma_carta1);
    } else {
        printf("  EMPATE! Ambas as cartas têm a mesma soma de atributos (%.2f)\n", soma_carta1);
    }
    
    printf("\n==================================================\n");
}

// Função para selecionar atributos e realizar a comparação
void selecionarAtributosEComparar(Carta carta1, Carta carta2) {
    int atributo1 = 0, atributo2 = 0;
    
    // Selecionar primeiro atributo
    while (1) {
        system("clear || cls");
        printf("\n=== SELECIONE O PRIMEIRO ATRIBUTO ===\n");
        exibirMenuAtributos(0); // Mostra todos os atributos
        
        if (scanf("%d", &atributo1) != 1) {
            printf("Entrada inválida! Digite um número.\n");
            while(getchar() != '\n'); // Limpa buffer
            continue;
        }
        
        if (atributo1 == 0) return; // Cancelar
        
        if (atributo1 >= 1 && atributo1 <= 6) break;
        
        printf("Opção inválida! Escolha um número entre 1 e 6, ou 0 para cancelar.\n");
    }
    
    // Selecionar segundo atributo (diferente do primeiro)
    while (1) {
        system("clear || cls");
        printf("\n=== SELECIONE O SEGUNDO ATRIBUTO (DIFERENTE DO PRIMEIRO) ===\n");
        exibirMenuAtributos(atributo1); // Exclui o primeiro atributo
        
        if (scanf("%d", &atributo2) != 1) {
            printf("Entrada inválida! Digite um número.\n");
            while(getchar() != '\n'); // Limpa buffer
            continue;
        }
        
        if (atributo2 == 0) return; // Cancelar
        
        if (atributo2 >= 1 && atributo2 <= 6 && atributo2 != atributo1) break;
        
        printf("Opção inválida! Escolha um número entre 1 e 6 (diferente de %d), ou 0 para cancelar.\n", atributo1);
    }
    
    // Realizar a comparação com os dois atributos selecionados
    compararCartasComDoisAtributos(carta1, carta2, atributo1, atributo2);
    
    printf("\nPressione Enter para voltar ao menu principal...");
    while(getchar() != '\n'); // Limpa buffer
    getchar(); // Aguarda Enter
}

// Menu principal
void exibirMenuPrincipal() {
    printf("\nMENU PRINCIPAL - SUPER TRUNFO\n");
    printf("1 - Comparar cartas usando dois atributos\n");
    printf("2 - Exibir cartas novamente\n");
    printf("0 - Sair do jogo\n");
    printf("Escolha uma opção: ");
}

int main() {
    // Declaração das duas cartas para comparação
    Carta carta1, carta2;
    int opcao;
    
    printf("============================================================\n");
    printf("      SUPER TRUNFO - COMPARAÇÃO AVANÇADA (NÍVEL MESTRE)\n");
    printf("============================================================\n");
    
    // === CADASTRO DA CARTA 1 ===
    printf("\nCADASTRANDO CARTA 1:\n");
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "A01");
    strcpy(carta1.nome, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 875.5;
    carta1.pontos_turisticos = 15;
    
    // Calcular atributos derivados da carta 1
    calcularAtributos(&carta1);
    
    // === CADASTRO DA CARTA 2 ===
    printf("\nCADASTRANDO CARTA 2:\n");
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "B02");
    strcpy(carta2.nome, "Rio de Janeiro");
    carta2.populacao = 6000000;
    carta2.area = 1200.27;
    carta2.pib = 400.8;
    carta2.pontos_turisticos = 20;
    
    // Calcular atributos derivados da carta 2
    calcularAtributos(&carta2);
    
    // Exibir as cartas cadastradas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    // Loop principal do menu
    do {
        system("clear || cls");
        exibirMenuPrincipal();
        scanf("%d", &opcao);
        while(getchar() != '\n'); // Limpa buffer
        
        switch(opcao) {
            case 0:
                printf("\nSaindo do jogo...\n");
                break;
            case 1:
                selecionarAtributosEComparar(carta1, carta2);
                break;
            case 2:
                system("clear || cls");
                exibirCarta(carta1, 1);
                exibirCarta(carta2, 2);
                printf("\nPressione Enter para voltar ao menu principal...");
                getchar();
                break;
            default:
                printf("\nOpção inválida! Por favor, escolha 0, 1 ou 2.\n");
                printf("\nPressione Enter para continuar...");
                getchar();
        }
    } while (opcao != 0);
    
    printf("\n============================================================\n");
    printf("       Obrigado por jogar Super Trunfo!\n");
    printf("============================================================\n");
    
    return 0;
}