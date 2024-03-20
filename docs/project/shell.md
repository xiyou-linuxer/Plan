# 实现自己的 shell

## 为什么实现一个自己 shell?

你是一个 Window/Android 用户，你可以直接用图形化桌面直接双击跑一个程序，没压力吧，轻松吧。
图形化工具为我们屏蔽了底层进程调用的细节。或者你是一个 Linux 用户，你喜欢用 bash 执行 `grep`
命令来查找文件中的内容，喜欢用 `git` 来提交代码，喜欢用 `ls` 来查看目录内容，有时你还会去使用
将多个命令一起使用：`cat cat.txt | grep "smelly cat" | wc -c`。作为一个 Linux Hacker，你理应
当了解这些图形化工具背后的原理，利用它实现一些更好玩的事情。

## Part 1

假设有以下文件 `1.txt` 记录着学长们悲惨的成绩：

```
zzw   环境编程    33
rzj   环境编程    55
lsh   网络编程    33
hzn   网络编程    55
zzy   数据结构    33
zt    计算机组成原理  55
lsh   计算机组成原理  55
zzy   计算机组成原理  55
xjj   数据结构    33
```

### TASK

执行下面这行的命令的结果是什么？你能解释下原因么？

1. `cat 1.txt | awk '{print $1}' | sort | uniq -c | sort -r -n | head -n 5`
2. `grep "rzj" > 2.txt < 1.txt`
3. `echo "the answer is 42" > 1.txt`

## Part 2

你的终端 `bash` 或者 `zsh` 是如何执行这些命令的呢？
参考阅读资料调研 `fork()`, `exec()`, `pipe()`, `mkfifo()` 等进程 API。

### TASK

打造一个绝无伦比的 `xxx-super-shell` (`xxx` 是你的名字)，它能实现下面这些功能：

- 实现 管道 (也就是 `|`)
- 实现 输入输出重定向(也就是 `<` `>` `>>`)
    - 要求实现 在管道组合命令的两端实现重定向运算符
    ```shell
    # Require 
    cat < 1.txt | grep -C 10 abc | grep -L efd | tac >> 2.txt
    # Does not require
    cat < 1.txt | grep -C 10 abc > test1.txt | test2.txt > grep -L efd | tac >> 2.txt
    ```
- 实现 后台运行（也就是 `&` ）
- 实现 `cd`，要求支持能切换到绝对路径，相对路径和支持 `cd -`
- 屏蔽一些信号（如 `ctrl + c` 不能终止）
- 界面美观
- 开发过程记录、总结、发布在个人博客中

要求：
- 不得出现内存泄漏，内存越界等错误
- 学会如何使用 gdb 进行调试，使用 valgrind 等工具进行检测

## Example

```sh
xxx@xxx ~ $ ./xxx-super-shell
xxx@xxx ~ $ echo ABCDEF
xxx@xxx ~ $ echo ABCDEF > ./1.txt
xxx@xxx ~ $ cat 1.txt
xxx@xxx ~ $ ls -t >> 1.txt
xxx@xxx ~ $ ls -a -l | grep abc | wc -l > 2.txt
xxx@xxx ~ $ python < ./1.py | wc -c
xxx@xxx ~ $ mkdir test_dir
xxx@xxx ~/test_dir $ cd test_dir
xxx@xxx ~ $ cd -
xxx@xxx ~/test_dir $ cd -
xxx@xxx ~ $ ./xxx-super-shell # shell 中嵌套 shell
xxx@xxx ~ $ exit
xxx@xxx ~ $ exit
```

注：
示例请参考 `Bash`、`Zsh` 命令

## 语言要求

语言在 C、C++、Go、Rust 中任选

## 截止时间

2024-03-25 21：00（UTC+8）
<!-- 2022-04-03 -->

## 知识要点

1. 懂得如何使用 shell
2. 理解 shell 原理
3. Linux系统编程：进程控制
4. gdb
5. valgrind

## 参考资料

- man 手册.
- MichaelKerrisk.Linux/UNIX系统编程手册\[M\].北京:人民邮电出版社.
- W.RichardStevens.Stephen.UNIX环境高级编程\[M\].第3版.戚正伟,译.北京:人民邮电出版社.

## 开源

- [bash](https://github.com/bminor/bash/graphs/contributors)
- [zsh](https://github.com/zsh-users/zsh)
- [fish-shell](https://github.com/fish-shell/fish-shell)
