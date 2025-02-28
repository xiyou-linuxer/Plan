---
author: [Y7n05h]
editor: [tiny-sky]
---

# 5. Linux 线程同步

## 进程间通信

阅读《Linux/Unix系统编程手册(上)》

| 章节 | 精读 | 预计耗时 |
| ---- | ---- | -------- |
| 43   | √    | 30 min   |
| 44   | √    | 50 min   |

阅读《UNIX环境高级编程》

| 章节      | 精读 | 预计耗时 |
| --------- | ---- | -------- |
| 15.1-15.6 | √    | 70 min   |

## 线程控制

> [!NOTE]
>
> 两本书勾选章节内容基本一致，相互参考，**重复内容任意选择一本书看**即可。
>
> 完成任务之后继续阅读其余章节（重点部分在参考资料中），后续任务需要其余章节知识背景，直到书籍阅读完毕。

阅读《Linux/Unix系统编程手册(上)》

| 章节 | 精读 | 预计耗时 |
| ---- | ---- | -------- |
| 29   | √    | 30 min   |
| 30   | √    | 70 min   |
| 31   | √    | 50 min   |
| 32   | √    | 20 min   |
| 33   | √    | 30 min   |

阅读《UNIX环境高级编程》

| 章节 | 精读 | 预计耗时 |
| ---- | ---- | -------- |
| 11   | √    | 40 min   |
| 12   | √    | 80 min   |
| 9    | √    | 80 min   |
| 10   | √    | 70 min   |

## TASK

在此任务中你需要使用线程来提高并发性能：[Thread](../project/thread)

在此任务中你需要处理不同状况下线程间的同步问题： [Synchronize](../project/synchronize)

## 参考

- 建议学习 GDB 如何调试线程
- 建议学习日志库的简单使用，建议尝试编写一个简单的日志库

可以尝试使用以下日志库：

- C
    - [zlog](http://hardysimpson.github.com/zlog)
- C++
    - [spdlog](https://github.com/gabime/spdlog)
    - [glog](https://github.com/google/glog)
- Go
    - [zap](https://github.com/uber-go/zap)
