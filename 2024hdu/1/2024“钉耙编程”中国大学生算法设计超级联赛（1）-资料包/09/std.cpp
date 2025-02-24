#include <bits/stdc++.h>

typedef long long int64;

const int N=500,S=10,mod=998244353;

int dp[2][N+9][N+9][S];

// b=1, pre 0
int DFSDP(bool b,int p,int q,int x,int n,const std::string &r){
  int &res=dp[b][p][q][x];
  if (res!=-1) return res;
  if (p==n) return res=q==(int)r.size()+1?1:0;
  if (q==(int)r.size()+1) return res=1LL*S*DFSDP(0,p+1,q,x,n,r)%mod;
  res=0;
  for (int y=0;y<S;++y){
    res=(res+DFSDP(b&&!y,p+1,q,x,n,r))%mod;
    if (b&&!y) continue;
    if (q&&r[q-1]=='<'&&x>=y) continue;
    if (q&&r[q-1]=='>'&&x<=y) continue;
    res=(res+DFSDP(0,p+1,q+1,y,n,r))%mod;
  }
  return res;
}

int Solve(const std::string &n,const std::string &r){
  int res=0;
  std::vector<std::vector<int>> f(r.size()+1,std::vector<int>(S,0));
  for (int i=0;i<(int)n.size();++i){
    auto add=[&](int y){
      auto g=f;
      g[0][y]=(g[0][y]+1)%mod;
      for (int j=0;j<(int)r.size();++j)
        for (int x=0;x<S;++x){
          if (r[j]=='<'&&x>=y) continue;
          if (r[j]=='>'&&x<=y) continue;
          g[j+1][y]=(g[j+1][y]+f[j][x])%mod;
        }
      // std::cerr<<"  "<<i<<' '<<y<<" :\n";
      // for (int j=0;j<=(int)r.size();++j)
      //   for (int x=0;x<S;++x)
      //     std::cerr<<"   "<<j<<' '<<x<<" : "<<g[j][x]<<'\n';
      return g;
    };
    int c=n[i]-'0';
    for (int y=0;y<c;++y){
      int t=DFSDP(!i&&!y,i+1,0,0,n.size(),r);
      // std::cerr<<" +0 "<<(!i&&!y)<<' '<<i+1<<' '<<0<<' '<<0<<' '<<n.size()<<' '<<r<<" : "<<t<<'\n';
      res=(res+t)%mod;
      if (!i&&!y) continue;
      auto g=add(y);
      for (int j=0;j<=(int)r.size();++j){
        for (int x=0;x<S;++x){
          if (!g[j][x]) continue;
          int t=DFSDP(0,i+1,j+1,x,n.size(),r);
          // std::cerr<<" +1 "<<0<<' '<<i+1<<' '<<j+1<<' '<<x<<' '<<n.size()<<' '<<r<<" : "<<t<<'\n';
          // std::cerr<<" +2 "<<i<<' '<<j<<' '<<x<<' '<<y<<" : "<<g[j][x]<<'\n';
          res=(res+1LL*g[j][x]*t)%mod;
        }
      }
    }
    f=add(c);
  }
  return res;
}

void work(){
  std::string l,r,s;
  std::cin>>l>>r>>s;
  std::reverse(r.begin(),r.end());
  r.push_back('0');
  for (int i=0;i<(int)r.size();++i){
    if(r[i]!='9'){
      ++r[i];
      break;
    }
    r[i]='0';
  }
  for (;r.size()>1&&r.back()=='0';r.pop_back());
  std::reverse(r.begin(),r.end());
  // std::cerr<<' '<<l<<' '<<r<<'\n';
  memset(dp,-1,sizeof(dp));
  int ans_r=Solve(r,s);
  memset(dp,-1,sizeof(dp));
  int ans_l=Solve(l,s);
  // std::cout<<Solve(r,s)<<'\n';
  std::cout<<(ans_r-ans_l+mod)%mod<<'\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}