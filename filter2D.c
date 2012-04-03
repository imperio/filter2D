#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<conio.h>

double **e(double **ptr,int row,int column,float sigma){
      int i,j,x=-(row-1)/2,y=-(column-1)/2;
      double sum=0;
      for(i=0;i<row;i++)
         for(j=0;j<column;j++){
           ptr[i][j]=exp(-((x+i)*(x+i)+(y+j)*(y+j))/(2*sigma*sigma));
           sum+=ptr[i][j];
}
      for(i=0;i<row;i++)
        for(j=0;j<column;j++)
           ptr[i][j]/=sum;

      return ptr;
}
double **allocate(double **ptr,int row,int column){
   int i;
   ptr=(double **)calloc(row,sizeof(double));
     for(i=0;i<row;i++)
     
   ptr[i]=(double *)calloc(column,sizeof(double));
    return ptr;
}
void print(double **ptr,int row,int column){
     int i,j;
     for(i=0;i<row;i++){
        for(j=0;j<column;j++)
     printf("%f ",ptr[i][j]);
     printf("\n");
}}

int main(){
    double **arr2,**filter,**arr1,**Ix,**Iy,**Ixx,**Ixy,**Iyy;
    double kernel[1][3]={1.0,-2.0,1.0};
    float sigma;
    int r1,r2,r3,c1,c2,c3,i,j,k,l;
srand(time(NULL));

    printf("enter row and column for array1\n");
    scanf("%d%d",&r1,&c1);
    printf("enter row and column for exp\n");
    scanf("%d%d",&r2,&c2);
    printf("enter sigma for exp\n");
    scanf("%f",&sigma);
    
r3=(r1-r2)+1;
c3=(c1-c2)+1;
printf("\narr1\n");

arr1=allocate(arr1,r1,c1);
if(arr1){
   for(i=0;i<r1;i++)
      for(j=0;j<c1;j++)
   arr1[i][j]=rand()%10;
   print(arr1,r1,c1);

}
   printf("\narr2\n");
   
   arr2=allocate(arr2,r2,c2);
   if(arr2){
   arr2=e(arr2,r2,c2,sigma);
   print(arr2,r2,c2);
}
  filter=allocate(filter,r3,c3);
  
  printf("\nfilter\n");
  if(filter){
for(i=0;i<r3;i++)
   for(j=0;j<c3;j++)
      for(k=0;k<r2;k++)
         for(l=0;l<c2;l++)
              filter[i][j]+=arr1[i+k][j+l]*arr2[k][l];
              print(filter,r3,c3);
}
//Ix Ixx icin
Ix=allocate(Ix,r3,c3-2);
Ixx=allocate(Ixx,r3,c3-2);

   for(i=0;i<r3;i++){
      for(j=0; j<c3-2 ;j++){
          Ix[i][j]=filter[i][j]*kernel[0][0]+filter[i][j+1]*kernel[0][1]
+filter[i][j+2]*kernel[0][2];
      Ixx[i][j]=Ix[i][j]*Ix[i][j];
}}
       printf("\nIx\n"); print(Ix,r3,c3-2);
       printf("\nIxx\n"); print(Ixx,r3,c3-2);
       
//Iy Iyy icin
Iy=allocate(Iy,r3-2,c3);
Iyy=allocate(Iyy,r3-2,c3);

    for(j=0;j<c3;j++){
       for(i=0;i<r3-2;i++){
           Iy[i][j]=filter[i][j]*kernel[0][0]+filter[i+1][j]*kernel[0][1]
+filter[i+2][j]*kernel[0][2];
           Iyy[i][j]=Iy[i][j]*Iy[i][j];
}}
       printf("\nIy\n"); print(Ix,r3-2,c3);
       printf("\nIyy\n"); print(Ixx,r3-2,c3);
       
//Ixy icin
Ixy=allocate(Ixy,r3-2,c3-2);
for(i=0;i<r3-2;i++)
      for(j=0; j<c3-2 ;j++)
          Ixy[i][j]=Ix[i][j]*Iy[i][j];

       printf("\nIxy\n"); print(Ixy,r3-2,c3-2);

getch();
return 0;
}
