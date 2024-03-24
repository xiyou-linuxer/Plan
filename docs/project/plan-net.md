```md
# 搞明白网络！

## 处理 TCP 丢包问题

首先需要声明两点：

1. TCP 丢包不是 TCP 的锅！
2. 这是一个**必做项目**。
   - 任务截止日期：2023.6.26 UTC+8

### 任务要求

- C/C++
  - Golang/Java 系同学不用担心，此 Lab 对 C++ 技能要求不高
- Socket 编程经验
  - 相信读完书的大家都可以写出一个 echo 服务器了

### 任务描述

- 你需要分别在服务器与客户端进行编码工作
  - 客户端发送字符串
  - 服务端接收字符串
  - gRPC 负责验证字符串传输是否正确
- 你的数据在由客户端发往服务器的时候会经历以下过程
  - 一些网络干扰（**故意的**）
  - 一些网络延迟（**故意的**）
  - 数据传输时 MTU 小于系统值（当然也是**故意的**）
    - 快问快答：
      - MTU 是什么？
      - 你的 Linux 的系统 MTU 值是多少？
      - MTU 变小了对数据传输有什么影响？
  - ...
  - 有兴趣的同学可以研究一下代码是怎么实现**干扰**操作的
- 传输的数据类型包括 ASCII / binary

### 任务环境准备

#### Step 1. 准备 gRPC

- 需启动 gRPC 从而正常运行测试代码
  - 注意：gRPC 仅负责测试代码，与其相关的代码可以忽略
- Debian 系（Ubuntu/Mint）
  - 启动一个 Arch Linux 环境的 Docker
  - 通过 Arch 的包管理器 `pacman` 安装必须环境
  - 参考[这里](https://github.com/xiyou-linuxer/Exercise?#tcp-%E9%83%A8%E5%88%86)

- Arch 系同学

```bash
pacman -Syu
pacman -S grpc cmake gcc make pkgconfig
```

#### Step 2. 生成测试相关代码

- Clone 代码（使用 Git 提供的 sparsecheckout 对指定文件夹进行 clone）

```bash
# 创建代码仓库
mkdir netPlan
cd netPlan
# 开始克隆
git init
git remote add origin git@github.com:xiyou-linuxer/NetWork.git
git pull origin main
cd Network
# 生成测试相关代码
protoc --cpp_out=. NetworkTest.proto
protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` NetworkTest.proto
```

#### Step 3. 运行测试代码

```bash
mkdir build
cd build
cmake ..
make -j8
```

- `make` 结束后，在 `build` 文件夹会生成两个文件：
  - client.out
  - server.out
- 在不同终端同时运行这两个可执行文件，即可开始自动测试

### 编写代码

任务相当于**代码填空**：
- 在 `/netPlan/Network/test_client.cpp` 中编写客户端代码
- 在 `/netPlan/Network/test_server.cpp` 中编写服务器代码

```md
你的目标是：

1. 客户端中，从 `msg` 类中 `pop` 出一个字符串，并将处理后发送给服务器。

```cpp
// pop message
auto str = msg->pop();
const char *data = str.data();
```

2. 服务器中，使用 `commit` 方法将接收到的字符串提交给测试机进行代码测试。

```cpp
// commit message
std::string str(buf, len);
test->commit(std::move(str));
```

## C/C++ Simple FTP

!!! note "TODO"
    (封装自己的网络协议)

## Golang: TODO List

!!! note "TODO"