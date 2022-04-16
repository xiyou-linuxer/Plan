#include <memory>



template<class T>
class SPSCQueue {
public:
    explicit SPSCQueue(int threadNumber);
    virtual bool Push(std::unique_ptr<T>) = 0;
    virtual std::unique_ptr<T> pop() = 0;
    virtual ~SPSCQueue() = 0;
};


template<class T>
class MPMCQueue {
public:
    explicit MPMCQueue(int threadNumber);
    virtual bool Push(std::unique_ptr<T>) = 0;
    virtual std::unique_ptr<T> pop() = 0;
    virtual ~MPMCQueue() = 0;
};
