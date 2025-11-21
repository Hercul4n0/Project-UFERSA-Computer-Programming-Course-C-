#include "bit.h"
#include <iostream>
using namespace std;
// Para poupar tempo, defini partes da moldura da fita e da tela como palavras chave
#define adorno_inferior1 "\xC8\xCD\xCD\xCD\xCD b i t s \xCD\xCD\xCD\xCD\xBC"
#define adorno_inferior2 "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC"
#define adorno_superior "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB"
// Define o código das cores vermelho, verde e branco usando o código ANSI
#define vermelho "\033[0;31m" 
#define verde "\033[0;32m" 
#define branco "\033[0;37m"

const unsigned char caractere_quadrado = 254; // CÓDIGO DO CARACTERE QUADRADO

void Linha(unsigned char linha_tela) { 
	// Se a função TestarBit() retornar true, a função Linha() pinta o quadrado na tela
	// se retornar falso, pinta o vermelho.
	// Obs: o quadrado branco é para evitar erros de compilação
	if (TestarBit(linha_tela, 7) == true) { cout << verde << caractere_quadrado << branco << " ";} 
	else {cout << vermelho << caractere_quadrado << branco << " ";}
	if (TestarBit(linha_tela, 6) == true) {cout << verde << caractere_quadrado << branco << " ";}
	else {cout << vermelho << caractere_quadrado << branco << " ";}
	if (TestarBit(linha_tela, 5) == true) {cout << verde << caractere_quadrado << branco << " ";}
	else {cout << vermelho << caractere_quadrado << branco << " ";}
	if (TestarBit(linha_tela, 4) == true) {cout << verde << caractere_quadrado << branco << " ";}
	else {cout << vermelho << caractere_quadrado << branco << " ";}
	if (TestarBit(linha_tela, 3) == true) {cout << verde << caractere_quadrado << branco << " ";}
	else {cout << vermelho << caractere_quadrado << branco << " ";}
	if (TestarBit(linha_tela, 2) == true) {cout << verde << caractere_quadrado << branco << " ";}
	else {cout << vermelho << caractere_quadrado << branco << " ";}
	if (TestarBit(linha_tela, 1) == true) {cout << verde << caractere_quadrado << branco << " ";}
	else {cout << vermelho << caractere_quadrado << branco << " ";}
	if (TestarBit(linha_tela, 0) == true) {cout << verde << caractere_quadrado << branco << " ";}
	else {cout << vermelho << caractere_quadrado << branco << " ";}
}

void Fita(unsigned char fita_bits) { // Desenha a fita emoldurada no terminal, com o auxílio da função linha
	cout << "\xC9 7 6 5 4 3 2 1 0 \xBB" << endl;
	cout << "\xBA "; Linha(fita_bits); cout << "\xBA" << endl;
	cout << adorno_inferior1 << endl;
}

void Tela(int estado_dos_pixels_tela) { // Desenha a tela emoldurada no terminal, usando a função linha 4 vezes e efetuando deslocamento de bits
	unsigned char mask;  // 000000000000000000000000[00000000]
	cout << adorno_superior << endl;
	cout << "\xBA "; Linha(estado_dos_pixels_tela); cout << "\xBA" << endl;
	mask = estado_dos_pixels_tela >> 8;           // 0000000000000000[00000000]00000000
	cout << "\xBA "; Linha(mask); cout << "\xBA" << endl;
	mask = estado_dos_pixels_tela >> 16;			 //00000000[00000000]0000000000000000
	cout << "\xBA "; Linha(mask); cout << "\xBA" << endl;
	mask = estado_dos_pixels_tela >> 24;		     //[00000000]000000000000000000000000
	cout << "\xBA "; Linha(mask); cout << "\xBA" << endl;
	cout << adorno_inferior2 << endl;
}

unsigned int Atualizar(unsigned int estado_pixels_tela, unsigned char estado_atual_fita, unsigned int numero_da_linha) {
	// Define uma máscara e estabelece condicionais para os números das linhas que o usuário inserir
		unsigned int mask_linhas = 0b00000000000000000000000011111111;

		if (numero_da_linha == 0) { 
			// Define o estado dos pixels na tela como sendo a conjunção entre ele mesmo e a negação da máscara.
			estado_pixels_tela = estado_pixels_tela & ~(mask_linhas); 
			// Far um OR entre o estado dos pixels na tela e o estado atual da fita, para atualizar os bits da tela preservando os bits já ligador
			estado_pixels_tela = estado_pixels_tela | (unsigned int)estado_atual_fita ;
			return estado_pixels_tela;
		}
		else if (numero_da_linha == 1) {
			mask_linhas = 0b00000000000000001111111100000000;
			estado_pixels_tela = estado_pixels_tela & ~(mask_linhas);
			estado_pixels_tela = estado_pixels_tela | ((unsigned int)estado_atual_fita << 8); // Deslocamento de 8 bits para representação correta do valor
			return estado_pixels_tela;
		}
		else if (numero_da_linha == 2) {
			mask_linhas = 0B00000000111111110000000000000000;
			estado_pixels_tela = estado_pixels_tela & ~(mask_linhas);
			estado_pixels_tela = estado_pixels_tela | ((unsigned int)estado_atual_fita << 16); // Deslocamento de 16 bits para representação correta do valor
			return estado_pixels_tela;
		}

		else if (numero_da_linha == 3) {
			mask_linhas = 0b11111111000000000000000000000000;
			estado_pixels_tela = estado_pixels_tela & ~(mask_linhas);
			estado_pixels_tela = estado_pixels_tela | ((unsigned int)estado_atual_fita << 24); // Deslocamento de 24 bits para representação correta do valor
			return estado_pixels_tela;
		}

}

unsigned char caractere_hacker = 35; // Define o caractere da tela hacker como #
void LinhaHacker(unsigned char inteiro_hacker_8bits) {
	// Basicamente a mesma coisa da função Linha(), mas com o caractere alterado
	if (TestarBit(inteiro_hacker_8bits, 7) == true) { cout << verde << caractere_hacker << branco << " "; }
	else { cout << vermelho << caractere_hacker << branco << " "; }
	if (TestarBit(inteiro_hacker_8bits, 6) == true) { cout << verde << caractere_hacker << branco << " "; }
	else { cout << vermelho << caractere_hacker << branco << " "; }
	if (TestarBit(inteiro_hacker_8bits, 5) == true) { cout << verde << caractere_hacker << branco << " "; }
	else { cout << vermelho << caractere_hacker << branco << " "; }
	if (TestarBit(inteiro_hacker_8bits, 4) == true) { cout << verde << caractere_hacker << branco << " "; }
	else { cout << vermelho << caractere_hacker << branco << " "; }
	if (TestarBit(inteiro_hacker_8bits, 3) == true) { cout << verde << caractere_hacker << branco << " "; }
	else { cout << vermelho << caractere_hacker << branco << " "; }
	if (TestarBit(inteiro_hacker_8bits, 2) == true) { cout << verde << caractere_hacker << branco << " "; }
	else { cout << vermelho << caractere_hacker << branco << " "; }
	if (TestarBit(inteiro_hacker_8bits, 1) == true) { cout << verde << caractere_hacker << branco << " "; }
	else { cout << vermelho << caractere_hacker << branco << " "; }
	if (TestarBit(inteiro_hacker_8bits, 0) == true) { cout << verde << caractere_hacker << branco << " "; }
	else { cout << vermelho << caractere_hacker << branco << " "; }
}

void Hackear(unsigned short inteiro_hacker_16bits) {
	// Usa a função LinhaHacker() para imprimir duas linhas alteradas por Joãozinho (O Hacker)

	unsigned int mask_hacker = 0b0000000011111111;
	unsigned short bitbaixo = (inteiro_hacker_16bits & mask_hacker);
	LinhaHacker(inteiro_hacker_16bits);

	mask_hacker = 0b1111111100000000;
	unsigned short bitalto = ((inteiro_hacker_16bits & mask_hacker) >> 8); cout << endl;
	LinhaHacker(bitalto); cout << endl;
}