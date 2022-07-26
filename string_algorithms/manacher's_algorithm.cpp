#include<bits/stdc++.h>
using namespace std;
void manachers_algo(string& text){
	int n=text.size();
	if(n==0){
		cout<<0<<endl;
	}
	n=2*n+1;
	int lps[n];
	lps[0]=0;
	lps[1]=1;
	int c=1;//centerposition
	int r=2;//centerrightposition
	int imirror;  //currentleftposition
	int diff=0;
	int expand=0;
	int maxlpslength=0;
	int maxcenterpos=0;
	for(int i=2;i<n;i++){
		imirror=2*c-i; //i-c=c-i'=i'=2c-i
		diff=r-i;
		expand=0;
		if(diff>=0){
			if(lps[imirror]<diff){
				lps[i]=lps[imirror];
			}
			else if(lps[imirror]==diff&&r==n-1){
				lps[i]=lps[imirror];
			}
			else if(lps[imirror]==diff&&r<n-1){
				lps[i]=lps[imirror];
				expand=1;
			}
			else if(lps[imirror]>diff){
				lps[i]=diff;
				expand=1;
			}
		}
		else{
			lps[i]=0;
			expand=1;
		}
		if(expand){
			while(((i-lps[i])>0&&(i+lps[i])<n)&&(((i+lps[i]+1)%2==0)||(text[(i+lps[i]+1)/2]==text[(i-lps[i]-1)/2]))){
				lps[i]++;
			}
		}
		if(lps[i]>maxlpslength){
			maxlpslength=lps[i];
			maxcenterpos=i;
		}
		if(i+lps[i]>r){
			c=i;
			r=i+lps[i];
		}
	}
	int start=(maxcenterpos-maxlpslength)/2;
	int end=start+maxlpslength-1;
	for(int i=start;i<=end;i++){
		cout<<text[i]<<" ";
	}
	cout<<endl;
}
int main(){
	string text,pat;
	getline(cin,text);
	manachers_algo(text);
	return 0;
}