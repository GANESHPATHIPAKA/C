#include<bits/stdc++.h>
using namespace std;

struct job {
    int pt;
    int at;
    int bt;
    int dbt;
    int ct;
    int rt;
    int wt;
    int tat;
    int ft;
};

void complete(struct job a[], int n, vector<pair<int, int>>& ganttChart) {
    int currentTime = 0;
    int process = 0;
    int shortestBurstIndex = 0;
    int shortestBurst = INT_MAX;
    int finishTime;
    bool check = false;

    while (process != n) {

        for (int i = 0; i < n; i++) {
            if (a[i].dbt > 0 && a[i].dbt < shortestBurst && a[i].at <= currentTime) {
                shortestBurstIndex = i;
                shortestBurst = a[i].dbt;
                check = true;
            }
        }
        if (check == false) {
            currentTime++;
            continue;
        }
        else {
            if (a[shortestBurstIndex].ft == -1) {
                a[shortestBurstIndex].ft = currentTime;
            }
        }
        a[shortestBurstIndex].dbt--;

        ganttChart.push_back({currentTime, a[shortestBurstIndex].pt});

        shortestBurst = a[shortestBurstIndex].dbt;
        if (shortestBurst == 0) {
            shortestBurst = INT_MAX;
        }
        if (a[shortestBurstIndex].dbt == 0) {
            process++;
            check = false;
            finishTime = currentTime + 1;

            a[shortestBurstIndex].ct = finishTime;
            a[shortestBurstIndex].tat = a[shortestBurstIndex].ct - a[shortestBurstIndex].at;
            a[shortestBurstIndex].wt = a[shortestBurstIndex].tat - a[shortestBurstIndex].bt;
            a[shortestBurstIndex].rt = a[shortestBurstIndex].ft - a[shortestBurstIndex].at;
        }
        currentTime++;
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
        cout << " P" << entry.second << " | ";
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
        a[i].ft = -1;
    }

    cout << "Enter Burst Time : \n";
    for (int j = 0; j < n; j++) {
        cin >> a[j].bt;
        a[j].dbt = a[j].bt;
    }

    complete(a, n, ganttChart);
    print(a, n);
    avg(a, n);
    printGanttChart(ganttChart);

    return 0;
}

/*
Enter n : 5
Enter Arrival Time : 
2 1 4 0 2
Enter Burst Time : 
1 5 1 6 3
P.T	 A.T	 B.T	 C.T	 T.A.T	 W.T	 R.T 
1 	 2 	 1 	 3 	 1 	 0 	 0
2 	 1 	 5 	 16 	 15 	 10 	 10
3 	 4 	 1 	 5 	 1 	 0 	 0
4 	 0 	 6 	 11 	 11 	 5 	 0
5 	 2 	 3 	 7 	 5 	 2 	 1
Average Waiting Time : 3.4
Average TurnAround Time : 6.6

Gantt Chart:
 P4 |  P4 |  P1 |  P5 |  P3 |  P5 |  P5 |  P4 |  P4 |  P4 |  P4 |  P2 |  P2 |  P2 |  P2 |  P2 |
*/
