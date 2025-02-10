#include <bits/stdc++.h>

typedef long long int64;

void work(){
  int n,k;
  std::cin>>n>>k;
  int64 ans=1;
  for (int i=0;i<k;++i)
    ans*=n>>i&1?12:4;
  std::cout<<ans<<'\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}