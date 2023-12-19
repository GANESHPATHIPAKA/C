#include<bits/stdc++.h>
using namespace std;

struct job{
    int pt;
    int at;
    int bt;
    int ct;
    int rt;
    int wt;
    int tat;
};

void sort(struct job a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].at > a[j].at) {
                int temp = a[i].at;
                a[i].at = a[j].at;
                a[j].at = temp;
                temp = a[i].bt;
                a[i].bt = a[j].bt;
                a[j].bt = temp;
                temp = a[i].pt;
                a[i].pt = a[j].pt;
                a[j].pt = temp;
            }
        }
    }
}

void complete(struct job a[], int n, vector<pair<int, int>>& ganttChart) {
    int sum = 0;
    sum = sum + a[0].at;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i].bt;
        a[i].ct = sum;
        a[i].tat = a[i].ct - a[i].at;
        a[i].wt = a[i].tat - a[i].bt;
        a[i].rt = a[i].wt;
        if (sum < a[i + 1].at) {
            sum = a[i + 1].at;
        }
        ganttChart.push_back({sum - a[i].bt, a[i].pt});
    }
}

void print(struct job a[], int n) {
    cout << "P.T\t A.T\t B.T\t C.T\t T.A.T\t W.T\t R.T \n";
    for (int i = 0; i < n; i++) {
        cout << a[i].pt << " \t " << a[i].at << " \t " << a[i].bt << " \t " << a[i].ct << " \t " << a[i].tat << " \t " << a[i].wt << " \t " << a[i].rt << "\n";
    }
}

void avg(struct job a[], int n) {
    int wtSum = 0;
    int tatSum = 0;
    for (int i = 0; i < n; i++) {
        wtSum = wtSum + a[i].wt;
        tatSum = tatSum + a[i].tat;
    }
    float wtAvg = (float)wtSum / n;
    float tatAvg = (float)tatSum / n;
    cout << "Average Waiting Time : " << wtAvg << "\n";
    cout << "Average TurnAround Time : " << tatAvg << "\n";
}

void printGanttChart(const vector<pair<int, int>>& ganttChart) {
    cout << "\nGantt Chart:\n";
    for (const auto& entry : ganttChart) {
        cout << "P" << entry.second << " | ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;
    job a[n];
    vector<pair<int, int>> ganttChart;

    cout << "Enter Arrival Time : \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].at;
        a[i].pt = i + 1;
    }

    cout << "Enter Burst Time : \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].bt;
    }

    sort(a, n);
    complete(a, n, ganttChart);
    print(a, n);
    avg(a, n);
    printGanttChart(ganttChart);

    return 0;
}


/*
Enter n : 5
Enter Arrival Time : 
2 0 2 3 4
Enter Burst Time : 
2 1 3 5 4
P.T	 A.T	 B.T	 C.T	 T.A.T	 W.T	 R.T 
2 	 0 	 1 	 1 	 1 	 0 	 0
1 	 2 	 2 	 4 	 2 	 0 	 0
3 	 2 	 3 	 7 	 5 	 2 	 2
4 	 3 	 5 	 12 	 9 	 4 	 4
5 	 4 	 4 	 16 	 12 	 8 	 8
Average Waiting Time : 2.8
Average TurnAround Time : 5.8

Gantt Chart:
P2 | P1 | P3 | P4 | P5 | 
*/
