#include<stdio.h>

#define size 15

int dopisz(int *g, int liczba, int tail, int head);
int usun(int *g, int head, int tail);
void wyswietl(int *g);
void inicjalizuj(int *g);


int main () {
  int wybor;
  int g[size];
  int head=0;
  int tail=0;
  int nextInt;
  
  inicjalizuj(g);
  
  do{
    printf(".-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-.\n");
    printf("            ..::MENU::..\n");
    printf("0 - Zakonczenie programu\n");
    printf("1 - Dopisanie elementu do kolejki\n");
    printf("2 - Usuniecie elementu z kolejki\n");
    printf("3 - Wyswietlenie zawartosci kolejki\n");
    printf(".-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-.\n");
    scanf("%i",&wybor);
    
    switch(wybor) {
    case 0 :
      printf("Kriejted baj Sz. Rekawek\n");
      break;
    case 1 : 
      printf("Podaj jaka liczbe chcesz dodac: ");
      scanf("%i", &nextInt);
      
      tail = dopisz(g, nextInt, tail, head);
      tail%=size;
      break;
    case 2 :
      head = usun(g, head, tail);
      head%size;
      break;
    case 3 :
      wyswietl(g);
      break;
    default :
      printf("Nie ma takiej pozycji w menu.\n");
    }
  }while(wybor != 0);

  return 0;
}

int usun(int *g, int head, int tail) {
  if(head == tail) {
    printf("Kolejka pusta\n");
    return head;
  }
  
  else {
    g[head] = 0;
    return ++head;
  }
}

int dopisz(int *g, int liczba, int tail, int head) {
  if((tail+1)%size == head) {
    printf("Kolejka pelna\n");
    return tail; 
  }
  
  else {
    g[tail] = liczba;
    return ++tail; 
  }
}

void wyswietl(int *g) {
  int i;
  printf("ZAWARTOSC KOLEJKI:\n");
  printf("|");
  for(i=0;i<size;i++)
    printf(" %i |", g[i]);
  printf("\n");
}

void inicjalizuj(int *g) {
  int i;
  for(i=0;i<size;i++)
    g[i] = 0;
}
