# 线程同步

## 生产者消费者问题

「并发环境下的经典模型」

生产者消费者共享缓冲区，生产者向缓冲区中放数据，消费者从缓冲区取数据，当缓冲区被放满时，生产者线程就必须进入挂起状态，直到消费者从缓冲中取走数据时，生产者才能继续向缓冲区中存放数据。同样，当缓冲区中没有数据时，消费者线程就必须进入挂起休眠状态，直到生产者向缓冲区中放入数据时，消费者才能被唤醒继续从缓冲区中取走数据。

生产者消费者问题，也称为有限缓冲问题，是一个多线程同步问题的经典案例。

1. 单生产者单消费者队列（Single-producer, single-consumer Queue）
2. 多生产者多消费者队列（Multi-producer, multi-consumer Queue）

- [C API](https://github.com/xiyou-linuxer/Plan/tree/main/code/TaskQueue.c)
- [C++ API](https://github.com/xiyou-linuxer/Plan/tree/main/code/TaskQueue.cpp)
- [Java interface](./java/multi-threading.md){ .md-button }

## 哲学家问题

有五个哲学家围坐在圆桌旁，每个哲学家面前都有一盘食物，两个相邻的哲学家之间有一支筷子，因此每个哲学家左右各有一支筷子。哲学家有两种状态，思考或拿起筷子就餐。如果哲学家只拿到一支筷子，他就无法就餐，只有同时拿到两支筷子才能进餐，并且每次只能拿起自己身边的一支筷子。一旦哲学家拿起筷子，就会一直保持拿筷子的状态，直到将食物吃完，然后才会将筷子放回原处。如果不幸的是，每个哲学家都只拿起自己左边的筷子，那么就没有人能吃到食物。

哲学家进餐问题是一个经典的多线程应用示例，涉及线程同步/互斥、临界区访问问题以及死锁问题。

至少使用 2~3 种解决方案来解决该问题。

## TASK

[LockTest](https://github.com/xiyou-linuxer/LockTest)