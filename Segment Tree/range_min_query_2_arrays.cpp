#include<bits/stdc++.h>
using namespace std;
class SGTree{
	vector<int> seg; 
public:
	SGTree(int n){
		seg.resize(4*n+1);
	}
	void build(int ind,int low,int high,int arr[]){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}
	int mid=(low+high)>>1;
	build(2*ind+1,low,mid,arr);
	build(2*ind+2,mid+1,high,arr);
	seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r){
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
	int left=query(2*ind+1,low,mid,l,r);
	int right=query(2*ind+2,mid+1,high,l,r);
	return min(left,right);
}
void update(int ind,int low,int high,int index,int value){
	if(low==high){
		seg[ind]=value;
		return;
	}
	int mid=(low+high)>>1;
	if(index<=mid){
		update(2*ind+1,low,mid,index,value);
	}
	else{
		update(2*ind+2,mid+1,high,index,value);
	}
	seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
};
//JUST ONE ARRAY.... OPERATIONS(QUERY,UPDATE)
// void solve(){
// 	int n;
// 	cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++){
// 		cin>>arr[i];
// 	}
// 	int seg[4*n];
// 	build(0,0,n-1,arr,seg);
// 	int q;
// 	cin>>q;
// 	for(int i=0;i<q;i++){
// 		int type;
// 		cin>>type;
// 		if(type==1){
// 			int l,r;
// 			cin>>l>>r;
// 			cout<<query(0,0,n-1,l,r,seg);
// 		}
// 		else if(type==2){
// 			int ind,val;
// 			cin>>ind>>val;
// 			arr[ind]=val;
// 			update(0,0,n-1,ind,val,seg);
// 		}
// 	}
// }
//NOW YOU ARE GUVEN 2 ARRAYS INSTEAD OF BASICALLY DOING CODE REDUNDANCY MAKE USE OF OOPS CONCEPTS THAT IS CLASSES OBJECTS
void solve2(){
	int n1,n2;
	cin>>n1>>n2;
	int arr1[n1],arr2[n2];
	for(int i=0;i<n1;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<n2;i++){
		cin>>arr2[i];
	}
	SGTree seg1(n1);
	SGTree seg2(n2);
	seg1.build(0,0,n1-1,arr1);
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int l1,r1,l2,r2;
			cin>>l1>>r1>>l2>>r2;
			int ans1=seg1.query(0,0,n1-1,l1,r1);
			int ans2=seg2.query(0,0,n2-1,l2,r2);
			cout<<min(ans1,ans2);
		}
		else{
			int arrno,ind,val;
			cin>>arrno>>ind>>val;
			if(arrno==1){
				seg1.update(0,0,n1-1,ind,val);
				arr1[ind]=val;
			}
			else{
				seg2.update(0,0,n2-1,ind,val);
				arr2[ind]=val;
			}
		}
	}
}