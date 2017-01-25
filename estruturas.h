/*
 * Definição de uma estrutura auxiliar para guardar os valores das horas de partida dos voos constítuido por um
 * inteiro que aramazena a componente das horas e outro que aramazena os minutos
 */
typedef struct
{
	int horas;
	int mins;
} HORAS;


/*
 * De modo a facilitar o processamento de dados para o output, decidimos criar uma estrutura que guarda as informações
 *necessárias sobre cada aeroporto, para que no final seja apenas necessário fazer a escrita delas no ficheiro out.txt
 *Esta estrutura tem a seguinte forma:
 *										-----------------------------------------------------
 *										|									|Número de			|Número de				|
 *										|Nome do aeroporto|partidas	neste	|chegadas	a				|
 *										|									|Aeroporto			|este Aeroporto		|
 *										-----------------------------------------------------
 *										|Destino mais 		|Destino com		|Apontador para		|
 *										|barato						|partida mais		|o próximo 				|
 *										|									|tardia					|Aeroporto				|
 *										-----------------------------------------------------
 *										|Preço do 				|Horas da				|
 *										|destino mais			|partida mais		|
 *										|barato						|tardia					|
 *										-----------------------------------
 *Assim ao manter os aeroportos por ordem alfabetica e com os dados necessários para o output actualizados em tempo
 *real, conseguimos, depois do pedido de informação, fazer um output muito mais rápido.
 */

struct aeroporto
{
	char nome[3+1];
	int partidas;
	int chegadas;
	char maisbarato[3+1];
	char maistarde[3+1];
	struct aeroporto *proximo;
	long double preco;
	HORAS horas;
};

/*
 *Definição do tipo que aponta para uma estrutura aeroporto
 */
typedef struct aeroporto * LISTA;

