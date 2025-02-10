#include<iostream>
#define int long long
using namespace std;
void mysort(int start,int end);
void merge(int start,int mid,int end);
struct p{
	int val;
	int id;
};
p res[1000005];
p nums[1000005];
int count[1000005];
int ans[1000005];
signed main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nums[i].val;
		nums[i].id=i;
	}
	mysort(1,n);
	for(int i=1;i<=n;i++){
		ans[i]=count[i]+ans[i-1];
	}
	cout<<ans[n];
	return 0;
}
void mysort(int start,int end){
	if(start==end)
		return ;
	int mid=start+(end-start)/2;
	mysort(start,mid);
	mysort(mid+1,end);
	merge(start,mid,end);
}
void merge(int start,int mid,int end){
	for (int i = start; i <= end; i++) {
		res[i] = nums[i];
	}
	int fast=start;
	int slow=mid+1;
	for(int i=start;i<=end;i++){
		if(fast==mid+1){
			nums[i]=res[slow];
			slow++;
		}else if(slow==end+1){
			nums[i]=res[fast];
			count[res[fast].id]+=slow-mid-1;
			fast++;
		}else if(res[fast].val>res[slow].val){
			nums[i]=res[slow];
			slow++;
		}else{
			nums[i]=res[fast];
			count[res[fast].id]+=slow-mid-1;
			fast++;
		}
	}
}
