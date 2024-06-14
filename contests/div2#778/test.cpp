#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>a={1,2,3};
    vector<int>b={3,2};
    b=a;
    cout<<b.size()<<endl;
    for(auto it:b)cout<<it<<endl;
    return 0;
}