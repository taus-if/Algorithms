#include<bits/stdc++.h>
using namespace std;

#define EMPTY_VALUE -1
#define MAX 100
#define INF 1<<30

int m[100][100];
int s[100][100];
vector<int>dim;

int mcm(int left, int right){
    if(left==right) return 0;
    if(left+1==right) s[left][right]=left;
    if(m[left][right]) return m[left][right];

    int mn=INT_MAX;
    int cost;

    for(int mid=left;mid<right;mid++){
        cost=mcm(left, mid)+mcm(mid+1, right)+dim[left-1]*dim[mid]*dim[right];
        if(mn>cost){
            mn=cost;
            s[left][right]=mid;
        }
    }
    return m[left][right]=mn;
}

void printOrder(int left, int right){
    if(left==right)
        cout<<'A'<<left;
    else{
        cout<<"(";
        printOrder(left, s[left][right]);
        printOrder(s[left][right]+1, right);
        cout<<")";
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        int a;
        cin>>a;
        dim.push_back(a);
    }
    mcm(1,n);
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    printOrder(1,n);
}
