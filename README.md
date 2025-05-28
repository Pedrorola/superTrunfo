# Super Trunfo - Nível Mestre 🃏

## 📋 Índice
- [Descrição do Projeto](#-descrição-do-projeto)
- [Regras do Jogo](#-regras-do-jogo)
- [Como Jogar](#-como-jogar)
- [Atributos](#-atributos)
- [Estratégias](#-estratégias)
- [Execução](#-execução)
- [Estrutura do Código](#-estrutura-do-código)
- [Requisitos](#-requisitos)

## 🎯 Descrição do Projeto
Jogo de cartas "Super Trunfo" implementado em C com sistema avançado de comparação por múltiplos atributos. Versão "Nível Mestre" inclui:

- Comparação por 2 atributos simultâneos
- Menus interativos dinâmicos
- Lógica de soma de atributos
- Tratamento especial para densidade populacional

## 🧩 Regras do Jogo

### Objetivo Principal
**Comparar duas cartas** utilizando dois atributos diferentes e determinar a carta vencedora através da **soma dos valores**.

### Sistema de Pontuação
| Situação | Critério |
|----------|----------|
| Vitória | Maior soma de atributos |
| Empate  | Somas iguais |
| Regra especial | Densidade: menor valor vence |

## 🕹️ Como Jogar

1. **Inicialização**:
   - Sistema exibe automaticamente 2 cartas (São Paulo × Rio)

2. **Seleção de Atributos**:
   ```bash
   === SELECIONE O PRIMEIRO ATRIBUTO ===
   1 - População
   2 - Área
   3 - PIB
   4 - Pontos Turísticos
   5 - Densidade Populacional
   6 - PIB per capita
Comparação:

Atributo 1: Comparação individual

Atributo 2: Comparação individual

Soma: Resultado final

Resultado:

Exibição detalhada dos valores

Comparações parciais

Vencedor final

📊 Atributos
#	Atributo	Unidade	Regra
1	População	hab	Maior vence
2	Área	km²	Maior vence
3	PIB	bilhões R$	Maior vence
4	Pontos Turísticos	pts	Maior vence
5	Densidade Populacional	hab/km²	Menor vence
6	PIB per capita	R$	Maior vence

Dicas:

Priorize atributos onde sua carta tem vantagem clara

Combine um atributo forte com um neutro

Use densidade populacional quando a carta tiver valor baixo

🏗️ Estrutura do Código
Principais Funções
Função	Descrição
calcularAtributos()	Calcula densidade e PIB per capita
exibirCarta()	Mostra dados completos da carta
compararAtributo()	Lógica de comparação individual
selecionarAtributosEComparar()	Gerencia fluxo completo
Variáveis Globais
carta1, carta2: Estruturas com dados das cidades

opcao: Controle do menu principal

⚠️ Requisitos
Mínimos:

GCC ou Clang

Terminal ANSI

Recomendados:

Terminal com suporte a cores

80 colunas no mínimo

📄 Licença
Projeto educacional - livre para uso e modificação

