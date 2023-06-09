# 搞明白网络!

## 处理 TCP 丢包问题
首先需要声明两点:
1. TCP 丢包不是 TCP 的锅!
2. 这是一个`必做项目`
    - 任务截止日期: `2023.6.26 UTC+8`

### 任务描述
- 你需要分别在服务器与客户端进行编码工作
- 你的数据在由客户端发往服务器的时候会经历以下过程
  - 一些网络干扰(`故意的`)
  - 一些网络延迟(`故意的`)
  - 数据传输时 `MTU` 小于系统值(当然也是`故意的`)
    - 快问快答:
      - MTU 是什么?
      - 你的 Linux 的系统 MTU 值是多少?
      - MTU 变小了对数据传输有什么影响?
  - ...
  - 有兴趣的同学可以研究一下代码是怎么实现`干扰`操作的
- 传输的数据类型包括 ASCII / binary

### 任务环境准备
- 需启动 gRpc 从而正常运行测试代码
- Debian 系(Ubuntu/Mint)
  - 启动一个 Arch Linux 环境的 Docker
  - 通过 Arch 的包管理器 `pacman` 安装必须环境
  - 参考[这里](https://github.com/xiyou-linuxer/Exercise#:~:text=%E5%90%88%E5%B9%B6%E5%85%A5%E4%B8%BB%E5%88%86%E6%94%AF%EF%BC%8E-,TCP%20%E9%83%A8%E5%88%86,-%E5%A6%82%E6%9E%9C%E4%BD%A0%E7%9A%84%20Ubuntu)

- Arch 系同学
```bash
pacman -Syu
pacman -S grpc cmake gcc make pkgconfig
```

### 任务代码
- 任务相当于 `代码填空`
  - 在 `test_client.cpp` 中编写客户端代码
  - 在 `test_server.cpp` 中编写服务器代码
- Clone 代码(使用 Git 提供的 sparsecheckout 对指定文件夹进行 clone)
```bash
> mkdir Network
> cd Network
> git init
> git remote add origin https://github.com/xiyou-linuxer/Exercise
> git config core.sparsecheckout true
> echo "Network" >> .git/info/sparse-checkout
> git pull origin main
```




## C/C++ simple FTP
TODO
(封装自己的网络协议)

## golang: TODO List
TODO
