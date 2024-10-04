#include <stdio.h>
#include <stdlib.h>
struct Funcionario
{
    char nome[20];
    float salario;
    float salario_liquido;
    float imposto;
    int id;
};
float descontoIR(float valor, int aliquota)
{
    return valor - (valor * aliquota / 100);
}

void informacoes(struct Funcionario funcionario)
{
    printf("|-----------------------------------------------|\n");
    printf("| %-15s : %-25s |\n", "Nome", funcionario.nome);
    printf("| %-15s : %-25.2f |\n", "Salario Bruto", funcionario.salario);
    printf("| %-15s : %-25.2f |\n", "Salario Liquido", funcionario.salario_liquido);
    printf("| %-15s : %-25.2f |\n", "Desconto", funcionario.imposto);
    printf("|-----------------------------------------------|\n");
}
void mostrarNaTela(struct Funcionario datas[], int quantidade)
{
    system("cls");
    for (int i = 0; i < quantidade; i++)
    {
        informacoes(datas[i]);
    }
}

float calculoDoImpostoDeRenda(float salario)
{
    if (salario <= 999)
    {
        return descontoIR(salario, 10);
    }
    else if (salario > 999.01 && salario <= 1999)
    {
        return descontoIR(salario, 15);
    }
    else if (salario > 1999.01 && salario <= 9999)
    {
        return descontoIR(salario, 20);
    }
    else if (salario > 9999.01 && salario <= 99999)
    {
        return descontoIR(salario, 25);
    }
    else
    {
        return descontoIR(salario, 30);
    }
}
void lerDados(struct Funcionario datas[], int quantidiade)
{
    int i = 0;
    do
    {
        printf("Nome %d do funcionario(a): ", i + 1);
        scanf(" %s", &datas[i].nome);
        printf("Salario do funcionario(a) %s: ", datas[i].nome);
        scanf("%f", &datas[i].salario);
        datas[i].id = i;
        datas[i].salario_liquido = calculoDoImpostoDeRenda(datas[i].salario);
        datas[i].imposto = datas[i].salario - datas[i].salario_liquido;
        i++;
    } while (i < quantidiade);
}

void aplicacao()
{
    int quantidade;
    printf("Quantidade de funcionario? ");
    scanf("%d", &quantidade);
    system("cls");
    struct Funcionario dados[quantidade];
    lerDados(dados, quantidade);
    mostrarNaTela(dados, quantidade);
}

int main()
{
    aplicacao();
    return 0;
}