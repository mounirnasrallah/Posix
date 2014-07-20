/**
 * Definition d'une pile
 **/


#define POSIX_SOURCE 1


/* Initialisation de la pile */
int init_stack();

/* Operation d'empilement */
int push(void* element);

/* Operation de depilement ; l'element au sommet est supprime */
void* pop();

/* Calcul du nombre d'elements dans la pile */
int size();
