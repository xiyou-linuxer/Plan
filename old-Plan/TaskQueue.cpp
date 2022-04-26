#include <memory>


// Single-producer , single-consumer Queue
template<class T>
class SPSCQueue {
public:
    explicit SPSCQueue();
    virtual bool Push(std::unique_ptr<T>) = 0;
    virtual std::unique_ptr<T> pop() = 0;
    virtual ~SPSCQueue() = 0;
};

//Multi-producer , Multi-consumer Queue
template<class T>
class MPMCQueue {
public:
    explicit MPMCQueue(int threadNumber);
    virtual bool Push(std::unique_ptr<T>) = 0;
    virtual std::unique_ptr<T> pop() = 0;
    virtual ~MPMCQueue() = 0;
};
