package com.xiyoulinux.priorityqueue;

public class Entry implements Priority {

    String value;
    int priority;

    public Entry(String value, int priority) {
        this.value = value;
        this.priority = priority;
    }

    @Override
    public int priority() {
        return priority;
    }

    @Override
    public String toString() {
        return "(" + value + " priority=" + priority + ")";
    }
}
