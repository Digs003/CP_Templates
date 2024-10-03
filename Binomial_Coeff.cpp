//Pascal's Triangle Method
//O(N^2) //Useful when no modulo is given or modulo is not prime
if(r==0){nCr[n][r]=1;}
nCr[n][r]=nCr[n-1][r]+nCr[n-1][r-1];
