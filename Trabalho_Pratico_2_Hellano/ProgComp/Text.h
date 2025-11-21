#pragma once

struct Text {
	char* ponteiro_vetorcaractere; // Ponteiro para vetor dinâmico de caracteres
	int tamanho_texto_vetor; // Quantidade de caracteres armazenados/ Armazena numero de caracteres lidos na função Read
	int capacidade; // Capacidade máxima do vetor alocado
};

void Create(Text* endereco, int capacity); // Inicia um text com capacidade definida e aloca memória
void Init(Text* endereco, const char* s); // Copia um texto constante sem '\0' para inicializar o Text
void Destroy(Text* endereco); // Libera a memória alocada

void Show(const Text* ); // Mostra o conteúdo ignorando o caractere especial * e \n
void Print(const Text* texto); // Mostra o texto colorido e formatado

void Read(Text * texto); // Lê o input do teclado até encontrar um \n ou até atingir a capacidade 
char CharAt(const Text* texto, int posicao); //Retorna o caractere em uma posição ou '\0' se inválida

void Grow(Text* endereco, int novoTamanho); // Realoca a memória aumentando a capacidade para novoTamanho.
void Add(Text* destino, const Text* fonte); // Concatena o conteúdo da fonte no final do destino. Se necessário, usa Grow

void Highlight(const Text* texto_armazenado); // Exibe os trecos entre asteriscos destacados
void Boxed(Text* texto); // Mostra o texto dentro de uma caixa feita com os adornos gráficos

