#include <iostream>
using namespace std;
int sum[101][101];
int main(){int i,j,m,t,n,a;cin>>t;while(t--){m=0;cin>>n;for(i=1; i<=n; i++)for(j=1;j<=i;j++){cin>>a;sum[i][j]=a+max(sum[i-1][j-1],sum[i-1][j]);m=(sum[i][j] > m)?sum[i][j]:m;}cout<<m<<"\n";}}