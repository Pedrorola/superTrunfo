#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\nMENU DE ATRIBUTOS PARA COMPARAÇÃO\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per capita\n");
    printf("0 - Sair do jogo\n");
    printf("Escolha o atributo para comparar: ");
}

// Função para comparar cartas baseado no atributo escolhido
void compararCartas(Carta carta1, Carta carta2, int atributo_escolhido) {
    printf("\n==================================================\n");
    printf("COMPARAÇÃO DE CARTAS\n");
    printf("==================================================\n");
    
    // Variáveis para armazenar os valores a serem comparados
    float valor1, valor2;
    char nome_atributo[30];
    char unidade[20];
    int menor_vence = 0; // Flag para indicar se o menor valor vence
    
    // Definir qual atributo será comparado
    switch(atributo_escolhido) {
        case 1: // População
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            strcpy(nome_atributo, "População");
            strcpy(unidade, "habitantes");
            break;
            
        case 2: // Área
            valor1 = carta1.area;
            valor2 = carta2.area;
            strcpy(nome_atributo, "Área");
            strcpy(unidade, "km²");
            break;
            
        case 3: // PIB
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            strcpy(nome_atributo, "PIB");
            strcpy(unidade, "bilhões");
            break;
            
        case 4: // Pontos Turísticos
            valor1 = carta1.pontos_turisticos;
            valor2 = carta2.pontos_turisticos;
            strcpy(nome_atributo, "Pontos Turísticos");
            strcpy(unidade, "pontos");
            break;
            
        case 5: // Densidade Populacional
            valor1 = carta1.densidade_populacional;
            valor2 = carta2.densidade_populacional;
            strcpy(nome_atributo, "Densidade Populacional");
            strcpy(unidade, "hab/km²");
            menor_vence = 1; // Para densidade populacional, menor valor vence
            break;
            
        case 6: // PIB per capita
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            strcpy(nome_atributo, "PIB per capita");
            strcpy(unidade, "reais");
            break;
            
        default:
            printf("Atributo inválido!\n");
            return;
    }
    
    // Exibir a comparação
    printf("Atributo escolhido: %s\n\n", nome_atributo);
    printf("Carta 1 - %s (%s): %.2f %s\n", 
           carta1.nome, carta1.estado, valor1, unidade);
    printf("Carta 2 - %s (%s): %.2f %s\n", 
           carta2.nome, carta2.estado, valor2, unidade);
    
    printf("\n==============================\n");
    printf("RESULTADO:\n");
    printf("==============================\n");
    
    // Determinar o vencedor baseado na regra do atributo
    if (menor_vence) {
        // Para densidade populacional, menor valor vence
        if (valor1 < valor2) {
            printf("Carta 1 (%s) VENCEU!\n", carta1.nome);
            printf("Motivo: Menor %s (%.2f < %.2f)\n", nome_atributo, valor1, valor2);
        } else if (valor2 < valor1) {
            printf("Carta 2 (%s) VENCEU!\n", carta2.nome);
            printf("Motivo: Menor %s (%.2f < %.2f)\n", nome_atributo, valor2, valor1);
        } else {
            printf("EMPATE!\n");
            printf("Motivo: Ambas as cartas têm o mesmo valor de %s (%.2f)\n", 
                   nome_atributo, valor1);
        }
    } else {
        // Para outros atributos, maior valor vence
        if (valor1 > valor2) {
            printf("Carta 1 (%s) VENCEU!\n", carta1.nome);
            printf("Motivo: Maior %s (%.2f > %.2f)\n", nome_atributo, valor1, valor2);
        } else if (valor2 > valor1) {
            printf("Carta 2 (%s) VENCEU!\n", carta2.nome);
            printf("Motivo: Maior %s (%.2f > %.2f)\n", nome_atributo, valor2, valor1);
        } else {
            printf("EMPATE!\n");
            printf("Motivo: Ambas as cartas têm o mesmo valor de %s (%.2f)\n", 
                   nome_atributo, valor1);
        }
    }
}

int main() {
    // Declaração das duas cartas para comparação
    Carta carta1, carta2;
    int opcao;
    
    printf("============================================================\n");
    printf("      SUPER TRUNFO - COMPARAÇÃO DE CARTAS (NÍVEL AVENTUREIRO)\n");
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
    
    // Loop principal do menu interativo
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        // Limpar o buffer de entrada
        while(getchar() != '\n');
        
        switch(opcao) {
            case 0:
                printf("\nSaindo do jogo...\n");
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                compararCartas(carta1, carta2, opcao);
                break;
            default:
                printf("\nOpção inválida! Por favor, escolha uma opção entre 0 e 6.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            system("clear || cls"); // Limpa a tela (funciona em Linux e Windows)
        }
    } while (opcao != 0);
    
    printf("\n============================================================\n");
    printf("       Obrigado por jogar Super Trunfo!\n");
    printf("============================================================\n");
    
    return 0;
}