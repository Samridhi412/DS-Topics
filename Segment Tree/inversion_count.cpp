#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,int seg[],int arr[]){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}
	int mid=(low+high)>>1;
	build(2*ind+1,low,mid,seg,arr);
	build(2*ind+2,mid+1,high,seg,arr);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
void update(int ind,int low,int high,int seg[],int index){
	if(low==high){
		seg[ind]-=1;
		return;
	}
	int mid=(low+high)>>1;
	if(index<=mid){
		update(2*ind+1,low,mid,seg,index);
	}
	else{
		update(2*ind+2,mid+1,high,seg,index);
	}
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int query(int ind,int low,int high,int seg[],int l,int r){
	if(high<l||r<low)return 0;
	else if(l<=low&&high<=r)return seg[ind];
	int mid=(low+high)>>1;
	int left=query(2*ind+1,low,mid,seg,l,r);
	int right=query(2*ind+2,mid+1,high,seg,l,r);
	return left+right;
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max_ele=*max_element(arr.begin(),arr.end());
	int freq[max_ele+1];
	memset(freq,0,sizeof(freq));
	for(int i=0;i<n;i++){
		freq[arr[i]]++;
	}
	int seg[4*n];
	int res=0;
	build(0,0,max_ele,seg,freq);
	for(int i=0;i<n;i++){
		freq[arr[i]]--;
		update(0,0,max_ele,seg,arr[i]);
		res+=query(0,0,max_ele,seg,1,arr[i]-1);
	}
}