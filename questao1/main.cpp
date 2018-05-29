/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa para detectar se a frase é palíndroma ou não
* @since 27/05/2018
* @date 28/05/2018
*/

#include <iostream>
#include "pilha.h"
#include <string>
#include <iterator>
#include <algorithm>
#include <cctype>

using std::string;
using namespace std;
using std::endl;

int main(int argc, char const *argv[])
{
/**
	@brief criação de 3 strings
	@param letra cada letra da frase
	@param norm_frase a frase em um vetor 
	@param rev_frase a frase ao contrário em um vetor
*/
	string letra;
	string norm_frase[50];
	string rev_frase[50];
/**
	@brief criação de 4 praâmetros inteiros
	@param aux_rev é o inteiro auxilar da frase reversa
	@param aux_norm é o inteiro auxiliar da frase normal
	@param i é simplesmente um controle
*/
	int aux_rev=1,aux_norm = 1, i;

	cout << "Digite sua frase" << endl;
	cout << "Caso não queira digitar mais, clique enter e digite '&' e clique enter para saber se a frase é palíndroma ou não."<< endl;
/** 
	@brief cria uma Pilha pilha recebendo strings
*/
	Pilha<string> pilha;
/**
	@brief laço para acabar com a leitura da frase
	@details sempre dando um pilha.push() em cada letra
*/
	while(letra != "&"){
		cin >> letra;
		pilha.push(letra);
	}
/**
	@brief retirando o '&' digitado com pilha.pop()
*/
	if(pilha.top() == "&")
	pilha.pop();
/**  
	@brief criação de um laço
	@details O laço serve para saber a hora de parar com a inversão da frase e implementação pro minúsculo, sempre dando um pilha.pop() para não ficar em loop infinito
*/
	while(pilha.size() >0){
/**
	@brief utilização do reverse para reverter a frase
	@details reverse tem seu começo em begin pilha.top(), pois pretende-se o contrario
*/
	std::reverse(std::begin(pilha.top()), std::end(pilha.top()));
    for(auto e : pilha.top()){
    	
    	rev_frase[aux_rev] = tolower(e);
    	cout << e;
    	aux_rev++;
    	}
    pilha.pop();
	}
	cout << endl;
/**
	@brief criação de um contador para dar cout em na frase normal
*/
	for(i =aux_rev-1;i >0;i--){
		norm_frase[aux_norm] = rev_frase[i];
		cout << norm_frase[aux_norm];
		aux_norm++;
	}
/**
	@brief criação de um laço, caso a norm_frase seja igual a rev_frase, imprimir que são palíndromas
*/
	cout << endl;
	int j=1,contador=1;
	while(j != aux_norm){
		if(norm_frase[j] == rev_frase[j]){
			j++;
			contador++;
		}
		else{
			cout << "Não é palíndroma!" << endl;
			j=aux_norm;
		}
		if(contador == aux_norm){
			cout << "É palíndroma!" << endl;
			exit(0);
		}
	}
	return 0;
}