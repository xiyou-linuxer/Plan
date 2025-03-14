---
author: [yegetables, adlternative]
editor: [Y7n05h]
---

# Linux 网络编程

## 前置条件

1. 你以为你不懂多线程多进程文件就敢来碰网络编程？！跑个单线程 epoll 谁不会？连多线程并发控制都不会，客户数据出错了你负责？赶紧 run 去学 [Linux 系统编程](linux-system-programming) 吧你。
2. 数据结构和算法不会？不会还有人用链表去存所有用户元数据吧，笑死了，别这写低性能服务器了，打好你的基础：[数据结构和算法](data-structure-algorithm) 先吧。

## 为什么要学习服务器？

当今所有的 IT 行业都需要使用服务器为大量客户提供服务，往往 web 系程序员可以直接使用 Nginx、Apache 等开源的服务器，而我们 C 系程序员的目标是了解服务器的底层原理，服务器是如何撑住“百万并发”，多进程，多线程，协程服务器之间区别是什么，reactor/proactor 模型是什么？epoll 多路 I/O 复用是什么。

然而只明白服务器原理是并不够的。当前工业界往往需要服务器提供某种服务：数据存储也好，缓存也好，P2P 通信也好，它们都属于业务层需要实现的内容。小组同学在大一暑假的时候会接触到如何使用 epoll 简单实现一个聊天室，大概也能明白业务层和网络层之间的区别。

## 如何学习服务器？

当前最佳的方案是看书和学习（并参与开发）开源项目。如果是 API 上的问题可以 Google 其 man 手册或者去 Stack Overflow 寻找相关问题。

### 书籍

1. 《UNIX 网络编程 第一卷》：看了这个不能让你上天，很多网络模型现在都已经过时了明白么（注意它还没有讲 epoll）？TCP/UDP 必修，三次握手和四次挥手那些也得了解了解，那一堆 `setsockopt` 的调优不是你能短期内明白的，慢慢看。
2. 《图解网络-小林 coding-v2.0.pdf》：这种书虽然是那种偏向应付面试官的书，但是用来查缺补漏，学习网络基础，其实也不错。后面还有讲套接字内核参数调优，咱平时可没系统接触。
3. 《Linux 高性能服务器编程》：了解下基础的 Linux 网络框架，了解点 epoll，了解点 C++ 风格的服务器编程。
4. 《Linux 多线程服务端编程 使用 Muduo C++ 网络库》：陈硕大佬写的精品，之前看了高性能可以让你初步了解服务器，但是这本可以让你把一些服务器编程的精髓搞清楚，人家给你踩的这些多线程网络编程的坑，目前没有更好的一些书可以帮替代。但是 Muduo 也已经过时了！这是 2010 年左右的书！GitHub 有 Muduo 库的 98、11、17 版，别读死书！

你即使把上面这些都搞明白了，还是会感觉自己对服务器的了解局限在 Muduo 教给你的 reactor 模型和回调地狱里面。

少年的征途是星辰大海！

### 开源项目

1. 学习当前流行的开源 web 服务器，如 Nginx、libuv、libevent，钻研其源码。（boost::asio 也可能会比较难读）
2. 学习当前流行的开源项目如何使用服务器，例如 Redis 的网络层是如何实现的，深入研究其源码。

## 自我检验 HOMEWORK

你连 Muduo 都不会抄？还是说你只会抄 Muduo？那和废柴有什么区别？

不会有人认为服务器只能用于 web 吧！

我列了下面这些，你需要学会如何探索相关资料。老师、学长只能教你如何钓鱼，不能替你钓鱼。

- 实现一种通信协议，如 IRC、HTTPS、RPC、DNS...
- 提高性能的方法：
  1. 实现 web 服务器缓存层（如 memcached、redis）
  2. 使用 io_uring 进行异步 I/O
  3. 查找并消除性能瓶颈
- 提供持久性服务：
  1. 实现 web 服务器存储层（如 Haystack）
- 实现 web 服务器的容错服务...

## 如何进行调试

1. 使用 gdb（例如如何在多线程中设置断点）
2. 使用 Valgrind（如何检测内存越界，检测线程竞争）
3. 使用 AddressSanitizer（同上）

## 如何构建项目

1. 使用 CMake
2. 使用 Bazel
3. 使用 xmake

## 如何进行测试

1. 编写自己的单元测试，例如使用 Google Test
2. 使用 Postman 进行测试（适用于 web 服务器）
3. 编写客户端进行测试
4. 使用 ab 进行压力测试（适用于 web 服务器）

## 如何进行性能优化

1. 使用服务器性能测试工具（如 ab）进行性能测试，与 Nginx 等开源实现进行比较。
2. 使用性能分析工具（如 Perf、gperftools、eBPF...）分析服务器的热点，确定服务器的性能瓶颈，例如不必要的字符串拷贝、耗时的系统调用，或者是否需要禁用 TCP 的 Nagle 算法？还要了解 QPS、吞吐量和延迟的概念。

## 如何部署

1. 使用 Docker：你的服务器只能在本地运行吗？在云时代，连 Docker 都不会用？

## 后续学习方向

好了，你的服务器总算比屎好一点了。但如果客户要求你存储 TB 级别的数据，你难道还会使用文件存储吗？学习数据库可以让你了解服务器可以提供哪些服务，学习分布式系统可以了解如何扩展服务器的容量和性能，以及如何提供容错性。

1. 数据库
2. [分布式系统](distributed-systems)

## 参考资料

- [Favorites/NetworkProgramming](https://fav.xiyoulinux.com/NetworkProgramming)
