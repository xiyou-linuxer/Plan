### Project3: 实现自己的 ls 命令

#### 知识要点

1. Linux系统编程 目录和文件部分

2. C语言编程能力

#### 任务说明

`ls` 是 `GNU/Linux` 操作系统中常见的命令．
请使用 C 语言，基于 `GNU/Linux` 操作系统，编程实现 `ls` 命令的 **部分** 功能．

#### 验收要求

- 实现 ls 的 -a、-l、-R、-t、-r、-i、-s 参数，并允许这些参数任意组合．
- `-R` 需要通对 `/` 的遍历测试
- 界面美观（输出对齐、与颜色显示等）
- 无资源与内存泄露
- 开发过程记录、总结、发布在个人博客中

#### 命令输入示例

```bash
ls -a -l
ls -a /home
ls -alR /
ls -t
ls -ai -t /home
ls -i /home /etc
```

注：
命令输出示例请参考 `ls` 命令



#### 参考资料

- man 手册.
- MichaelKerrisk.Linux/UNIX系统编程手册\[M\].北京:人民邮电出版社.
- W.RichardStevens.Stephen.UNIX环境高级编程\[M\].第3版.戚正伟,译.北京:人民邮电出版社.

