#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n , m , k;
vector<pii> E[2][400005];
void adde(int u,int v,int w,int t = 1) {
    // printf("adde %d %d %d\n",u,v,w);
    E[0][u].push_back({v,w});
    E[0][v].push_back({u,w});

    E[1][v].push_back({u,w}) ;
    E[1][u].push_back({v,w});
}
struct b {
    int l , r , id;
};
vector<b> val[200005];
int v[200005];
bool operator < (b x,b y) {
    return x.l < y.l;
}
int Find(int i,int l,int r) { /// 第一个右端点大于等于l的
    int L = 0 , R = (int)val[i].size() ;
    while(L < R) {
        int md = (L + R >> 1);
        if(val[i][md].r < l) L = md + 1;
        else R = md;
    }
    return L;
}
int Find2(int i,int l,int r) { ///最后一个左端点小于等于r的
    int L = 0 , R = (int)val[i].size() - 1;
    while(L < R) {
        int md = (L + R >> 1) + 1;
        if(val[i][md].l <= r) L = md;
        else R = md - 1;
    }
    return L;
}
ll dis[2][400005];
typedef pair<ll,int> pli;
void dij(int s,ll *d,int id) {
    for(int i = 0;i <= m*2+1;i++) {
        d[i] = 1e18;
    }
    d[s] = 0;
    priority_queue<pli , vector<pli> , greater<pli> > pq;
    pq.push({0 , s});
    while(pq.size()) {
        auto [v,u] = pq.top() ; pq.pop() ;
        if(v != d[u]) continue ;
        for(auto [t,w] : E[id][u]) {
            if(d[t] > d[u] + w) {
                // printf("%d %d %d\n",t,d[u],w);
                d[t] = d[u] + w;
                pq.push({d[t] , t});
            }
        }
    }
    // printf("end %lld\n",d[m*2+1]);
    return ;
}
void solv()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y,l;
        cin >> x >> y >> l >> v[i];
        val[x].push_back({y , y+l-1 , i}) ;
    }
    for(int i = 1;i <= n;i++) {
        if(!val[i].size()) {
            for(int i = 1;i <= m;i++) cout << 0 << '\n';
            return ;
        }
        sort(val[i].begin() , val[i].end());
    }
    int S = 0 , T = m * 2 + 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 0 ; j < val[i].size() ;j++) {
            if(j + 1 < val[i].size()) adde(val[i][j].id + m , val[i][j + 1].id , 0) ;
            if(j == 0) adde(S , val[i][j].id , 0);
            adde(val[i][j].id , val[i][j].id + m , v[val[i][j].id] , 0);
        }
        adde(val[i].back().id + m , T , 0);
        if(i + 1 <= n) {
            for(int j = 0;j < val[i].size();j++) {
                int id = Find(i + 1 , val[i][j].l , val[i][j].r) ;
                if(id != val[i + 1].size() && val[i + 1][id].l <= val[i][j].r) {
                    int id2 = Find(i , val[i + 1][id].l , val[i + 1][id].r) ;
                    if(j == id2) {
                        adde(val[i][j].id , val[i + 1][id].id , 0);
                    }
                }
                else {
                    if(id > 0) adde(val[i][j].id , val[i + 1][id - 1].id + m , 0);
                    if(id != val[i + 1].size()) adde(val[i][j].id + m , val[i + 1][id].id , 0);
                }

                if(val[i + 1][0].l <= val[i][j].r) {
                    id = Find2(i + 1 , val[i][j].l , val[i][j].r) ;
                    // if(i == 2) printf("nxt id %d : %d\n",id , val[i + 1][id].id);
                    if(val[i + 1][id].r >= val[i][j].l) {
                        int id2 = Find2(i , val[i + 1][id].l , val[i + 1][id].r) ;
                        if(j == id2) {
                            adde(val[i][j].id + m, val[i + 1][id].id + m, 0);
                        }
                    }
                }
            }
        }
        if(i - 1 >= 1) {
            for(int j = 0;j < val[i].size();j++) {
                int id = Find(i - 1 , val[i][j].l , val[i][j].r) ;
                if(id == val[i - 1].size() || val[i - 1][id].l > val[i][j].r) {
                    if(id > 0) adde(val[i][j].id , val[i - 1][id - 1].id + m , 0);
                    if(id != val[i - 1].size()) adde(val[i][j].id + m , val[i - 1][id].id , 0);
                }
            }
        }
    }
    dij(S , dis[0] , 0) ;
    dij(T , dis[1] , 1) ;
    // cout << "D " << dis[0][T] << '\n';
    for(int i = 1;i <= m;i++) {
        // printf("%d : %lld %lld\n",i,dis[0][i],dis[1][i+m]);
        cout << min(dis[0][T] , min(dis[0][i] + dis[1][i + m] , dis[1][i] + dis[0][i + m])) << '\n';
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int T = 1;
    while(T--) solv();
    return 0;
}
