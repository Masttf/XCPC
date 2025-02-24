#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#define int long long
 
//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")
 
using namespace std;
const int N = 1e5+5;
const int LIM = 1e9;
vector<pair<int,int> > to[N];
int val[N],cnt[N],need[N],tot[N];
int inf[N];
void dfs(int u){
    if(need[u]>LIM){
        inf[u]=1;
        return;
    }
    if(to[u].empty()){
        tot[u]=val[u]*need[u];
        if(tot[u]>LIM){
            inf[u]=1;
        }
        return ;
    }
    for(auto [x,a]:to[u]){
        need[a]=need[u] *x;
        if(need[a]>LIM){
            inf[u]=1;
            continue;
        }
        dfs(a);
        if(inf[a]){
            inf[u]=1;
            continue;
        }
        tot[u]+=tot[a];
    }
}
void sol(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        val[i]=cnt[i]=need[i]=tot[i]=inf[i]=0;
        to[i].clear();
    }
    for(int i=1;i<=n;i++){
        int p;cin>>p;
        if(p==0){
            cin>>val[i];
        }
        else{
            int t;cin>>t;
            for(int j=1;j<=t;j++){
                int x,a;cin>>x>>a;
                to[i].push_back({x,a});
            }
        }
    }
    need[k]=1;
    dfs(k);
    int MAX=0,infcnt=0,ans=0;
    for(auto it:to[k]){
        // cout<<it.second<<endl;
        if(inf[it.second])infcnt++;
        else{
            MAX=max(MAX,tot[it.second]);
            ans+=tot[it.second];
        }
    }
    // cout<<infcnt<<endl;
    if(infcnt>1){cout<<"Impossible"<<endl;return;}
    else if(infcnt==0)ans-=MAX;
    if(ans>LIM)cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    return;
}
signed main ()
{
    //std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 
    int _=1;
    cin>>_;
    while(_--)sol();
 
    return 0;
 
}
