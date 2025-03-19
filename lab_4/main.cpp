#include "double_queue.h"

using namespace std;

int main() {
    DoubleQueue q;
    DoubleQueue k;
    q.push_back(1);
    q.push_back(2);
    q.push_front(0);
    cout << q << endl;
    return 0;
}
