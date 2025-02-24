#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=250005;
int Case,n,q,lim,i,k,x,a[N],b[N],c[N],cs,ct,S[N],T[N];
long long sum;
inline void fix(int&x){
  while(x<0)x+=n;
  while(x>=n)x-=n;
}
inline void gao(int x,int y){
  fix(x);
  fix(y);
  if(a[x]>=b[y])return;
  sum+=b[y]-a[x];
  a[x]=b[y];
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>q;
    sum=0;
    for(i=0;i<n;i++){
      cin>>a[i];
      sum+=a[i];
    }
    for(i=0;i<n;i++)cin>>b[i];
    for(i=0;i<n;i++)c[i]=b[i];
    sort(c,c+n);
    lim=sqrt(n);
    lim=max(lim,1);
    lim=min(lim,n);
    lim=c[n-lim];
    cs=ct=0;
    for(i=0;i<n;i++){
      if(a[i]<=lim)S[cs++]=i;
      if(b[i]>lim)T[ct++]=i;
    }
    while(q--){
      cin>>k;
      for(i=0;i<cs;){
        x=S[i];
        gao(x,x+k);
        if(a[x]>lim)swap(S[i],S[--cs]);else i++;
      }
      for(i=0;i<ct;i++){
        x=T[i];
        gao(x-k,x);
      }
      cout<<sum<<"\n";
    }
  }
}