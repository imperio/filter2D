#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

long double **f(int N,int M,double sigma)
{
      long double **p;
      double y,x,top=0.0;
      int i,j;
       //allocate memory for p
       p=(long double **)malloc(N*sizeof(long double*));
         for(i=0;i<M;i++){
                          p[i]=(long double *)malloc(M*sizeof(long double));}
       //find initial x and y values in equation                
       x= -(double)(M-1)/2; 
       y= -(double)(N-1)/2;
       //exponential
       for(i=0;i<N;i++){
                        for(j=0;j<M;j++){
           p[i][j]=exp(-((x*x)+(y*y))/(2*sigma*sigma));
           x++;}
           y++;
           x= -(double)(M-1)/2;
           //top+=p[i][j]; //sum of the values
           }
           
           //for (i=0;i<N;i++){
              //for(j=0;j<M;j++){
                 //p[i][j]/=top;}} //divide elements of the array 
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
    B=f(bsatir,bsutun,sigma);
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
    for(x=0;x<bsatir;x++){
       for(y=0;y<bsutun;y++){
           for(k=0;k<asatir;k++){
              for(m=0;m<asutun;m++){
                 sum+=(long double)A[i][j]*B[k][m];
                 i++; j++;}}
                 C[x][y]=sum;
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

