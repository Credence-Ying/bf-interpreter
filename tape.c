//我正在写一台机器用于执行脑图灵机的程序，这个程序使用C语言编写,遵循C23标准。以下是tape.c文件的实现代码，其中包含了对tape数组的操作函数。

#include <string.h>
#include "tape.h"

static unsigned char tape[TAPE_SIZE];
static int head = 0;

//reset是初始化函数，memset是C语言的一个函数，用于将一段内存空间的内容全部设置为指定的值。
//此处memset(tape, 0, sizeof tape)的作用是将tape数组中的所有元素都设置为0，从而实现对tape的初始化
void tape_reset(void) {
    memset(tape, 0, sizeof tape);   /* 示例：这一条我写给你，其余照这个风格自己写 */
    head = 0;
}

void tape_move_left(void) {
    /* TODO: head 左移；若 head 已是 0，则绕回 TAPE_SIZE-1 */ 
    if (head == 0) head = TAPE_SIZE - 1;
    else head--;
}

void tape_move_right(void) {
    /* TODO: head 右移；若 head 已是 TAPE_SIZE-1，则绕回 0 */ 
    if (head == TAPE_SIZE - 1) head = 0;
    else head++;
}

void tape_inc(void) {
    /* TODO: tape[head]++ */
    tape[head]++;
}

void tape_dec(void) {
    /* TODO: tape[head]-- */
    tape[head]--;
}

unsigned char tape_get(void) {
    /* TODO: return tape[head] */
    return tape[head];
}

void tape_set(unsigned char v) {
    /* TODO: tape[head] = v */ 
    tape[head] = v;
}
