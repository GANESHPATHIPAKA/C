#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int burstTimeRemaining;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    bool isComplete;
    bool inQueue;
};

void checkForNewArrivals(Process processes[], const int n, const int currentTime, queue<int> &readyQueue)
{
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrivalTime <= currentTime && !processes[i].inQueue && !processes[i].isComplete)
        {
            processes[i].inQueue = true;
            readyQueue.push(i);
        }
    }
}

void updateQueue(Process processes[], const int n, const int quantum, queue<int> &readyQueue, int &currentTime, int &programsExecuted, vector<pair<int, int>> &ganttChart)
{
    int i = readyQueue.front();
    readyQueue.pop();

    if (processes[i].burstTimeRemaining <= quantum)
    {
        processes[i].isComplete = true;
        currentTime += processes[i].burstTimeRemaining;
        processes[i].completionTime = currentTime;
        processes[i].waitingTime = max(0, processes[i].completionTime - processes[i].arrivalTime - processes[i].burstTime);
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

        processes[i].burstTimeRemaining = 0;
        ganttChart.push_back({currentTime - processes[i].burstTimeRemaining, processes[i].pid});
        
        if (programsExecuted != n)
        {
            checkForNewArrivals(processes, n, currentTime, readyQueue);
        }
    }
    else
    {
        processes[i].burstTimeRemaining -= quantum;
        currentTime += quantum;

        ganttChart.push_back({currentTime - quantum, processes[i].pid});

        if (programsExecuted != n)
        {
            checkForNewArrivals(processes, n, currentTime, readyQueue);
        }
        readyQueue.push(i);
    }
}

void printTitle(const string &title)
{
    cout << title << endl;
}

void outputTableHeader()
{
    cout << "Pid\tAT\tBT\tCT\tTAT\tWT" << endl;
}

void outputProcess(const Process &p)
{
    cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
         << p.completionTime << "\t" << p.turnaroundTime << "\t" << p.waitingTime << endl;
}

void printAverages(const double avgWaitingTime, const double avgTurnaroundTime)
{
    cout << "Average Waiting time=" << avgWaitingTime << endl;
    cout << "Average Turn Around Time=" << avgTurnaroundTime << endl;
}

void printGanttChart(const vector<pair<int, int>> &ganttChart)
{
    cout << "Gantt Chart: ";
    for (const auto &entry : ganttChart)
    {
        cout << "P" << entry.second << " ";
    }
    cout << endl;
}

void roundRobin(Process processes[], int n, int quantum)
{
    queue<int> readyQueue;
    readyQueue.push(0);
    processes[0].inQueue = true;

    int currentTime = 0;
    int programsExecuted = 0;
    vector<pair<int, int>> ganttChart;

    while (!readyQueue.empty())
    {
        updateQueue(processes, n, quantum, readyQueue, currentTime, programsExecuted, ganttChart);
    }

    printGanttChart(ganttChart);
}

int main()
{
    int n, quantum;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> quantum;

    Process processes[n + 1];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time and burst time for P" << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].burstTimeRemaining = processes[i].burstTime;
        processes[i].pid = i + 1;
    }

    sort(processes, processes + n, [](const Process &p1, const Process &p2)
         { return p1.arrivalTime < p2.arrivalTime; });

    roundRobin(processes, n, quantum);

    printTitle("Process Execution Order");
    for (int i = 0; i < n; i++)
    {
        cout << "P" << processes[i].pid << " ";
    }
    cout << endl;

    outputTableHeader();
    for (int i = 0; i < n; i++)
    {
        outputProcess(processes[i]);
    }

    double avgWaitingTime = 0;
    double avgTurnaroundTime = 0;

    for (int i = 0; i < n; i++)
    {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printAverages(avgWaitingTime, avgTurnaroundTime);

    return 0;
}

