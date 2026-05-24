#include<stdio.h>

#define MAX_TASKS 100
#define MAX_DESC 256

typedef struct {
    char description[MAX_DESC];
    int completed; // 0 = 未完成, 1 = 已完成
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;