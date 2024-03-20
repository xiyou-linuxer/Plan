package com.xiyoulinux.blockingqueue;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Timeout;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TestBlockingQueue1 {

    private static final int THREAD_COUNT = 100;
    private static final int ELEMENT_COUNT = 1000;

    @Test
    @Timeout(value = 5, unit = TimeUnit.SECONDS)
    @DisplayName("testDeadlock & testFalseAwakening & testSizeAtomicity")
    public void testDeadlock() throws InterruptedException {
        final BlockingQueue<Integer> queue = new BlockingQueue1<>(ELEMENT_COUNT);
        final CountDownLatch latch = new CountDownLatch(THREAD_COUNT * 2);

        for (int i = 0; i < THREAD_COUNT; i++) {
            new Thread(() -> {
                try {
                    for (int j = 0; j < ELEMENT_COUNT; j++) {
                        queue.offer(j);
                    }
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                } finally {
                    latch.countDown();
                }
            }).start();
        }

        for (int i = 0; i < THREAD_COUNT; i++) {
            new Thread(() -> {
                try {
                    for (int j = 0; j < ELEMENT_COUNT; j++) {
                        queue.poll();
                    }
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                } finally {
                    latch.countDown();
                }
            }).start();
        }

        latch.await();

        assertEquals(0, queue.size());
    }
}