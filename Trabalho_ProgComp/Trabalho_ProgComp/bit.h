#pragma once

unsigned short BitsAltos(unsigned int); // Pega os bits de ordem mais alta de um inteiro sem sinal
unsigned short BitsBaixos(unsigned int); // Pega os bits de ordem mais baixa de um inteiro sem sinal
bool TestarBit(unsigned char, unsigned char); // Verifica se um determinado bit está ligado para imprimir o bit na tela (usado na biblioteca tela, função Linha())
unsigned char LigarBit(unsigned char, unsigned char); // Liga os bits da fita. 
unsigned char DesligarBit(unsigned char, unsigned char); // Desliga os bits da fita
