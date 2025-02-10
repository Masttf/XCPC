#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){//特殊例子，再通过普通变到特殊
	int n;cin>>n;//其实本质是一段连续的0或者1那么一定是剩下里最小或者最大的赢
	string s;cin>>s;//只和最后连续的串有关
	int l1=0,l2=0;//如果这个字母是1后缀连续1的个数
	//假设为x 如果x==n-1肯定只有最大的赢，如果不是则x+1到n都能赢
	//原因 在连续1前0之前可以把x+1到n的数除i拿出去比最后x+1到n只会剩下2个人再通过0筛掉1然后就只剩下
	for(int i=0;i<n-1;i++){
		int x=i+2;
		if(s[i]=='0'){
			l1=0,l2++;
			if(l2==i+1)cout<<1<<' ';
			else cout<<x-l2<<' ';
		}
		else{
			l1++;
			l2=0;
			if(l1==i+1)cout<<1<<' ';
			else cout<<x-l1<<' ';
		}
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
