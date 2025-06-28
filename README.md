# 🖥️ Emulador do Processador SP1

Este projeto implementa um emulador para o **SP1 (Simple Processor 1)** — um processador acadêmico de 8 bits com arquitetura simples, usado como exercício de interpretação de instruções e manipulação de registradores.

## 🔧 Tecnologias

- Linguagem C
- Manipulação de arquivos binários
- Arquitetura baseada em acumulador
- Simulação de instruções de máquina

## 🧠 Registradores simulados

- `acc` → acumulador de 8 bits
- `pc` → program counter (contador de instruções)
- `status` → registrador de flags (carry, zero, overflow)
- `mem[256]` → memória de 256 bytes

## 🧾 Instruções suportadas

| Nome  | Código | Ação                                   |
|-------|--------|----------------------------------------|
| LOADM | 0      | acc = mem[operando]                    |
| LOADV | 1      | acc = operando                         |
| STORE | 2      | mem[operando] = acc                    |
| ADD   | 3      | acc += mem[operando]                   |
| SUB   | 4      | acc -= mem[operando]                   |
| MUL   | 5      | acc *= mem[operando]                   |
| DIV   | 6      | acc /= mem[operando]                   |
| INC   | 7      | acc++                                  |
| DEC   | 8      | acc--                                  |
| AND   | 9      | acc &= mem[operando]                   |
| OR    | 10     | acc |= mem[operando]                   |
| NOT   | 11     | acc = ~acc                             |
| JMP   | 12     | pc = operando                          |
| JZ    | 13     | if acc == 0 → pc = operando            |
| JNZ   | 14     | if acc != 0 → pc = operando            |
| JG    | 15     | if acc > 0 → pc = operando             |
| JL    | 16     | if acc < 0 → pc = operando             |
| JGE   | 17     | if acc >= 0 → pc = operando            |
| JLE   | 18     | if acc <= 0 → pc = operando            |
| HLT   | 19     | halt: fim do programa                  |

## ▶️ Como executar

1. Compile o programa:
   ```bash
   gcc sp1.c -o sp1
