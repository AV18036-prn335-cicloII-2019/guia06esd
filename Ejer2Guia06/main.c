#include<stdio.h>
#include<stdlib.h>

#define bool int

struct nodo1{

    struct nodo1 *next1;
    int value;

};

struct pila{

    struct nodo1 *top;
    int cant;

};


void init(struct pila *miPila){

    miPila->top = NULL;
    miPila->cant = 0;

}

bool isEmpty(struct pila *miPila){

    return miPila->cant == 0;

}

int size(struct pila *miPila){

    return miPila->cant;

}

bool top(struct pila *miPila){

    return miPila->top->value;

}

void push(struct pila *miPila, int value){

    miPila->cant ++;

    struct nodo1 * nuevo = malloc(sizeof(struct nodo1));
    nuevo->value = value;

    struct nodo1 *temp = miPila->top;
    miPila->top = nuevo;
    nuevo->next1 = temp;

}

void pop(struct pila *miPila){

    if(isEmpty(miPila)){
        printf("Error: pop en pila vacia.\n");
        return;
    }

    miPila->cant --;

    struct nodo1 *temp = miPila->top;
    miPila->top = temp->next1;
    free(temp);

}


int main(){

    int n;
    printf("Ingrese numero de elementos.\n");
    scanf("%d",&n);

    struct pila * miPila = malloc(sizeof(struct pila));

    init(miPila);

    int a;

    printf("Ingrese los elementos que usted desea\n");

    for(int i = 0; i < n; i++){

        scanf("%d",&a);

        push(miPila,a);

    }

    printf("El orden inverso de los elementos esta de esta manera:\n");

    while(!isEmpty(miPila)){

        printf("%d ",top(miPila));
        pop(miPila);

    }
    printf("\n");


    return 0;
}