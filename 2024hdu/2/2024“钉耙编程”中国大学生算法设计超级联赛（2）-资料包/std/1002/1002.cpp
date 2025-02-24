#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#define M 55
using namespace std;
struct data{
    int x,y,val,d,len;
}A[M];
int mp[M][M];
int dp[M][M][1<<10];
int cost[M][M][1<<10];
int n,m,K,lim,I;
void Init(){
    memset(cost,0,sizeof(cost));
    for(int chs=0;chs<=I;chs++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=K;k++){
                    if((1<<(k-1))&chs)continue;
                    int d=abs(i-A[k].x)+abs(j-A[k].y);
                    if(d<=A[k].len)cost[i][j][chs]+=A[k].d;
                }
            }
        }
    }
}
bool done[M][M];
struct node{
    int x,y,val;
    bool operator <(const node &_)const{
        return val<_.val;
    }
};
int ans;
int xr[]={0,-1,0,1};
int yr[]={1,0,-1,0};
bool check(int x,int y){
    return 1<=x&&x<=n&&1<=y&&y<=m;
}
void check_max(int &x,int y){
    if(x<y)x=y;
}
void Solve(int chs){
    memset(done,0,sizeof(done));
    priority_queue<node>Q;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(dp[i][j][chs]>-1e8){
            Q.push((node){i,j,dp[i][j][chs]});
        }
    }
    while(!Q.empty()){
        node now=Q.top();Q.pop();
        if(done[now.x][now.y])continue;
        done[now.x][now.y]=true;
        ans=max(ans,dp[now.x][now.y][chs]);
        for(int op=0;op<4;op++){
            int pass=0,tot_val=0;
            for(int i=1;i<=lim;i++){
                node nxt=now;
                nxt.x+=xr[op]*i;
                nxt.y+=yr[op]*i;
                if(!check(nxt.x,nxt.y))break;
                if(mp[nxt.x][nxt.y]!=0&&!((1<<(mp[nxt.x][nxt.y]-1))&chs)){
                    pass|=1<<(mp[nxt.x][nxt.y]-1);
                    tot_val+=A[mp[nxt.x][nxt.y]].val;
                }else if(!pass){
                    int nxt_dp=dp[now.x][now.y][chs]-cost[nxt.x][nxt.y][chs];
                    if(dp[nxt.x][nxt.y][chs]<nxt_dp){
                        dp[nxt.x][nxt.y][chs]=nxt_dp;
                        Q.push((node){nxt.x,nxt.y,nxt_dp});
                    }
                }else {
                    check_max(dp[nxt.x][nxt.y][chs|pass],dp[now.x][now.y][chs]+tot_val-cost[nxt.x][nxt.y][chs|pass]);
                }
            }
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        for(int i=0;i<M;i++)for(int j=0;j<M;j++)for(int k=0;k<(1<<10);k++)dp[i][j][k]=-1e9;
        memset(mp,0,sizeof(mp));
        scanf("%d%d%d",&n,&m,&K);
        scanf("%d",&lim);
        for(int i=1;i<=K;i++){
            scanf("%d%d%d%d%d",&A[i].x,&A[i].y,&A[i].val,&A[i].d,&A[i].len);
            mp[A[i].x][A[i].y]=i;
        }
        int sx,sy;
        scanf("%d%d",&sx,&sy);
        dp[sx][sy][0]=0;
        I=1<<K;I--;
        Init();
        for(int chs=0;chs<=I;chs++){
            Solve(chs);
        }
        printf("%d\n",ans);
    }
    return 0;
}
