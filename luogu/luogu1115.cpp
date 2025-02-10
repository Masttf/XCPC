//dp
//前缀和
//滑动窗口
#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[300005];
signed main(){
	int n;cin>>n;
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		res[i]=a+res[i-1];
	}
	//
	int mx=res[1];//最长递增子序列不就是这个点减去前面min的res【i
	int mi=res[0];
	for(int i=1;i<n;i++){
		mi=min(mi,res[i]);//0到i的最小值
		mx=max(mx,res[i+1]-mi);//前去前面的最小值就是以这个节点的最大子序列
	}
	cout<<mx;
	return 0;
}
