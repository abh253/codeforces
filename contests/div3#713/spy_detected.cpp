#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int arraysize;
        cin>>arraysize;
        vector<int>array(arraysize);
        for(int j=0;j<arraysize;j++){
            cin>>array[j];
        }
        for(int k=2;k<arraysize;k++){
        if(array[0]==array[1]&&array[1]==array[k])continue;
        if(array[0]==array[1]&&array[1]!=array[k]){
            cout<<k+1<<endl;
            break;
        }
        if(array[0]!=array[1]){
            if(array[0]==array[k]){
                cout<<"2"<<endl;
            }
            if(array[1]==array[k]){
                cout<<"1"<<endl;
            }
        }
        }
        array.erase(array.begin(),array.end());
    }
    return 0;
}