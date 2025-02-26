# Java 多线程

## BlockingQueue

或许是为了让用户严格遵循CSP模型（或许只是因为懒），Go自身没有线程安全的数据结构，但是Go的chan实际上就相当于一个线程安全的BlockingQueue（实际上还是有些区别）。我们一般写并发的程序就直接加很多锁，其实这种思维方式不是很到位，因为锁不是那么好加的，粒度大了效率低，粒度小了出问题。所以针对并发编程，大牛们就抽象出了一个模型叫CSP（Communicating Sequential Processes），让我们这些智力不如他们的人借助这个模型来安排自己的程序结构，不加锁也可以很好地解决并发问题（不加锁怎么可能只是锁加在了chan或者说BlockingQueue里）。Go借助chan就可以很好地支持这种模型。

当然这说得有点远了，就是让你们知道这个东西其实挺重要的（但是重要的是它的抽象而不是实现）。

只需要实现 BlockingQueue 的以下接口：

1. offer
2. poll

### 代码

- [实现一个 Java 的 BlockingQueue](https://github.com/xiyou-linuxer/Queue4j/tree/main/BlockingQueue)
    - [BlockingQueue1](https://github.com/xiyou-linuxer/Queue4j/tree/main/BlockingQueue/src/main/java/com/xiyoulinux/blockingqueue/BlockingQueue1.java)中定义了需要实现的方法和类。
    - [TestBlockingQueue1](https://github.com/xiyou-linuxer/Queue4j/tree/main/BlockingQueue/src/test/java/com/xiyoulinux/blockingqueue/TestBlockingQueue1.java)中有相应的使用和测试。

具体可参考 [link](https://docs.oracle.com/javase/8/docs/api/java/util/concurrent/BlockingQueue.html) 里的接口文档。

## 线程池

借助Google查找以下问题写一篇博客，并完成线程池。

### 什么是线程池？

> [!WARNING]
>
> 待完善。

### 为什么要有线程池？你还见过什么池？

> [!WARNING]
>
> 待完善。

### 怎样做一个简单的线程池？

> [!WARNING]
>
> 文本和代码待完善。

要求实现以下接口：

```java
ThreadPool(int corePoolSize, int maxPoolSize, int timeout);
public void execute(Runnable task);
public BlockingQueue shutdown();
```

内部保存任务的数据结构必须用第一个实现的 BlockingQueue。

### 延伸

借助线程池有兴趣的同学可以写个计时器玩玩，看似简单的东西要做好的话其实难度也蛮大的。（不做要求）
