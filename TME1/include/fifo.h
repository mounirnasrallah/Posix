/**
 * Definition d'une file
 **/


#define POSIX_SOURCE 1


/* Initialisation de la file */
int init_queue();

/* Operation d'enfilement */
int queue(void* element);

/* Operation de defilement ; l'element en fin est supprime */
void* dequeue();

/* Calcul du nombre d'elements dans la file */
int size();