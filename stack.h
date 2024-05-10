#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100
// max size is index not length

typedef struct coord {
    int x;
    int y;
    int deed;
} Coords;

typedef struct coordinates {
    Coords coords[MAX_SIZE];
    int top;
} Coordinates;

void mark(char (*arr)[MAX_SIZE], Coordinates *coordinates);
void move_f(Coordinates *coordinates);
void move_b(Coordinates *coordinates);
void move_l(Coordinates *coordinates);
void move_r(Coordinates *coordinates);
int cwf(char arr[][MAX_SIZE], Coordinates *coordinates);
int cwb(char arr[][MAX_SIZE], Coordinates *coordiantes);
int cwl(char arr[][MAX_SIZE], Coordinates *coordinates);
int cwr(char arr[][MAX_SIZE], Coordinates *coordinates);
void push(Coords coord, Coordinates *coordinates);
Coords pop(Coordinates *coordinates);
Coords peek(Coordinates *coordinates);
void clear(Coordinates *coordinates);
bjpi
cjpi
void backtrack
rpnt

#endif