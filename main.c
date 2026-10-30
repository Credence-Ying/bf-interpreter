#include <stdio.h>
#include "tape.h"

int main(int argc, char *argv[]) {
    if (argc < 2) { printf("usage: bf <file.bf>\n"); return 1; }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) { printf("cannot open %s\n", argv[1]); return 1; }

    tape_reset();
    int c;
    while ((c = fgetc(fp)) != EOF) {
        switch (c) {
            case '>': tape_move_right(); break; //右移
            case '<': tape_move_left(); break; //左移
            case '+': tape_inc(); break; //增加
            case '-': tape_dec(); break; //减少
            case '.': putchar(tape_get()); break; //输出当前指针指向的值
            case ',': tape_set(getchar()); break; //输入一个值并存储到当前指针指向的位置
            case '[': if (tape_get() == 0) { //如果当前指针指向的值为0，则跳转到对应的']'之后继续执行
                int loop = 1;
                while (loop > 0) {
                    c = fgetc(fp);
                    if (c == EOF) { printf("unmatched '['\n"); return 1; }
                    if (c == '[') loop++;
                    if (c == ']') loop--;
                }
            } break;
            default: break;              /* 空格、换行等非指令字符忽略 */
        }
    }
    fclose(fp);
    return 0;
}
