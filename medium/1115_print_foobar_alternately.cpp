#include <mutex>
#include<condition_variable>
#include <functional>

using namespace std;

class FooBar {
private:
    mutex m;
    condition_variable cv;
    bool readyFoo = false;;
    bool readyBar = false;
    int n;

public:
    FooBar(int n) {
        this->n = n;
        readyFoo = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            cv.wait(lk,[&]{ return readyFoo;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            readyFoo = false;
            readyBar = true;
            lk.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            cv.wait(lk,[&]{return readyBar;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            readyBar = false;
            readyFoo = true;
            lk.unlock();
            cv.notify_one();
        }
    }
};


int main()
{
    return 0;
}