# Linux 网络编程

## 前置条件

1. 你以为你不懂多线程多进程文件就敢来碰网络编程？！跑个单线程 epoll 谁不会？连多线程并发控制都不会，客户数据出错了你负责？赶紧 run 去学 [Linux 系统编程](linux-system-programming.md) 吧你。
2. 数据结构和算法不会？不会还有人用链表去存所有用户元数据吧，笑死了，别这写低性能服务器了，打好你的基础：[数据结构和算法](data-structure-algorithm.md)先吧。

## 为什么要学习服务器？

当今所有的 IT 行业都需要使用服务器为大量客户提供服务，往往 web 系程序员可以直接使用 nginx, apache 等开源的服务器，而我们 c 系程序员的目标是了解服务器的底层原理，服务器是如何撑住“百万并发”，多进程，多线程，协程 服务器之间区别是什么， reactor/ proactor 模型是什么？epoll 多路 io 复用是什么。

然而只明白服务器原理是并不够的。当前工业界往往需要服务器提供某种服务：数据存储也好，缓存也好，P2P 通信也好，它们都属于业务层需要实现的内容。小组同学在大一暑假的时候会接触到如何使用 epoll 简单实现一个聊天室，大概也能明白业务层和网络层之间的区别。

## 如何学习服务器?

当前最佳的方案是看书和学习（并参与开发）开源项目。如果是  api 上的问题可以 google 其 man 手册或者去 stackoverflow 寻找相关问题。

### 书籍

1. 《UNIX 网络编程 第一卷》看了这个不能让你上天，很多网络模型现在都已经过时了明白么（注意它还没有讲 epoll）？TCP/UDP 必修，三次握手和四次挥手那些也得了解了解，那一堆 `setsockopt` 的调优不是你能短期内明白的，慢慢看。
2. 《图解网络-小林coding-v2.0.pdf》这种书虽然是那种偏向应付面试官的书，但是用来查缺补漏，学习网络基础，其实也不错。后面还有讲套接字内核参数调优，咱平时可没系统接触。
3. 《linux 高性能服务器编程》了解下基础的 linux 网络框架，了解点 epoll，了解点 c++ 风格的服务器编程。
4. 《Linux多线程服务端编程 使用 muduo C++网络库》陈硕大佬写的精品，之前看了高性能可以让你初步了解服务器，但是这本可以让你把一些服务器编程的精髓搞清楚，人家给你踩的这些多线程网络编程的坑，目前没有更好的一些书可以帮替代。但是 muduo 也已经过时了！这是 2010 年左右的书！github 有 muduo 库的 98,11,17 版，别读死书！

你即使把上面这些都搞明白了，还是会感觉自己对服务器的了解局限在 muduo 教给你的 reactor 模型和回调地狱里面。

少年的征途是星辰大海！

### 开源项目

1. 学习当前流行的开源 web 服务器如 nginx, libuv, libevent，钻研其源码。（boost::asio 会比较难看）
2. 学习当前流行的开源项目是如何使用服务器的，如 redis 的网络层是如何实现的，钻研其源码。


## 自我检验 HOMEWORK

你连 muduo 都不会抄或者你只会抄 muduo? 那和废柴有什么区别？

不会有人认为服务器只能做 web 吧！

给你列了下面这些，自己得学会怎么探索相关资料。老师，学长只能教会你怎么钓鱼，不能帮你钓鱼。

- 包装一种通信协议：
e.g. IRC, HTTPS, RPC, DNS...
- 提高性能的方式：
    1. 实现 web 服务器缓存层 (memcached,redis)
    2. io_uring 异步 io
    3. 查找并消除性能瓶颈
- 提供持久性服务：
    1. 实现 web 服务器存储层 (haystack)
- 实现 web 服务器容错服务...

## 如何 DEBUG
1. gdb （比如该怎么给多线程打断点）
2. valgrind（如何检测内存越界，检测线程竞争）
3. asan（同上）

## 如何构建项目
1. cmake
2. bazel
3. xmake

## 如何进行测试
1. 自己写单元测试 例如 google-test
2. postman（针对 web 服务器）
3. 自己写客户端测
4. ab 压力测试（针对 web 服务器）

## 如何性能优化

1. 使用服务器工具 ab 等 进行性能测试，对比和 nginx 等开源实现之间的差距。
2. 使用性能测试工具 perf, gperftools, ebpf... 分析服务器的热点，也就是你的服务器的性能瓶颈在哪里，是不必要的字符串拷贝还是某个系统调用卡了太久时间或者是不是该考虑禁用 tcp 的 negle 算法？如何做连接数以及请求上的负载均衡？

你还得理解啥是 qps，啥是吞吐量和延迟。

## 如何部署
1. docker

你的服务器只能在本地跑？笑死了，大火的云时代连 docker 都不会？

## 后面还可以干啥

行了，你的服务器总算和屎有点区别了。但客户想让你给它存 TB 级别数据，你不会还得用文件去存吧。学了数据库可以了解服务器可以提供啥服务，学习分布式可以了解怎么对服务器容量或者性能进行扩展，怎么提供容错。

1. 数据库
2. [分布式](distributed-systems.md)

## 参考资料

- [Favorites/NetworkProgramming.md](https://github.com/xiyou-linuxer/Favorites/blob/master/NetworkProgramming.md)