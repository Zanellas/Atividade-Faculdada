#include <stdio.h>

int main() {

    int movie_option, ticket_quantity, age;
    float ticket_price = 30.50, total_value;

    printf("Selecione uma das opcoes de filme abaixo: \n");
    printf("1 - A Baleia\n");
    printf("2 - Avatar: O caminho da agua\n");
    printf("3 - Tar\n");
    printf("4 - Nada de Novo no Front\n");
    scanf("%d", &movie_option);

    printf("Quantos ingressos deseja comprar?\n");
    scanf("%d", &ticket_quantity);

    total_value = ticket_quantity * ticket_price;

    for (int i = 0; i < ticket_quantity; i++) {
        printf("Qual a idade da pessoa que utilizara o ingresso %d?\n", i + 1);
        scanf("%d", &age);

        if (age < 10 || age > 65) {
            total_value = total_value - (ticket_price / 2);
        }
    }

    if (movie_option == 1) {
        printf("Filme selecionado: A Baleia\n");
    }
    else if (movie_option == 2) {
        printf("Filme selecionado: Avatar: O caminho da agua\n");
    }
    else if (movie_option == 3) {
        printf("Filme selecionado: Tar\n");
    }
    else if (movie_option == 4) {
        printf("Filme selecionado: Nada de Novo no Front\n");
    }

    printf("Valor total da compra: R$ %.2f\n", total_value);

    return 0;
}
