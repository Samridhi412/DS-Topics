#include<bits/stdc++.h>
using namespace std;
void z_array(int z[],string& s){
	z[0]=0;
	int l=0,r=0;
	for(int i=1;i<s.size();i++){
		if(i>r){
			l=r=i;
		while(r<=s.size()&&s[r]==s[r-l]){
			r++;
		}
		z[i]=r-l;
		r--;
		}
		else{
			int ind=i-l;
			if(z[ind]<=r-i){
				z[i]=z[ind];
			}
			else{
				l=i;
				while(r<=s.size()&&s[r]==s[r-l]){
				r++;
				}
				z[i]=r-l;
				r--;
			}
		}
	}
}
void z_algorithm(string& s,int m){
	int n=s.size();
	int zarr[n];
	z_array(zarr,s);
	for(int x=0;x<=n;x++){
		if(zarr[x]==m){
			cout<<"pattern found at index"<<x-(m+1)<<endl;
		}
	}
}
int main(){
string text,pat;
getline(cin,text);
getline(cin,pat);
int m=pat.size();
string tot=pat+'#'+text;
z_algorithm(tot,m);
	return 0;
}