#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MemoryPartition {
    int id;
    int size;
    bool allocated;
};

void worstFit(vector<MemoryPartition>& partitions, int processId, int processSize) {
    int worstFitIdx = -1;
    int maxSize = -1;

    for (int i = 0; i < partitions.size(); i++) {
        if (!partitions[i].allocated && partitions[i].size >= processSize && partitions[i].size > maxSize) {
            worstFitIdx = i;
            maxSize = partitions[i].size;
        }
    }

    if (worstFitIdx != -1) {
        partitions[worstFitIdx].allocated = true;
        cout << "Process " << processId << " allocated to Partition " << partitions[worstFitIdx].id << endl;
    } else {
        cout << "Process " << processId << " cannot be allocated." << endl;
    }
}

int main() {
    int numPartitions, numProcesses;
    cout << "Enter the number of memory partitions: ";
    cin >> numPartitions;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<MemoryPartition> partitions(numPartitions);

    for (int i = 0; i < numPartitions; i++) {
        partitions[i].id = i + 1;
        cout << "Enter size of Partition " << partitions[i].id << ": ";
        cin >> partitions[i].size;
        partitions[i].allocated = false;
    }

    for (int i = 0; i < numProcesses; i++) {
        int processSize;
        cout << "Enter size of Process " << i + 1 << ": ";
        cin >> processSize;
        worstFit(partitions, i + 1, processSize);
    }

    return 0;
}
