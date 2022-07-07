#include "stdio.h"

#define MAXN 3
int main()
{
    int flag=1;
    int N;
    int A[MAXN],B[MAXN];
    while(scanf("%d",&N) && N)
    {
        int i;
        for ( i = 0; i < N ; i++) {
            scanf("%d",&A[i]);
        }
        for ( i = 0; i < N ; i++) {
            scanf("%d",&B[i]);
        }
        int pointsA=0;
        int pointsB=0;
        for ( i = 0; i < N; i++) {
            if(A[i]<B[i]){
                if(A[i]==1 && B[i]==2){
                    pointsA+=6;
                }else{
                    if(B[i]-A[i]==1){
                        pointsA+=A[i]+B[i];
                    }else{
                        pointsB+=B[i];
                    }
                }
            }else{
                if(A[i]>B[i]){
                    if(A[i]==2 && B[i]==1){
                        pointsB+=6;
                    }else{
                        if(A[i]-B[i]==1){
                            pointsB+=A[i]+B[i];
                        }else{
                            pointsA+=A[i];
                        }
                    }
                }
            }
        }
        if(flag++!=1){
            printf("\n");
        }
        printf("A has %d points. B has %d points. \n",pointsA,pointsB);
    }
    return 0;
}