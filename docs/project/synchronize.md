### 生产者消费者问题
「并发环境下的经典模型」

生产者消费者共享缓冲区，生产者向缓冲区中放数据，消费者从缓冲取中取数据，当缓冲区中被放满时，生产者线程就必须进入挂起状态，直到消费者从缓冲中取走数据时，生产者才能继续向缓冲区中存放数据，同样当缓冲取中没有数据时，消费者线程就必须进入挂起休眠状态，直到生产者向缓冲区中放入数据时，消费者才能被唤醒继续从缓冲区中取走数据。

生产者消费者问题，也称有限缓冲问题，是一个多线程同步问题的经典案例。

1. 单生产者单消费者队列（Single-producer , single-consumer Queue）
2. 多生产者多消费者队列（Multi-producer , Multi-consumer Queue）

- [C API](https://github.com/xiyou-linuxer/Plan/tree/main/code/TaskQueue.c)
- [C++ API](https://github.com/xiyou-linuxer/Plan/tree/main/code/TaskQueue.cpp)
- [java interface ](./java/multi-threading.md)

### 哲学家问题

有五个哲学家绕着圆桌坐，每个哲学家面前有一盘面，两人之间有一支筷子，这样每个哲学家左右各有一支筷子。哲学家有2个状态，思考或者拿起筷子吃饭。如果哲学家拿到一只筷子，不能吃饭，直到拿到2只才能吃饭，并且一次只能拿起身边的一支筷子。一旦拿起便不会放下筷子直到把饭吃完，此时才把这双筷子放回原处。如果，很不幸地，每个哲学家拿起他或她左边的筷子，那么就没有人可以吃到饭了。

哲学家进餐问题是一个多线程运用的经典例子，涉及到线程同步/互斥，临界区访问问题以及死锁问题。

至少采用2~3种解决方案。

### TASK

[LockTest](https://github.com/xiyou-linuxer/LockTest)