#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>res(n+m+1);
    for(int i=1;i<=n;i++){
        res[i]=res[i-1]^a[i];
        //dbg(i,res[i]);
    }
    int tot=0;
    vector<int>root(n+m+1);
    vector t(2,vector<int>(n*50));
    vector<int>val(n*50);
    auto ins=[&](int u,int v,int x)->void{
        for(int i=31;i>=0;i--){
            //dbg(u,v);
            t[0][u]=t[0][v];
            t[1][u]=t[1][v];
            int d=(x>>i)&1;
            t[d][u]=++tot;
            u=t[d][u];
            v=t[d][v];
            val[u]=val[v]+1;
        }
        //val[u]=val[v]+1;
    };
    auto query = [&](int u,int v,int x)->int{
        int res=0;
        for(int i=31;i>=0;i--){
            int d=(x>>i)&1;
            d=d^1;
            if(val[t[d][u]]-val[t[d][v]]){
                u=t[d][u];
                v=t[d][v];
                res+=(1<<i);
            }else{
                u=t[d^1][u];
                v=t[d^1][v];
            }
        }
        return res;
    };

    //cout<<"yes"<<endl;
    for(int i=1;i<=n;i++){
        root[i]=++tot;
        ins(root[i],root[i-1],res[i]);
    }
    //cout<<tot<<endl;
    for(int i=1;i<=m;i++){
        char t;cin>>t;
        if(t=='A'){
            int x;cin>>x;
            n++;
            res[n]=res[n-1]^x;
            root[n]=++tot;
            //dbg(n,res[n]);
            ins(root[n],root[n-1],res[n]);
        }else{
            int l,r,x;cin>>l>>r>>x;
            int ans=query(root[r-1],root[max(l-2,0ll)],res[n]^x);
            if(l==1)ans=max(ans,res[n]^x);
            cout<<ans<<'\n';
        }
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
5 5
2 6 4 3 6
A 1 
Q 3 5 4 
A 4
Q 5 7 0 
Q 3 6 6 

4 5 6
*/
