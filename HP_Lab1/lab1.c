#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

const int number = 20;

int main(){

  double a, b, c;
  int i,j,k,l;
  
  FILE*fichero;
  
  srand(time(NULL));

  printf("Insert two real numbers:\n");
  scanf("%lf %lf", &a, &b);
  printf("Random numbers from interval: %lf - %lf\n", a, b);

  for(i=0;i<number;i++){

    c = (double)rand() * ((fmod(a,b) + 1)+a); 

    printf("%lf ",c);
#ifdef DEBUG
    if(c<a || c>b) {
      printf("Generation error %lf\n", c); exit(0);
    }
#endif

  }
  
  srand(time(NULL));
  printf("Insert two integer numbers:\n");
  scanf("%d %d", &j, &k);
  printf("Random numbers from interval: %d - %d\n", j, k);

  for(i=0;i<number;i++){

    l = rand() % (k - j + 1) + j; 
    printf("%d \n",l);
    fichero = fopen("test.txt","wt");
    fichero(fichero, "%d", l);
    fclose(fichero);

#ifdef DEBUG
    if(l<j || l>k) {
      printf("Generation error %d\n", l); exit(0);
    }
#endif

  }
}

