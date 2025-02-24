#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
const int maxn=1e5+5;
int a[maxn],tree[maxn],bin[maxn];
int n,k;
void updata(int x,int kk){
	while(x<=n){//更新时每个节点既要更新最大值需要直连节点然后更新父节点，父节点同样操作
		tree[x]=kk;
		for(int i=1;i<lowbit(x);i<<=1){
			tree[x]=max(tree[x],tree[x-i]);
		}
		x+=lowbit(x);
	}
}
int query(int L,int R){
	int ans=0;
	while(L<=R){
		ans=max(ans,bin[R]);
		R--;
		while(R-L>=lowbit(R)){
			ans=max(ans,tree[R]);
			R-=lowbit(R);
		}
	}
	return ans;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans1=0;
	for(int i=1;i<=n;i++){
		int l=1,r=ans1,res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			int t =query(1,mid);
			if(t>=a[i])res=mid,r=mid-1;
			else l=mid+1;
		}
		if(res==-1){
			ans1++;
			bin[ans1]=k-a[i];
			updata(ans1,k-a[i]);
		}else{
			bin[res]-=a[i];
			updata(res,bin[res]-a[i]);
		}
	}
	multiset<int>s;
	for(int i=1;i<=n;i++){
		auto it=s.lower_bound(a[i]);
		if(it!=s.end()){
			int mid=*it-a[i];
			s.erase(it);
			s.insert(mid);
		}else{
			s.insert(k-a[i]);
		}	
	}
	cout<<ans1<<' '<<s.size()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}		
	return 0;
}
