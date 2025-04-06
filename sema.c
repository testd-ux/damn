#include<stdio.h>
#include<stdlib.h>
int m=1,f=0,e=3,x=0;
int signal(int s)
{
return(++s);
}
int wait(int s)
{
return(--s);
}
void produce()
{
e=wait(e);
m=wait(m);
x++;
printf("\nProducer produced item %d\n",x);
m=signal(m);
f=signal(f);
}


void consume()
{
f=wait(f);
m=wait(m);
printf("\nconsumer consumed the item %d\n",x);
x--;
m=signal(m);
e=signal(e);
}
void main(){
int n;
	printf("\n 1 : Producer\n 2 : Consumer\n 3 : Exit\n");
	do{
	printf("\nChose one option 1 , 2 or 3 : ");
	scanf("%d", &n);
	switch(n)
		{
	case 1:
		if (m==1&&e!=0)
          produce();
	else{
		printf("Buffer is Full\n\n");
                }
	    break;
	case 2:
	    	if (m==1&&f!=0)
          consume();
	else{
		printf("Buffer is empty\n\n");
                }
                break;
    case 3:
		 exit(0);
	      break;
		}
	}
        while (n!=3);
}	
