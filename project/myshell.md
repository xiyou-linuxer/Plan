### Project4: 实现自己的 shell

#### 知识要点

1. Linux系统编程 进程控制

2. 编程能力

#### 任务说明

`shell` 是 `GNU/Linux` 操作系统中传统的用户和计算机的交互界面．常见 `Shell` 有 `Bash`、`Zsh`、`Fish` 等。

请基于 `GNU/Linux` 操作系统，编程实现 `shell` 的 **部分** 功能．

#### 语言要求

语言在 C、C++、Go、Rust 中任选

##### C

- 不得使用除 `readline` 外的第三方库。
- 当然，你也可以不用 `readline`。

##### C++

- 不得使用除 `readline`、`gtest`、`gmock` 外的第三方库。
- 当然，你也可以不用 `readline`、`gtest`、`gmock` 中的全部或部分。

##### Go

- 不得使用第三方模块。

##### Rust

- 不得使用除 `libc` 外的 `crate`。
- 当然，你也可以不用 `libc` 这个 `crate`。

P.S. **不推荐** 没学懂 C++ 的人学 Rust

#### 验收要求

- 实现 管道（也就是 | ）
- 实现 输入输出重定向(也就是 < > >>)
- 实现 后台运行（也就是 & ）
- 实现 cd
- 屏蔽一些信号（如ctrl + c 不能终止）
- 界面美观
- 开发过程记录、总结、发布在个人博客中

#### 命令输入示例

```bash
echo ABCDEF
echo ABCDEF > ./1.txt
cat 1.txt
ls -t >> 1.txt
ls -a -l | grep abc | wc -l > 2.txt
python < ./1.py | wc -c
```

注：
示例请参考 `Bash`、`Zsh` 命令

**截止时间 2022-04-03**


#### 参考资料

- man 手册.
- MichaelKerrisk.Linux/UNIX系统编程手册\[M\].北京:人民邮电出版社.
- W.RichardStevens.Stephen.UNIX环境高级编程\[M\].第3版.戚正伟,译.北京:人民邮电出版社.
