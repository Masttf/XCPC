#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
struct node{
	int val,num,tm;
	bool operator <(const node &y)const{
		return val<y.val;
	}
}a[maxn];
int ans[maxn];
map<int,int>mm;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,x;cin>>x>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val>>a[i].tm>>a[i].num;
	}
	for(int i=1;i<=x;i++)mm[i]=1;
	mm[x+1]=1;
	mm[0]=1;
	sort(a+1,a+1+n);//对于每种糖果都是放到离当前时间最后的最贪
	for(int i=1;i<=n;i++){
		if(mm.size()==2)break;
		int r=a[i].tm;
		r=min(x,r);
		int cnt=a[i].num;
		for(auto it=--mm.upper_bound(r);it->first>=1;it--){
			if(!cnt)break;
			ans[it->first]=a[i].val;
			it=mm.erase(it);//注意map的删除操作以及边界问题
			cnt--;
		}
	}
	int f=1;
	for(int i=1;i<=x;i++){
		if(ans[i]==0)f=0;
		ans[i]+=ans[i-1];
	}
	if(f)cout<<ans[x];
	else cout<<-1;
	return 0;
}
