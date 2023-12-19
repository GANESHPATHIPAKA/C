#include<bits/stdc++.h>
using namespace std;

void FindDiff(int n,int req[],int head,int diff[][2]){
	for(int i=0;i<n;i++){
		diff[i][0]=abs(head-req[i]);
	}
}

int FindMin(int diff[][2],int n){
	int index=-1;
	int min=1e9;
	for(int i=0;i<n;i++){
		if(!diff[i][1] && diff[i][0] < min){
			min=diff[i][0];
			index=i;
		}
	}
	return index;
}

void DiskSstf(int n,int req[],int head){
	if(n==0){
		return;
	}
	int diff[n][2]={{0,0}};
	int seq[n+1]={0};
	int seek=0;
	for(int i=0;i<n;i++){
		seq[i]=head;
		FindDiff(n,req,head,diff);
		int index=FindMin(diff,n);
		diff[index][1]=1;
		seek=seek+diff[index][0];
		head=req[index];
	}
	seq[n]=head;
	
	cout<<"Total Seek Operations :"<<seek<<endl;;
	cout<<"Sequence of Operations :";
	for(int i=0;i<=n;i++){
		cout<<seq[i]<<" ";
	}
	cout<<""<<endl;
}

int main(){
	cout<<"Enter the no. of Sequences:";
	int n;
	cin>>n;
	int req[n];
	cout<<"Enter the Sequence :";
	for(int i=0;i<n;i++){
		cin>>req[i];
	}
	cout<<"Enter the head :";
	int head;
	cin>>head;
	DiskSstf(n,req,head);
	return 0;
}

/*
Enter the no. of Sequences:8
Enter the Sequence :176 79 34 60 92 11 41 114 
Enter the head :50
Total Seek Operations :204
Sequence of Operations :50 41 34 11 60 79 92 114 176 

*/
