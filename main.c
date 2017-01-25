#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"
#include "funcoes.c"

/*
 * Protótipos das funções
 */
void reverse(char s[]);
void itoa(int n, char s[]);
void inic(LISTA *lista);
void insereOrigem(char *aeronome, LISTA *lista);
void insereDestino(char *aeronome, LISTA *lista);
void insereMaisBarato(char *aeroorig, char *aerodest, long double euro, LISTA *lista);
void insereMaisTarde(char *aeroorig , char *aerodest , HORAS h, LISTA *lista);
char* mostra(char *aeronome, char *output, LISTA *lista);
int mostraNumAero(LISTA *lista, int contador);

/*
 * Função main que efectua a leitura do ficheiro in.txt, pede às funções definidas em funcoes.c para actualizarem 
 * a lista dos dados e quando forem lidas em que o primeiro caracter é 'i' ele faz printf da informação pedida.
 */

int main()
{
	int nl, hInicioMin, hInicioHora;
	int i = 0;
	char linha[100+1];  
	char companhia[6+1], aeroO[3+1], aeroD[3+1], hFim[5+1];
	char output[20+1]; 
	char aerop[3+1];
	double preco;
	LISTA dados = NULL;
	inic(&dados);
	scanf("%d", &nl);


	for(i = 0 ; i < nl; i++)
		{
			scanf("%s ", linha);
			if (strcmp(linha, "v") == 0)
				{
					scanf("%s %s %s %d:%d %s %lf", companhia, aeroO, aeroD, 
																				&hInicioHora, &hInicioMin, hFim, &preco);		
					insereOrigem(aeroO, &dados);
					insereDestino(aeroD, &dados);
					insereMaisBarato(aeroO, aeroD, preco, &dados);
					insereMaisTarde(aeroO, aeroD, converte( hInicioHora, hInicioMin) , &dados);
				}
			else
				{				
					scanf(" %s" , aerop);
					printf ("%s\n", mostra(aerop, output, &dados));
				}
		}
	printf("%d\n", mostraNumAero(&dados, 0));
		
	return 0;
}





