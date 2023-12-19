#include<bits/stdc++.h>
using namespace std;

int main(){
	cout<<"Enter no of  Processes : ";
	int n;
	cin>>n;
	cout<<"Enter no of Resources : ";
	int m;
	cin>>m;
	cout<<"Enter Allocation : ";
	int Allocation[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>Allocation[i][j];
		}
	}
	cout<<"Enter Max Allocation : ";
	int MaxAllocation[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>MaxAllocation[i][j];
		}
	}
	cout<<"Enter Availability : ";
	int Availability[m];
	for(int i=0;i<m;i++){
		cin>>Availability[i];
	}
	
	int Need[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			Need[i][j]=MaxAllocation[i][j]-Allocation[i][j];
		}
	}
	int Finish[n];
	int index=0;
	int Result[n];
	for(int i=0;i<n;i++){
		Finish[i]=0;
	}
	int flag1;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(Finish[i]==0){
				int flag1=0;
				for(int j=0;j<m;j++){
					if(Need[i][j]>Availability[j]){
						flag1=1;
						break;
					}
				}	
				if(flag1==0){
					Result[index++]=i;
					for(int y=0;y<m;y++){
						Availability[y]=Availability[y]+Allocation[i][y];
						Finish[i]=1;
					}
				}
			}
		}	
	}
	cout<<"Need Matrix :"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<Need[i][j]<<" ";
		}
		cout<<""<<endl;
	}
	int flag2=1;
	for(int i=0;i<n;i++){
		if(Finish[i]==0){
			flag2=0;
			cout<<"The Sequenece is NOT Safe."<<endl;
			break;
		}
	}
	if(flag2==1){
		cout<<"Following is the SAFE Sequence."<<endl;
		for(int i=0;i<n-1;i++){
			cout<<"P"<<Result[i]<<"-> ";
		}
		cout<<"P"<<Result[n-1]<<endl;
	}
	
	return 0;
}


/*
Enter no of  Processes : 5
Enter no of Resources : 3
Enter Allocation :  0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter Max Allocation : 
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter Availability : 3 3 2
Need Matrix :
7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 
Following is the SAFE Sequence.
P1-> P3-> P4-> P0-> P2

*/
