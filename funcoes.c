/*
 * Função que compara duas estruturas do tipo HORAS e devolve 
 */

int cmphoras(HORAS var1, HORAS var2)
{
	if((var1.horas) == (var2.horas))
		return (var1.mins) > (var2.mins);
	else
		if((var1.horas) > (var2.horas))
			return (var1.horas) > (var2.horas);
		else
			return 0;
}


/*
 *Definição do tipo que representa os ponteiros para as estruturas onde se guardam os dados
 */



/* 
 * reverse:  inverte a string s  
 */
void reverse(char s[])
{
	int i, j;
	char c;
 
	for (i = 0, j = strlen(s)-1; i<j; i++, j--)
		{
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
}

/* 
 * itoa: converte uma string para um numero inteiro 
 */
void itoa(int n, char s[])
 {
	int i, sign;
	if ((sign = n) < 0)   
			n = -n;          
	i = 0;
	do 
	{  
			s[i++] = n % 10 + '0';  
	} 
	while ((n /= 10) > 0);    
  if (sign < 0)
			s[i++] = '-';
	s[i] = '\0';
	reverse(s);
 }

/* 
 * converte: Coloca dois inteiros numa estrutura do tipo HORAS e devolve a mesma  
 */
HORAS converte(int h, int m)
{
	HORAS aux;
	aux.horas = h;
	aux.mins = m;
	return aux;
}


/*
 * Função usada para inicializar o ponteiro que irá (eventualmente) apontar para o inicio da lista de dados
 */
void inic(LISTA* lista)
{
	*lista = NULL;
}

/*
 * Esta função procura um aeroporto na lista dos dados e caso não a encontre irá alocar memória para a guardar
 * colocando o último elemento da lista a apontar para a nova estrutura e dando o nome do aeroporto a essa 
 * estrutura. Se encontrar o aeroporto na lista apenas actualiza a lista dos dados incrementando o valor de 
 * partidas na estrutura correspondente. No caso de criar uma estrutura ele também inicializa a mesma
 */
void insereOrigem(char *aeronome, LISTA *lista){
	if (*lista	== NULL)
		{
			HORAS aux = {-1, -1};
			*lista = (LISTA) malloc(sizeof(struct aeroporto));
			strcpy((*lista)->nome, aeronome);
			(*lista)->proximo = NULL;
			(*lista)->partidas = 1;
			(*lista)->preco= -1.0;
			strcpy((*lista)->maisbarato, "000");
			strcpy((*lista)->maistarde, "000");
			(*lista)->horas = aux;
		}
	else
		if ( (strcmp(aeronome, (*lista)->nome)) == 0)
				(*lista)->partidas = ++(*lista)->partidas;
		else
			insereOrigem(aeronome, &(**lista).proximo);
}


/*  
 * Esta função funciona exactamente como a função insereOrigem, no entanto em vez de se aplicarem as alterações
 * às partidas, aplicam-se às chegadas das estruturas (incrementa-se o valor). 
 */
void insereDestino(char *aeronome, LISTA *lista){
	if(*lista	== NULL)
		{	
			HORAS aux = {-1, -1};
			*lista = (LISTA) malloc(sizeof(struct aeroporto));
			strcpy((*lista)->nome, aeronome);
			(*lista)->proximo = NULL;
			(*lista)->chegadas = 1;
			(*lista)->preco = -1.0;
			strcpy((*lista)->maisbarato, "000");
			strcpy((*lista)->maistarde, "000");
			(*lista)->horas = aux;
		}
	else
		if ( (strcmp(aeronome, (*lista)->nome)) == 0)
				(*lista)->chegadas = ++(*lista)->chegadas;
		else
			insereDestino(aeronome, &(**lista).proximo);
}


/*   
 * Esta função recebe um aeroporto (aeroorig) para procurar na lista de dados (lista) e comparar o preço do
 * voo mais barato com partida nesse aeroporto com o preço fornecido à função (euro). Caso o preço seja mais
 * barato do que o voo que lá se encontra ele troca o o nome do aeroporto com voo mais barato pelo nome
 * fornecido (aerodest)
 */
void insereMaisBarato(char *aeroorig, char *aerodest, long double euro, LISTA *lista)
{
	if((strcmp((*lista)->nome, aeroorig)) == 0)
		{
			if((*lista)->preco == -1.0)
				{
					(*lista)-> preco = euro;
					strcpy( (*lista)->maisbarato, aerodest);
					return ;
				}
			else
				if(euro < (*lista)->preco)
						{
							(*lista)->preco = euro;
							strcpy ((*lista)->maisbarato, aerodest);
							return ;
						}
		}
	else
		insereMaisBarato(aeroorig, aerodest, euro, &(**lista).proximo);
		 
}	


/*  
 * Esta função funciona de maneira igual ao insereMais Barato, no entanto as alterações que se 
 * verificam tem como base no aeroporto com as horas de partida mais tarde, ou seja ele compara
 * as horas fornecidas com as horas da estrutura e se as horas fornecidas forem maiores ele coloca
 * o aerodest 
 */
void insereMaisTarde(char *aeroorig , char *aerodest , HORAS h, LISTA *lista)
{
	if(strcmp((*lista)->nome, aeroorig) ==0)
		{
			if(cmphoras(h, (*lista)->horas))
				{
					(*lista)->horas = h;
					strcpy ( (*lista)->maistarde, aerodest);
					return ;
				}
			else
				return ;
		}
	else
		insereMaisTarde(aeroorig, aerodest, h, &(**lista).proximo);
		 
}	


/*  
 * A função procura pelo aeoroporto (aeronome) na lista dos dados (lista) e ao encontrá-la coloca os 
 * valores no vector output devolvendo-o    
 */
char* mostra(char *aeronome, char *output, LISTA *lista)
{
	if (*lista	== NULL)
		{
			strcpy(output, aeronome);
			strcat(output, " 0 0 000 000");
			return output;
		}
	else
		if ( (strcmp(aeronome, (*lista)->nome)) == 0)
			{	
				int aux1 = (*lista)->partidas, aux2 = (*lista)->chegadas;
				char vaux1[4+1], vaux2[4+1];
				itoa(aux1, vaux1);
				itoa(aux2, vaux2);
				strcpy(output, (*lista)->nome);
				strcat(output, " ");
				strcat(output, vaux1);
				strcat(output, " ");
				strcat(output, vaux2);
				strcat(output, " ");
				strcat(output, (*lista)->maisbarato);
				strcat(output, " ");
				strcat(output, (*lista)->maistarde);
				return output;
			}
		else
			{
				output = mostra(aeronome, output, &(**lista).proximo);
				return output;
			}
}

/*  
 * Esta função vai contar o número de aeroportos (estruturas) existentes na lista de dados (lista)
 */
int mostraNumAero(LISTA *lista, int contador)
{
	if(*lista	== NULL)
		return contador;
	else
		return mostraNumAero(&(**lista).proximo, ++contador);
		
}


