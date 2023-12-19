#include<bits/stdc++.h>
using namespace std;

void BestFit(int p,int process[],int b,int block[],int add){
	int allocation[p];
	int Internal[p];
	int External=0;
	int sum=0;
	for(int i=0;i<p;i++){
		allocation[i]=-1;
		Internal[i]=0;
	}
	
	for(int i=0;i<p;i++){
		int wf=-1;
		for(int j=0;j<b;j++){
			if(block[j] >= process[i]){
				if(wf==-1){
					wf=j;
				}
				else if(block[j] < block[wf]){
					wf=j;
				}
			}
		}
	if(wf!=-1){
			allocation[i]=wf;
			Internal[i]=block[wf]-process[i];
			sum=sum+block[wf];
			block[wf]=0;
		}
	}
	cout<<"process\tblock\tallocation\tinternalfrag"<<endl;
	for(int i=0;i<p;i++){
		cout<<i+1<<"\t"<<process[i];
		if(allocation[i]!=-1){
			cout<<"\t"<<allocation[i]+1;
		}
		else{
			cout<<"\t"<<"Not Allocated.";
		}
		cout<<"\t\t"<<Internal[i]<<endl;
	}
	External=add-sum;
	if(External >0){
			cout<<"External Fragmentation is Present : "<<External<<endl;
		}
	else{
			cout<<"External Fragmentation is NOT Present."<<endl;
		}
}

int main(){
	cout<<"Enter the no. of Process : ";
	int p,b;
	cin>>p;
	cout<<"Enter Processes :";
	int process[p];
	for(int i=0;i<p;i++){
		cin>>process[i];
	}
	cout<<"Enter the no. of Block : ";
	cin>>b;
	int block[b];
	int add=0;
	cout<<"Enter Blocks :";
	for(int i=0;i<b;i++){
		cin>>block[i];
		add=add+block[i];
	}
	BestFit(p,process,b,block,add);
	return 0;
}

/*
Enter the no. of Process : 4
Enter Processes :20 30  40 50
Enter the no. of Block : 5
Enter Blocks :10 20 30 10 20
process	block	allocation	internalfrag
1	20	2		0
2	30	3		0
3	40	Not Allocated.		0
4	50	Not Allocated.		0
External Fragmentation is Present : 40


*/
