#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct list {
    struct node *first;
    int size;
};

struct node {
    struct node *next;
    struct elem *data;
};

struct elem {
    float x;
    float y;
    int   i;
    char  t;
};

struct list* listNew() {
    struct list* l = (struct list*)malloc(sizeof(struct list));
    l->first = 0;
    l->size = 0;
    return l;
}

void listAdd(struct list* l, float x, float y, int i, char t) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    struct elem* e = (struct elem*)malloc(sizeof(struct elem));
    e->x = x;
    e->y = y;
    e->i = i;
    e->t = t;
    n->data = e;
    n->next = l->first;
    l->first = n;
    l->size = l->size + 1;
}

void listDelete(struct list* l) {
    struct node* n = l->first;
    while ( n != 0 ) {
        struct node* r = n;
        n = n->next;
        free(r->data);
        free(r);
    }
    free(l);
}

void listPrint(struct list* l) {
    struct node* n = l->first;
    printf("[");
    while ( n != 0 ) {
        struct elem* e = n->data;
        printf("(%f,%f,%i,%i)", e->x, e->y, e->i, e->t);
        n = n->next;
        if( n != 0 ) {
            printf(",");
        }
    }
    printf("]");
}

float magnitudeAverage(struct list* ls) {
	
	if (ls == NULL || ls->first == NULL || ls->size == 0) {
		return 0;
	}
	
	struct node* curr = ls->first;
	float prom = 0;
	while(curr!=0){
		prom += sqrt((curr->data)->x * (curr->data)->x + (curr->data)->y * (curr->data)->y);
		curr = curr->next;
	}

	prom = prom / ls->size;
    
    return prom;    
}

int sorted(struct list* ls) {

	if (ls == NULL || ls->first == NULL || ls->size == 0) {
		return 0;
	}
	
    struct node* curr = ls->first;
	int num = curr->data->i;
	while(curr->next!=0){
		if(curr->data->i > curr->next->data->i){
			return 0;
		}
		curr = curr->next;
	}
    
    return 1;    
}

void numerate(struct list* ls) {

	if (ls == NULL || ls->first == NULL || ls->size == 0) {
		return;
	}
	
    struct node* curr = ls->first;
	int i = 0;
	while(curr!=0){
		curr->data->t = i;
		i++;
		curr = curr->next;
	}

}

void swap(struct list* ls, int i, int j) {
	if (ls == NULL || ls->first == NULL || i < 0 || j < 0 || i >= ls->size || j >= ls->size || i == j) {
		return;
	}
	
	struct node* curr = ls->first;
	struct node* node_i = NULL;
	struct node* node_j = NULL;
	
	int index = 0;
	while (curr != NULL) {
		if (index == i) {
			node_i = curr;
		}
		if (index == j) {
			node_j = curr;
		}
		curr = curr->next;
		index++;
	}
	
	struct elem* temp = node_i->data;
	node_i->data = node_j->data;
	node_j->data = temp;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct list* l = listNew();
    listAdd(l, 30.0, 30.0, 30, 30);
    listAdd(l, 20.0, 20.0, 20, 20);
    listAdd(l, 10.0, 10.0, 10, 10);

    listPrint(l);
    printf("\n");
    float f = magnitudeAverage(l);
    printf("El modulo de los elementos x e y de la lista es: %f\n\n",f);

    listPrint(l);
    printf("\n");
    int i = sorted(l);
    printf("Los elementos de la lista estan ordenados: %i\n\n",i);

    listPrint(l);
    printf("\n");
    numerate(l);
    printf("Los elementos de la lista luego de numerarlos:\n");
    listPrint(l);
    printf("\n\n");

    listPrint(l);
    printf("\n");
    swap(l, 0, 1);
    printf("Los elementos con indices 0 y 1 estan intercambiados:\n");
    listPrint(l);
    printf("\n\n");

    listDelete(l);

    // */

    return 0;
}
