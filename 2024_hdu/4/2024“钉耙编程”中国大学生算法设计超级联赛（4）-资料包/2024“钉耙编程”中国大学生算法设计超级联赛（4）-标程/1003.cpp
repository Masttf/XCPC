#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int>P;
const int N=200005;
int Case,n,k,i,j,a[N];bool vis[N],is_prime[N],OK;
int L,R,MID,ANS;
set<P>T;
inline void ins(int sum,int ptr){
  T.insert(P(sum,ptr));
}
inline bool valid(int sum,int ptr){
  for(set<P>::iterator it=T.begin();it!=T.end();it++){
    if(sum-it->first<MID)return 0;
    if(is_prime[ptr-it->second])return 1;
  }
  return 0;
}
inline bool check(){
  for(int cur=1,ptr=1;cur<=k;cur++){
    if(ptr>n)return 0;
    T.clear();
    ins(0,ptr-1);
    for(int sum=0;;ptr++){
      if(ptr>n)return 0;
      sum+=a[ptr];
      if(valid(sum,ptr)){
        ptr++;
        break;
      }
      ins(sum,ptr);
    }
  }
  return 1;
}
int main(){
  for(i=2;i<N;i++)if(!vis[i]){
    is_prime[i]=1;
    for(j=i;j<N;j+=i)vis[j]=1;
  }
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>k;
    L=R=OK=0;
    for(i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]>0)R+=a[i];else L+=a[i];
    }
    while(L<=R){
      MID=(L+R)/2;
      if(check()){
        OK=1;
        ANS=MID;
        L=MID+1;
      }else R=MID-1;
    }
    if(OK)cout<<ANS<<"\n";else cout<<"impossible\n";
  }
}