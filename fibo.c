#include<stdio.h>
#include<time.h>

#define ITER 1000

/* fibonnaci en recursif */


int fib_recu(int n )
{
  if (n < 2)
    {
      return n ;
    }

  else {
    return fib_recu(n-1) + fib_recu(n-2);
  }

  return 0 ;
  
}

/* iteratif avec for */

int fib_iter(int n )
{
  int a , b  ;
  a = 0 ;
  b = 1 ;
  int i , c;
  for(i = 2 ; i <= n; i++)
    {
      c = a + b ;
      a = b ;
      b = c ;
    }

  return c ; 
}


/* iteratif avec while */

int fibiter_while(int n )
{
  int a , b , c ;
  a = 0;
  b = 1 ;
  while(n--)
    {
      c = a + b ;
      a = b ;
      b = c ;
      
    }

  return a ;
}


typedef unsigned long long int ullint;
struct paire {
  ullint fun;
  ullint fdeux;
} ;
typedef struct paire paire;


paire fiblog (int n) {
  paire mi, res;
  ullint fi;
  int i;

  if (n < 2) {
	res.fun = (ullint) 1;
	res.fdeux = (ullint) 1;
	return res;
  }
  i = n >> 1;
  mi = fiblog(i);
  if (n & 0x01) {
	res.fdeux = mi.fun * mi.fun + mi.fdeux * mi.fdeux;
	res.fun = (mi.fun + mi.fdeux + mi.fdeux) * mi.fun;
	return res;
  }
  res.fun = mi.fun * mi.fun + mi.fdeux * mi.fdeux;
  res.fdeux = (mi.fun + mi.fun - mi.fdeux) * mi.fdeux;
	/* car on cherche fib(n+1) */
  return res;
}
ullint fibo (int n) {
  paire res;
  if (n >= 0 && n < 92) {
	res = fiblog (n);
	return res.fun;
  }
  return (ullint) 0;
}



int main(int argc, char const **argv[])
{
  int i, n , resl, pas;
  ullint res;
  clock_t t0,t1,dt;

  n = 10 ;
  
   if(argc < 2)
     // n = 3;
  t0 = clock();
  for(i = 0; i < ITER ;i++)
    {
      fiblog(n);
           
    }

  t1 = clock();
  printf(" avec log %d\n",(int )(t1-t0));

  /** recursif */

 if(argc < 2)
   //n = 3;
  t0 = clock();
  for(i = 0; i < ITER ;i++)
    {
      fib_recu(n);
           
    }

  t1 = clock();
  printf(" avec la recursivité  %d\n",(int )(t1-t0));


   /** iteratif avec bouble for  */

 if(argc < 2)
   // n = 3;
  t0 = clock();
  for(i = 0; i < ITER ;i++)
    {
      fib_iter(n);
           
    }

  t1 = clock();
  printf(" iteratif boucle for  %d\n",(int )(t1-t0));




     /** iteratif avec bouble while  */

 if(argc < 2)
   // n = 3;
  t0 = clock();
  for(i = 0; i < ITER ;i++)
    {
      fibiter_while(n);
           
    }

  t1 = clock();
  printf(" iteratif boucle while  %d\n",(int )(t1-t0));
  
  
  return 0 ;
}
