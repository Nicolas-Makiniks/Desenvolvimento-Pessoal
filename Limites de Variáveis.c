#include <stdio.h>
#include <stdint.h>

/*
    Esta é uma implementação clássica de segurança (overflow check).

    Se você tentar somar um valor a uma variável que já está perto do seu
    limite máximo, ela "zera" e volta para o negativo (ou para zero se for unsigned),
    então utilizo de um valor padronizado "macro" da biblioteca stdint.h
    que representa o maior valor possível para aquela quantidade de bytes.
*/

int main() {
    // Simulação de um sistema com registros progressivos de ID
    // Inicializa a variável muito próxima do limite máximo de 64 bits
    uint64_t current_id = UINT64_MAX - 5;
    uint64_t ids_to_add = 10;

    printf("ID atual          : %llu\n", current_id);
    printf("Tentando adicionar: %llu\n", ids_to_add);

    // Verificação de segurança: O espaço restante é menor que a quantidade a adicionar?
    if (UINT64_MAX - current_id < ids_to_add) {
        printf("ERRO DE SEGURANCA: A operacao causaria um Overflow de memoria!\n");
    }
    else {
        current_id += ids_to_add;
        printf("Operacao bem sucedida. Novo ID: %llu\n", current_id);
    }

    return 0;
}