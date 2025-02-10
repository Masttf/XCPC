//即前缀和一定是递增的所以枚举某个i所对应的值作为最小值那么其最大的舒适度为左边相同的和右边相同的
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int res[100];
int pre[100];
int dp[100];
int left[100];
int rihgt[100];
stack<int>l;
stack<int>r;
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		pre[i]=pre[i-1]+res[i];
	}
	
	return 0;
}
