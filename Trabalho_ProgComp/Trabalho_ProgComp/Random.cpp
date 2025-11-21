#include <iostream>
#include <ctime>
void Srand32() {
	srand(time(NULL)); // Srand: gera uma semente aleatoria. Com unsigned int, garante-se que a semente gerada é um inteiro
}

unsigned int Rand32() {
	unsigned int variavel_32bits = rand(); // Atribui um valor pseudoaleatório à variavel_32bits
	variavel_32bits = variavel_32bits << 15;     // Gera os primeiros 15 bits e desloca-os 15 bits pra esquerda
	variavel_32bits = (variavel_32bits | (rand() % 2) << 1); //Vai efetuar uma divisão por 2 e adicionar o resto no primeiro bit, até agora temos 31 bits
	variavel_32bits = (variavel_32bits | rand() % 2); // Vai novamente efetuar a divisão por 2, e adicionar o bit que falta na variável =. Agora temos 32 bits
	return variavel_32bits; 
}