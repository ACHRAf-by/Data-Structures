

#ifndef PILES_WITHFILE_H
#define PILES_WITHFILE_H
#define MAX_FLNM 100


typedef struct s_stack {
    char filename[MAX_FLNM];
    int fd; // file descriptor of the open file
    int top_off; // final offset
} t_stack;

void set_file(t_stack *, const char *); // special function to determine the file to be used

void delete_file(const char *);


void init_stack(t_stack *); // initalize the data structure
int push_stack(t_stack *, int); // push value into stack
int pop_stack(t_stack *, int *); // pops top value from stack
int top_stack(t_stack *); // returns top value of stack
void display_stack(t_stack *); // displays the contents of the stack

#endif //PILES_WITHFILE_H
