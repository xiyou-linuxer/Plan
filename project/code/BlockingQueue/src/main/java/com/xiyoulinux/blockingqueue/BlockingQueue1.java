package com.xiyoulinux.blockingqueue;

import java.util.Arrays;

/**
 * 双锁实现
 * 使用级联唤醒(Cascade Wake-up)提高性能
 *
 * @param <E> 元素类型
 */
@SuppressWarnings("all")
public class BlockingQueue1<E> implements BlockingQueue<E> {

    private final E[] array;
    private int head;
    private int tail;

    public BlockingQueue1(int capacity) {
        this.array = (E[]) new Object[capacity];
    }

    @Override
    public String toString() {
        return Arrays.toString(array);
    }

    @Override
    public int size() {
        return 0;
    }

    @Override
    public void offer(E e) throws InterruptedException {

    }

    @Override
    public E poll() throws InterruptedException {
        return null;
    }
}
