#include<iostream>
#include<vector>
using namespace std;
class SGTree{
	vector<vector<int>> seg;
	vector<vector<int>> init_seg;
public:
	SGTree(int row,int col){
		seg.resize(4*row,vector<int>(4*col));
		init_seg.resize(4*row,vector<int>(4*col));
	}
	void build(int ind,int low,int high,int rowno,vector<vector<int>>& arr){
		if(low==high){
			init_seg[rowno][ind]=arr[rowno][low];
			return;
		}
		int mid=(low+high)>>1;
		build(2*ind+1,low,mid,rowno,arr);
		build(2*ind+2,mid+1,high,rowno,arr);
		init_seg[rowno][ind]=init_seg[rowno][2*ind+1]+init_seg[rowno][2*ind+2];
	}
	void finalbuild(int ind,int low,int high,vector<vector<int>>& arr,int m){
		if(low==high){
			for(int i=0;i<4*m;i++){
				seg[ind][i]=init_seg[low][i];
			}
			return;
		}
		int mid=(low+high)>>1;
		finalbuild(2*ind+1,low,mid,arr,m);
		finalbuild(2*ind+2,mid+1,high,arr,m);
		for(int i=0;i<4*m;i++){
			seg[ind][i]=seg[2*ind+1][i]+seg[2*ind+2][i];
		}
	}
	void finalupdate(int ind,int low,int high,int rowno,int index,int val){
		if(low==high){
			seg[rowno][ind]=val;
			return;
		}
		int mid=(low+high)>>1;
		if(index<=mid){
			finalupdate(2*ind+1,low,mid,rowno,index,val);
		}
		else{
			update(2*ind+2,mid+1,high,rowno,index,val);
		}
		seg[rowno][ind]=seg[rowno][2*ind+1]+seg[rowno][2*ind+2];
	}
	void update(int ind,int low,int high,int x,int y,int val,int m){
		if(low==high){
			finalupdate(0,0,m-1,ind,y,val);
			return;
		}
		int mid=(low+high)>>1;
		if(x<=mid)update(2*ind+1,low,mid,x,y,val,m);
		else update(2*ind+2,mid+1,high,x,y,val,m);
		for(int i=0;i<4*m;i++){
			seg[ind][i]=seg[2*ind+1][i]+seg[2*ind+2][i];
		}
	}
	int finalquery(int ind,int low,int high,int l,int r,int rowno){
		if(high<l||r<low)return 0;
		else if(low<=l&&r<=high)return seg[rowno][ind];
		int mid=(low+high)>>1;
		int left=finalquery(2*ind+1,low,mid,l,r,rowno);
		int right=finalquery(2*ind+2,mid+1,high,l,r,rowno);
		return left+right;
	}
	int query(int ind,int low,int high,int x1,int x2,int y1,int y2,int m){
		if(x2<low||high<x1)return 0;
		else if(low<=x1&&x2<=high){
			return finalquery(0,0,m-1,y1,y2,ind);
		}
		int mid=(low+high)>>1;
		int left=query(2*ind+1,low,mid,x1,x2,y1,y2,m);
		int right=query(2*ind+2,mid+1,high,x1,x2,y1,y2,m);
		return left+right;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> arr(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	SGTree st(n,m);
	for(int i=0;i<n;i++){
		st.build(0,0,m-1,i,arr);
	}
	st.finalbuild(0,0,n-1,arr,m);
	
}