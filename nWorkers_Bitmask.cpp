#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100][100];
int val[100][100];
int allmask=15;


int work(int i, int mask){
    if(i>n) return 0;
    if(dp[i][mask]) return dp[i][mask];

    int mn=INT_MAX;
    for(int j=1;j<=n;j++){
        if(mask&(1<<j)) continue;
        else{
            int cost=work(i+1,mask|(1<<j))+val[i][j];
            if(mn>cost) mn=cost;
        }
    }
    return dp[i][mask]=mn;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>val[i][j];
        }
    }
    int min_cost=work(1,0);
    cout<<min_cost<<endl;
}
