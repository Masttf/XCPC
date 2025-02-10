#include<bits/stdc++.h>
using namespace std;
int res[50005];
int main(){
	int w,n;
	cin>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	sort(res+1,res+1+n);
	int left=1,right=n;
	int ans=0;
	while(left<=right){
		if(res[right]+res[left]<=w){
			left++;
			right--;
		}else{
			right--;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
