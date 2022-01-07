#include<bits/stdc++.h>
using namespace std;


int n, arr[]={1,2,5,8,12,17,19};
int taken[7]={};

void sum(int ind, int sm){
    if(ind==7){
        if(sm==n){
            for(int i=0;i<7;i++){
                if(taken[i]){
                    cout<<arr[i]<<' ';
                }
            }
            cout<<endl;
        }
        return;
    }
    for(int i=0;i<=1;i++){
        taken[ind]=i;
        sum(ind+1,sm+i*arr[ind]);
        taken[ind]=false;
    }
    return;
}

int main(){
    cin>>n;
    sum(0,0);
}
