#include <queue>
#include <mutex>

template<typename T>
class ThreadSafeQueue {
public:
    void Push(T value) {
        std::lock_guard<std::mutex> lock(Mutex);
        Queue.push(value);
    }

    T Pop() {
        std::lock_guard<std::mutex> lock(Mutex);
        auto front = Queue.front();
        Queue.pop();
        return front;
    }

    bool Empty() {
        std::lock_guard<std::mutex> lock(Mutex);
        return Queue.empty();
    }

private:
    std::queue<T> Queue;
    std::mutex Mutex;

};
