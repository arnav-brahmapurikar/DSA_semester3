#include<stdio.h>
int main(){
    int n,m,z,nz;
    printf("Enter row and columns:");
    scanf("%d %d",&n,&m);
    int A[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==0){
                z++;
            }
            else{
                nz++;
            }
        }
    }
    if(nz>z){
        printf("Not A Sparse Matrix");
    }
    else{
        int S[nz][3];
        int k=0;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]!=0){
                S[k][0]=i;
                S[k][1]=j;
                S[k][2]=A[i][j];
                k++;
            }
        }
    }
    printf("\n");
    printf("Sparse Matrix: ");
    printf("\n");
    for(int i=0;i<nz;i++){
        for(int j=0;j<3;j++){
            printf("%d",S[i][j]);
            
        }
        printf("\n");
    }
    }
    return 0;
}