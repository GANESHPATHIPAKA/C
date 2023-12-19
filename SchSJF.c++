#include<iostream>
#include<algorithm>
using namespace std;

int min_at(int v[], int at[], int n) {
    int i, min = 999, min_i;
    for (i = 1; i <= n; i++) {
        if (v[i] != 1 && min > at[i]) {
            min = at[i];
            min_i = i;
        }
    }
    return min_i;
}

void sort1(int p[], int at[], int bt[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (bt[i] > bt[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int min_bt(int bt[], int at[], int t, int n, int v[]) {
    int i;
    for (i = 1; i <= n; i++) {
        if (v[i] != 1 && at[i] <= t) {
            return i;
        }
    }
    return 0;
}

void chart(int p[], int at[], int bt[], int n) {
    int k = 0, t = 0, x, c = 0, v[20], i;
    int ct[20], tat[20], wt[20], rt[20];
    for (i = 1; i <= n; i++) {
        v[i] = 0;
    }
    x = min_at(v, at, n);
    if (at[x] != 0) {
        cout << "| idle";
        t = at[x];
    }
    else {
        cout << "| p" << p[x];
        t = at[x] + bt[x];
        v[x] = 1;
        c++;
        ct[x] = t;
        tat[x] = ct[x] - at[x];
        wt[x] = tat[x] - bt[x];
        rt[x] = wt[x]; // Response time is the same as waiting time
    }
    while (c < n) {
        x = min_bt(bt, at, t, n, v);
        if (x == 0) {
            x = min_at(v, at, n);
            cout << "| idle";
            t = at[x];
        }
        else {
            cout << "| p" << p[x];
            t = t + bt[x];
            v[x] = 1;
            c++;
            ct[x] = t;
            tat[x] = ct[x] - at[x];
            wt[x] = tat[x] - bt[x];
            rt[x] = wt[x]; // Response time is the same as waiting time
        }
    }
    cout << endl;
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    cout << "-----------------------------------------------\n";
    for (i = 1; i <= n; i++) {
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << rt[i] << "\n";
    }
    float sum = 0, sum1 = 0;
    for (i = 1; i <= n; i++) {
        sum = sum + tat[i];
        sum1 = sum1 + wt[i];
    }
    cout << "\n";
    cout << "Avg TAT:" << sum / n << "\n";
    cout << "Avg WT:" << sum1 / n << "\n";
}

int main() {
    int p[20], at[20], bt[20], n, i;
    cout << "enter no. of processes\n";
    cin >> n;
    cout << "enter arrival times and burst times\n";
    for (i = 1; i <= n; i++) {
        p[i] = i;
        cin >> at[i] >> bt[i];
    }
    sort1(p, at, bt, n);
    chart(p, at, bt, n);
    return 0;
}

/*
enter no. of processes
5
enter arrival times and burst times
2 1
1 5
4 1
0 6
2 3
| p4| p1| p3| p5| p2

P	AT	BT	CT	TAT	WT	RT
-----------------------------------------------
1	2	1	7	5	4	4
3	4	1	8	4	3	3
5	2	3	11	9	6	6
2	1	5	16	15	10	10
4	0	6	6	6	0	0

Avg TAT:7.8
Avg WT:4.6

*/

