# 优先队列

## 前置知识
- `类和对象`：**类**，**接口**，**构造方法**，**封装、继承、多态**
- `泛型`：**泛型类**，**泛型接口**，**泛型方法**，**约束元素类型**
- `数据结构`：**队列**，**堆**
- `Maven` 的使用

## 介绍
优先队列（Priority Queue）是一种特殊的队列数据结构，其中每个元素都有一个关联的优先级。
与普通队列不同，优先队列中的元素并不按照插入顺序进行排列，而是根据其优先级进行排序。

堆（Heap）：优先队列可以使用二叉堆（Binary Heap）实现。
堆是一个完全二叉树，也就是说除了最后一层，其他层的节点都是满的，最后一层的节点从左到右填入。
在大顶堆（Max Heap）中，对于堆中的任意节点 X，节点 X 的值大于等于其子节点的值；而在小顶堆（Min Heap）中，节点 X 的值小于等于其子节点的值。

```java
package com.alibaba.datastructure;

import java.util.PriorityQueue;

public class PriorityQueueExample {
    public static void main(String[] args) {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();

        priorityQueue.offer(8);
        priorityQueue.offer(3);
        priorityQueue.offer(5);
        priorityQueue.offer(2);
        priorityQueue.offer(10);

        while (!priorityQueue.isEmpty()) {
            int element = priorityQueue.poll();
            System.out.println("Removed: " + element);
        }
    }
}
```

我们运行上述代码会看到如下结果：

```
Removed: 2
Removed: 3
Removed: 5
Removed: 8
Removed: 10
```

在优先队列中，具有较高优先级的元素会先被取出，而具有较低优先级的元素会被推迟处理。

优先队列在数据结构中非常重要，具体体现就是 LeetCode 算法题和项目中经常用到。

## PriorityQueue 类的实现
[PriorityQueue](https://github.com/xiyou-linuxer/Queue4j/tree/main/PriorityQueue/src/main/java/com/xiyoulinux/priorityqueue/PriorityQueue.java) 中定义了需要实现的类，完成这个文件中的所有方法，可以自由添加辅助方法。

[TestPriorityQueue.java](https://github.com/xiyou-linuxer/Queue4j/tree/main/PriorityQueue/src/test/java/com/xiyoulinux/priorityqueue/TestPriorityQueue.java) 中有相应的测试（包括测试时间复杂度）。

> [!IMPORTANT]
>
> 1. **先安装 Maven**，一般 IDEA 自带 Maven，所以熟悉怎么使用即可。
> 2. pom.xml 中使用的 JDK 21，JUnit 比较新，要使用过去的版本可以自行修改。
> 3. 测试中数据规模较大，可以体会优化算法带来的时间复杂度巨大的提升。

编译、运行和测试：
```bash
cd PriorityQueue
mvn test
```

## 建议
- 先掌握 Maven 的使用。
- 掌握优先队列和堆的思想，写好上浮（Up-Heap）操作和下沉（Down-Heap）操作。
- 可以先用无序数组或有序数组实现一个，后期用堆进行优化。

## 时间
开始时间：2024-4-20
截止时间：2024-5-12

## 参考资料
- [1]：[java/PriorityQueue](https://docs.oracle.com/javase/8/docs/api/java/util/PriorityQueue.html)
