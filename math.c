#include <stdio.h>
#include <stdlib.h>

int main() {

    int i = 1;

    while(i == 1) {

        double num1, num2, resultado;
        char operador;
        char ans;

        // Solicita ao usuário o primeiro número, o operador e o segundo número
        printf("Digite o primeiro numero: ");
        scanf("%lf", &num1);
        
        printf("Digite o operador (+, -, *, /): ");
        scanf(" %c", &operador); // Note o espaço antes de %c para evitar o caractere de quebra de linha pendente.
        
        printf("Digite o segundo numero: ");
        scanf("%lf", &num2);
        
        // Realiza a operação selecionada
        switch (operador) {
            case '+':
                resultado = num1 + num2;
                break;
            case '-':
                resultado = num1 - num2;
                break;
            case '*':
                resultado = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    resultado = num1 / num2;
                } else {
                    printf("Erro: Divisao por zero!\n");
                    resultado = 0;
                }
                break;
            default:
                printf("Operador invalido!\n");
                resultado = 0;
        }
        
        // Exibe o resultado
        printf("Resultado: %.2lf\n",resultado);
        
        printf("Deseja continuar? y/n ");
        scanf(" %c", &ans);

        switch (ans) {
        case 'y':
            i = 1;
            break;
        case 'Y':
            i = 1;
            break;
        default:
            i = 0;
            break;
        }
 
    
}
    return 0;

}