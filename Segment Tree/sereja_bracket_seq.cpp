#include<bits/stdc++.h>
using namespace std;
struct node{
int open,close,full;
node(int _open,int _close,int _full){
	open=_open;
	close=_close;
	full=_full;
}	
};
node merge(node left,node right){
	int open=left.open+right.open-min(left.open,right.close);
	int close=left.close+right.close-min(left.open,right.close);
	int full=left.full+right.full+min(left.open,right.close);
	return node(open,close,full);
}
void build(int ind,int low,int high,string s,node seg[]){
	if(low==high){
		seg[ind]=node(s[low]=='(',s[low]==')',0);
		return;
	}
	int mid=(low+high)>>1;
	build(2*ind+1,low,mid,s,seg);
	build(2*ind+2,mid+1,high,s,seg);
	seg[ind].open=seg[2*ind+1].open+seg[2*ind+2].open-min(seg[2*ind+1].open,seg[2*ind+2].close);
	seg[ind].close=seg[2*ind+1].close+seg[2*ind+2].close-min(seg[2*ind+1].open,seg[2*ind+2].close);
	seg[ind].full=min(seg[2*ind+1].open,seg[2*ind+2].close)+seg[2*ind+1].full+seg[2*ind+2].full;
	
	
}
node query(int ind,int low,int high,node seg[],int l,int r){
	if(r<low||high<l){
		return node(0,0,0);
	}
	else if(l<=low&&high<=r){
		return seg[ind];
	}
	int mid=(low+high)>>1;
	int left=query(2*ind+1,low,mid,seg,l,r);
	int right=query(2*ind+2,mid+1,high,seg,l,r);
	return merge(seg[2*ind+1],seg[2*ind+2]);
}
int main(){
	string str;
	cin>>str;
	int n=str.size();
	int q;
	cin>>q;
	node seg[4*n];
	build(0,0,n-1,str,seg);
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		query(0,0,n-1,seg,l,r);
	}
	return 0;
}