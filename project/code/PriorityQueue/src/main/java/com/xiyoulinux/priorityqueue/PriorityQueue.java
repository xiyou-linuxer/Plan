package com.xiyoulinux.priorityqueue;


// 实现优先队列
public class PriorityQueue<E extends Priority> implements Queue<E> {

    Priority[] array;
    int size;

    public PriorityQueue(int capacity) {
        array = new Priority[capacity];
    }

    @Override
    public boolean offer(E value) {
        return false;
    }

    @Override
    public E poll() {
        return null;
    }

    @Override
    public E peek() {
        return null;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public boolean isFull() {
        return false;
    }
}
