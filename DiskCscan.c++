#include<bits/stdc++.h>
using namespace std;

void DiskCscan(int n,int req[],int head,int DiskSize){
	vector<int>left,right;
	vector<int>seq;
	left.push_back(0);
	right.push_back(DiskSize-1);
	
	for(int i=0;i<n;i++){
		if(req[i] > head){
			right.push_back(req[i]);
		}
		if(req[i] < head){
			left.push_back(req[i]);
		}
	}
	
	std::sort(left.begin(),left.end());
	std::sort(right.begin(),right.end());
	
	int seek=0;int distance;
	int current;
	
	for(int i=0;i<right.size();i++){
		current=right[i];
		seq.push_back(right[i]);
		distance=abs(current-head);
		seek=seek+distance;
		head=current;
	}
	seek=seek+(DiskSize-1);
	head=0;
	for(int i=0;i<left.size();i++){
		current=left[i];
		seq.push_back(left[i]);
		distance=abs(current-head);
		seek=seek+distance;
		head=current;
	}
	
	cout<<"Total Seek Operations :"<<seek<<endl;;
	cout<<"Sequence of Operations :";
	for(int i=0;i<seq.size();i++){
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
	cout<<"Enter the Disk Size:";
	int DiskSize;
	cin>>DiskSize;
	DiskCscan(n,req,head,DiskSize);
	return 0;
}

/*
Enter the no. of Sequences:8
Enter the Sequence :176 79 34 60 92 11 41 114
Enter the head :50
Enter the Disk Size:200
Total Seek Operations :389
Sequence of Operations :60 79 92 114 176 199 0 11 34 41
*/

