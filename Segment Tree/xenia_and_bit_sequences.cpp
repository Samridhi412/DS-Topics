#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,int seg[],int arr[],int isor){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}
	int mid=(low+high)>>1;
	build(2*ind+1,low,mid,seg,arr,isor);
	build(2*ind+2,mid+1,high,seg,arr,isor);
	if(isor)seg[ind]=seg[2*ind+1]|seg[2*ind+2];
	else seg[ind]=seg[2*ind+1]^seg[2*ind+2];
}
void update(int ind,int low,int high,int index,int value,int seg[],nt isor){
	if(low==high){
		seg[ind]=value;
		return;
	}
	int mid=(low+high)>>1;
	if(index<=mid){
		update(2*ind+1,low,mid,index,value,seg,isor);
	}
	else{
		update(2*ind+2,mid+1,high,index,value,seg,isor);
	}
	if(isor)seg[ind]=seg[2*ind+1]|seg[2*ind+2];
	else seg[ind]=seg[2*ind+1]^seg[2*ind+2];
}
int main(){
	int n,q;
	int ele=1<<n;
	int arr[ele];
	for(int i=0;i<ele;i++){
		cin>>arr[i];
	}
	int seg[4*ele+1];
	if(n&1)build(0,0,ele-1,seg,arr,1);
	else build(0,0,ele-1,seg,arr,0);
	while(q--){
		int ind,val;
	    ind--;
	    arr[ind]=val;
	    if(n&1)update(0,0,ele-1,ind,val,seg,1);
	    else update(0,0,ele-1,ind,val,seg,0);
	    cout<<seg[0]<<endl;
	}
	return 0;
	
}