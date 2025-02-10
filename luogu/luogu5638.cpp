#include<iostream>
#include<algorithm>
using namespace std;
long long pre[10000005];
int main(){
	long long n,k;
	cin>>n>>k;
	long long x;
	if(k>=n-1){
		cout<<0;
		return 0;
	}
	//前缀和
	for(int i=1;i<=n-1;i++){
		cin>>x;
		pre[i]=pre[i-1]+x;
	}
	//其实就是拿到k区间内的最大长度
    long long mk=pre[k];
	for(int i=1;i<n-1;i++){
		if(i+k>n-1)
			break;
		mk=max(mk,pre[i+k]-pre[i]);
	}
	cout<<pre[n-1]-mk;
	return 0;
}
