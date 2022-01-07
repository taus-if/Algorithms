#include<bits/stdc++.h>
using namespace std;

string text="AABAACAABAA";
string pat="AABA";

int ips[100]={0};

void ips_table(){
    int sz=pat.size();
    int ips[sz]={0};
    int len=0;
    for(int i=1;i<sz;i++){
        if(pat[i]==pat[len]){
            len=len+1;
            ips[i]=len;
        }
        else{
            if(len>0){
                len=ips[len-1];
                i--;
            }
        }
    }


    for(int i=0;i<sz;i++){
        cout<<ips[i]<<"";
    }
    cout<<endl;
}

void Search(){
    int j=0;
    for(int i=0;i<text.size();i++){
        if(text[i]==pat[j]){
            j++;
            if(j==pat.size()){
                cout<<"Pattern Found at "<<i-j+1<<" position."<<endl;
                j=ips[j-1];
            }
        }
        else{
            if(j>0){
                j=ips[j-1];
            }
        }
    }
}

int main()
{
    ips_table();

    Search();
}
