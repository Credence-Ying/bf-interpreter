#ifndef TAPE_H
#define TAPE_H

#define TAPE_SIZE 30000

void tape_reset(void);
void tape_move_left(void);
void tape_move_right(void);
void tape_inc(void);
void tape_dec(void);
unsigned char tape_get(void);
void tape_set(unsigned char v);

#endif