#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;//即应该要找出合法的x使得原本是大于的变成小于，小于的不变
	for(int i=1;i<=n;i++)cin>>a[i];//考虑所有x的范围
	//如果原本是《那么x的范围就是《两个相加向下取整
	//如果原本是》那么x的范围是两个相加向上取整
	int l=0,r=INT_MAX;
	for(int i=1;i<n;i++){
		if(a[i]<a[i+1]){
			r=min(r,(a[i]+a[i+1])/2);
		}else if(a[i]>a[i+1]){
			l=max(l,(a[i]+a[i+1]+1)/2);//向上取整
		}	
	}
	if(r>=l)cout<<l<<'\n';
	else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
