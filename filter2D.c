#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

long double **f(int N,int M,double sigma)
{
      long double **p;
      double i,j,top=0.0;
      int k,x;
       //allocate memory for p
       p=(long double **)malloc(M*sizeof(long double*));
         for(x=0;x<N;x++){
                          p[x]=(long double *)malloc(N*sizeof(long double));}
       //find initial x and y values in equation                
       i= -(double)(N-1)/2; 
       j= -(double)(M-1)/2;
       //exponential
       for(x=0;x<M;x++){
                        for(k=0;k<N;k++){
           p[x][k]=exp(-((i*i)+(j*j))/(2*sigma*sigma));
           i++;}
           j++;
           i= -(double)(N-1)/2;
           top+=p[x][k]; //sum of the values
           }
           
           for (x=0;x<M;x++){
              for(k=0;k<N;k++){
                 p[x][k]/=top;}} //divide elements of the array 
                                     //  by sum of the values 
           return p;
}
          
int main()
{
    int bsatir,bsutun,i=0,j=0,k=0,a;
    int asatir,asutun,x,y,m;
    double sum=0.0,sigma;
    long double **B,**C;
    int **A;
    //column and line for A
    printf("A line:");
    scanf("%d",&asatir);
    printf("A column:");
    scanf("%d",&asutun);
    //allocate memory for A
     A=(int **)malloc(asatir*sizeof(int*));
         for(x=0;x<asatir;x++){
                          A[x]=(int *)malloc(asutun*sizeof(int));}
    
    srand(time(NULL));
    //create random numbers in A
    for(a=0;a<asatir;a++){
                          for(i=0;i<asatir;i++){
        A[a][i]=rand()%10;
        printf("%d ",A[a][i]);
        } printf("\n");
    }
    //column and line for B
    printf("B line:");
    scanf("%d",&bsatir);
    printf("B column:");
    scanf("%d",&bsutun);
    printf("enter sigma");
    scanf("%lf",&sigma);
    //take the elements of B from the function f
    B=f(bsutun,bsatir,sigma);
    //print B
    for(i=0;i<bsatir;i++){
                          for(a=0;a<bsutun;a++){
    printf("%lf ",B[i][a]);}
    printf("\n");}
    
    //allocate memory for C(output)
    C=(long double **)malloc(bsatir*sizeof(long double*));
      for(i=0;i<bsutun;i++){
          C[i]=(long double *)malloc(bsutun*sizeof(long double));}
    
    
    //create array C
    for(x=0;x<bsatir;){
       for(y=0;y<bsutun;){
           for(k=0;k<asatir;){
              for(m=0;m<asutun;){
                 sum+=(long double)A[i][j]*B[k][m];
                 i++; j++;
                 k++; m++;}}
                 C[x][y]=sum;
                 k=0; m=0;
                 i=i-(k-1);
                 j=j-(m-1);
                 sum=0.0;}}
        
        

//print C
        for(a=0;a<bsatir;a++){
                              for(i=0;i<bsutun;i++){
        printf("C[%d][%d]=%lf ",a,i,C[a][i]);
        }
        printf("\n");
}
//clean memory
   for(i=0;i<asatir;i++){
         free(A[i]); }
         free(A);
   for(k=0;i<bsatir;k++){
         free(B[k]); }
         free(B);
   for(x=0;x<bsatir;x++){
       free(C[x]); }
       free(C);
    
    system("pause");
    return 0;
}

