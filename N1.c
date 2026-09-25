#include <stdio.h>
#include <stdlib.h>

int totalPedidos = 0;
int totalItens = 0;
float faturamentoBruto = 0.0;
float descontosConcedidos = 0.0;
float faturamentoFinal = 0.0;


float somar(float a, float b) { return a + b; }
float subtrair(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) { return a / b; }


float calcularDesconto(float total) {
    if (total >= 100.0) return total * 0.15;
    else if (total >= 60.0) return total * 0.10;
    else if (total >= 30.0) return total * 0.05;
    else return 0.0;
}

void mostrarMenu(void) {
    printf("\n=============================\n");
    printf("         CANTINA UCB\n");
    printf("=============================\n");
    printf("1 - Novo pedido\n");
    printf("2 - Calculadora rapida\n");
    printf("3 - Simular desconto\n");
    printf("4 - Relatorio da sessao\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void cardapio() {
    printf("\n--- CARDAPIO ---\n");
    printf("1 - Sanduiche    | R$ 12.00\n");
    printf("2 - Refrigerante | R$ 6.00\n");
    printf("3 - Suco         | R$ 8.00\n");
    printf("4 - Salgado      | R$ 7.00\n");
    printf("5 - Cafe         | R$ 4.00\n");
}

void novoPedido() {
    char nome_cliente[50];
    int continuar = 1;
    int opcao_cardapio, quantidade;
    int itens_pedido = 0;
    float preco_unitario = 0.0;
    float total_bruto_pedido = 0.0;

    printf("\nDigite o nome do cliente: ");
    scanf(" %49[^\n]", nome_cliente);

    do {
        cardapio();
        printf("Digite o codigo do produto (1 a 5): ");
        scanf("%d", &opcao_cardapio);

        switch (opcao_cardapio) {
            case 1: preco_unitario = 12.00; break;
            case 2: preco_unitario = 6.00; break;
            case 3: preco_unitario = 8.00; break;
            case 4: preco_unitario = 7.00; break;
            case 5: preco_unitario = 4.00; break;
            default:
                printf("\nCodigo invalido! Tente novamente.\n");
                continue;
        }

        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidade);

        if (quantidade <= 0) {
            printf("\nQuantidade invalida! Deve ser maior que zero.\n");
            continue;
        }

        total_bruto_pedido += preco_unitario * quantidade;
        itens_pedido += quantidade;
        printf("Subtotal acumulado: R$ %.2f\n", total_bruto_pedido);

        printf("\nAdicionar outro item? 1-Sim / 0-Nao: ");
        scanf("%d", &continuar);
    } while (continuar == 1);

    if (itens_pedido > 0) {
        float desconto = calcularDesconto(total_bruto_pedido);
        float total_final_pedido = total_bruto_pedido - desconto;

        
        totalPedidos++;
        totalItens += itens_pedido;
        faturamentoBruto += total_bruto_pedido;
        descontosConcedidos += desconto;
        faturamentoFinal += total_final_pedido;

        printf("\n=============================\n");
        printf("      RESUMO DO PEDIDO\n");
        printf("=============================\n");
        printf("Cliente: %s\n", nome_cliente);
        printf("Itens registrados: %d\n", itens_pedido);
        printf("Total bruto: R$ %.2f\n", total_bruto_pedido);
        printf("Desconto:    R$ %.2f\n", desconto);
        printf("Total final: R$ %.2f\n", total_final_pedido);
        printf("=============================\n");
        printf("Pedido registrado com sucesso!\n");
    } else {
        printf("\nNenhum item adicionado. Pedido cancelado.\n");
    }
}

void calculadora() {
    float num1, num2, resultado;
    int opcao_calc;

    printf("\n=== CALCULADORA ===\n");
    printf("1 - Somar\n");
    printf("2 - Subtrair\n");
    printf("3 - Multiplicar\n");
    printf("4 - Dividir\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao_calc);

    if (opcao_calc == 0) {
        printf("\nVoltando...\n");
        return;
    }
    if (opcao_calc < 0 || opcao_calc > 4) {
        printf("\nOpcao invalida!\n");
        return;
    }

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    switch(opcao_calc) {
        case 1:
            resultado = somar(num1, num2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 2:
            resultado = subtrair(num1, num2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 3:
            resultado = multiplicar(num1, num2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 4:
            if (num2 == 0) {
                printf("Nao e possivel dividir por zero!\n");
            } else {
                resultado = dividir(num1, num2);
                printf("Resultado: %.2f\n", resultado);
            }
            break;
    }
}

void simularDesconto() {
    float valor, desconto;
    int faixa = 0;

    printf("\n=== Simular desconto ===\n");
    printf("Valor da compra: ");
    scanf("%f", &valor);

    if (valor < 0) {
        printf("Valor invalido!\n");
        return;
    }

    desconto = calcularDesconto(valor);

    
    if (valor >= 100.0) faixa = 15;
    else if (valor >= 60.0) faixa = 10;
    else if (valor >= 30.0) faixa = 5;

    printf("\nFaixa encontrada: %d%%\n", faixa);
    printf("Desconto: R$ %.2f\n", desconto);
    printf("Valor final: R$ %.2f\n", valor - desconto);
}

void mostrarRelatorio() {
    printf("\n======= RELATORIO =======\n");
    printf("Pedidos realizados: %d\n", totalPedidos);
    printf("Itens vendidos:     %d\n", totalItens);
    printf("Faturamento bruto:  R$ %.2f\n", faturamentoBruto);
    printf("Descontos concedidos:R$ %.2f\n", descontosConcedidos);
    printf("Faturamento final:  R$ %.2f\n", faturamentoFinal);
    printf("=========================\n");
}

int main(void) {
    int opcao;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                novoPedido();
                break;
            case 2:
                calculadora();
                break;
            case 3:
                simularDesconto();
                break;
            case 4:
                mostrarRelatorio();
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
