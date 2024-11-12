#include <stdio.h>
#include <stdlib.h>

struct list {
    struct node *first;
    int size;
};

struct node {
    struct node *next;
    struct node *prev;
    char *data;
};

struct list* listNew() {
    struct list* l = (struct list*)malloc(sizeof(struct list));
    l->first = 0;
    l->size = 0;
    return l;
}

void listDelete(struct list* l) {
    struct node* n = l->first;
    while ( n != 0 ) {
        struct node* r = n;
        n = n->next;
        free(r);
    }
    free(l);
}

void listPrint(struct list* l) {
    struct node* n = l->first;
    printf("[");
    while ( n != 0 ) {
        printf("\"%s\"", n->data);
        n = n->next;
        if( n != 0 ) {
            printf(",");
        }
    }
    printf("]");
}

struct list* addFirst(struct list* l, char* data) {

	if(l == NULL){
		return NULL;
	}
    struct node* first = (struct node*)malloc(sizeof(struct node));
	first->prev = 0;
	first->data = data;
	l->size++;
	if(l->first == NULL){
		first->next = 0;
		l->first = first;
		return l;
	}
	first->next = l->first;
	l->first->prev = first;
	l->first = first;
    
    return l;
}

struct list* removeFirst(struct list* l) {

    if(l==NULL ||l->first == NULL){
		return NULL;
	}
	if(l->size == 1){
		struct node* temp = l->first;
		l->first = NULL;
		l->size--;
		free(temp);
		return l;
	}
	if(l->size == 0){
		return l;
	}
	struct node* temp = l->first;
    l->first = l->first->next;
	l->first->prev = NULL;
	l->size--;
	free(temp);
    return l;
}

struct list* removeNode(struct list* l, struct node* n) {
	if (l == NULL || l->first == NULL) {
		return NULL;
	}
	
    struct node* curr = l->first;
	while(curr!=0){
		if(curr->data == n->data){
			if(curr->prev == NULL){
				l->first = curr->next;
				curr->prev = NULL;
			}
			else if(curr->next == NULL){
				curr->prev->next = NULL;
			}
			else{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
			}
			l->size--;
			struct node* temp = curr;
			curr = curr->next;	
			free(temp);
		}
		else{
			curr = curr->next;	
		}
	}
    
    return l;
}

struct list* removeNodei(struct list* l, int i) {

	if(i>=0 && l->size-1>=i){
		struct node* curr = l->first;
		for(int j = 0; j<l->size; j++){
			if(j == i){
				struct node* temp = curr;
				if(i==0){
					l = removeFirst(l);
				}
				else if(curr->next == NULL){
					curr->prev->next = NULL;
					l->size--;	
					free(temp);
				}
				else{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
					l->size--;	
					free(temp);
				}
				return l;
			}
			curr = curr->next;
		}
	}
    
    return l;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct list* l = listNew();
    l = addFirst(l, "back");
    struct node* toRemove1 = l->first;
    l = addFirst(l, "swim");
    l = addFirst(l, "for");
    l = addFirst(l, "anything");
    struct node* toRemove2 = l->first;
    l = addFirst(l, "save");
    l = addFirst(l, "never");
    struct node* toRemove3 = l->first;
    l = addFirst(l, "I");
    listPrint(l);
    printf("\n\n");

    printf("RemoveFirst\n");
    l = removeFirst(l);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove1->data);
    l = removeNode(l, toRemove1);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove2->data);
    l = removeNode(l, toRemove2);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove3->data);
    l = removeNode(l, toRemove3);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 0\n");
    l = removeNodei(l, 0);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 1\n");
    l = removeNodei(l, 1);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 0\n");
    l = removeNodei(l, 0);
    listPrint(l);
    printf("\n\n");

    listDelete(l);

    // */

    return 0;
}
