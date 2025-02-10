#include<cstdio>
#include<algorithm>
using namespace std;
const int N=21,M=10,LEN=(1<<M)+5;
int Case,n,m,i,ans,val[N],w[LEN],q[LEN],at[LEN];
bool fl[N][LEN],fr[N][LEN];
inline bool cmp(int x,int y){return w[x]<w[y];}
inline void umin(int&a,int b){a>b?(a=b):0;}
inline void umax(int&a,int b){a<b?(a=b):0;}
void dfs(int x,int suml,int sumr){
  if(x==n){
    for(int i=0,ml=-1,mr=-1;i<1<<m;i++){
      int o=q[i];
      if(fl[n][o]&&w[o]>=w[o^suml]){
        umax(ml,w[o^suml]);
        if(~mr)umin(ans,w[o]-min(w[o^suml],mr));
      }
      if(fr[n][o]&&w[o]>=w[o^sumr]){
        umax(mr,w[o^sumr]);
        if(~ml)umin(ans,w[o]-min(w[o^sumr],ml));
      }
    }
    return;
  }
  int v=val[x];
  for(int i=0;i<1<<m;i++){
    fl[x+1][i]=fl[x][i]|fl[x][i^v];
    fr[x+1][i]=fr[x][i];
  }
  dfs(x+1,suml^v,sumr);
  for(int i=0;i<1<<m;i++){
    fl[x+1][i]=fl[x][i];
    fr[x+1][i]=fr[x][i]|fr[x][i^v];
  }
  dfs(x+1,suml,sumr^v);
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&val[i]);
    for(i=0;i<1<<m;i++)scanf("%d",&w[i]),q[i]=i;
    sort(q,q+(1<<m),cmp);
    for(i=0;i<1<<m;i++)at[q[i]]=i;
    for(i=0;i<1<<m;i++)fl[1][i]=fr[1][i]=0;
    fl[1][0]=fr[1][0]=1;
    fl[1][val[0]]=1;
    ans=~0U>>1;
    dfs(1,val[0],0);
    printf("%d\n",ans);
  }
}