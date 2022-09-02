#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,int arr[],int seg[]){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}
	int mid=(low+high)>>1;
	build(2*ind+1,low,mid,arr,seg);
	build(2*ind+2,mid+1,high,arr,seg);
	seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r,int seg[]){
	// no overlap
	if(high<l||r<low){
		return INT_MAX;
	}
	// complete overlap
	else if(l<=low&&high<=r){
		return seg[ind];
	}
	// partial overlap
	int mid=(low+high)>>1;
	int left=query(2*ind+1,low,mid,l,r,seg);
	int right=query(2*ind+2,mid+1,high,l,r,seg);
	return min(left,right);
}
void update(int ind,int low,int high,int index,int value,int seg[]){
	if(low==high){
		seg[ind]=value;
		return;
	}
	int mid=(low+high)>>1;
	if(index<=mid){
		update(2*ind+1,low,mid,index,value,seg);
	}
	else{
		update(2*ind+2,mid+1,high,index,value,seg);
	}
	seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int seg[4*n];
	build(0,0,n-1,arr,seg);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int type;
		cin>>type;
		if(type==1){
			int l,r;
			cin>>l>>r;
			cout<<query(0,0,n-1,l,r,seg);
		}
		else if(type==2){
			int ind,val;
			cin>>ind>>val;
			arr[ind]=val;
			update(0,0,n-1,ind,val,seg);
		}
	}
}