要求使用下述三种方式通过网络将一个文件发送到对端，测试 IO 性能发生的变化，感悟零拷贝和直接 IO 的魅力或者缺陷。

| IO 模式      | 4KB | 8KB | ... | 1GB |
| ------------ | --- | --- | --- | --- |
| read + write |     |     |     |     |
| mmap + write |     |     |     |     |
| sendfile     |     |     |     |     |
| direct io    |     |     |     |     |
<!-- maybe async io? -->


请你绘制 4KB，8KB...512MB （间距为 4KB） 的性能变化曲线。(可以使用 matplotlib.pyplot.plot() 来绘制图形)
分析各个模式下的性能变化，为什么？