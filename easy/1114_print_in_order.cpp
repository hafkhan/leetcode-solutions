#include <mutex>
#include <condition_variable>
#include <functional>
#include <semaphore>

using namespace std;

// class Foo {
// private:
//     mutex m;
//     mutex m2;
//     condition_variable cv;
//     condition_variable cv2;
//     bool ready2 = false;
//     bool ready3 = false;
// public:
//     Foo() {
        
//     }

//     void first(function<void()> printFirst) {
//         lock_guard lk(m);
//         printFirst();
//         ready2 = true;
//         // printFirst() outputs "first". Do not change or remove this line.
//         cv.notify_one();
//     }

//     void second(function<void()> printSecond) {
//         unique_lock lk(m);
//         cv.wait(lk, [&]{ return ready2;});
//         // printSecond() outputs "second". Do not change or remove this line.
//         lk.unlock();
//         cv.notify_one();
//         lock_guard lk2(m2);
//         printSecond();
        
//         ready3 = true;
//         cv2.notify_one();
//     }

//     void third(function<void()> printThird) {
//         unique_lock lk(m2);
//         cv2.wait(lk, [&]{return ready3;});
        
//         // printThird() outputs "third". Do not change or remove this line.
//         printThird();

//         lk.unlock();

//     }
// };

class Foo {
private:
    std::counting_semaphore<1> s12{0}; // gate from first->second
    std::counting_semaphore<1> s23{0}; // gate from second->third

public:
    void first(std::function<void()> printFirst) {
        printFirst();
        s12.release(); // allow second
    }

    void second(std::function<void()> printSecond) {
        s12.acquire(); // wait for first
        printSecond();
        s23.release(); // allow third
    }

    void third(std::function<void()> printThird) {
        s23.acquire(); // wait for second
        printThird();
    }
};

int main()
{
    return 0;
}