#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100]={0};

bool isSafe(int row, int col){
    if(arr[col]) return false;
    for(int c=1;c<=n;c++){
        if(arr[c] and c-arr[c]==col-row) return false;
        if(arr[c] and c+arr[c]==col+row) return false;
    }
    return true;
}

void Queen(int row){

    if(row>n){
        for(int r=1;r<=n;r++){
            for(int c=1;c<=n;c++){
                if(arr[c]==r) cout<<" Q";
                else cout<<" .";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }

    for(int col=1;col<=n;col++){
        if(isSafe(row,col)){
            arr[col]=row;
            Queen(row+1);
            arr[col]=0;
        }
    }
}

int main(){
    cin>>n;
    Queen(1);
}
