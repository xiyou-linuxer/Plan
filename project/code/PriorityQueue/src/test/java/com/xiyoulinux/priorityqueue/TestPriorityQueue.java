package com.xiyoulinux.priorityqueue;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.Random;

import static org.junit.jupiter.api.Assertions.*;

public class TestPriorityQueue {

    @Test
    @DisplayName("常规功能测试")
    public void poll() {
        PriorityQueue<Entry> queue = new PriorityQueue<>(5);
        queue.offer(new Entry("task1", 4));
        queue.offer(new Entry("task2", 3));
        queue.offer(new Entry("task3", 2));
        queue.offer(new Entry("task4", 5));
        queue.offer(new Entry("task5", 1));
        assertFalse(queue.offer(new Entry("task6", 7)));

        assertEquals(5, queue.peek().priority());
        assertEquals(5, queue.poll().priority());
        assertEquals(4, queue.poll().priority());
        assertEquals(3, queue.poll().priority());
        assertEquals(2, queue.poll().priority());
        assertEquals(1, queue.poll().priority());
    }

    @Test
    @DisplayName("测试时间复杂度")
    public void testPriorityQueueTimeComplexity() {
        int n = 100000; // 输入规模

        PriorityQueue<Entry> priorityQueue = new PriorityQueue<>(n);

        Random random = new Random();

        long startTime = System.currentTimeMillis();

        // 执行插入操作
        for (int i = 0; i < n; i++) {
            int priority = random.nextInt(n);
            priorityQueue.offer(new Entry(String.format("task%d", i), priority));
        }

        // 执行删除操作
        for (int i = 0; i < n; i++) {
            priorityQueue.poll();
        }

        long endTime = System.currentTimeMillis();
        long executionTime = endTime - startTime;

        System.out.println("Execution Time: " + executionTime + " milliseconds");

        assertTrue(executionTime <= 500);
    }
}
