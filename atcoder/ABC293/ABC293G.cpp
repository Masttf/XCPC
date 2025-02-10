#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int len;
struct node{
	int l,r,id;
}qe[maxn];// 对问题进行莫队
//莫队的作用离线区间查询时间复杂度n*sqrt(n);
bool cmp(node&x,node&y){
	int i=x.l/len,j=y.l/len;
	if(i!=j)return i<j;
	else return x.r<y.r;
}
int ans[maxn];
int cnt[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	len = sqrt(q);
	for(int i=1;i<=q;i++){
		cin>>qe[i].l>>qe[i].r;
		qe[i].id=i;
	}
	sort(qe+1,qe+1+q,cmp);
	int res=0;
	for(int i=1,l=1,r=0;i<=q;i++){
		int ll=qe[i].l,rr=qe[i].r;
		while(r<rr){
			r++;
			res-=(cnt[a[r]])*(cnt[a[r]]-1)*(cnt[a[r]]-2)/6;
			cnt[a[r]]++;
			res+=(cnt[a[r]])*(cnt[a[r]]-1)*(cnt[a[r]]-2)/6;
		}
		while(r>rr){
			res-=(cnt[a[r]])*(cnt[a[r]]-1)*(cnt[a[r]]-2)/6;
			cnt[a[r]]--;
			res+=(cnt[a[r]])*(cnt[a[r]]-1)*(cnt[a[r]]-2)/6;
			r--;
		}
		while(l<ll){
			res-=(cnt[a[l]])*(cnt[a[l]]-1)*(cnt[a[l]]-2)/6;
			cnt[a[l]]--;
			res+=(cnt[a[l]])*(cnt[a[l]]-1)*(cnt[a[l]]-2)/6;
			l++;
		}
		while(l>ll){
			l--;
			res-=(cnt[a[l]])*(cnt[a[l]]-1)*(cnt[a[l]]-2)/6;
			cnt[a[l]]++;
			res+=(cnt[a[l]])*(cnt[a[l]]-1)*(cnt[a[l]]-2)/6;
		}
		ans[qe[i].id]=res;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}
