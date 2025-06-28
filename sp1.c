#include <stdio.h>

#define LOADM 0
#define LOADV 1
#define STORE 2
#define ADD 3
#define SUB 4
#define MUL 5
#define DIV 6
#define INC 7
#define DEC 8
#define AND 9 
#define OR 10
#define NOT 11
#define JMP 12
#define JZ 13
#define JNZ 14
#define JG 15
#define JL 16
#define JGE 17
#define JLE 18
#define HLT 19

// "Apelido" de unsigned char para Byte
#define Byte unsigned char

// Estrutura para cada instrução
typedef struct sp1
{
    Byte opcode;
    Byte operando;
} sp1;

int main()
{
    sp1 instrucao[256];

    // Registradores
    Byte acc;        // Registrador de acumulador 8 bits
    Byte pc = 0;     // Contador de programa 8 bits 
    Byte status = 0; // Registrador de status 8 bits
    Byte mem[256];   // Memória do programa 256 bytes

    // Abre o arquivo binário para leitura
    FILE *file = fopen("a.sp1", "rb");
    if(file == NULL){
        printf("Não foi possível abrir o arquivo\n");
        return 1; 
    }

    Byte buf[2];
    // Loop para ler as instruções do arquivo binário 
    for(int i = 0; fread(buf, sizeof(Byte), 2, file); i++){
        instrucao[i].opcode = buf[0];
        instrucao[i].operando = buf[1];
    }

    // Loop da execução do programa
    while (instrucao[pc].opcode != HLT) {
        switch (instrucao[pc].opcode) {
            case LOADM:
                acc = mem[instrucao[pc].operando];
                break;
            case LOADV:
                acc = instrucao[pc].operando;
                break;
            case STORE:
                mem[instrucao[pc].operando] = acc;
                break;
            case ADD:
                acc += mem[instrucao[pc].operando];
                break;
            case SUB:
                acc -= mem[instrucao[pc].operando];
                break;
            case MUL:
                acc *= mem[instrucao[pc].operando];
                break;
            case DIV:
                acc /= mem[instrucao[pc].operando];
                break;
            case INC:
                acc++;
                break;
            case DEC:
                acc--;
                break;
            case AND:
                acc &= mem[instrucao[pc].operando];
                break;
            case OR:
                acc |= mem[instrucao[pc].operando];
                break;
            case NOT:
                acc = ~acc;
                break;
            case JMP:
                pc = instrucao[pc].operando;
                break;
            case JZ:
                if (acc == 0) {
                    pc = instrucao[pc].operando;
                }
                break;
            case JNZ:
                if (acc != 0) {
                    pc = instrucao[pc].operando;
                }
                break;
            case JG:
                if (acc > 0) {
                    pc = instrucao[pc].operando;
                }
                break;
            case JL:
                if (acc < 0) {
                    pc = instrucao[pc].operando;
                }
                break;
            case JGE:
                if (acc >= 0) {
                    pc = instrucao[pc].operando;
                }
                break;
            case JLE:
                if (acc <= 0) {
                    pc = instrucao[pc].operando;
                }
                break;
            case HLT:
                break;
            default:
                break;
        }
        pc++;
    } 
    return 0;
}
