#include<bits/stdc++.h>
using namespace std;

void FirstFit(int p,int process[],int b,int block[],int add){
	int allocation[p];
	int Internal[p];
	int External=0;
	int sum=0;
	for(int i=0;i<p;i++){
		allocation[i]=-1;
		Internal[i]=0;
	}
	
	for(int i=0;i<p;i++){
		for(int j=0;j<b;j++){
			if(block[j] >= process[i]){
			allocation[i]=j;
			Internal[i]=block[j]-process[i];
			sum=sum+block[j];
			block[j]=0;
			break;
			}
		}
	}
	External=add-sum;
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
	FirstFit(p,process,b,block,add);
	return 0;
}


/*
Enter the no. of Process : 4
Enter Processes :212 417 112 426
Enter the no. of Block : 5
Enter Blocks :100 500 200 300 600
process	block	allocation	internalfrag
1	212	2		288
2	417	5		183
3	112	3		88
4	426	Not Allocated.		0
External Fragmentation is Present : 400

*/
