// inclusão de bibliotecas 
#include <iostream> // Biblioteca padrão c++
#include <Windows.h> // Biblioteca para manipulação de tempo
#include <bitset> // Biblioteca para exibição de código binário
#include "bit.h" // Biblioteca com as funções de manipulação de bits
#include "Tela.h" // Biblioteca onde estão inicializadas as funções que irão desenhar a tela, as linhas e a fita no terminal
#include "Random.h" // Biblioteca com funções que gerarão sementes aleatórias para testar os bits da tela

// criando funções com macros
#define Print(X) std::cout << X
#define Read(X) std::cin >> X

int main()
{
	// Chamando a função Srand32 para gerar a semente aleatória
	Srand32();
	unsigned char linha = 0; // A variável linha representa o valor impresso na fita de bits
	unsigned int tela = 0;   // e a variável tela representa o valor atual impresso na tela, sendo essas variáveis o "estado atual" de ambas
	// mostra a tela ligada
	Tela(0b11111111111111111111111111111111); // Mostra a tela ligada por 1,5 segundos apresentando um inteiro de 32 bits cheio
	Print("\n");
	Print("[+] Ligando tela...\n");
	Sleep(1500); // Função de descanso de tempo que será usada várias vezes no código. Escala: Sleep(1000) = 1 segundo de pausa

	// A seguir, o laço for que irá testar os bits da tela, atualizando a tela 10 vezes e exibindo 10 valores pseudo-aleatórios gerados pela função Rand32()
	for (int i = 0; i < 10; i++)
	{
		// limpa a janela
		system("cls");

		// exibe tela com pixels aleatórios e mensagens programadas
		unsigned int Var_32bits = Rand32();
		Tela(Var_32bits);
		Print("\n");
		Print("[+] Ligando tela... \n");
		Print("[+] Testando bits... \n");
		
		// Dorme por 1 segundo
		Sleep(1000);
	}
	// Desliga os pixels da tela. A tela por default deve estar com todos os bits desligados
	system("cls"); // Limpa a janela
	Tela(0); // Exibe a tela completamente desligada
	// Reexibe as mensagens novamente. Isso se repetirá várias vezes no decorrer do código. 
	Print("\n");
	Print("[+] Ligando tela... \n");
	Print("[+] Testando bits... \n");
	Print("[+] Teste concluído...");
	Print("\n\n");
	// Exibe a fita de bits com os bits desligados. A fita por padrão deve estar desligada
	Fita(0); Print("\n");
	// Inicialização das variáveis que vão ser ocupadas com os comandos do usuário
	int num; // Inteiro representando a posição dos bits
	char op = 0; // Char para receber os caracteres inseridos pelo usuário
	

	// Loop while onde estão programados os comandos que o programa receberá do usuário. O laço opera enquanto o input do usuário for diferente da instrução [S]air
	while (op != 'S')
	{
		// mostra interface de comandos
		Print("[L]igar [D]esligar [T]odos [N]enhum [E]nviar [S]air\n\n");
		Print("> Comando: ");
		Read(op);
		// A seguir, até a linha 145, uma série de condicionais preparadas para receber do usuário os comandos descritos no documento do trabalho 
		if (op == 'L') { // Comando para ligar Bit. Usa a função LigarBit() para, como o próprio nome sugere, ligar os bits da fita. *checar biblioteca bit.cpp
			Read(num);
			linha = LigarBit(linha, num);   // Linha e posição são recebidos pela função. A variável "linha" representa o valor atual da fita e "num" a posição a ser ligada 
			// Limpa e atualiza a janela
			system("cls");
			Tela(tela);
			Print("\n");
			Print("[+] Ligando tela... \n");
			Print("[+] Testando bits... \n");
			Print("[+] Teste concluído...");
			Print("\n\n");
			// Exibe a fita de bits atualizada
			Fita(linha); Print("\n");
		}
		else if (op == 'D') { // Comando para desligar Bit. Opera da mesma forma que a função LigarBit(), mas na lógica inversa. *checar biblioteca bit.cpp
			Read(num);
			linha = DesligarBit(linha, num);
			// Limpa e atualiza a janela
			system("cls");
			Tela(tela);
			Print("\n");
			Print("[+] Ligando tela... \n");
			Print("[+] Testando bits... \n");
			Print("[+] Teste concluído...");
			Print("\n\n");
			// Exibe a fita de bits atualizada
			Fita(linha); Print("\n");
		}
		else if (op == 'T') { // Função para ligar todos os bits da fita ao mesmo tempo. Chama a função LigarBit() 8 vezes, sem saltos de linha.
			linha = LigarBit(linha, 0);
			linha = LigarBit(linha, 1);
			linha = LigarBit(linha, 2);
			linha = LigarBit(linha, 3);
			linha = LigarBit(linha, 4);
			linha = LigarBit(linha, 5);
			linha = LigarBit(linha, 6);
			linha = LigarBit(linha, 7);
			system("cls");
			Tela(tela);
			Print("\n");
			Print("[+] Ligando tela... \n");
			Print("[+] Testando bits... \n");
			Print("[+] Teste concluído...");
			Print("\n\n");
			// Exibe a fita de bits com todos os bits ligados
			Fita(linha); Print("\n");
		}
		else if (op == 'N') { // Comando para desligar todos os bits da tela. Opera de forma semelhante ao comando [T]odos, mas na forma inversa, chamando
			// a função DesligarBit() 8 vezes
			linha = DesligarBit(linha, 0);
			linha = DesligarBit(linha, 1);
			linha = DesligarBit(linha, 2);
			linha = DesligarBit(linha, 3);
			linha = DesligarBit(linha, 4);
			linha = DesligarBit(linha, 5);
			linha = DesligarBit(linha, 6);
			linha = DesligarBit(linha, 7);
			// Limpa e atualiza a janela
			system("cls");
			Tela(tela);
			Print("\n");
			Print("[+] Ligando tela... \n");
			Print("[+] Testando bits... \n");
			Print("[+] Teste concluído...");
			Print("\n\n");
			// Exibe a fita de bits com os bits desligados
			Fita(linha); Print("\n");
		}
		// Comando para enviar a atual configuração da fita de bits à tela na linha de escolha do usuário
		else if (op == 'E') {
			Read(num); // Nesse caso, a variável num representa a linha da tela, e não a posição da fita de bits
			// Chama a função atualizar (checar tela.cpp) para atualizar o valor 32 bits da tela com o valor da fita
			tela = Atualizar(tela, linha, num);
			// Limpa e atualiza a janela
			system("cls");
			// Exibe a tela atualizada 
			Tela(tela);
			Print("\n");
			Print("[+] Ligando tela... \n");
			Print("[+] Testando bits... \n");
			Print("[+] Teste concluído...");
			Print("\n\n");
			// Exibe a fita de bits como de costume
			Fita(linha); Print("\n");
		}
	}
	// Uma vez que o usuário insere o valor "S", o programa sairá do laço while e executará a condicional a seguir, que de acordo com o documento,
	// deve iniciar o ataque hacker
	if (op == 'S') {
		char aspa = '"'; // Define uma variável como aspa dupla, para exibir aspas na mensagem "Joãozinho "O Hacker" esteve aqui!"
		// A seguir, utilizei a biblioteca bitset para separar e criar quatro variáveis de 8 bits do valor atual da tela (de 32 bits)
		std::bitset<8> binarioALTO(BitsAltos(tela) >> 8);
		std::bitset<8> binarioalto(BitsAltos(tela));
		std::bitset<8> binariobaixo(BitsBaixos(tela) >> 8);
		std::bitset<8> binarioBAIXO(BitsBaixos(tela));
		// Exibição das mensagens descritas no documento, com pausa de tempo
		Print("\n");
		Print("[+] Acesso remoto em andamento..."); Print("\n");
		Sleep(1000);
		// Mensagem informando que o programa foi interceptado e exibindo o valor da tela em binário
		Print("[+] Interceptado: "); Print(binarioBAIXO); Print(binariobaixo); Print(binarioalto); Print(binarioALTO); Print("\n");
		Sleep(1000);
		Print("[+] Tela hackeada..."); Print("\n\n");
		// Uso da função Hackear() em conjunto das funções BitsBaixos() e BitsAltos() para exibir a nova tela adulterada por Joãozinho (O Hacker).
		// O caractere usado foi um jogo da velha (#). 
		Hackear(BitsBaixos(tela));
		Hackear(BitsAltos(tela)); Print("\n\n");
		Print("Joãozinho "); Print(aspa); Print("O Hacker"); Print(aspa); Print(" esteve aqui!"); Print("\n");
	}
	// finaliza o programa

	system("pause");
	return 0;
}