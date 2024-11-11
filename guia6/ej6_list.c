#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addLast(struct node* n, int data) {
	
	struct node* curr = n;
	
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = 0;
	
	if (curr == NULL) {
		return new_node;
	}
	
	while (curr->next != 0) {
		curr = curr->next;
	}
	
	curr->next = new_node;
	
	return n;
}

struct node* removeFirst(struct node* n) {

    if(n!=0){
		struct node* temp = n;
		n = n->next;
		free(temp);
	}
    
    return n;
}

struct node* join(struct node* n1, struct node* n2) {
	
	struct node* new_list = 0;
	struct node* last = 0;
	
	struct node* curr = n1;
	while (curr != 0) {
		struct node* new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = curr->data;
		new_node->next = 0;
		
		if (new_list == 0) {
			new_list = new_node;
			last = new_node;
		} else {
			last->next = new_node;
			last = last->next;
		}
		
		curr = curr->next;
	}
	
	curr = n2;
	while (curr != 0) {
		struct node* new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = curr->data;
		new_node->next = 0;
		
		if (new_list == 0) {
			new_list = new_node;
			last = new_node;
		} else {
			last->next = new_node;
			last = last->next;
		}
		
		curr = curr->next;
	}
	
	return new_list;
}

struct node* removeData(struct node* n, int data) {
    
    // COMPLETAR
    
    return 0;
}

void printList(struct node* n) {
    printf("[");
    if(n == 0){
        printf("]\n");
    } else {
        while(n->next != 0){
            printf("%i, ", n->data);
            n = n->next;
        }
        printf("%i]\n", n->data);
    }
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct node *n1 = NULL;
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n1\n");
    n1 = addLast(n1, 2021);
    n1 = addLast(n1, 42);
    n1 = addLast(n1, 0x400);
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n2\n");
    struct node *n2 = NULL;
    n2 = addLast(n2, 0);
    n2 = addLast(n2, 42);
    printList(n2);
    printf("\n");
    
    printf("Join lista n1 y n2: n3\n");
    struct node *n3 = join(n1, n2);
    printList(n3);
    printf("\n");

    printf("RemoveFirst: n3\n");
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");
    /*
    printf("RemoveData: 42\n");
    n3 = removeData(n3, 42);
    printList(n3);
    printf("\n");
    
    printf("RemoveFirst dos veces: n3\n");
    n3 = removeFirst(n3);
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");

    // */

    return 0;
}
