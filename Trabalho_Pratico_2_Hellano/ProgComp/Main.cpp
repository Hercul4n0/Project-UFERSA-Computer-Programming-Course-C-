#include <iostream>
#include "Text.h"
#include "Bot.h"
using namespace std;
int main()
{
	Text text, line; // Cria duas variáveis do tipo Text. text será o acumulador de toda a conversa e line será 
	// para ler a entrada do usuário
// Criação dos buffers
	Create(&text, 20); // Aloca um vetor dinâmico para text com capacidade 20
	Create(&line, 100); // Aloca um vetor dinâmico para line com capacidade 100.
	// Essas chamadas fazem new[] internamente, liberar depois
	int i = 0; // Inicializa um contador. Vai contar quantas linhas foram processadas
	Read(&line); // Lê a entrada do usuário até o \n ou a capacidade máxima ser atingida


	while (CharAt(&line, 0) != '%') // Loop continua até o caractere '%' 
	{
		Add(&text, &line); // Adiciona a última linha digitada pelo usuário ao histórico acumulado em text
		Print(&line); // Exibe a linha formatada com a mensagem padrão "> Entendi: "
		Answer(i++); // Chama a função Answer para gerar a resposta do Bot
		Read(&line); // Lê a próxima entrada do usuário e armazena em line

	}

	// Ao digitar '%' o programa sai do loop e segue para o resumo final

	Text title; // Declara uma variável Text pra guardar "Resumo da Conversa"
	Init(&title, "Resumo da Conversa "); // Atribui a frase a variável
	Boxed(&title); //Exibe o título dentro da moldura 
	Highlight(&text); // Mostra o histórico de mensagens completo com formatação especial
	
	// Libera a memória usada pelo texto temporário, pelo histórico de mensagens e pelo título
	Destroy(&line);
	Destroy(&text);
	Destroy(&title);
}