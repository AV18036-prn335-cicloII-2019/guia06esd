#include<stdio.h>
#include<stdlib.h>

#define bool int
#define true 1
#

struct nodo1{

    struct nodo1 *next1;
    int value;

};

struct pila{

    struct nodo1 *top1;
    int cant;

};


void init(struct pila *miPila){

    miPila->top1 = NULL;
    miPila->cant = 0;

}

bool isEmpty(struct pila *miPila){

    return miPila->cant == 0;

}

int size(struct pila *miPila){

    return miPila->cant;

}

bool top1(struct pila *miPila){

    return miPila->top1->value;

}

void push(struct pila *miPila, int value){

    miPila->cant ++;

    struct nodo1 * nuevo = malloc(sizeof(struct nodo1));
    nuevo->value = value;

    struct nodo1 *temp = miPila->top1;
    miPila->top1 = nuevo;
    nuevo->next1 = temp;

}

void pop(struct pila *miPila){

    if(isEmpty(miPila)){
        printf("Error: pop en pila se encuentra vacia.\n");
        return;
    }

    miPila->cant --;

    struct nodo1 *temp = miPila->top1;
    miPila->top1 = temp->next1;
    free(temp);

}

int main(){

    int op;
    int value;

    struct pila *miPila = malloc(sizeof(struct pila));
    init(miPila);

    while(true){

        printf("\nIngrese opcion que desea:\n");
        printf("0. Salir.\n");
        printf("1. Insertar nuevo valor.\n");
        printf("2. Ver ultimo elemento de la pila.\n");
        printf("3. Eliminar ultimo elemento de la pila .\n");
        printf("4. Revisar tamanio.\n");
        printf("5. Revisar si vacio.\n\n");

        scanf("%d", &op);

        switch(op){

            case 0:

                return 0;

                break;

            case 1:

                printf("Ingrese valor que desea.\n");
                scanf("%d", &value);

                push(miPila,value);

                break;

            case 2:

                printf("El ultimo elemento de la pila es:\n");
                printf("%d\n",top1(miPila));
                break;

            case 3:

                printf("Eliminar elemento de la pila");
                pop(miPila);

                break;

            case 4:
                printf("El tamanio de la pila es de:\n");
                printf("%d elementos.\n",size(miPila));

                break;

            case 5:

                if(isEmpty(miPila)){

                    printf("La pila se encuentra vacia.\n");

                }else{

                    printf("La pila tiene elementos\n");

                }

                break;

        }

    }

    return 0;
}