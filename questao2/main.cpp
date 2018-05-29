/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa para resolver uma notação Polonesa inversa
* @since 20/05/2018
* @date 28/05/2018
*/

#include <iostream>
#include "pilha.h"
#include <string>
#include "math.h"

using namespace std;
using std::string;
using std::endl;
int paraInteiro(string contas){
	int aux2 = 0, size = contas.size();

	for(int i = 0,j = size;i<size;i++)
		aux2+=(contas[--j]-'0')*pow(10,i);
	return aux2;
}

int main(int argc, char const *argv[])
{
/**
	@brief criação de 3 strings
	@param operacao contará as operações como (+ - * /)
	@param contas terá o numero de contas feitas
	@param numeros tem numeros tidos na notação Polonesa
*/
	string operacao[20];
	string contas[20];
	string numeros[20];
/**
	@brief criação de 3 int
	@param j serve para auxiliar no programa
	@param aux serve para auxiliar no programa
	@param i serve para controle
	@param tamanho para receber o pilha.size() para ajudar no programa
*/
	int aux;
	int i = 0;
	int tamanho;
/** 
	@brief cria uma Pilha pilha recebendo strings
*/
	Pilha<string> pilha;
	cout << "Escreva a notação Polonesa inversa e clique enter: " << endl;
	cout << "Utilize '&' e clique enter para sair da escrita da notação " << endl;
/**
	@brief laço para acabar com a leitura da notação
	@details sempre dando um pilha.push() em cada numero ou operador
*/
	while(numeros[i]!= "&"){
	cin >> numeros[i];
	if(numeros[i] == "&")
		goto lugar;
	if(i == 0){
		pilha.push(numeros[i]);
	}
	else if(i%2!=0){
		pilha.push(numeros[i]);
	}
	else if(i>0 && i%2==0){
		pilha.pop();
		pilha.push(numeros[i]);
		pilha.push(numeros[i-1]);		
	}
	i++;
	}
	lugar:

	cout<< "\n";

	//cout << pilha.size() << endl;
	tamanho = pilha.size();
	cout<< "\n";
	/**
	while(!pilha.empty()){
	cout << pilha.top()<< endl;
	pilha.pop();
	}	
	cout << endl;
	}
	*/
	i=0;
	
/**
	@brief é criado um laço para organizar a pilha para que possa realizar as contas
*/
	while(!pilha.empty()){
		
		if(i == 0 || i%2 ==0)
		contas[i] = pilha.top();//cout << contas[i];
		
		if(i%2 != 0)
		operacao[i] = pilha.top();//cout << operacao[i] << endl;
		
		i++;
		pilha.pop();
	}

	i=0;
/**
	@brief criação de uma condicional para os 3 primeiros elementos, pois eles sao diferentes do resto da notação
	@details caso operador for igual '+' somar os numeros
*/
	if(operacao[tamanho-2] == "+"){
		aux = paraInteiro(contas[tamanho-1]) + paraInteiro(contas[tamanho-3]);
		//cout << aux<< endl;
	}
/**
	@brief criação de uma condicional para os 3 primeiros elementos, pois eles sao diferentes do resto da notação
	@details caso operador for igual '+' somar os numeros
*/
	if(operacao[tamanho-2] == "-"){
		aux = paraInteiro(contas[tamanho-1]) - paraInteiro(contas[tamanho-3]);
		//cout << aux<< endl;
	}
/**
	@brief criação de uma condicional para os 3 primeiros elementos, pois eles sao diferentes do resto da notação
	@details caso operador for igual '+' somar os numeros
*/
	if(operacao[tamanho-2] == "*"){
		aux = paraInteiro(contas[tamanho-1]) * paraInteiro(contas[tamanho-3]);
	
		//cout << aux<< endl;
	}
/**
	@brief criação de uma condicional para os 3 primeiros elementos, pois eles sao diferentes do resto da notação
	@details caso operador for igual '+' somar os numeros
*/
	if(operacao[tamanho-2] == "/"){
		aux = paraInteiro(contas[tamanho-1]) / paraInteiro(contas[tamanho-3]);
		//cout << aux<< endl;	
	}

	i=tamanho-1;
/**
	@brief contador recebe tamanho-4 pois precisa diminuir da memória ja utilizada anteriormente
	@param contador
*/
	int contador=tamanho-4;
/**
	@brief contador2 serve para ter controle do laço seguinte
	@param contador2
*/
	int contador2 = (tamanho-3)/2;
/**
	@brief criação de um laço para realizar as contas da notação polonesa
	@details com condicionais para os operadores (+ - * /)
*/
	while(contador2 != 0){
		if(operacao[contador] == "+"){
		aux+= paraInteiro(contas[contador-1]);
		
		cout << "Resultado: " << aux<< endl;
		
		contador-=2;
		contador2--;

	}
	if(operacao[contador] == "-"){
		aux-= paraInteiro(contas[contador-1]);
		cout << "Resultado: " << aux<< endl;
		
		contador-=2;
		contador2--;
	}
	if(operacao[contador] == "*"){
		aux*= paraInteiro(contas[contador-1]);
	
		cout << "Resultado: " << aux<< endl;
		
		contador-=2;
		contador2--;
	}
	if(operacao[contador] == "/"){
		aux/= paraInteiro(contas[contador-1]);
		cout << "Resultado: " << aux<< endl;	
		
		contador-=2;
		contador2--;
	}
	}
	
	return 0;
}