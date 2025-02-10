#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
struct node{
	int x,y,val;
}g[maxn];
int a[maxn],b[maxn];
int px[maxn],py[maxn];
map<pair<int,int>,int>m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i].x>>g[i].y>>g[i].val;
		a[i]=g[i].x;
		b[i]=g[i].y;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int l1=unique(a+1,a+1+n)-a;
	int l2=unique(b+1,b+1+n)-b;
	for(int i=1;i<=n;i++){
		g[i].x=lower_bound(a+1,a+l1,g[i].x)-a;
		g[i].y=lower_bound(b+1,b+l2,g[i].y)-b;
		m[{g[i].x,g[i].y}]=1;
	}
	for(int i=1;i<=n;i++){
		px[g[i].x]+=g[i].val;
		py[g[i].y]+=g[i].val;
	}
	int ans=0;
	set<pair<int,int>>s;
	for(int i=1;i<=l2-1;i++)s.insert({py[i],i});
	for(int i=1;i<=n;i++){
		ans=max(ans,px[g[i].x]+py[g[i].y]-g[i].val);
	}
	for(int i=1;i<=l1;i++){//因为一共就n个点所以最多就跳n次
		auto it=s.end();
		it--;
		while(1){
			pair<int,int>temp=*it;
			if(!m.count({i,temp.second})){
				ans=max(ans,px[i]+temp.first);
				break;
			}
			if(it==s.begin())break;
			it--;
		}
	}
	cout<<ans;
	return 0;
}
