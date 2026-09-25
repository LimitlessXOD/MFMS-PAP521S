#ifndef COMMON_H
#define COMMON_H

#define MAX_EMPLOYEES   100
#define MAX_SUPPLIERS   100
#define MAX_ASSETS      100
#define MAX_DEPARTMENTS 20
#define MAX_NAME_LEN    50
#define MAX_LINE_LEN    100

/* Clears leftover characters in stdin after a bad or partial scanf read.
   Used everywhere so a non-numeric menu choice never causes an infinite loop. */
void clearInputBuffer(void);

/* Reads a line of text into buffer safely (strips trailing newline). */
void readLine(char *buffer, int size);

#endif
