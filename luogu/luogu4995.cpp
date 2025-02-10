#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[305];
signed main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	sort(res+1,res+1+n);
	int left=1;
	int right=n;
	int flag=1;//判断从高跳到矮还是从矮跳到高
	int sum=res[n]*res[n];
	while(left<right){
		if(flag){
			sum+=(res[right]-res[left])*(res[right]-res[left]);
			right--;
			flag=0;
		}else{
			sum+=(res[right]-res[left])*(res[right]-res[left]);
			left++;
			flag=1;
		}
	}
	cout<<sum;
	return 0;
}
