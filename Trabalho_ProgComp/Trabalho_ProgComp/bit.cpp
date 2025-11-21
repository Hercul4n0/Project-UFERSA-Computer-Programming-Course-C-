unsigned short BitsAltos(unsigned int a) {
	// A função BitsAltos define uma máscara de 32 bits e efetua um AND com a variável de entrada para apagar os bits de mais baixa ordem.
	// Em seguida, ela desloca os bits altos 16 bits para a direita para que o valor correspondente aos 16 bits mais altos seja exibido corretamente
	int mask = 0b11111111111111110000000000000000;
	return short((a & mask) >> 16);
}
unsigned short BitsBaixos(unsigned int a) {
	// Mesma lógica da função BitsAltos(), mas dessa vez, não há necessidade de deslocamento
	int mask = 0b1111111111111111;
	return short((a & mask));
}

bool TestarBit(unsigned char a, unsigned char b) {
	// Se o bit estiver ligado, a função retorna verdadeiro, o que permite que o bit seja representado na tela.
	// A função faz isso através de um AND entre o valor da linha da tela e o valor 1 da máscara deslocado manualmente.
	if (a&(1<< b)){
		return true;
	}
	else{
		return false;
	}
}

unsigned char LigarBit(unsigned char estado_atual_fita, unsigned char num_posicao) {
	// A lógica é semelhante a da função TestarBit(), mas dessa vez com um OR, para preservar os bits já ligados
	return estado_atual_fita | (1 << num_posicao);
}
unsigned char DesligarBit(unsigned char a, unsigned char b) {
	// Lógica inversa a da função TestarBit() para que o bit sempre retorne falso
	return (a & ~(1 << b));
}