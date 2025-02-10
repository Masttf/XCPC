#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=998244353;
const int maxn=2e5+3;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void dec(int &x,int y){x-=y;if(x<0) x+=M;} 
struct graph{
    int n,m,deg[maxn],cnt[maxn],lson[maxn];
    long long sum[maxn];
    int t12,t13,t22,t3;
    vector<pi> E;
    void read(){
        cin >> n >> m;
        for (int i=1;i<=n;i++) sum[i]=lson[i]=cnt[i]=deg[i]=0;
        E.clear();
        for (int i=1;i<=m;i++){
            int u,v; cin >> u >> v;
            deg[u]++; deg[v]++;
            sum[u]+=v; sum[v]+=u;
            E.pb((pi){u,v});
        }
        for (auto e:E){
            int u=e.F,v=e.S;
            if (deg[u]==1) lson[v]++;
            if (deg[v]==1) lson[u]++;
        }
        for (int i=1;i<=n;i++) cnt[deg[i]]++;
        t12=t13=t22=t3=0;
        for (auto e:E){
            int u=e.F,v=e.S;
            if (deg[u]>deg[v]) swap(u,v);
            if (deg[u]==1&&deg[v]==2) t12++;
            else if (deg[u]==1&&deg[v]==3) t13++;
            else if (deg[u]==2&&deg[v]==2){
                t22++;
                if (lson[u]||lson[v]) t3++;
                if (sum[u]-v==sum[v]-u&&deg[sum[u]-v]==3) t3++;
            }
        }
        for (int i=1;i<=n;i++) 
            if (deg[i]==3&&lson[i]==2) t3++;
    }
}G1,G2;
int main(){
    G1.read(); G2.read();
    int ans=0;
    long long tot=(1ll*G1.n*G2.m+1ll*G2.n*G1.m-3)%M;
    add(ans,2ll*G1.t12*G2.t12%M);
    add(ans,1ll*G1.cnt[1]*(G2.t3+G2.t13+G2.t22+G2.cnt[3])%M);
    add(ans,1ll*G2.cnt[1]*(G1.t3+G1.t13+G1.t22+G1.cnt[3])%M);
    add(ans,1ll*G1.cnt[2]*G2.cnt[2]%M);
    add(ans,tot*G1.cnt[1]%M*(G2.cnt[2]+G2.t12)%M);
    add(ans,tot*G2.cnt[1]%M*(G1.cnt[2]+G1.t12)%M);
    long long cnt=1ll*G1.cnt[1]*G2.cnt[1]%M;
    add(ans,tot*(tot+1)/2%M*cnt%M);
    dec(ans,cnt*(cnt-1)/2%M);
    dec(ans,2ll*G1.cnt[1]*G2.t12%M);
    dec(ans,2ll*G2.cnt[1]*G1.t12%M);
    cout << ans << endl;
}
