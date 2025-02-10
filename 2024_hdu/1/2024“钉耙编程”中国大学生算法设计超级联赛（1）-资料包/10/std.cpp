#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

const int N=200000,C=21,K=25;

int n,q,a[N+9];

void Read(){
  std::cin>>n>>q;
  for (int i=1;i<=n;++i)
    std::cin>>a[i];
}

int lg[N+9];
std::pair<int,int> max[N+9][C];

void InitST(){
  for (int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
  for (int i=1;i<=n;++i) max[i][0]=std::make_pair(a[i],i);
  for (int i=1;i<C;++i)
    for (int j=1;j+(1<<i)-1<=n;++j)
      max[j][i]=std::max(max[j][i-1],max[j+(1<<i-1)][i-1]);
}

std::pair<int,int> QueryMax(int l,int r){
  int t=lg[r-l+1];
  return std::max(max[l][t],max[r-(1<<t)+1][t]);
}

void Inter(){
  uint64 nans=0;
  for (int cas=1;cas<=q;++cas){
    int l,r;
    std::cin>>l>>r;
    std::priority_queue<std::pair<std::pair<int,int>,std::pair<int,int>>> pq;
    pq.emplace(QueryMax(l,r),std::make_pair(l,r));
    std::pair<int64,int> ans(0,0);
    for (int i=1;i<=K;++i){
      if (pq.empty()) break;
      int val=pq.top().first.first;
      int64 cnt=0;
      for (;!pq.empty()&&pq.top().first.first==val;){
        auto [v,p]=pq.top().first;
        auto [l,r]=pq.top().second;
        pq.pop();
        cnt+=1LL*(p-l+1)*(r-p+1);
        if (p>l) pq.emplace(QueryMax(l,p-1),std::make_pair(l,p-1));
        if (p<r) pq.emplace(QueryMax(p+1,r),std::make_pair(p+1,r));
      }
      ans=std::max(ans,std::make_pair(cnt,val));
    }
    nans^=1ULL*ans.second*cas;
  }
  std::cout<<nans<<'\n';
}

void work(){
  Read();
  InitST();
  Inter();
}

int main(){
  std::ios::sync_with_stdio(0);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}