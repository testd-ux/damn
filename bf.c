#include<stdio.h>
#define max 25
int i,j,k=0,nb,nf,temp=0;
int lowest;
void bestfit(int b[],int f[])
{
  for(i=1;i<=nf;i++)
   {
    lowest=999;
      for(j=1;j<=nb;j++)
         { 
             temp=b[j]-f[i];
              if(temp>=0&& temp<lowest)
               {
                   k=j;
                   lowest = temp;
                   }
                   }
   if(lowest!=999){

     
   printf("\nFile size %d is put in %d partition\n",f[i],b[k]);
               b[k]=temp;
   }else{
          printf("\nFile size %d must wait\n",f[i]);
   }}}
   
   int main()
{
      int b[max],f[max];
 printf("\nBest Fit\n\n");     

 printf("\nEnter no of block : ");
 scanf("%d",&nb);
 
  printf("\nEnter no of files : ");
 scanf("%d",&nf);
printf("\n_____________________________\n");
   printf("\nEnter size of blocks\n");
     for(i=1;i<=nb;i++){
    printf("\nBlock %d : ",i);
          scanf("%d",&b[i]);
          }
  printf("\n_____________________________\n");
             printf("\nEnter size of files\n");
               for(i=1;i<=nf;i++){
               printf("\nfile %d : ",i);
                  scanf("%d",&f[i]);
                  
              }
printf("\n_____________________________\n");
       bestfit(b,f);
       return 0;
      }
   
