### Project1: 设计一个 C 语言的动态扩容缓冲区

#### 知识要点
1. 字符串。
2. 面向对象的 C 语言设计。
3. 动态内存分配。
4. Linux File API。
5. getline。

#### 介绍
如果同学们了解过 C++ | Java | Golang | Python 的字符串的话，应该知道它们的字符串是可以动态扩容的，见下图 C++ 代码 ：

```cpp
// strbuf_test.cpp
#include <stdio.h>
#include <string>

int main() {
  std::string str("xiyou");
  str += "linux";
  printf("%s", str.c_str()); // xiyoulinux
}
```

我们来编译运行一下：

```sh
$ g++ strbuf_test.cpp -o ./strbuf_test
$ ./strbuf_test
xiyoulinux
```

成功输出 `xiyoulinux`，啊，这就邪恶的 C++ 施展的黑魔法么？

对比 c 语言版本：

```c
// strbuf_test.c
#include <stdio.h>
#include <string.h>

int main() {
  char str[6] = "xiyou";
  strcat(str, "linux");
  printf("%s\n", str);
}
```

我们来编译运行一下：

```
$ gcc strbuf_test.c -o ./strbuf_test
$ ./strbuf_test
xiyoulinux
*** stack smashing detected ***: terminated
[1]    1117368 abort (core dumped)  ./strbuf_test
```

然而....可恶！吾可爱的栈竟然被粉碎了！！！这是为何？

使用一个 c 语言字符数组似乎不可避免的存放不下一个不确定长度的字符串，你开长度为 11，我也许就想要存长度为 20 的字符串。所以你又有新的方法：`malloc` + `realloc`：

```c
// strbuf_test2.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int len = 5;
  char *str = malloc(sizeof(char) * len);
  memcpy(str, "xiyou", 5);
  str = realloc(str, len + strlen("linux") + 1);
  strcpy(str + 5, "linux");
  printf("%s\n", str);
}
```

```sh
$ gcc strbuf_test2.c -o ./strbuf_test2
$ ./strbuf_test2
xiyoulinux
```

是的，这次我们成功输出了 `xiyoulinux`！

但是，上面我们硬编码了字符串长度, 我们可不可以将它包装成一个统一的函数去做到这一件事情呢？

事实上，在很多优秀项目都会去封装这样的一种接口，如 [redis](https://github.com/redis/redis/blob/unstable/src/sds.c),[git](https://github.com/git/git/blob/master/strbuf.c)。现在你的目标是重新造一遍在轮子（belong to you!）：


这个缓冲区类的定义就免费送给你们啦：

```c
struct strbuf {
  int len;     //当前缓冲区（字符串）长度
  int alloc;   //当前缓冲区（字符串）容量
  char *buf;   //缓冲区（字符串）
};
```

有了 `strbuf`，意味着我们就可以进行以下的字符串操作了：

```c
int main() {
  struct strbuf sb;
  strbuf_init(&sb, 10);
  strbuf_attach(&sb, "xiyou", 5, 10);
  assert(strcmp(sb.buf, "xiyou") == 0);
  strbuf_addstr(&sb, "linux");
  assert(strcmp(sb.buf, "xiyoulinux") == 0);
  strbuf_release(&sb);
}
```

你需要做的，就是实现 `strbuf` 的这些操作函数。

#### HINT

* `strbuf` 的成员 `len` 代表的是 `buf` 缓冲区的长度，每次我们将字符串追加入 `strbuf` 中，我们都应该使用 `strbuf_setlen()` 去更新 `strbuf` 的长度 `len`，注意 `123\0456` 的长度不是 3，而是 7。
* `strbuf` 的成员 `alloc` 代表的是 `buf` 缓冲区的容量，也就是我们每次动态分配的数组大小，每当我们需要向 `sb` 内追加一个字符串，我们需要计算当前的字符串长度加上追加的字符串长度，如果超过了当前的容量，我们就需要把容量扩大一倍，然后将字符串添加进去。

#### Part 2A

##### TASK

实现字符串缓冲区类 `strbuf` 简单的初始化，填充，释放，交换，比较，清空等操作。

具体 API 如下：

| API                                                                       | 功能简介                                               |
| ------------------------------------------------------------------------- | ------------------------------------------------------ |
| void strbuf_init(struct strbuf *sb, size_t alloc);                        | 初始化 `sb` 结构体，容量为 `alloc`。                   |
| void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc); | 将字符串填充到 `sb` 中，长度为 `len`, 容量为 `alloc`。 |
| void strbuf_release(struct strbuf *sb);                                   | 释放 `sb` 结构体的内存。                               |
| void strbuf_swap(struct strbuf *a, struct strbuf *b)                      | 交换两个 strbuf。                                      |
| char *strbuf_detach(struct strbuf *sb, size_t *sz);                       | 将 `sb` 中的原始内存取出，并获得其长度。               |
| int strbuf_cmp(const struct strbuf *first, const struct strbuf *second);  | 比较两个 strbuf 的内存是否相同。                       |
| void strbuf_reset(struct strbuf *sb);                                          | 清空 `sb`。                                            |


#### Part 2B

##### TASK

实现字符串缓冲区类 `strbuf` 扩容，(追加|插入)字符，字符串等操作。

| API                                                                              | 功能简介                                                      |
| -------------------------------------------------------------------------------- | ------------------------------------------------------------- |
| void strbuf_grow(struct strbuf *sb, size_t extra);                               | 将 `sb` 的长度扩大 `extra`。                                  |
| void strbuf_add(struct strbuf *sb, const void *data, size_t len);                | 向 `sb` 追加长度为 `len` 的数据 `data`。                      |
| void strbuf_addch(struct strbuf *sb, int c);                                     | 向 `sb` 追加一个字符 `c`。                                    |
| void strbuf_addstr(struct strbuf *sb, const char *s);                            | 向 `sb` 追加一个字符串 `s`。                                  |
| void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2);                 | 向一个 `sb` 追加另一个 `strbuf`的数据。                       |
| void strbuf_setlen(struct strbuf *sb, size_t len);                 | 设置 `sb` 的长度 `len`。                                      |
| size_t strbuf_avail(const struct strbuf *sb)                       | 计算 `sb` 目前仍可以向后追加的字符串长度。                    |
| void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len); | 向 `sb` 内存坐标为 `pos` 位置插入长度为 `len` 的数据 `data`。 |

#### Part 2C

##### TASK

实现字符串缓冲区类 `strbuf` 删除部分内容等功能。

| API                                                            | 功能简介                                           |
| -------------------------------------------------------------- | -------------------------------------------------- |
| void strbuf_ltrim(struct strbuf *sb);                          | 去除 `sb` 缓冲区左端的所有 空格，tab, '\t'。       |
| void strbuf_rtrim(struct strbuf *sb);                          | 去除 `sb` 缓冲区右端的所有 空格，tab, '\t'。       |
| void strbuf_remove(struct strbuf *sb, size_t pos, size_t len); | 删除 `sb` 缓冲区从 `pos` 坐标长度为 `len` 的内容。 |


#### Part 2D

1. 在我们使用 C FILE API 读取一个小文件的时候经常会有这样的一个困惑，我们为什么不能直接一次性读完整个文件到一个大缓冲区呢? 而 `fread` or `read` 总是用一个将一个文件中的内容反复读到一个缓冲区中，然后我们从这个缓冲区中取出内容, 但是为什么我们不能直接将一个文件读到一个缓冲区中呢?

2. 在我们想要从文件或者终端读取一行数据的时候经常有这样的疑惑，我应该用什么函数去读？C++ 的 `cin.getline()`? `C++` 的 `getline()`? C 的 `getline()`? Python 的 `readline()`? 正如 StackOverFlow 的网友的总结[stackoverflow](https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c),c版本的 `getline()` 效率是最高的。那么问题来了, C 的 `getline()` 每次都得我去指定缓冲区和长度... 有什么好的方法让用户可以直接调用一个 `strbuf_getline()` 无脑的从缓冲区中拿到想要的内容呢？

##### TASK
| API                                                                         | 功能简介                                                                                            |
| --------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint);                | 为 `sb` 直接扩容 `hint ? hint : 8192` 大小， 然后将文件描述符为 `fd` 的所有文件内容读取到 `sb` 中。 |
| int strbuf_getline(struct strbuf *sb, FILE *fp);                            | 将 将文件句柄为 `fp` 的一行内容读取到 `sb` 。                                                       |

---
#### 无信用挑战练习

##### CHALLENGE

1. 实现字符串切割（C 系字符串函数的一个痛点）。

| API                                                                                     | 功能简介                                                                                                             |
| --------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max); | 将长度为 `len` 的字符串 `str` 根据切割字符 `terminator` 切成多个 strbuf,并从结果返回，max 可以用来限定最大切割数量。返回 `struct strbuf` 的指针数组，数组的最后元素为 `NULL` |

2. 实现判断一个 strbuf 是否以指定字符串开头的功能（C 系字符串函数的另一个痛点）。

| API  |    功能简介 |
| -- |   -- |
| bool strbuf_begin_judge(char* target_str, const char* str, int strlen);   | target_str : 目标字符串，str : 前缀字符串，strlen : target_str 长度 ，前缀相同返回 true 失败返回 false     |




3. 获取字符串从坐标 `[begin, end)` 的所有内容（可以分成引用和拷贝两个模式） 。


| API  |    功能简介 |
| -- |   -- |
| char* strbuf_get_mid_buf(char* target_buf, int begin, int end, int len);   | target_str : 目标字符串，begin : 开始下标，end 结束下标。len : target_buf的长度，参数不合法返回 NULL. 下标从0开始，[begin, end]区间。 |
---
#### 参考资料

- [1] [strbuf API](https://schacon.github.io/git/technical/api-strbuf.html).
- [2] [goldsborough/vector](https://github.com/goldsborough/vector).
- [3] [eteran/c-vector](https://github.com/eteran/c-vector).
- [4] [git/strbuf](https://github.com/git/git/blob/master/strbuf.h).
- [5] [redis/sds](https://github.com/redis/redis/blob/unstable/src/sds.h).
