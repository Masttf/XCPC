#include<cstdio>
const int N=55,K=5,P=1000000007;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int Case,n,m,delay,hp,px,py,ex,ey,i,j,k,x,y,d,lim,o;
int f[2][N][N][K][K*2][K*2],g[2][N][N],ans;
bool ban[N][N];
char ch[N];
inline void up(int&a,int b){a=a+b<P?a+b:a+b-P;}
inline bool check(int x,int y){
  if(x<1||x>n||y<1||y>n)return 0;
  return !ban[x][y];
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d%d%d",&n,&m,&delay,&hp);
    for(i=1;i<=n;i++){
      scanf("%s",ch+1);
      for(j=1;j<=n;j++){
        if(ch[j]=='#')ban[i][j]=1;else ban[i][j]=0;
        if(ch[j]=='P')px=i,py=j;
        if(ch[j]=='E')ex=i,ey=j;
      }
    }
    ex-=px,ey-=py;
    for(o=0;o<2;o++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=0;k<hp;k++)for(x=-k;x<=k;x++){
      lim=k-(x>0?x:-x);
      for(y=-lim;y<=lim;y++)f[o][i][j][k][x+K][y+K]=0;
    }
    for(o=0;o<2;o++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)g[o][i][j]=0;
    m-=delay;
    f[0][px][py][0][K][K]=1;
    o=0;
    while(m--){
      for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=0;k<hp;k++)for(x=-k;x<=k;x++){
        lim=k-(x>0?x:-x);
        for(y=-lim;y<=lim;y++)f[o^1][i][j][k][x+K][y+K]=0;
      }
      for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=0;k<hp;k++)for(x=-k;x<=k;x++){
        lim=k-(x>0?x:-x);
        for(y=-lim;y<=lim;y++){
          int now=f[o][i][j][k][x+K][y+K];
          if(!now)continue;
          for(d=0;d<4;d++){
            px=i+dx[d],py=j+dy[d];
            if(!check(px,py))continue;
            if(check(px+ex+x,py+ey+y))up(f[o^1][px][py][k][x+K][y+K],now);
            else if(k+1==hp)up(g[0][px][py],now);
            else up(f[o^1][px][py][k+1][x-dx[d]+K][y-dy[d]+K],now);
          }
        }
      }
      o^=1;
    }
    o=0;
    while(delay--){
      for(i=1;i<=n;i++)for(j=1;j<=n;j++)g[o^1][i][j]=0;
      for(i=1;i<=n;i++)for(j=1;j<=n;j++){
        int now=g[o][i][j];
        if(!now)continue;
        for(d=0;d<4;d++){
          px=i+dx[d],py=j+dy[d];
          if(!check(px,py))continue;
          up(g[o^1][px][py],now);
        }
      }
      o^=1;
    }
    ans=0;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)up(ans,g[o][i][j]);
    printf("%d\n",ans);
  }
}