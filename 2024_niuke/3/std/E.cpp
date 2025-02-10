#include<bits/stdc++.h>
using namespace std;
typedef double db;
char s[1005];
db p,f[1005][1005],ans;
int n,m,nxt[1005*1005][2],sz[1005*1005];
int rt=1,cnt=1;
void dfs(int u){
    int l=sz[nxt[u][0]],r=sz[nxt[u][1]];
    ans*=f[l+r][l];
    if (l) dfs(nxt[u][0]);
    if (r) dfs(nxt[u][1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> p;
    f[0][0]=1;
    for (int i=1;i<=n;i++){
        f[i][0]=f[i-1][0]*p;
        f[i][i]=f[i-1][i-1]*p;
        for (int j=1;j<i;j++)
            f[i][j]=p*max(f[i-1][j-1],f[i-1][j])+(1-p)*min(f[i-1][j-1],f[i-1][j]);
    }
    for (int i=0;i<n;i++){
        cin >> s;
        int pos=rt;
        for (int j=0;j<m;j++){
            int o=s[j]-'0';
            if (!nxt[pos][o]) nxt[pos][o]=++cnt;
            pos=nxt[pos][o];
            sz[pos]++;
        }
    }
    ans=1.0;
    dfs(rt);
    printf("%.12f\n",ans);
}
