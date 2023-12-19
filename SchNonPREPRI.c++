#include <bits/stdc++.h>
using namespace std;

struct job {
    int pt;
    int at;
    int bt;
    int ct;
    int rt;
    int wt;
    int tat;
    int cmp;
    int priority;
};

int checkZero(struct job a[], int n, int currentTime) {
    int shortestPriority = INT_MAX;
    int shortestPriorityIndex = -1;
    int arrivalCheck = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!a[i].cmp && a[i].priority <= shortestPriority && a[i].at <= currentTime) {
            if (a[i].priority == shortestPriority) {
                if (arrivalCheck > a[i].at) {
                    arrivalCheck = a[i].at;
                    shortestPriority = a[i].priority;
                    shortestPriorityIndex = i;
                } else {
                    continue;
                }
            } else {
                arrivalCheck = a[i].at;
                shortestPriority = a[i].priority;
                shortestPriorityIndex = i;
            }
        }
    }
    return shortestPriorityIndex;
}

int check(struct job a[], int n) {
    int shortestPriority = INT_MAX;
    int shortestPriorityIndex = -1;
    int arrivalCheck = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!a[i].cmp && a[i].priority <= shortestPriority) {
            if (a[i].priority == shortestPriority) {
                if (arrivalCheck > a[i].at) {
                    arrivalCheck = a[i].at;
                    shortestPriority = a[i].priority;
                    shortestPriorityIndex = i;
                } else {
                    continue;
                }
            } else {
                arrivalCheck = a[i].at;
                shortestPriority = a[i].priority;
                shortestPriorityIndex = i;
            }
        }
    }
    return shortestPriorityIndex;
}

void complete(struct job a[], int n, vector<pair<int, int>>& ganttChart) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        int shortestPriorityIndex = checkZero(a, n, currentTime);
        if (shortestPriorityIndex == -1) {
            shortestPriorityIndex = check(a, n);
            if (currentTime <= a[shortestPriorityIndex].at) {
                currentTime = a[shortestPriorityIndex].at;
            }
        }

        ganttChart.push_back({a[shortestPriorityIndex].pt, currentTime});

        a[shortestPriorityIndex].ct = currentTime + a[shortestPriorityIndex].bt;
        a[shortestPriorityIndex].tat = a[shortestPriorityIndex].ct - a[shortestPriorityIndex].at;
        a[shortestPriorityIndex].wt = a[shortestPriorityIndex].tat - a[shortestPriorityIndex].bt;
        a[shortestPriorityIndex].rt = currentTime;
        a[shortestPriorityIndex].cmp = true;
        currentTime = a[shortestPriorityIndex].ct;
    }
}

void print(struct job a[], int n) {
    cout << "P.T\t PR.T\t A.T\t B.T\t C.T\t T.A.T\t W.T\t R.T \n";
    for (int i = 0; i < n; i++) {
        cout << a[i].pt << " \t " << a[i].priority << "\t" << a[i].at << " \t " << a[i].bt << " \t " << a[i].ct << " \t "
             << a[i].tat << " \t " << a[i].wt << " \t " << a[i].rt << "\n";
    }
}

void avg(struct job a[], int n) {
    int wtSum = 0;
    int tatSum = 0;
    for (int i = 0; i < n; i++) {
        wtSum += a[i].wt;
        tatSum += a[i].tat;
    }
    float wtAvg = (float)wtSum / n;
    float tatAvg = (float)tatSum / n;
    cout << "Average Waiting Time : " << wtAvg << "\n";
    cout << "Average TurnAround Time : " << tatAvg << "\n";
}

void printGanttChart(const vector<pair<int, int>>& ganttChart) {
    cout << "\nGantt Chart:\n";
    for (const auto& entry : ganttChart) {
        cout << "| P" << entry.first << " ";
    }
    cout << "|\n";
}

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;
    job a[n];
    cout << "Enter Arrival Time : \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].at;
        a[i].pt = i + 1;
        a[i].cmp = false;
    }
    cout << "Enter Burst Time : \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].bt;
    }
    cout << "Enter Priority : \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].priority;
    }

    vector<pair<int, int>> ganttChart;
    complete(a, n, ganttChart);
    print(a, n);
    avg(a, n);
    printGanttChart(ganttChart);
    return 0;
}


/*
Enter n : 7
Enter Arrival Time : 
0 1 3 4 5 6 10
Enter Burst Time : 
8 2 4 1 6 5 1
Enter Priority : 
3 4 4 5 2 6 1
P.T	 PR.T	 A.T	 B.T	 C.T	 T.A.T	 W.T	 R.T 
1 	 3	0 	 8 	 8 	 8 	 0 	 0
2 	 4	1 	 2 	 17 	 16 	 14 	 15
3 	 4	3 	 4 	 21 	 18 	 14 	 17
4 	 5	4 	 1 	 22 	 18 	 17 	 21
5 	 2	5 	 6 	 14 	 9 	 3 	 8
6 	 6	6 	 5 	 27 	 21 	 16 	 22
7 	 1	10 	 1 	 15 	 5 	 4 	 14
Average Waiting Time : 9.71429
Average TurnAround Time : 13.5714

Gantt Chart:
| P1 | P5 | P7 | P2 | P3 | P4 | P6 |

*/
