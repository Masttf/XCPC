#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=300005;
int Case,n,m,i;ll bit[N];vector<int>gl[N],gr[N];
struct E{int y,w;ll pre,suf,val;}e[N];
struct Qry{int yl,yr;ll ans,ur,ru;}q[N];
inline void up(ll&a,ll b){a<b?(a=b):0;}
inline void ins(int x,ll p){for(;x<=n;x+=x&-x)up(bit[x],p);}
inline ll ask(int x){
  ll t=0;
  for((x>n)&&(x=n);x;x-=x&-x)up(t,bit[x]);
  return t;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>m;
    for(i=1;i<=n;i++){
      cin>>e[i].y>>e[i].w;
      gl[i].clear();
      gr[i].clear();
    }
    for(i=1;i<=m;i++){
      int xl,xr;
      cin>>xl>>q[i].yl>>xr>>q[i].yr;
      gl[xl].emplace_back(i);
      gr[xr].emplace_back(i);
    }
    for(i=1;i<=n;i++)bit[i]=0;
    for(i=1;i<=n;i++){
      for(const auto&j:gl[i])q[j].ur=ask(q[j].yr);
      e[i].pre=ask(e[i].y)+e[i].w;
      ins(e[i].y,e[i].pre);
      for(const auto&j:gr[i])q[j].ru=ask(q[j].yl-1);
    }
    for(i=0;i<=n;i++)bit[i]=0;
    for(i=n;i;i--){
      for(const auto&j:gr[i])q[j].ru+=ask(n+1-q[j].yl);
      e[i].suf=ask(n+1-e[i].y)+e[i].w;
      ins(n+1-e[i].y,e[i].suf);
      e[i].val=e[i].pre+e[i].suf-e[i].w;
      for(const auto&j:gl[i])q[j].ur+=ask(n+1-(q[j].yr+1));
    }
    for(i=1;i<=m;i++)q[i].ans=max(q[i].ur,q[i].ru);
    for(i=1;i<=n;i++)bit[i]=0;
    for(i=1;i<=n;i++){
      for(const auto&j:gl[i])up(q[j].ans,ask(n+1-(q[j].yr+1)));
      ins(n+1-e[i].y,e[i].val);
    }
    for(i=1;i<=n;i++)bit[i]=0;
    for(i=n;i;i--){
      for(const auto&j:gr[i])up(q[j].ans,ask(q[j].yl-1));
      ins(e[i].y,e[i].val);
    }
    for(i=1;i<=m;i++)cout<<q[i].ans<<"\n";
  }
}