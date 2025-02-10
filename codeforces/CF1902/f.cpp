#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct LB{
    //vector<int>r;
    int r[20];
    int sz=0;
    LB():sz(0){
        for(int i=19;i>=0;i--)r[i]=0;
    }
    bool insert(int x){
        if(sz==20)return false;
        for(int i=19;i>=0;i--){
            if(x>>i&1){
                if(!r[i]){
                    r[i]=x;
                    sz++;
                    break;
                }else x^=r[i];
            }
        }
        return x>0;
    }
    bool find(int x){
        if(sz==20)return true;
        for(int i=19;i>=0;i--){
            if(x>>i&1){
                if(!r[i])break;
                else x^=r[i];
            }
        }
        return x==0;
    }
    bool insert(LB &a){
        if(sz==20)return true;
        if(a.sz==20){
            for(int i=19;i>=0;i--){
                r[i]=a.r[i];
            }
            return true;
        }
        for(int i=19;i>=0;i--){
            if(a.r[i])insert(a.r[i]);
        }
        return true;
    }
};
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<vector<int>>g(n+1);
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>dep(n+1);
    vector f(21,vector<int>(n+1));
    vector val(21,vector<LB>(n+1));
    auto dfs = [&](auto self,int now,int father)->void{
        dep[now]=dep[father]+1;
        f[0][now]=father;
        val[0][now].insert(a[father]);
        for(int i=1;(1<<i)<dep[now];i++){
            f[i][now]=f[i-1][f[i-1][now]];
            val[i][now]=val[i-1][now];
            val[i][now].insert(val[i-1][f[i-1][now]]);
        }
        for(auto v:g[now]){
            if(v==father)continue;
            self(self,v,now);
        }
    };
    auto get = [&](int x,int y,int k)->bool{
        if(dep[x]<dep[y])swap(x,y);
        LB res;
        res.insert(a[x]);
        for(int i=20;i>=0;i--){
            if(dep[x]-(1<<i)>=dep[y]){
                res.insert(val[i][x]);
                x=f[i][x];
            }
        }
        if(x==y){
            return res.find(k);
        }
        res.insert(a[y]);
        for(int i=20;i>=0;i--){
            if(f[i][x]!=f[i][y]){
                res.insert(val[i][x]);
                res.insert(val[i][y]);
                x=f[i][x];
                y=f[i][y];
            }
        }
        res.insert(a[f[0][x]]);
        return res.find(k);
    };
    dfs(dfs,1,0);

    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int x,y,k;cin>>x>>y>>k;
        if(get(x,y,k))cout<<"Yes\n";
        else cout<<"No\n";
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}
/*
4
0 1 2 10
2 1
3 2
4 2
8
3 3 0
3 4 1
3 4 7
1 3 1
1 3 2
1 3 10
1 4 10
1 4 11

*/