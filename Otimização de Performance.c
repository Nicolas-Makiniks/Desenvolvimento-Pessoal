#include <stdio.h>
#include <stdint.h>

/*
    Descobrindo uma nova forma de iterar através de um FOR.
    
    Ao usar o tipo fast, você sacrifica o controle rígido do tamanho da memória
    em troca da velocidade máxima de processamento da CPU, porque ela
    copia essas informações da memória RAM para seu cache que geralmente
    é de 32 bits a 64 bits em processadores modernos, e devido a essa arquitetura
    ao armazenar um int_fast16_t (2 bytes ou 16 bits) ele registrará esta informação em uma posição
    multipla do tamanho do cache do processador que são 4 bytes. 
    
    ex:
    int_fast8_t (1 byte) ocupará 4 bytes na memória RAM para facilitar o acesso
    ao endereço desta memória caso o tamanho mínimo do processador seja 4 bytes

    Segue o teste em código com exemplo executável:
*/

int main(int argc, char *argv[]) {
    uint_fast16_t i = 0; // 2 bytes ou 16 bits

    printf("Iniciando loop de alta performance...\n");

    /*
        int_fast8_t pede um tipo de pelo menos 8 bits, mas o mais RÁPIDO para a CPU.
        Em processadores x86/x64, o Visual Studio mapeará isso para um int de 32 bits, 
        pois a CPU processa 32 bits mais rápido do que fatia a memória para ler 16 bits.
    */
    for (; i < UINT16_MAX; i++) { // UINT16_MAX = 0xffffui16 = 65.535 porque é o tamanho máximo positivo de um byte sem sinal negativo (unsigned)
        printf("Iteracao rapida: %d\n", (int)i);
    }
    printf("Tamanho escolhido para velocidade: %zu bytes\n\n", sizeof(i));
    printf("Quase instantaneo certo?\n\n");

    return 0;
}