#include<bits/stdc++.h>
using namespace std;

void DiskFcfs(int n,int seq[],int head){
	int current;
	int distance;
	int seek=0;
	for(int i=0;i<n;i++){
		current=seq[i];
		distance=abs(current-head);
		seek=seek+distance;
		head=current;
	}
	cout<<"Total Seek Operations :"<<seek<<endl;;
	cout<<"Sequence of Operations :";
	for(int i=0;i<n;i++){
		cout<<seq[i]<<" ";
	}
	cout<<""<<endl;
}

int main(){
	cout<<"Enter the no. of Sequences:";
	int n;
	cin>>n;
	int seq[n];
	cout<<"Enter the Sequence :";
	for(int i=0;i<n;i++){
		cin>>seq[i];
	}
	cout<<"Enter the head :";
	int head;
	cin>>head;
	DiskFcfs(n,seq,head);
	return 0;
}

/*
Enter the no. of Sequences:8
Enter the Sequence :176 79 34 60 92 11 41 114 
Enter the head :50
Total Seek Operations :510
Sequence of Operations :176 79 34 60 92 11 41 114
*/
