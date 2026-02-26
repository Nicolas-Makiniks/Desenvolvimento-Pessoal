#include <stdio.h>
#include <stdint.h>

/*
    Aqui, pedimos ao compilador uma variável que suporte pelo menos 16 bits.

    Se a arquitetura do processador não tiver um tipo de exatamente 16 bits,
    o programa não vai quebrar; ele alocará o próximo tamanho disponível
    (como 32 bits) de forma automática.
*/

int main(int argc, char *argv[]) {
    // O compilador garante PELO MENOS 16 bits
    int_least16_t sensor_reading = 32000;

    // O cast (int) garante que o printf leia corretamente independente do tamanho final
    printf("Leitura do sensor: %d\n", (int)sensor_reading);

    // No Windows/Visual Studio, isso geralmente retorna 2 bytes (16 bits), 
    // mas em arquiteturas incomuns poderia ser 4 bytes.
    printf("Tamanho alocado para o sensor: %zu bytes\n", sizeof(sensor_reading));

    return 0;
}