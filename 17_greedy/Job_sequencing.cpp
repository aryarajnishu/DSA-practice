#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Job {
    char id;
    int deadline;
    int profit;
};
bool compareJobs(const Job& job1, const Job& job2) {
    return (job1.profit > job2.profit);
}

void jobSequencing(const vector<Job>& jobs) {
    
    vector<Job> sortedJobs = jobs;
    sort(sortedJobs.begin(), sortedJobs.end(), compareJobs);

    int n = jobs.size();
    vector<bool> slot(n, false);
    vector<char> result(n);

    for (int i = 0; i < n; ++i) {
        for (int j = min(n, sortedJobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                result[j] = sortedJobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    // Print the sequence
    cout << "Job Sequence: ";
    for (int i = 0; i < n; ++i) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job details (id, deadline, profit) for each job:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs);

    return 0;
}
