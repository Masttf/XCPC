#include<iostream>
#include<string>
using namespace std;
const int N=1000005,day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int Case,n,m,i,j,x,ans,suf[N],f[N][26],vis[26];string a;
inline int godate(int*s){
  int x=m+1;
  for(int i=3;~i;i--){
    x--;
    if(x<1)return 0;
    x=f[x][s[i]];
  }
  return x;
}
inline int goname(){
  int x=0;
  for(int i=0;i<a.size();i++){
    x++;
    if(x>m)return m+1;
    x=f[x][a[i]-'a'];
  }
  return x;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>m>>a;
    for(j=0;j<10;j++)vis[j]=0;
    for(i=1;i<=m;i++){
      if(a[i-1]>='0'&&a[i-1]<='9')vis[a[i-1]-'0']=i;
      for(j=0;j<10;j++)f[i][j]=vis[j];
    }
    for(i=0;i<=m+1;i++)suf[i]=0;
    for(i=1;i<=12;i++)for(j=1;j<=day[i];j++){
      static int pool[4];
      pool[0]=i/10;
      pool[1]=i%10;
      pool[2]=j/10;
      pool[3]=j%10;
      x=godate(pool);
      if(x)suf[x]++;
    }
    for(i=m;i>1;i--)suf[i-1]+=suf[i];
    for(j=0;j<26;j++)vis[j]=m+1;
    for(i=m;i;i--){
      if(a[i-1]>='a'&&a[i-1]<='z')vis[a[i-1]-'a']=i;
      for(j=0;j<26;j++)f[i][j]=vis[j];
    }
    ans=0;
    while(n--){
      cin>>a;
      x=goname();
      if(x<m)ans+=suf[x+1];
    }
    cout<<ans<<"\n";
  }
}