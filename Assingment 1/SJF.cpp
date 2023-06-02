#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int id;            // Process ID
    int arrival;       // Arrival time
    int burst;         // Burst time
    int remainingTime; // Remaining burst time
};

void sjfScheduling(Process processes[], int n)
{
    int completionTime[n]; // Array to store completion times
    int turnaroundTime[n]; // Array to store turnaround times
    int waitingTime[n];    // Array to store waiting times

    // Set the remaining time of each process as its burst time
    for (int i = 0; i < n; i++)
    {
        processes[i].remainingTime = processes[i].burst;
    }

    int currentTime = 0; // Current time
    int completed = 0;   // Number of completed processes

    while (completed < n)
    {
        int shortestIndex = -1; // Index of the process with the shortest burst time

        // Find the process with the shortest burst time among the arrived processes
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival <= currentTime && processes[i].remainingTime > 0)
            {
                if (shortestIndex == -1 || processes[i].remainingTime < processes[shortestIndex].remainingTime)
                {
                    shortestIndex = i;
                }
            }
        }

        if (shortestIndex == -1)
        {
            currentTime++; // No process is available, increment the current time
        }
        else
        {
            // Execute the process with the shortest burst time for 1 unit
            processes[shortestIndex].remainingTime--;
            currentTime++;

            // If the process has completed its execution
            if (processes[shortestIndex].remainingTime == 0)
            {
                completionTime[shortestIndex] = currentTime;                                                      // Set its completion time
                turnaroundTime[shortestIndex] = completionTime[shortestIndex] - processes[shortestIndex].arrival; // Calculate its turnaround time
                waitingTime[shortestIndex] = turnaroundTime[shortestIndex] - processes[shortestIndex].burst;      // Calculate its waiting time
                completed++;                                                                                      // Increment the number of completed processes
            }
        }
    }

    // Display the process details and times
    cout << "Process\tArrivalTime\tBurstTime\tCompletionTime\tTurnaroundTime\tWaitingTime\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << processes[i].id << "\t\t" << processes[i].arrival << "\t"
             << processes[i].burst << "\t\t" << completionTime[i] << "\t\t"
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

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    // Input process details
    cout << "\nEnter process details:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Process " << processes[i].id << " Arrival time: ";
        cin >> processes[i].arrival;
        cout << "Process " << processes[i].id << " Burst time: ";
        cin >> processes[i].burst;
    }

    // Sort the processes based on arrival time
    sort(processes, processes + n, [](const Process &a, const Process &b)
         { return a.arrival < b.arrival; });

    // Call the SJF scheduling function
    sjfScheduling(processes, n);

    return 0;
}
