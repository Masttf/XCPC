#include<bits/stdc++.h>
using namespace std;
int nums[5000005];
int partition(int s,int e){
	int pivot=nums[s];
	int i=s+1,j=e;
	while(i<=j){
		while(i<e&&nums[i]<=pivot)i++;
		while(j>s&&nums[j]>pivot)j--;
		//结束时[s,i)为<=pivot(j,e]为>pivot
		if(i>=j)break;
		swap(nums[i],nums[j]);
	}
	swap(nums[s],nums[j]);
	return j;
}
int find_kth_minest(int k,int n){
	int s=1,e=n;
	while(s<=e){
		int p=partition(s,e);
		if(k<p)e=p-1;
		else if(k>p)s=p+1;
		else return nums[p];
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	srand(time(0));
	random_shuffle(nums+1,nums+1+n);
	cout<<find_kth_minest(k+1,n);
	return 0;
}
