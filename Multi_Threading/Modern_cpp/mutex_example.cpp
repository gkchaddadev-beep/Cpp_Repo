#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


mutex mx;
int number = 0;
void increment()
{
    mx.lock();
    for(int i=0;i<1000000;i++)
    {
        number++;
    }
    mx.unlock();
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    
    t1.join();
    t2.join();
    
    cout<<number;
    return 0;
	
}
