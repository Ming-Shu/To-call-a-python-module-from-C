#include <stdio.h>
#include <stdlib.h>
#include <python2.7/Python.h>
#include "interface.h"

int  main(void){

	int a,b,c;

	a = 3;
	b = 4;
  
	c = HelloWorld(a,b);
	
	printf("The 'Helloworld' reuturn value is %d\n\n",c);

	return 0;  
} 
