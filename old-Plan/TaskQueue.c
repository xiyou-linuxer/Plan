// Single-producer , single-consumer Queue
struct SPSCQueue{
    /* Define Your Data Here */

}typedef SPSCQueue;;
SPSCQueue *SPSCQueueInit();
void SPSCQueuePush(SPSCQueue *pool, void *s);
void *SPSCQueuePop(SPSCQueue *pool);
void SPSCQueueDestory(SPSCQueue *);


//Multi-producer , Multi-consumer Queue
struct MPMCQueue {
    /* Define Your Data Here */
} typedef MPMCQueue;

MPMCQueue *MPMCQueueInit(int threadNumber);
void MPMCQueuePush(MPMCQueue *pool, void *s);
void *MPMCQueuePop(MPMCQueue *pool);
void MPMCQueueDestory(MPMCQueue *);
