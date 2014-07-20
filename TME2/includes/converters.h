/**** converters.h ****/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


/* Nb de pcs convertisseurs (exo 3) */
#define NB_CONVERTERS 5

/* Identifiant pour convertisseur d'euros */
#define EUR_CONV 0
/* Identifiant pour convertisseur de livres sterling */
#define GBP_CONV 1 
/* Identifiant pour convertisseur de dollars US */
#define USD_CONV 2 
/* Identifiant pour convertisseur de yens */
#define JPY_CONV 3 
/* Identifiant pour convertisseur de yuans */
#define CNY_CONV 4 

/* Taux de change euro */
#define EUR 1			
/* Taux de change livre sterling */
#define GBP 0.8796		
/* Taux de change dollar US */
#define USD 1.3605		
/* Taux de change yen */
#define JPY 124.25		
/* Taux de change yuan */
#define CNY 6.8264		


/* Message de conversion.
	Un client pour une conversion envoie un message contenant :
		- son pid
		- la devise d'origine
		- le montant a convertir
	Un convertisseur renvoie :
		- son pid
		- la devise cible
		- le montant apres conversion */
typedef struct conv_msg {
	pid_t pid_sender;		/* pid du pcs emetteur */
	char currency[3];		/* devise */
	double amount;			/* montant */
} conversion_message;

/* Tableau de resultats de conversion (exos 2 et 3) */
typedef conversion_message results_array[NB_CONVERTERS];

/* Convertit d'une devise vers une autre.
	input_currency :	devise d'origine
	target_currency :	devise cible
	input_amount :		montant a convertir */
double convert(char* input_currency, char* target_currency, double input_amount);

/* Traite une requete de conversion.
	request :	requete
	result :	resultat de la conversion
	conv_nb :	numero de conversion ; definit la devise cible ; cf. identifiants en debut de fichier. */
void handle_conversion_request(conversion_message request, conversion_message *result, int conv_nb);

/* Affiche le contenu d'une reponse a une requete de conversion. (exos 2 et 3)
	request :			requete d'origine
	results_array :		tableau des resultats de conversion */
void display_results(conversion_message request, results_array results);

char* determine_currency(int curr_nb);
