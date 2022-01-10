### 为什么要学习分布式

大数据时代单机的局限性：磁盘存储空间不足，计算能力的不足，容错能力的不足。
通过构建分布式系统，我们可以获得更好的计算能力，更大的存储空间，更好的容错能力。

### 如何去学习分布式

目前最好的方案就是做 lab。

#### 推荐的课程
- [mit 6.033](http://web.mit.edu/6.033/www/)

6.033涵盖四个单元的技术内容：操作系统、网络、分布式系统和安全。
可以帮助我们从单机操作系统逐步扩展到分布式系统的知识，以更好的理解分布式系统的设计原理。

- [mit 6.824](https://pdos.csail.mit.edu/6.824/schedule.html)

分布式领域最著名的课程，由讲师 Frans Kaashoek 讲授，课程内容涉及到很多的分布式原理如分布式共识，CAP，分布式事务... 介绍了很多分布式计算/存储系统：如分布式文件系统，分布式数据库，分布式缓存，分布式区块链...

youtube 视频 去 Chrome 下双语翻译插件

论文由于是英文的，对我们来说的阅读难度会比较大，推荐寻找网上已经有的翻译资源或者通过有道翻译等翻译软件双语对照。如果有翻译的不够准确或者有歧义的内容，请记得参照原文。

论文在阅读过程中推荐记录笔记，否则后面很容易会忘。

学习的过程中可以配套 [极客时间：大数据经典论文解读](https://time.geekbang.org/column/intro/100091101?tab=catalog&page=A) 加深对部分 papers 的理解。

| 论文（英文原版）                                                                                                                                              | 论文 （中文翻译）                                                                                                                                                    | 为什么要看这一篇论文                                             |
| --------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------- |
| MapReduce: Simplified Data Processing on Large Cluster                                                                                                    | [MapReduce: Simplied Data Processing on Large Clusters](https://github.com/pirDOL/kaka/blob/master/Papers/MapReduce-Simplified-Data-Processing-on-Large-Clusters.md) |
| [Scaling Memcache at Facebook](https://pdos.csail.mit.edu/6.824/papers/memcache-fb.pdf)                                                                   | [Facebook 对 Memcache 伸缩性的增强](https://www.oschina.net/translate/scaling-memcache-facebook)                                                                     | 了解分布式环境下 DB 和 Cache 之间的一致性是如何实现的            |
| [Resilient Distributed Datasets: A Fault-Tolerant Abstraction for In-Memory Cluster Computing](https://pdos.csail.mit.edu/6.824/papers/zaharia-spark.pdf) | [RDD：基于内存的集群计算容错抽象](https://shiyanjun.cn/archiveas/744.html)                                                                                           | 了解新一代的分布式计算框架 Spark 是如何获得比 MapReduce 更高性能 |
| [Secure Untrusted Data Repository (SUNDR)](https://pdos.csail.mit.edu/6.824/papers/li-sundr.pdf)                                                          | N/A                                                                                                                                                                  | 了解非拜占庭文件服务器如何实现 Fork 一致性                       |
| [Bitcoin: A Peer-to-Peer Electronic Cash System](https://pdos.csail.mit.edu/6.824/papers/bitcoin.pdf)                                                     | [比特币：一种点对点的电子现金系统](https://nakamotoinstitute.org/static/docs/bitcoin-zh-cn.pdf)                                                                      | 了解去中心化的分布式区块链如何达成一致性共识 (拜占庭分布式系统)  |
| [Blockstack: A Global Naming and Storage System Secured by Blockchains](https://pdos.csail.mit.edu/6.824/papers/blockstack-atc16.pdf)                     | N/A                                                                                                                                                                  | 了解如何通过去中心化的分布式区块链技术实现去中心化服务           |


- [CDDSCLab/training-plan](https://github.com/CDDSCLab/training-plan)

尽管这个成电的培养计划  难度系数挺高的，但说实话内容的确是很硬核的。可以作为学习分布式的扩展学习计划。

### 推荐的书单
* 《数据密集型应用系统设计》DDIA
* 《分布式数据库原理 架构与实践》


### github 上开源的分布式项目

* ztcd
* hdfs
* ...

### 学习资源

- [Favorites/DistributedSystem.md](https://github.com/xiyou-linuxer/Favorites/blob/master/DistributedSystem.md)

由你来完善和丰富！
