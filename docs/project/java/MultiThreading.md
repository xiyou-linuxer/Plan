1.   BlockingQueue

     或许是为了让用户严格的遵循CSP模型（或许只是因为懒），Go自身没有线程安全的数据结构，但是Go的chan实际上就相当于一个线程安全的BlockingQueue（实际上还是有些区别），我们一般写并发的程序就直接加很多锁，其实这种思维方式不是很到位，因为锁不是那么好加的，粒度大了效率低，粒度小了出问题。所以针对并发编程，大牛们就抽象出了一个模型叫CSP（Communicating Seyuential Process），让我们的这些智力不如他们的人，借助这个模型来安排自己的程序结构不加锁都可以很好的解决并发问题（不加锁怎么可能只是锁加在了chan或者说BlockingQueue里）。Go借助chan就可以很好的支持这种模型。

     当然这就说的有点远了，就是让你们知道这个东西其实蛮重要（但是重要的是他的抽象不是实现）

     只需要实现BlockingQueue的以下接口

     1.   offer
     2.   poll
     - [实现一个 Java 的 BlockingQueue](https://github.com/xiyou-linuxer/Plan/tree/main/code/BlockingQueue.md)

     [BlockingQueue1](https://github.com/xiyou-linuxer/Plan/tree/main/code/BlockingQueue/src/main/java/com/xiyoulinux/blockingqueue/BlockingQueue1.java)中定义了需要实现的方法和类

     [TestBlockingQueue1](https://github.com/xiyou-linuxer/Plan/tree/main/code/BlockingQueue/src/test/java/com/xiyoulinux/blockingqueue/TestBlockingQueue1.java)中有相应的使用和测试

  具体可参照 [link](https://docs.oracle.com/javase/8/docs/api/java/util/concurrent/BlockingQueue.html)里的接口文档

2.   线程池

     借助Google查找以下问题写一篇博客,并完成线程池

     1.   什么是线程池

          xxxxxxx

     2.   为什么要有线程池，你还见过什么池？

          xxxxxxx

     3.   怎样做一个简单的线程池

          xxxxxx

          /code/

          要求实现一下接口

          1.   ThreadPool(int corePoolSize,int maxPoolSize，int timeout)
          2.   public void execute(Runnable task)
          3.   public BlockingQueue shutdown()

          内部保存任务的数据结构必须用第一个实现的BlockingQueue

2.   借助线程池有兴趣的同学可以写个计时器玩玩，看似简单的东西要做好的话其实难度也蛮大的。（不做要求）
