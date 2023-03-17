#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <windows.h>
#include <conio.h>

//JUEGO DE ADIVINAR EL PATRON. JOSE CARRILLO - ACT 3. ESTRUCTURAS DINAMICAS DE DATOS

int j = 1, k = 1;


struct nodo{
    int data;
    struct nodo* sig;
};

struct cola{
    struct  nodo  *primero, *ultimo;
};

struct  nodo *crearNodo (int data){
    struct nodo * nuevo =  (struct nodo*) malloc(sizeof(struct  nodo));

    nuevo->data = data;
    nuevo->sig  = NULL;
    return nuevo;
};

struct cola * crearCola(){
    struct cola * c = (struct cola*)  malloc (sizeof (struct cola));
    c -> primero = c-> ultimo = NULL;
    return c;
};

void  enQueue (int data, struct cola** c){

    struct nodo* nuevo =  crearNodo(data);
    if((*c )->primero == NULL){
        (*c )->primero = (*c )->ultimo = nuevo;
    return;
    };

    (*c )-> ultimo->sig = nuevo;
    (*c) -> ultimo = nuevo;
    j++;
}


int  deQueue(struct cola ** c){
     if( (*c )->primero==NULL)  return INT_MIN;

     struct nodo *eliminado = (*c) -> primero ;
      int data = eliminado -> data;

      (*c) ->primero = eliminado -> sig;

      if((*c) -> primero == NULL){
        (*c) -> ultimo = NULL;
      }

      free(eliminado);
j--;

      return data;
}


void mostrar (struct cola ** c){
    if ( (*c )->primero==NULL) return;
    

    struct nodo* actual  = (*c )->primero;
int i = 1;
    while(actual){

printf ("Nivel #%d:\n\n", k);
    	
    	printf("Primer valor: %d\n\nUltimo valor (#%d): %d\n\n", (*c )->primero->data, j, (*c )->ultimo->data );
        printf ("Valor actual (#%d): %d", i, actual->data);
        actual = actual -> sig;
        getch();
        system ("cls");
        i++;
    }

    return;
}

int main (){


	
struct cola  * c = crearCola();


printf ("Bienvenido al Adivina Patrones!\nHay 4 niveles con patrones que debes adivinar viendo la menor cantidad de numeros del patron posibles.\nBuena suerte!!\n\n");


    enQueue(10, &c);
    enQueue(20, &c);
    enQueue(30, &c);
    enQueue(40, &c);
    enQueue(50, &c);
    enQueue(60, &c);
    enQueue(70, &c);
    enQueue(80, &c);
    enQueue(90, &c);

 mostrar(&c);

for (int i=0; i<9; i++){
	deQueue(&c);  
}

k++;
j++;

    enQueue(4, &c);
    enQueue(7, &c);
    enQueue(12, &c);
    enQueue(19, &c);
    enQueue(28, &c);
    enQueue(39, &c);
    enQueue(52, &c);
    enQueue(67, &c);

 mostrar(&c);

for (int i=0; i<8; i++){
	deQueue(&c);  
}

k++;
j++;

    enQueue(3, &c);
    enQueue(8, &c);
    enQueue(11, &c);
    enQueue(19, &c);
    enQueue(30, &c);
    enQueue(49, &c);
    enQueue(79, &c);

 mostrar(&c);

for (int i=0; i<7; i++){
	deQueue(&c);  

}

k++;
j++;

    enQueue(1, &c);
    enQueue(2, &c);
    enQueue(6, &c);
    enQueue(24, &c);
    enQueue(120, &c);
    enQueue(720, &c);

 mostrar(&c);

for (int i=0; i<6; i++){
	deQueue(&c);  
}

printf ("Gracias por jugar!!");
    return 0;
}
