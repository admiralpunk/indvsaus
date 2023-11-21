#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Structure to represent memory partitions
struct MemoryPartition {
    int id;
    int size;
    bool allocated;
};
// next time it starts from where it left time
// Function to perform next fit memory allocation
void nextFit(vector<MemoryPartition>& partitions, int processId, int processSize, int& lastAllocatedIdx) {
    for (int i = 0; i < partitions.size(); i++) {
        int currentIdx = (i + lastAllocatedIdx) % partitions.size();
        if (!partitions[currentIdx].allocated && partitions[currentIdx].size >= processSize) {
            partitions[currentIdx].allocated = true;
            lastAllocatedIdx = currentIdx;
            cout << "Process " << processId << " allocated to Partition " << partitions[currentIdx].id << endl;
            return;
        }
    }
    cout << "Process " << processId << " cannot be allocated." << endl;
}

int main() {
    int numPartitions, numProcesses;
    cout << "Enter the number of memory partitions: ";
    cin >> numPartitions;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<MemoryPartition> partitions(numPartitions);
    int lastAllocatedIdx = 0; // Initialize with the first partition.

    // Initialize memory partitions
    for (int i = 0; i < numPartitions; i++) {
        partitions[i].id = i + 1;
        cout << "Enter size of Partition " << partitions[i].id << ": ";
        cin >> partitions[i].size;
        partitions[i].allocated = false;
    }

    // Process allocation
    for (int i = 0; i < numProcesses; i++) {
        int processSize;
        cout << "Enter size of Process " << i + 1 << ": ";
        cin >> processSize;
        nextFit(partitions, i + 1, processSize, lastAllocatedIdx);
    }

    return 0;
}
