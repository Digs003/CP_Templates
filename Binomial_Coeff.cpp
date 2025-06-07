//Pascal's Triangle Method
//O(N^2) //Useful when no modulo is given or modulo is not prime
void init(){
    nCr[0][0]=1;
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)nCr[i][j]=1;
            else nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
        }
    }
}
