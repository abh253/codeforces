long long solution(string a, string b) {
    
    
    long long ci=-1;
    long long times=0;
    
    vector<vector<int>>v(26);
    
    for(int i=0;i<a.length();i++){
        v[a[i]-'a'].push_back(i);
    }
    
    for(int i=0;i<b.length();i++){
        int z=b[i]-'a';
        int x=lower_bound(v[z].begin(),v[z].end(),ci+1)-v[z].begin();
        
        if(x==v[z].size()){
            i--;
            times++;
            ci=-1;
        }else{
            ci=v[z][x];
        }
    }
    
    return times*a.size()+ci+1;
    
}