// Single-producer , single-consumer Queue
struct SPSCQueue {
    /* Define Your Data Here */

} typedef SPSCQueue;

SPSCQueue *SPSCQueueInit(int capacity);
void SPSCQueuePush(SPSCQueue *queue, void *s);
void *SPSCQueuePop(SPSCQueue *queue);
void SPSCQueueDestory(SPSCQueue *);


//Multi-producer , Multi-consumer Queue
struct MPMCQueue {
    /* Define Your Data Here */
} typedef MPMCQueue;

MPMCQueue *MPMCQueueInit(int capacity);
void MPMCQueuePush(MPMCQueue *queue, void *s);
void *MPMCQueuePop(MPMCQueue *queue);
void MPMCQueueDestory(MPMCQueue *);
