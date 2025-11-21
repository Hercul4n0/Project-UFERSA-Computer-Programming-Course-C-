#include <iostream>
#include "Text.h"

using std::cout;
using std::cin;
using std::endl;

// Create
void Create(Text* endereco, int capacidade)
{
    // Cria dinamicamente um vetor de caracteres com o tamanho solicitado.
    endereco->ponteiro_vetorcaractere = new char[capacidade];
    // Inicializa o tamanho atual como zero.
    endereco->tamanho_texto_vetor = 0;
    // Armazena a capacidade máxima do vetor no registro.
    endereco->capacidade = capacidade;

    // Muda a cor do texto pra cinza (visual apenas). Os códigos ANSI a seguir
    // Serão acompanhados apenas pelo nome da cor
    cout << "\033[90m";

#ifdef _DEBUG
    // Exibe mensagem informando criação do buffer. (Apenas no modo DEBUG)
    cout << "> Texto com " << capacidade << " caracteres foi criado." << endl;
#endif

    // Retorna para a cor branca de novo
    cout << "\033[0m";
}

// Init
void Init(Text* endereco, const char* frase)
{
    int tamanho = 0;

    // Laço while pra alcular quantos caracteres existem na frase recebida até encontrar o '\0'.
    while (frase[tamanho] != '\0')
    {
        tamanho++;
    }

    // Cria espaço exatamente do tamanho necessário para a frase.
    endereco->ponteiro_vetorcaractere = new char[tamanho];

    // Define tamanho e capacidade iguais ao tamanho encontrado.
    endereco->tamanho_texto_vetor = tamanho;
    endereco->capacidade = tamanho;

    // Lopia os caracteres da string recebida para dentro da estrutura.
    for (int i = 0; i < tamanho; i++)
    {
        endereco->ponteiro_vetorcaractere[i] = frase[i];
    }

}

// Destroy
void Destroy(Text* endereco)
{
    // Cinza para o texto do DEBUG
    cout << "\033[90m";

#ifdef _DEBUG // Informa a memória liberada (no modo DEBUG apenas)
    cout << "> Texto com " << endereco->capacidade << " caracteres foi liberado." << endl;
#endif
    cout << "\033[0m";

    // Libera a memoria ocupada pelo vetor dinâmico
    delete[] endereco->ponteiro_vetorcaractere;

    // Zera os parametros pra evitar ponteiros soltos e eventuais problemas no codigo
    endereco->ponteiro_vetorcaractere = 0;
    endereco->tamanho_texto_vetor = 0;
    endereco->capacidade = 0;
}


// Show  (ignora '*' e '\n')
void Show(const Text* endereco)
{
    // Percorre o texto inteiro
    for (int i = 0; i < endereco->tamanho_texto_vetor; i++)
    {
        char c = endereco->ponteiro_vetorcaractere[i];

        // Se detectar '*' ou '\n', não exibe.
        if (c != '*' && c != '\n')
        {
            cout << c;
        }
    }
}

// Print
void Print(const Text* endereco)
{
    cout << "\x1B[33m";  // amarelo

    // Mensagem padrão do bot formatada na cor correta
    cout << "> Entendi: \"";
    Show(endereco);
    cout << "\"\x1B[0m";
    cout << endl;
}

// Read
void Read(Text* endereco)
{
    // Zera o tamanho antes de uma nova leitura
    endereco->tamanho_texto_vetor = 0;
    char c;

    // Símbolo de entrada
    cout << "> ";

    // Lê o primeiro caractere antes de entrar no while
    cin.get(c);

    // Continua lendo até o usuario digitar ENTER ('\n)
    while (c != '\n')
    {
        // Se houver espaço no vetor, armazena o caractere
        if (endereco->tamanho_texto_vetor < endereco->capacidade)
        {
            endereco->ponteiro_vetorcaractere[endereco->tamanho_texto_vetor] = c;
            endereco->tamanho_texto_vetor++;
        }
        else
        {
            // Se atingir o limite, força parada do while simulando um ENTER
            c = '\n'; 
        }

        cin.get(c);
    }
}

char CharAt(const Text* endereco, int posicao)
{
    // Verifica se a posição solicitada existe dentro do texto armazenado
    if (posicao < 0 || posicao >= endereco->tamanho_texto_vetor)
    {
        // Retorna caractere nulo caso esteja fora do intervalo
        return '\0';
    }
    // Retorna o caractere da posição solicitada
    return endereco->ponteiro_vetorcaractere[posicao];
}

void Grow(Text* endereco, int novaCapacidade)
{
    // Cria um novo vetor com espaço maior
    char* novoVetor = new char[novaCapacidade];

    // Determina quantos caracteres podem ser copiados sem ultrapassar limite novo
    int quantidadeCopiada = endereco->tamanho_texto_vetor;

    if (quantidadeCopiada > novaCapacidade)
    {
        quantidadeCopiada = novaCapacidade;
    }

    // Copia os caracteres do vetor antigo para o novo
    for (int i = 0; i < quantidadeCopiada; i++)
    {
        novoVetor[i] = endereco->ponteiro_vetorcaractere[i];
    }

    // Cinza
    cout << "\033[90m";

#ifdef _DEBUG
    // Exibe mensagem informando expansão do buffer
    cout << "> Expandindo texto de " << endereco->capacidade << " para " << novaCapacidade << " caracteres." << endl;
#endif

    // Libera o vetor antigo
    delete[] endereco->ponteiro_vetorcaractere;

    // Atualiza o ponteiro para o novo espaço 
    endereco->ponteiro_vetorcaractere = novoVetor;

    // Atualiza capacidade e tamanho
    endereco->capacidade = novaCapacidade;
    endereco->tamanho_texto_vetor = quantidadeCopiada;
}

// Add 
void Add(Text* destino, const Text* origem)
{
    // Determina se precisa quebrar linha no final da origem
    int precisaNovaLinha = 0;
    if (origem->tamanho_texto_vetor == 0)
    {
        // Se a origem estiver vazia, representa linha em branco no histórico
        precisaNovaLinha = 1;
    }
    else
    {
        // verifica se já existe quebra de linha no final
        char ultimo = origem->ponteiro_vetorcaractere[origem->tamanho_texto_vetor - 1];
        if (ultimo != '\n')
        {
            // Se não houver, adiciona
            precisaNovaLinha = 1;
        }
        else
        {
            precisaNovaLinha = 0;
        }
    }

    // Calcula o espaço total necessário após concatenar a origem.
    int necessario = destino->tamanho_texto_vetor + origem->tamanho_texto_vetor;
    if (precisaNovaLinha == 1)
    {
        necessario = necessario + 1; // espaço extra para o '\n' que vamos inserir
    }

    // Se o espaço não for suficiente, aumenta o buffer
    if (necessario > destino->capacidade)
    {
        Grow(destino, necessario);
    }

    // Copia os caracteres da origem para o final do destino exibe a mensagem (Apenas para o modo DEBUG)
#ifdef _DEBUG
    cout << "\033[90m"; // Cinza 
    cout << "> Adicionando \"";
#endif

    for (int i = 0; i < origem->tamanho_texto_vetor; i++)
    {
        char ch = origem->ponteiro_vetorcaractere[i];

        // Verifica se há '*' no texto e não exibe na mensagem
        if (ch != '*' && ch != '\n') {
#ifdef _DEBUG
            cout << ch; // exibe a mensagem(Apenas no modo DEBUG)
#endif
        }
        destino->ponteiro_vetorcaractere[destino->tamanho_texto_vetor + i] = origem->ponteiro_vetorcaractere[i];
    }

#ifdef _DEBUG
    cout << "\"";
    cout << endl;
#endif

    cout << "\033[0m"; // Deixa o texto branco novamente

    // Atualiza tamanho com os caracteres copiados
    destino->tamanho_texto_vetor = destino->tamanho_texto_vetor + origem->tamanho_texto_vetor;

    // Se necessário, adiciona um '\n' separador
    if (precisaNovaLinha == 1)
    {
        destino->ponteiro_vetorcaractere[destino->tamanho_texto_vetor] = '\n';
        destino->tamanho_texto_vetor = destino->tamanho_texto_vetor + 1;
    }
}



void Highlight(const Text* endereco)
{
    cout << "\033[33m"; // Amarelo
    int destaque = 0;

    // Percorre todo o texto e imprime como o trabalho pede
    for (int i = 0; i < endereco->tamanho_texto_vetor; i++)
    {
        char c = endereco->ponteiro_vetorcaractere[i];

        // Se encontrar o '*', adiciona o destaque no texto
        if (c == '*')
        {
            if (destaque == 0)
            {
                cout << "\x1B[7m"; // Código do destaque
                destaque = 1;
            }
            else
            {
                cout << "\033[0;33m"; // Desativa o destaque mantendo a cor
                destaque = 0;
            }
        }
        else if (c == '\n')
        {
            // Quebras de linha para fins visuais
            cout << endl;
        }
        else{
            // Imprime o texto
            cout << c;
        }
    }

    // Se terminou no meio de destaque, reseta
    if (destaque == 1)
    {
        cout << "\x1B[0m";
    }
    cout << endl;
}

// Boxed
void Boxed(Text* endereco)
{
    int largura = 0;

    // Conta quantos caracteres visíveis existem (ignorando * e \n) para calcular tamanho da caixa
    for (int i = 0; i < endereco->tamanho_texto_vetor; i++)
    {
        char c = endereco->ponteiro_vetorcaractere[i];
        if (c != '*' && c != '\n')
        {
            largura++;
        }
    }

    // Adiciona margens entre o testo e as linhas da moldura
    int interno = largura + 2;

    // Desenha borda superior com caracteres gráficos
    cout << "\xC9";
    for (int i = 0; i < interno; i++) cout << "\xCD";
    cout << "\xBB" << endl;

    // Lateral esquerda e espaço inicial
    cout << "\xBA ";
    cout << "\x1B[33m";

    int destaque = 0;

    // Imprime texto interno 
    for (int i = 0; i < endereco->tamanho_texto_vetor; i++)
    {
        char c = endereco->ponteiro_vetorcaractere[i];

        if (c == '*')
        {
            if (destaque == 0)
            {
                cout << "\x1B[7m";
                destaque = 1;
            }
            else
            {
                cout << "\033[0;33m";
                destaque = 0;
            }
        }
        else if (c != '\n')
        {
            cout << c;
        }
    }

    cout << "\x1B[0m";

    if (destaque == 1)
    {
        cout << "\x1B[0m";
    }

    // Moldura direita da caixa
    cout << " \xBA" << endl;

    // Desenha a borda inferior com caracteres gráficos
    cout << "\xC8";
    for (int i = 0; i < interno; i++) cout << "\xCD";
    cout << "\xBC" << endl;
}