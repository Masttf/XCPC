#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
#define int long long
using namespace std;
const int maxn=1e5+5;
int tree1[maxn],tree2[maxn];
int n,m;
void updata1(int x,int d){
	while(x<=n){
		tree1[x]+=d;
		x+=lowbit(x);
	}
	return ;
}
void updata2(int x,int d){
	while(x<=n){
		tree2[x]+=d;
		x+=lowbit(x);
	}
	return ;
}
int sum1(int x){
	int ans=0;
	while(x>0){
		ans+=tree1[x];
		x-=lowbit(x);
	}
	return ans;
}
int sum2(int x){
	int ans=0;
	while(x>0){
		ans+=tree2[x];
		x-=lowbit(x);
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int old=0,t,x,y,k;
	for(int i=1;i<=n;i++){
		cin>>t;
		updata1(i,t-old);
		updata2(i,(i-1)*(t-old));
		old=t;
	}
	for(int i=1;i<=m;i++){
		cin>>t;
		if(t==1){
			cin>>x>>y>>k;
			updata1(x,k);
			updata1(y+1,-k);
			updata2(x,(x-1)*k);
			updata2(y+1,(-k)*y);
		}else{
			cin>>x>>y;
			cout<<y*sum1(y)-sum2(y)-(x-1)*sum1(x-1)+sum2(x-1)<<'\n';
		}
	}
	return 0;
}
/*分块
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int sum[maxn],pos[maxn],add[maxn],a[maxn],block,t,s[maxn],ed[maxn];
void updata(int l,int r,int d){
	int p=pos[l],q=pos[r];
	if(p==q){
		for(int i=l;i<=r;i++){
			a[i]+=d;
		}
		sum[p]+=(r-l+1)*d;
	}else{
		for(int i=p+1;i<=q-1;i++)add[i]+=d;
		for(int i=l;i<=ed[p];i++)a[i]+=d;
		sum[p]+=(ed[p]-l+1)*d;
		for(int i=s[q];i<=r;i++)a[i]+=d;
		sum[q]+=(r-s[q]+1)*d;
	}
	return ;
}
int query(int l,int r){
	int p=pos[l],q=pos[r];
	int ans=0;
	if(p==q){
		for(int i=l;i<=r;i++)ans+=a[i];
		ans+=(r-l+1)*add[q];
	}else{
		for(int i=p+1;i<=q-1;i++)ans+=sum[i]+(ed[i]-s[i]+1)*add[i];
		for(int i=l;i<=ed[p];i++)ans+=a[i];
		ans+=(ed[p]-l+1)*add[p];
		for(int i=s[q];i<=r;i++)ans+=a[i];
		ans+=(r-s[q]+1)*add[q];
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	block=sqrt(n);
	t=n/block;
	if(n%block)t++;
	ed[t]=n;
	for(int i=1;i<=n;i++)cin>>a[i],pos[i]=(i-1)/block+1;
	for(int i=1;i<=t;i++){
		s[i]=(i-1)*block+1;
		ed[i]=i*block;
	}
	for(int i=1;i<=t;i++){
		for(int j=s[i];j<=ed[i];j++){
			sum[i]+=a[j];
		}
	}
	int t,x,y,k;
	while(m--){
		cin>>t;
		if(t==1){
			cin>>x>>y>>k;
			updata(x,y,k);
		}else{
			cin>>x>>y;
			cout<<query(x,y)<<'\n';
		}
	}
	return 0;
}
 */
