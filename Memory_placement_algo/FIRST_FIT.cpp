#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct MemoryPartition {
    int id;
    int size;
    bool allocated;
};

void firstFit(vector<MemoryPartition>& partitions, int processId, int processSize) {
    for (int i = 0; i < partitions.size(); i++) {
        if (!partitions[i].allocated && partitions[i].size >= processSize) {
            partitions[i].allocated = true;
            cout << "Process " << processId << " allocated to Partition " << partitions[i].id << endl;
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
        firstFit(partitions, i + 1, processSize);
    }

    return 0;
}
