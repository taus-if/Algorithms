#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100][100];
int graph[100][100];

int tsp(int i, int mask){
    if(mask==(1<<n)-1) return graph[i][0];
    if(dp[i][mask]) return dp[i][mask];
    int mn=INT_MAX;
    for(int j=0;j<n;j++){
        //if(graph[i][j]==9999) continue;
        if((mask&(1<<j))==0){
            //cout<<mask<<" "<<graph[i][j]<<" "<<mn<<endl;
            int cost=tsp(j,mask|(1<<j))+graph[i][j];
            if(cost<mn) mn=cost;
        }
    }
    return dp[i][mask]=mn;
}

int main(){
    memset(dp,0,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    int cost=tsp(0,1);
    cout<<cost<<endl;
}

/*
sample input:
4
9999 2 10 5
2 9999 9 9999
4 3 9999 4
6 8 7 9999
*/
