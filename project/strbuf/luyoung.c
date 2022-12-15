#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct strbuf {
    int len;    // 当前缓冲区（字符串）长度
    int alloc;  // 当前缓冲区（字符串）容量
    char* buf;  // 缓冲区（字符串）
};
// 初始化 `sb` 结构体，容量为 `alloc`
void strbuf_init(struct strbuf* sb, size_t alloc) {
    (*sb).alloc = alloc;
    (*sb).len = 0;
    char *temp = (char*)malloc(sizeof(char)*(alloc));
    (*sb).buf = temp;
    ((*sb).buf[(*sb).len]) = '\0';
}
// 将字符串填充到 `sb` 中，长度为 `len`, 容量为 `alloc`。
// strbuf_attach(&sb, "xiyou", 5, 10);
void strbuf_attach(struct strbuf* sb, void* str, size_t len, size_t alloc) {
    // 更新 `len`
    int sb_len = sb->len, str_len = strlen(str);
    (*sb).len = sb_len + str_len;

    // 刷新 `alloc`
    if ((*sb).len < alloc) {
        sb->alloc <<= 1; //扩充,增加速度
    }
    // 刷新新的字符串
    char *new_alloc = (char*)malloc(sizeof(char)*(*sb).alloc);
    strcat(new_alloc, (*sb).buf);
    printf("1%s\n", new_alloc);
    strcat(new_alloc,str);
    printf("2%s\n", new_alloc);
    (*sb).buf = new_alloc;
}
// 释放 `sb` 结构体的内存
void strbuf_release(struct strbuf *sb){
    free(sb);
}
// 交换两个 strbuf  (利用C语言自身特性)
void strbuf_swap(struct strbuf *a, struct strbuf *b){
    struct strbuf temp = *a;
    *a = *b;
    *b = temp;
}
// 将 `sb` 中的原始内存取出，并将 `sz` 设置为其 `alloc` 大小
char *strbuf_detach(struct strbuf *sb, size_t *sz){
    *sz = (*sb).alloc;
    char *ret = (char*)malloc(sizeof(char)*((*sb).len)+1);
    strcpy(ret,sb->buf);
    return ret;
}
// 比较两个 strbuf 的内存是否相同
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second){
    if(first->buf == second->buf){
        return 1;
    }
    return 0;
}
// 清空 `sb`
void strbuf_reset(struct strbuf *sb){
    (*sb).len = 0;
    *(*sb).buf = '\0';

}

int main() {
    struct strbuf sb;
    strbuf_init(&sb, 10);
    strbuf_attach(&sb, "xiyou", 50, 10);
    assert(strcmp(sb.buf, "xiyou") == 0);
    strbuf_addstr(&sb, "linux");
    assert(strcmp(sb.buf, "xiyoulinux") == 0);
    strbuf_release(&sb);
    // printf("%s\n", sb.buf);
    return 0;
}
