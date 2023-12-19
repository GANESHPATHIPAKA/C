#include<bits/stdc++.h>
using namespace std;

void pages(int n,int page[],int frames){
	unordered_set<int>s;
	queue<int>q;
	int pageFaults=0;
	int pageHits=0;
	for(int i=0;i<n;i++){
		if(s.size() < frames){
			if(s.find(page[i]) == s.end()){
				s.insert(page[i]);
				pageFaults++;
				q.push(page[i]);
			}
		}
		else{
			if(s.find(page[i]) == s.end()){
				int val = q.front();
				q.pop();
				s.erase(val);
				q.push(page[i]);
				s.insert(page[i]);
				pageFaults++;
			}
			else{
				pageHits++;
			}
		}
	}
	float HitRatio=float(pageHits)/n;
	cout<<"Total Page Faults are : "<<pageFaults<<endl;
	cout<<"Total Page Hits are : "<<pageHits<<endl;
	cout<<"Total Hit Ratio : "<<fixed << setprecision(2)<<HitRatio<<endl;
}


int main(){
	int n;
	cout<<"Enter no of pages : ";
	cin>>n;
	int page[n];
	cout<<"Enter page numbers : ";
	for(int i=0;i<n;i++){
		cin>>page[i];
	}
	cout<<"Enter no of frames : ";
	int frames;
	cin>>frames;
	pages(n,page,frames);
	return 0;
}
