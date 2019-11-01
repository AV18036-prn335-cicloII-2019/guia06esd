#include<stdio.h>
#include<stdlib.h>

#define bool int


struct nodo1{

    struct nodo1 *next;
    int value;

};

struct pila{

    struct nodo1 *top;
    int cant1;

};


void init(struct pila *miPila){

    miPila->top = NULL;
    miPila->cant1 = 0;

}

bool isEmpty(struct pila *miPila){

    return miPila->cant1 == 0;

}

int size(struct pila *miPila){

    return miPila->cant1;

}

bool top(struct pila *miPila){

    return miPila->top->value;

}

void push(struct pila *miPila, int value){

    miPila->cant1 ++;

    struct nodo1 * nuevo = malloc(sizeof(struct nodo1));
    nuevo->value = value;

    struct nodo1 *temp = miPila->top;
    miPila->top = nuevo;
    nuevo->next = temp;

}

void pop(struct pila *miPila){

    if(isEmpty(miPila)){
        printf("Error: pop en pila vacia.\n");
        return;
    }

    miPila->cant1 --;

    struct nodo1 *temp = miPila->top;
    miPila->top = temp->next;
    free(temp);

}

void replace(struct pila *miPila, int nuevo, int viejo){

    if(isEmpty(miPila)){
        printf("La pila esta vacia por el momento.\n");
    }

    struct nodo1 *curr = miPila->top;

    while(NULL != curr->next){


        if(curr->value == viejo){

            printf("Encontrado el valor buscado.\n");

            curr->value = nuevo;

            return;

        }

        curr = curr->next;

    }

    printf("No encontrado lo que desea .\n");

}

int main(){

    int n;
    printf("Ingrese numero de elementos que tendra .\n");
    scanf("%d",&n);

    struct pila * miPila = malloc(sizeof(struct pila));

    init(miPila);

    int a;

    printf("Ingrese los elementos que usted desea\n");

    for(int i = 0; i < n; i++){

        scanf("%d",&a);

        push(miPila,a);

    }

    int nuevo;
    int viejo;

    printf("Ingrese elemento a buscar que usted desea.\n");
    scanf("%d",&viejo);

    printf("Ingrese elemento nuevo a añadir.\n");
    scanf("%d",&nuevo);

    replace(miPila,nuevo,viejo);

    printf("El orden inverso de los elementos esta de la siguiente manera:\n");

    while(!isEmpty(miPila)){

        printf("%d ",top(miPila));
        pop(miPila);

    }
    printf("\n");

    return 0;
}