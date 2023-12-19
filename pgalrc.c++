#include<bits/stdc++.h>
using namespace std;

void pages(int n,int page[],int frames){
	unordered_set<int>s;
	unordered_map<int,int>m;
	int pageFaults=0;
	int pageHits=0;
	for(int i=0;i<n;i++){
		if(s.size() < frames){
			if(s.find(page[i]) == s.end()){
				s.insert(page[i]);
				pageFaults++;
			}
				m[page[i]]=i;
		}
		else{
			if(s.find(page[i]) == s.end()){
				int lrc=INT_MAX,val;
				for(auto it=s.begin();it!=s.end();it++){
					if(m[*it] < lrc){
						lrc=m[*it];
						val=*it;
					}
				}
				s.erase(val);
				s.insert(page[i]);
				pageFaults++;
			}
			else{
				pageHits++;
			}
			m[page[i]]=i;
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
