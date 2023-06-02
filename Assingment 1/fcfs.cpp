#include <iostream>
using namespace std;

struct Process {
    int id;      // Process ID
    int arrival; // Arrival time
    int burst;   // Burst time
};

void fcfsScheduling(Process processes[], int n) {
    
    int completionTime[n]; // Array to store completion times
    int turnaroundTime[n]; // Array to store turnaround times
    int waitingTime[n];    // Array to store waiting times

    // Calculate completion time of each process
    //This process finds the completiontime of the first process and rest acts acoording to it 

    completionTime[0] = processes[0].arrival + processes[0].burst;
    
    for (int i = 1; i < n; i++) 
    
    {
        completionTime[i] = max(completionTime[i - 1], processes[i].arrival) + processes[i].burst;
    }

    // Calculate turnaround time and waiting time of each process
    for (int i = 0; i < n; i++) 
    
    {
        turnaroundTime[i] = completionTime[i] - processes[i].arrival;
        waitingTime[i] = turnaroundTime[i] - processes[i].burst;
    }

    // Display the process details and times
    cout << "Process\tArrivalTime\tBurstTime\tCompletionTime\tTurnaroundTime\tWaitingTime\n";
    for (int i = 0; i < n; i++) 
    
    {
        cout << "P"<< processes[i].id << "\t" << processes[i].arrival << "\t"
             << processes[i].burst << "\t" << completionTime[i] << "\t\t"
             << turnaroundTime[i] << "\t\t" << waitingTime[i] << endl;
    }

    // Calculate average turnaround time and waiting time
    double avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++) 
    {
        avgTurnaroundTime += turnaroundTime[i];
        avgWaitingTime += waitingTime[i];
    }
    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    // Input process details
    cout << "\nEnter process details:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Process " << processes[i].id << " Arrival time: ";
        cin >> processes[i].arrival;
        cout << "Process " << processes[i].id << " Burst time: ";
        cin >> processes[i].burst;
    }

    // Call the FCFS scheduling function
    fcfsScheduling(processes, n);

    return 0;
}
