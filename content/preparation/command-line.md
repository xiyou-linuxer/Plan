---
author: [Y7n05h, yegetables, adlternative]
---

# Shell 与命令行

## Q&A

### 初学阶段必须掌握的命令有哪些

咱得先知道 Linux 的一个重要思想：一切皆文件。

无论是目录、普通文本文件还是可执行文件，我们需要多种方式观测或者修改它们：

1. `mkdir`：创建目录
2. `ls`：查看目录
3. `cd`：切换目录
4. `rm`：删除文件或目录
5. `cat`：查看普通文件
6. `cp`：拷贝文件
7. `touch`：创建文件
8. `vim`/`nano`/...：修改文件
   另外，我们可能还需要很多高级命令来方便我们编程或者管理。有兴趣的话，可以阅读《鸟哥的 Linux 私房菜》或者上网查阅相关资料。

### 为什么需要学习 Shell 命令

一个合格的 Linux 用户常常会频繁地通过终端操控 GNU/Linux 系统，而不是使用图形用户界面（GUI）。熟悉这些基础的命令是一个成熟的 Linux 用户的必经之路。

### 这些命令的功能也可以用图形界面操作，命令行有必要吗？

与命令行相比，图形用户界面的操作更为直观。但是，要完成一些功能，通常需要在图形界面中反复寻找并点击选项，甚至在多级菜单中更改多个设置。与此不同的是，在 Linux 终端上通常只需要一条或多条命令就能完成这些操作。

### 命令那么多，参数那么复杂，记不住

记住命令用法并不是必要的。作为一个 GNU/Linux 用户，当你长期使用命令行来操作系统时，即使你不刻意记忆命令的用法，你也会逐渐熟悉你所需要的大部分命令。

1. 当你不了解命令的用法时，你可以通过程序的帮助获取命令的用法。例如，你不了解 `ls` 的用法，那么你可以执行 `ls --help` 来获取帮助。
2. 如果你需要关于命令更详细的用法，你还可以参考 `man` 手册。例如，通过 `man ls` 就能查询到 `ls` 命令的详细说明。
3. 你可能觉得 `man` 手册太长，只想了解程序的简单使用方法。那么你也可以通过查询 `tldr` 在线手册来获取帮助。例如，`tldr ls` 就能获得 `ls` 的一些常见用例。
4. 如果你之前使用过某个命令，但现在忘记了用法，你可以通过 `history` 命令查看你过去使用这个命令的情况。例如，`history | grep ls` 就能告诉你之前如何使用 `ls`。

### 命令那么长，敲起来好烦，还不如用图形化界面更有效率！

事实上，我们有很多方法来简化繁琐的命令输入：

1. 你可以为命令设置别名，为较长的命令设置较短的别名，这样可以有效减少需要输入的内容。
2. 如果有多条命令经常需要执行，你可以将它们写在一个 shell 脚本中，只需要执行这个脚本就相当于执行了这些命令。
3. Shell 命令常常可以使用 Tab 键进行补全。我们通常不需要完整地输入命令的全部内容，只需要输入命令或参数的一部分，然后通过 Tab 键补全即可得到完整的内容。善用补全能极大地提高命令的输入效率。（Zsh 在命令补全方面提供了更多支持）

## 任务

- 学会使用命令行以及 `vim`、`gcc`、`gdb` 命令。
- 简单学习 GDB，了解使用 GCC 如何将 `.c` 文件编译成可执行文件的过程。
- 学习 Vim：简单编辑、保存等操作，可选配置插件，代码补全等。
- **严禁只会使用** IDE 或编辑器内直接提供的运行代码和调试功能！
- 每两周至少发布一篇博客。
- 每周至少解决四道算法题。
- 保持 GitHub 更新，小绿点的数量也可以作为评价活跃度的标准。

## 阅读

《鸟哥的 Linux 私房菜》
