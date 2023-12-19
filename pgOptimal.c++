#include <bits/stdc++.h>
using namespace std;

void optimalPage(int pg[], int pn, int fn)
{
	int fr[fn];
	for(int i=0;i<fn;i++){
		fr[i]=-1;
	}

	int hit = 0;
	for (int i = 0; i < pn; i++) {
		bool found = false;
		for (int j = 0; j < fn; j++) {
			if (fr[j] == pg[i]) {
				hit++;
				found = true;
				break;
			}
		}

		if (found)
			continue;

		bool emptyFrame = false;
		for (int j = 0; j < fn; j++) {
			if (fr[j] == -1) {
				fr[j] = pg[i];
				emptyFrame = true;
				break;
			}
		}

		if (emptyFrame)
			continue;

		int farthest = -1, replaceIndex = -1;
		for (int j = 0; j < fn; j++) {
			int k;
			for (k = i + 1; k < pn; k++) {
				if (fr[j] == pg[k]) {
					if (k > farthest) {
						farthest = k;
						replaceIndex = j;
					}
					break;
				}
			}
			if (k == pn) {
				replaceIndex = j;
				break;
			}
		}
		fr[replaceIndex] = pg[i];
	}
	float HitRatio=float(hit)/pn;
	cout << "Total Page Hits are : " << hit << endl;
	cout << "Total Page Faults are : " << pn - hit << endl;
	cout<<"Total Hit Ratio : "<<fixed << setprecision(2)<<HitRatio<<endl;
}

int main() {
	int pn;
	cout<<"Enter no of pages : ";
	cin>>pn;
	int pg[pn];
	cout<<"Enter page numbers : ";
	for(int i=0;i<pn;i++){
		cin>>pg[i];
	}
	cout<<"Enter no of frames : ";
	int fn;
	cin>>fn;
	optimalPage(pg,pn,fn);
	return 0;
}

/*
Enter no of pages : 13
Enter page numbers : 7 0 1 2 0 3 0 4 2 3 0 3 2
Enter no of frames : 4
Total Page Hits are : 7
Total Page Faults are : 6
Total Hit Ratio : 0.54

*/

