#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void mark(char (*arr)[MAX_SIZE], Coordinates *coordinates) { //mark position with pheromone
    Coords current = coordinates->coords[coordinates->top];
    arr[current.x][current.y] = '+'; // Mark current position with '+'
}

void move_f(Coordinates *coordinates) { //move forward one
    coordinates->coords[coordinates->top].x++; //increment x
}

void move_b(Coordinates *coordinates) { //move backward one
    coordinates->coords[coordinates->top].x--; //decrement x
}

void move_l(Coordinates *coordinates) { //move left one
    coordinates->coords[coordinates->top].y--; //decrement y
}

void move_r(Coordinates *coordinates) { //move right one
    coordinates->coords[coordinates->top].y++; //increment y
}

int cwf(char arr[][MAX_SIZE], Coordinates *coordinates) {
    Coords current = coordinates->coords[coordinates->top]; // Access the last element in the array
    for (int i = 1; current.x + i < MAX_SIZE; i++) { // Corrected loop condition
        if (arr[current.x + i][current.y] == '*')
            return 0;
    }
    return 1;
}

int cwb(char arr[][MAX_SIZE], Coordinates *coordinates) { //checks if the next locations in the back are pheromone free
    Coords current = coordinates->coords[coordinates->top];
    int i;
    for (i = 1; current.x - i <= 0; i++) {
        if (arr[current.x - i][current.y] == '*')
            return 0;
    }
    return 1;
}

int cwl(char arr[][MAX_SIZE], Coordinates *coordinates) {
    Coords current = coordinates->coords[coordinates->top]; // Access the last element in the array
    int i;
    for (i = 1; current.y - i >= 0; i++) { // Corrected loop condition
        if (arr[current.x][current.y - i] == '*')
            return 0;
    }
    return 1;
}


int cwr(char arr[][MAX_SIZE], Coordinates *coordinates) { //checks if the next locations to the right are pheromone free
    Coords current = coordinates->coords[coordinates->top];
    int i;
    for (i = 1; current.y + i < 10; i++) {
        if (arr[current.x][current.y + i] == '*')
            return 0;
    }
    return 1;
}

void push(Coords coord, Coordinates *coordinates) {
    coordinates->top += 1;
    coordinates->coords[coordinates->top] = coord;
}

Coords pop(Coordinates *coordinates) {
    Coords temp = coordinates->coords[coordinates->top];
    coordinates->top = coordinates->top - 1;
    return temp;
}

Coords peek(Coordinates *coordinates) {
    return coordinates->coords[coordinates->top];
}

void clear(Coordinates *coordinates) {
    coordinates->top = -1;
}

