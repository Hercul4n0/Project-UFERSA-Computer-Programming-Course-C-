#include <iostream>
#include "Bot.h"
using namespace std;

// Definição do vetor de respostas
const char* answers[] = {
    "Olá, tudo Bom?",
    "Que bom! Qual é o seu curso?",
    "Bacana! Está em qual período?",
    "Legal! Preciso ir agora...",
    "Tchau tchau, até outro dia!"
};

void Answer(int posicao)
{
    // Calcula quantos elementos existem no vetor
    int total = sizeof(answers) / sizeof(answers[0]);

    // Índice circular usando módulo
    int position = posicao % total;

    // Aplica cor vermelha (ANSI)
    cout << "\x1B[31m";
    cout << "> " << answers[position];
    cout << "\x1B[0m" << endl; // Reset de cor
}
