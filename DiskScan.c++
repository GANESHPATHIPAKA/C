#include<bits/stdc++.h>
using namespace std;

void DiskScan(int n,int req[],int head,string Direction,int DiskSize){
	vector<int>left,right;
	vector<int>seq;
	
	if(Direction =="Left"){
		left.push_back(0);
	}
	else if(Direction == "Right"){
		right.push_back(DiskSize-1);
	}
	
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
	
	int current;
	int distance;
	int seek=0;
	int run=2;
	while(run--){
		if(Direction =="Left"){
			for(int i=left.size()-1;i!=-1;i--){
				current=left[i];
				seq.push_back(current);
				distance=abs(current-head);
				seek=seek+distance;
				head=current;
			}
			Direction = "Right";
		}
		else if(Direction == "Right"){
			for(int i=0;i<right.size();i++){
				current=right[i];
				seq.push_back(current);
				distance=abs(current-head);
				seek=seek+distance;
				head=current;
			}
			Direction ="Left";
		}
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
	cout<<"Enter Direction :";
	string Direction;
	cin>>Direction;
	cout<<"Enter the Disk Size:";
	int DiskSize;
	cin>>DiskSize;
	DiskScan(n,req,head,Direction,DiskSize);
	return 0;
}

/*
Enter the no. of Sequences:8
Enter the Sequence :176 79 34 60 92 11 41 114
Enter the head :50
Enter Direction :Left
Enter the Disk Size:200
Total Seek Operations :226
Sequence of Operations :41 34 11 0 60 79 92 114 
*/
