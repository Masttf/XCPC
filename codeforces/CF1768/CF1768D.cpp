//首先考虑先将这个数组排序，可以交换任意两个位置
//那么首先就是第一个位置应该把1换过来再把原来的数换到它对的位置
//那么最终会成环，一个环的长度为n则需要交换n-1次，那么一整个数组需要交换的次数就是n-环数
//然后考虑逆序对即交换两个相邻位置,如果这个两个相邻位置不在同一个环上会导致两个环合并为一个环
//如果在一个环上则会分成两个环
//举例3 4 1 2  1 2 3 4成2个环 1-3 2-4 交换12则成 -2-3-1-4成一个环
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int res[maxn],a[maxn];
void solve(){
	memset(a,0,sizeof(a));
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i];
	int d=1;
	for(int i=1;i<=n;i++){
		if(a[i])continue;
		int v=i;
		while(a[v]==0){
			a[v]=d;
			v=res[v];
		}
		d++;
	}
	d--;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cout<<n-d-1<<'\n';
			return ;
		}
	}
	cout<<n-d+1<<'\n';
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
