package com.xiyoulinux.priorityqueue;

public interface Priority {

    /**
     * 返回对象的优先级, 约定数字越大, 优先级越高
     *
     * @return 优先级
     */
    int priority();
}
