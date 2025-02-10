//遍历加二分找数
//另解map
//或者利用双指针来寻找这个区间？倍增
#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[200005],cnt;
int left_bound(int target,int n){
	int i=1,j=n;
	while(i<=j){
		int mid=(i+j)>>1;
		if(res[mid]==target){
			j=mid-1;
		}else if(res[mid]>target){
			j=mid-1;
		}else if(res[mid]<target){
			i=mid+1;
		}
	}
	if(res[i]==target)return i;
	else return 0;
}
int right_bound(int target,int n){
	int i=1,j=n;
	while(i<=j){
		int mid=(i+j)>>1;
		if(res[mid]==target){
			i=mid+1;
		}else if(res[mid]>target){
			j=mid-1;
		}else if(res[mid]<target){
			i=mid+1;
		}
	}
	if(res[j]==target)return j;
	else return 0;
}
signed main(){
	int n,c;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	sort(res+1,res+1+n);
	int a;
	for(int i=1;i<=n;i++){
		a=res[i];
		int left=left_bound(a-c,n);
		int right;
		if(left){
			right=right_bound(a-c,n);
			cnt+=right-left+1;
		}
	}
	cout<<cnt;
	return 0;
}
