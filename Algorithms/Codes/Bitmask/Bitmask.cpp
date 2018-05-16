/* Incompleto 

#include<iostream>
using namespace std;

	Bitmask,
	
	É uma forma mais leve e eficiente de representar um conjunto de booleanos, usando um número inteiro, lembrando que o computador guarda um número inteiro como binário e permite fazermos operações bit-a-bit,  como operaremos usando apenas operações bit-a-bit a velocidade será bem maior que mexer na memória, porém o tamanho do número em bits, deve ser levado em consideração 31-32, 63-64.
	
	Exemplo:
		int n = 4;//(10)
		0000 0100 // (2)
		
	01- Operação de multiplicação e divisão por 2:
		*Multiplicação por 2:   n<<1;
		*Divisão por 2      :   n>>1;//divisão inteira
		
	02-
		Como setar o j-ésimo bit indexado em 0:
			n = 4;
			j = 3;
			n |=(1<<j)
	03- 
		Checar se 0 j-ésimo bit está setado 0 indexed:
			n = 4;
			j = 3;
			n & (1<<j)
	04-
		Para limapar o j-ésimo bit
			n = 4;
			j = 3;
			n & =~(1<<j);
	05 -
		Mudar o valor do bit:
			n = 4;
			j = 3;
			n ^= (1<<j);// O valor do bit só é invertido se os dois bits forem diferentes, 0^0 = 0;
	06 -
		Setar todos os bits j bits on:
			S = (1<<j) -1;
	07 - 
		último bit significativo:
			n = 4;
			n -= (n &  -n);
    

