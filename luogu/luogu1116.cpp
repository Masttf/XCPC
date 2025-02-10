#include<bits/stdc++.h>
using namespace std;
int nums[10005];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	int count=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(nums[j]>nums[j+1])
				swap(nums[j],nums[j+1]),count++;
		}
	}
	cout<<count;
	return 0;
}
