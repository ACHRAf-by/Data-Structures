
#include "WithFile.h"

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void set_file(t_stack *stack, const char *filename) {
    strcpy(stack->filename, filename);
    stack->fd = open(stack->filename, O_RDWR | O_CREAT, 0777);
    if (stack->fd == -1) {
        fprintf(stderr , "Error while opening|creating the file " );
    }
}

void init_stack(t_stack *stack) {
    stack->top_off = lseek(stack->fd, 0, SEEK_END);
}

int push_stack(t_stack *stack, int val) {
    lseek(stack->fd, stack->top_off, SEEK_SET);
    write(stack->fd, &val, sizeof(int));
    stack->top_off += sizeof(int);
    return 1;
}

int pop_stack(t_stack *stack, int *val) {
    if (stack == NULL || stack->top_off == 0) {
        return 0;
    }
    lseek(stack->fd, stack->top_off - sizeof(int), SEEK_SET);
    read(stack->fd, val, sizeof(int));
    stack->top_off -= sizeof(int);
    return 1;
}

int top_stack(t_stack *stack) {
    if (stack == NULL || stack->top_off == 0) {
        return (0);
    }
    int val;

    lseek(stack->fd, 0 , SEEK_SET);
    read(stack->fd, &val, sizeof(int));

    return val;
}

void display_stack(t_stack *stack) {
    lseek(stack->fd, 0, SEEK_SET);
    int val;
    while (!eof(stack->fd)){
        read(stack->fd , &val , sizeof(int));
        printf("%d -> " , val);
    }
    printf("\n");
}

void delete_file(const char * filename){
    //unlink(filename)
    if(remove(filename) != 0 ){
       perror("While deleting the file");
    }
    else    printf("The file is removed successfully \n");
}
