#include <iostream>
#include <vector>
#include <climits>

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
    int priority;
};

void complete(struct job a[], int n, vector<pair<int, int>>& ganttChart) {
    int currentTime = 0;
    int process = 0;
    int shortestPriorityIndex = 0;
    int shortestPriority = INT_MAX;
    int finishTime;
    bool check = false;

    while (process != n) {
        shortestPriority = INT_MAX; // Reset the shortestPriority for each iteration

        for (int i = 0; i < n; i++) {
            if (a[i].dbt > 0 && a[i].priority < shortestPriority && a[i].at <= currentTime) {
                shortestPriorityIndex = i;
                shortestPriority = a[i].priority;
                check = true;
            }
        }

        if (check == false) {
            currentTime++;
            continue;
        } else {
            if (a[shortestPriorityIndex].ft == -1) {
                a[shortestPriorityIndex].ft = currentTime;
            }
        }

        ganttChart.push_back({a[shortestPriorityIndex].pt, currentTime});

        a[shortestPriorityIndex].dbt--;

        if (a[shortestPriorityIndex].dbt == 0) {
            process++;
            check = false;
            finishTime = currentTime + 1;

            a[shortestPriorityIndex].ct = finishTime;
            a[shortestPriorityIndex].wt = finishTime - a[shortestPriorityIndex].bt - a[shortestPriorityIndex].at;
            a[shortestPriorityIndex].tat = a[shortestPriorityIndex].bt + a[shortestPriorityIndex].wt;
            a[shortestPriorityIndex].rt = a[shortestPriorityIndex].ft - a[shortestPriorityIndex].at;
            if (a[shortestPriorityIndex].wt < 0) {
                a[shortestPriorityIndex].wt = 0;
            }
        }
        currentTime++;
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
    cout << "Enter n: ";
    cin >> n;
    job a[n];
    cout << "Enter Arrival Time:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].at;
        a[i].pt = i + 1;
        a[i].ft = -1;
    }
    cout << "Enter Burst Time:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].bt;
        a[i].dbt = a[i].bt;
    }
    cout << "Enter Priority:\n";
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
Enter n: 7
Enter Arrival Time:
0 1 3 4 5 6 10
Enter Burst Time:
8 2 4 1 6 5 1
Enter Priority:
3 4 4 5 2 6 1
P.T	 PR.T	 A.T	 B.T	 C.T	 T.A.T	 W.T	 R.T 
1 	 3	0 	 8 	 15 	 15 	 7 	 0
2 	 4	1 	 2 	 17 	 16 	 14 	 14
3 	 4	3 	 4 	 21 	 18 	 14 	 14
4 	 5	4 	 1 	 22 	 18 	 17 	 17
5 	 2	5 	 6 	 12 	 7 	 1 	 0
6 	 6	6 	 5 	 27 	 21 	 16 	 16
7 	 1	10 	 1 	 11 	 1 	 0 	 0
Average Waiting Time : 9.85714
Average TurnAround Time : 13.7143

Gantt Chart:
| P1 | P1 | P1 | P1 | P1 | P5 | P5 | P5 | P5 | P5 | P7 | P5 | P1 | P1 | P1 | P2 | P2 | P3 | P3 | P3 | P3 | P4 | P6 | P6 | P6 | P6 | P6 |

*/

