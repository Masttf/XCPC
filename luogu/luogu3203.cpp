//为什么考虑分块呢，首先题目是单点修改，单点查询，问题是跳跃
//分块的作用就是只修改需要修改的部分
//那么对于一个跳跃过程可以把它拆成跳出当前块所需的步数和跳出后所在的点
//需要修改时直接把整个块内的都修改，这样只修改了部分而不用全部修改
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],pos[maxn],f[maxn],to[maxn],s[maxn],ed[maxn];
int n;
void updata(int x,int k){
	int p=pos[x];
	a[x]=k;
	for(int i=ed[p];i>=s[p];i--){
		if(a[i]+i>ed[p])f[i]=1,to[i]=i+a[i];
		else f[i]=1+f[i+a[i]],to[i]=to[i+a[i]];
	}
	return ;
}
int query(int x){
	int cnt=0;
	int start=x;
	while(start<=n){
		cnt+=f[start];
		start=to[start];
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int block=sqrt(n);
	int t=n/block;
	if(n%block)t++;
	for(int i=1;i<=t;i++){
		s[i]=(i-1)*block+1;
		ed[i]=i*block;
	}
	ed[t]=n;
	for(int i=1;i<=n;i++)cin>>a[i],pos[i]=(i-1)/block+1;
	for(int i=t;i>=1;i--){
		for(int j=ed[i];j>=s[i];j--){
			if(a[j]+j>ed[i])f[j]=1,to[j]=j+a[j];
			else f[j]=1+f[j+a[j]],to[j]=to[j+a[j]];
		}
	}
	int m;cin>>m;
	int te,k,l;
	while(m--){
		cin>>te;
		if(te==1){
			cin>>l;
			cout<<query(l+1)<<'\n';
		}else{
			cin>>l>>k;
			updata(l+1,k);
		}
	}
	return 0;
}
