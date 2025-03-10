---
author: [houkuo123, vincillau]
editor: [Y7n05h]
---

# Linux 系统编程

学习 Linux 系统编程，就是学习使用 Linux 内核和 C 库（通常是 glibc，它封装了 Linux 内核提供给我们的系统调用及其他有用的工具函数）为我们编写的应用程序提供的接口。
在 Linux 上运行的各种程序都会直接或间接地调用 Linux 系统调用（或者 C 库）。
学会 Linux 系统编程，我们才能实现能在 Linux 上运行特定功能的程序。

## 书籍推荐

### Linux/UNIX 系统编程手册

重点章节：

- 文件 I/O（第 4 章、第 5 章、第 13 章）
- 文件系统（第 14 章、第 15 章、第 18 章）
- 进程控制（第 6 章、第 24 章到第 27 章、第 34 章到第 37 章）
- 信号（第 20 章、第 21 章、第 22 章）
- 定时器与休眠（第 23 章）
- 线程（第 29 章到第 33 章）
- I/O 多路复用（重点学习 epoll）
- 进程间通信
- 网络编程

### UNIX 环境高级编程

可以与《Linux/UNIX 系统编程手册》对照阅读。

## 其他学习资料

- man 手册
- GitHub 上的学习资料和优秀开源项目
- 学会使用 Google
- 维基百科
- Stack Overflow
- glibc 源码
