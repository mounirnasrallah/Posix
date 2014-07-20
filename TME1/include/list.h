/**
 * Definition d'une liste doublement chainee 
 **/


#define POSIX_SOURCE 1


typedef struct cell_type {
	struct cell_type *previous;
	struct cell_type *next;
	void *content;
} cell;


struct list_type {
	cell* head;
	cell* tail;
};


/* Initialisation de la liste */
void init_list(struct list_type *l);

/* Insertion d'un element en tete de liste */
void insert_head(struct list_type *l, void* element);

/* Extraction (avec suppression) d'un element en tete de liste */
void* extract_head(struct list_type *l);

/* Extraction (avec suppression) d'un element en fin de liste */
void* extract_tail(struct list_type *l);

/* Calcul du nombre d'elements dans la liste */
int list_size(struct list_type *l);