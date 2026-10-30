# bf-interpreter

用 C 写的 Brainfuck 解释器（图灵机模型：一条 30000 格纸带 + 一个读写头）。

## 编译与运行
gcc -Wall -o bf.exe main.c tape.c
./bf.exe test.bf

## 进度
- [x] 八条指令中的六条（> < + - . ,）
- [ ] 循环 [ ]
