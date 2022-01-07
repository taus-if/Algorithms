#include<bits/stdc++.h>
using namespace std;

int graph[100][100]={};
int color[100]={};
int n;

string name[]={"LOL","MIST","BUP","MIT","DU","BUET"};
string clr[]={"LOL","RED","GREEN","YELLOW","BLUE"};

bool isValid(int country,int col){
    for(int i=1;i<=n;i++){
        if(graph[country][i]){
            if(color[i]==col) return false;
        }
    }
    return true;
}

void graphColor(int country){
    if(country>n){
        for(int i=1;i<=n;i++){
            cout<<name[i]<<" "<<clr[color[i]]<<endl;
        }
        cout<<endl<<endl;
        return;
    }
    for(int c=1;c<=4;c++){
        if(isValid(country,c)){
            color[country]=c;
            graphColor(country+1);
            color[country]=0;
        }
    }
    return;
}

int main(){
    int e;
    cin>>n>>e;
    for(int i=0;i<e;i++){

        int p,q;
        cin>>p>>q;
        graph[p][q]=1;
        graph[q][p]=1;

    }

    graphColor(1);
}
