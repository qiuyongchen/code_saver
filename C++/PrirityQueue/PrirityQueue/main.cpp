#include <iostream>
#include <string>
#include <queue>
using namespace std;
int max(queue<int> q) {
    priority_queue<int> pq;
    int temp = q.size();
    for (int i = 0; i < temp; i++) {
        pq.push(q.front());
        q.pop();
    }
    return pq.top();
}

int main() {
    int n, num, pos, temp;
    cin >> n;
    while (n--) {
        queue<int> priority, position;
        cin >> num >> pos;
        bool hasPrintJob = false;
        // collect the file that is represented by priority.
        for (int i = 0; i < num; i++) {
            cin >> temp;
            priority.push(temp);

            if (i != pos)
                position.push(0);
            else
                position.push(1);
        }
        // pop until the file we have is poped out.
        while (!hasPrintJob) {
            if (priority.front() == max(priority)) {
                if (position.front() == 1) {
                    hasPrintJob = true;
                } else {
                    priority.pop();
                    position.pop();
                }
            } else {  // loop until the greatest element is at top.
                priority.push(priority.front());
                position.push(position.front());
                priority.pop();
                position.pop();
            }
        }
        cout << (num - priority.size() + 1) << endl;
    }
    return 0;
}
