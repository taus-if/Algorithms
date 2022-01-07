#include<bits/stdc++.h>
using namespace std;
#define V 4
int travellingSalesmanProblem(int graph[][V],int s){
    vector<int>vertex;
    for(int i=0;i<V;i++){
        if(i!=s){
            vertex.push_back(i);
        }
    }
    int min_path=INT_MAX;
    do{
        int curWeight=0;

        int k=s;
        for(int i=0;i<vertex.size();i++){
            curWeight+=graph[k][vertex[i]];
            k=vertex[i];
        }
        curWeight+=graph[k][s];
        min_path=min(min_path,curWeight);
    }while(
           next_permutation(vertex.begin(),vertex.end()));
       return min_path;
}

int main(){
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s=0;
    cout<<travellingSalesmanProblem(graph,s)<<endl;
}

/*
i64 call(i64 u,i64 d)
{
  if(d==0) return 0;
  if(!vis[u][d])
  {
	 vis[u][d]=1;
	 i64 MX=-1*1e16;
	 if(d==1)
	 {
		for(int i=1;i&lt;=N;i++)
		if(last[i])	MX=max(MX,mat[u][i]);
		return dp[u][d]=MX;

	 }
	 for(int i=1;i&lt;=N;i++)
	 {
		i64 ret=mat[u][i]+call(i,d-1);
		MX=max(ret,MX);
	 }
	 return dp[u][d]=MX;
  }
  return dp[u][d];
}
*/
