//分块，排序一个排序多次使用
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn],s[maxn],ed[maxn],add[maxn],pos[maxn],b[maxn];
void updata(int l,int r,int d){
	int p=pos[l],q=pos[r];
	if(p==q){
		for(int i=l;i<=r;i++)a[i]+=d;
		for(int i=s[p];i<=ed[p];i++)b[i]=a[i];
		sort(b+s[p],b+ed[p]+1);
	}else{
		for(int i=p+1;i<=q-1;i++)add[i]+=d;
		for(int i=l;i<=ed[p];i++)a[i]+=d;
		for(int i=s[p];i<=ed[p];i++)b[i]=a[i];
		sort(b+s[p],b+ed[p]+1);
		for(int i=s[q];i<=r;i++)a[i]+=d;
		for(int i=s[q];i<=ed[q];i++)b[i]=a[i];
		sort(b+s[q],b+ed[q]+1);
	}
	return ;
}
int query(int l,int r,int k){
	int p=pos[l],q=pos[r];
	int cnt=0;
	if(p==q){
		k-=add[p];
		for(int i=l;i<=r;i++){
			if(a[i]>=k)cnt++;
		}
	}
	else{
		for(int i=p+1;i<=q-1;i++){
			cnt+=ed[i]+1-(lower_bound(b+s[i],b+ed[i]+1,k-add[i])-b);
		}
		for(int i=l;i<=ed[p];i++){
			if(a[i]>=k-add[p])cnt++;
		}
		for(int i=s[q];i<=r;i++){
			if(a[i]>=k-add[q])cnt++;
		}
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int block=sqrt(n);
	int t=n/block;
	if(n%block)t++;
	for(int i=1;i<=t;i++){
		s[i]=(i-1)*block+1;
		ed[i]=i*block;
	}
	ed[t]=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		pos[i]=(i-1)/block+1;
	}
	for(int i=1;i<=t;i++){
		sort(b+s[i],b+ed[i]+1);
	}
	string temp;
	int x,y,c;
	while(m--){
		cin>>temp>>x>>y>>c;
		if(temp[0]=='A'){
			cout<<query(x,y,c)<<'\n';
		}else{
			updata(x,y,c);
		}
	}
	return 0;
}
