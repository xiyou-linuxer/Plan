### 前置条件
你连单机服务器编程都整不会，搁着搭空中楼阁呢？！分布式本身就是许多个单机节点构成的。
为此你得先看 [linux 网络编程](LinuxNetworkProgramming.md)，等你把该看的书都看了，该做的项目都做了，
咱再回来跟你好好说一说咋去学分布式这些狗屁玩意～

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

youtube 视频 去 Chrome 下双语翻译插件, 或者B站有个simviso的官方(翻译质量还可以，但后续有一些要收费）

论文由于是英文的，对我们来说的阅读难度会比较大，推荐寻找网上已经有的翻译资源或者通过有道翻译等翻译软件双语对照。如果有翻译的不够准确或者有歧义的内容，请记得参照原文。

论文在阅读过程中推荐记录笔记，否则后面很容易会忘。

学习的过程中可以配套 [极客时间：大数据经典论文解读](https://time.geekbang.org/column/intro/100091101?tab=catalog&page=A) 加深对部分 papers 的理解。

部分论文有中文翻译，参考 [MIT 6.824涉及的部分论文翻译](https://blog.csdn.net/weixin_43705457/article/details/106083524?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164360970516780357238002%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=164360970516780357238002&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-5-106083524.nonecase&utm_term=mit&spm=1018.2226.3001.4450)。

- [CDDSCLab/training-plan](https://github.com/CDDSCLab/training-plan)
尽管这个成电的培养计划  难度系数挺高的，但说实话内容的确是很硬核的。可以作为学习分布式的扩展学习计划。

### 推荐的书单
* 《数据密集型应用系统设计》DDIA
* 《分布式数据库原理 架构与实践》

### 自我检验 HOMEWORK
1. 实现 MIT6.824 的 4 个 plan

### 学习资源

- [Favorites/DistributedSystem.md](https://github.com/xiyou-linuxer/Favorites/blob/master/DistributedSystem.md)

由你来完善和丰富！
