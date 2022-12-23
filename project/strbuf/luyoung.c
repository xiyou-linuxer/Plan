#include <assert.h>
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
    char* temp = (char*)malloc(sizeof(char) * (alloc));
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
        sb->alloc <<= 1;  // 扩充,增加速度
    }
    // 刷新新的字符串
    char* new_alloc = (char*)malloc(sizeof(char) * (*sb).alloc);
    strcat(new_alloc, (*sb).buf);
    printf("1%s\n", new_alloc);
    strcat(new_alloc, str);
    printf("2%s\n", new_alloc);
    (*sb).buf = new_alloc;
}
// 释放 `sb` 结构体的内存
void strbuf_release(struct strbuf* sb) {
    if (sb->alloc > 0) {
        free(sb->buf);
        strbuf_init(sb, 0);
    }
}
// 交换两个 strbuf  (利用C语言自身特性)
void strbuf_swap(struct strbuf* a, struct strbuf* b) {
    struct strbuf temp = *a;
    *a = *b;
    *b = temp;
}
// 将 `sb` 中的原始内存取出，并将 `sz` 设置为其 `alloc` 大小
char* strbuf_detach(struct strbuf* sb, size_t* sz) {
    *sz = (*sb).alloc;
    char* ret = (char*)malloc(sizeof(char) * ((*sb).len) + 1);
    strcpy(ret, sb->buf);
    return ret;
}
// 比较两个 strbuf 的内存是否相同
int strbuf_cmp(const struct strbuf* first, const struct strbuf* second) {
    if (first->buf == second->buf) {
        return 1;
    }
    return 0;
}
// 清空 `sb`
void strbuf_reset(struct strbuf* sb) {
    (*sb).len = 0;
    *(*sb).buf = '\0';
}

// Part 2B

// 确保在 `len` 之后 `strbuf` 中至少有 `extra` 个字节的空闲空间可用
void strbuf_grow(struct strbuf* sb, size_t extra) {
    int sb_left = sb->alloc-sb->len;
    if(sb_left < extra){

    }
}
// 向 `sb` 追加长度为 `len` 的数据 `data`
void strbuf_add(struct strbuf* sb, const void* data, size_t len) {}
// 向 `sb` 追加一个字符 `c`
void strbuf_addch(struct strbuf* sb, int c) {}
// 向 `sb` 追加一个字符串 `s`
void strbuf_addstr(struct strbuf* sb, const char* s) {}
// 向一个 `sb` 追加另一个 `strbuf`的数据
void strbuf_addbuf(struct strbuf* sb, const struct strbuf* sb2) {}
// 设置 `sb` 的长度 `len`
void strbuf_setlen(struct strbuf* sb, size_t len) {}
// 计算 `sb` 目前仍可以向后追加的字符串长度
size_t strbuf_avail(const struct strbuf* sb) {}
// 向 `sb` 内存坐标为 `pos` 位置插入长度为 `len` 的数据 `data`
void strbuf_insert(struct strbuf* sb,
                   size_t pos,
                   const void* data,
                   size_t len) {}
// Part 2C

// 去除 `sb` 缓冲区左端的所有 空格，tab, '\t'
void strbuf_ltrim(struct strbuf* sb) {}
// 去除 `sb` 缓冲区右端的所有 空格，tab, '\t'
void strbuf_rtrim(struct strbuf* sb) {}
// 删除 `sb` 缓冲区从 `pos` 坐标长度为 `len` 的内容
void strbuf_remove(struct strbuf* sb, size_t pos, size_t len) {}
// `sb` 增长 `hint ? hint : 8192` 大小， 然后将文件描述符为 `fd`
// 的所有文件内容追加到 `sb` 中
ssize_t strbuf_read(struct strbuf* sb, int fd, size_t hint) {}
// 将文件句柄为 `fp` 的一行内容（抛弃换行符）读取到 `sb`
int strbuf_getline(struct strbuf* sb, FILE* fp) {}
// CHALLENGE

// 将长度为 `len` 的字符串 `str` 根据切割字符 `terminator` 切成多个 strbuf,
// 并从结果返回，max 可以用来限定最大切割数量。返回 `struct strbuf`
// 的指针数组，数组的最后元素为 `NULL`
struct strbuf** strbuf_split_buf(const char* str,
                                 size_t len,
                                 int terminator,
                                 int max) {}
// target_str : 目标字符串，str : 前缀字符串，strlen : target_str 长度
// ，前缀相同返回 true 失败返回 false
bool strbuf_begin_judge(char* target_str, const char* str, int strlen) {}
// target_str : 目标字符串，begin : 开始下标，end 结束下标。len :
// target_buf的长度， 参数不合法返回 NULL. 下标从0开始，[begin, end)区间
char* strbuf_get_mid_buf(char* target_buf, int begin, int end, int len) {}

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