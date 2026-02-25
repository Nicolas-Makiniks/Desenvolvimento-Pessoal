#include <stdio.h>
#include <stdint.h>
#include <locale.h>

/*
    Meu primeiro contato com a biblioteca stdint.h revisão de tipagem, alocação e sufixos de dados em C.

    Este programa usa o tipo exato de 64 bits para armazenar o valor
    máximo de de um número na base 36 com 12 caracteres "ZZZZZZZZZZZZZZZZ".

    Ele garante que a variável terá exatamente 8 bytes de tamanho
    na memória (nem mais, nem menos), independentemente de onde o código for executado

    Sufixos conhecidos:
    F   - Float para 4 bytes
    U   - Unsigned para valores positivos            -   Aloca a memória para apenas número positivos
    L   - Long para 4 a 8 bytes (Windows - Linux)    -   (-65.536 a 65.535) a (-4.294.967.296 a 4.294.967.295)
    LL  - Long Long para 8 bytes garantido           -   -4.294.967.296 a 4.294.967.295
    ULL - Unsigned Long Long para 8 bytes garantido  -   0 a 18.446.744.073.709.551.615

    Sem sufixos como o pré-processador fará por padrão:
    3.14                 - Será lido como double (8 bytes)
    -15                  - Será lido como int (4 bytes)

    18446744073709551615 - Falha pois não cabe em 4 bytes (int)
*/

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "pt-br.utf8");

    // Garantia absoluta de 64 bits (8 bytes)
    uint64_t max_combinations = 4738381338321616896ULL;

    /*
        Garantia absoluta de 8 bits (1 byte) com sinal

        Sem sufixo pois o pré-processador lê este valor como 32 bits (4 bytes)
        sendo que -15 cabe perfeitamente até mesmo em 1 byte (-128 a 127)
    */
    int8_t temperature = -15;

    printf("Combinações (64 bits): %llu\n", max_combinations);
    printf("Temperatura (8 bits) : %d\n", temperature);

    // Verificando o tamanho na memória
    printf("Tamanho de uint64_t  : %zu bytes\n", sizeof(max_combinations));
    printf("Tamanho de int8_t    : %zu bytes\n", sizeof(temperature));

    return 0;
}