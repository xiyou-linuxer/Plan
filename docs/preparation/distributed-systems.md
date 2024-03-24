# 分布式系统

## 前置条件
你连单机服务器编程都整不会，搁着搭空中楼阁呢？！分布式本身就是许多个单机节点构成的。为此，你得先看 [Linux 网络编程](linux-network-programming.md)，等你把该看的书都看了，该做的项目都做了，咱再回来跟你好好说一说咋去学分布式这些狗屁玩意~

## 为什么要学习分布式

大数据时代单机的局限性：磁盘存储空间不足，计算能力的不足，容错能力的不足。通过构建分布式系统，我们可以获得更好的计算能力、更大的存储空间和更好的容错能力。

## 如何去学习分布式

目前最好的方案就是做 Lab。

### 推荐的课程

- [MIT 6.033](http://web.mit.edu/6.033/www/)

6.033 涵盖四个单元的技术内容：操作系统、网络、分布式系统和安全。可以帮助我们从单机操作系统逐步扩展到分布式系统的知识，以更好地理解分布式系统的设计原理。

- [MIT 6.824](https://pdos.csail.mit.edu/6.824/schedule.html)

分布式领域最著名的课程，由讲师 Frans Kaashoek 讲授，课程内容涉及到很多的分布式原理，如分布式共识、CAP、分布式事务等。介绍了很多分布式计算/存储系统，如分布式文件系统、分布式数据库、分布式缓存、分布式区块链等。

Youtube 视频去 Chrome 扩展商店下双语翻译插件，或者 B 站有个 simviso 的官方（翻译质量还可以，但后续有一些要收费）。

论文由于是英文的，对我们来说的阅读难度会比较大，推荐寻找网上已经有的翻译资源或者通过有道翻译等翻译软件双语对照。如果有翻译的不够准确或者有歧义的内容，请记得参照原文。

在阅读过程中推荐记录笔记，否则后面很容易会忘。

学习的过程中可以配套 [极客时间：大数据经典论文解读](https://time.geekbang.org/column/intro/100091101?tab=catalog&page=A) 加深对部分 papers 的理解。

部分论文有中文翻译，参考 [MIT 6.824 涉及的部分论文翻译](https://blog.csdn.net/weixin_43705457/article/details/106083524)。

尽管这个成电的培养计划 [CDDSCLab/training-plan](https://github.com/CDDSCLab/training-plan) 难度系数挺高的，但说实话内容的确是很硬核的。可以作为学习分布式的扩展学习计划。

## 推荐的书单

- 《数据密集型应用系统设计》DDIA
- 《分布式数据库原理 架构与实践》

## 自我检验 HOMEWORK

实现 MIT 6.824 的 4 个 Plan

## 学习资源

!!! note
    由你来完善和丰富！

- [Favorites/DistributedSystem.md](https://github.com/xiyou-linuxer/Favorites/blob/master/DistributedSystem.md)