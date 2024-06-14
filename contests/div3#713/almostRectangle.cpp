#include<bits/stdc++.h>
using namespace std;
class coordinate{
    public:
    int x[2],y[2];
};
int main(){
    int n;
    cin>>n;
    coordinate c1[n];
    for(int i=0;i<n;i++){
        int side;
        cin>>side;
        char array[side][side];
        for(int j=0;j<side;j++){
            for(int k=0,current=0;k<side;k++){
                cin>>array[j][k];
                if(array[j][k]=='*'){
                    c1[i].x[current]=j;
                    c1[i].y[current]=k;
                }
            }
        } 
        int a=c1[i].x[1]-c1[i].x[0];
        int b=c1[i].y[1]-c1[i].y[0];
        int smallside=a>b?a:b;
        array[c1[i].x[1]][c1[i].y[0]+smallside]='*';
        array[c1[i].x[1]+smallside][c1[i].y[0]]='*';
        array[c1[i].x[1]+smallside][c1[i].y[0]+smallside]='*';
          for(int j=0;j<side;j++){
            for(int k=0;k<side;k++){
              cout<<array[j][k]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}