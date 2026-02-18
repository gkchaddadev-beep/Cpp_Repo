#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

std::mutex mu1, mu2;
int shared_data = 0;

void do_work() {
    // Both mutexes are locked simultaneously in a deadlock-free manner
    std::scoped_lock lock(mu1, mu2); //

    // Critical section protected by both locks
    shared_data++;
    cout<<"\nchild thread : "<<shared_data;
} 

int main() {
    std::thread t1(do_work);
    std::thread t2(do_work);

    t1.join();
    t2.join();
    
    cout<<"\nMain thread : "<<shared_data;

    return 0;
}