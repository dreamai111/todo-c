#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_DESC 256

//typedef {原类型} 新别名
//typedef 是 C 语言里用来给已有类型起个别名的关键字
//它的作用就是让复杂的类型名变得更短、更好理解
//我定义了一个结构体 Task 来表示任务，可以直接使用 Task 来声明变量
typedef struct {
    char description[MAX_DESC];
    // 0 = 未完成，1 = 已完成
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task() {
    //检查是否已满
    if (task_count >= MAX_TASKS) {
        printf("待办列表已满，无法添加！\n");
        return;
    }

    //获取用户输入
    //这个 . 是结构体成员访问运算符，用来访问结构体变量的成员
    printf("请输入新的待办描述：");
    fgets(tasks[task_count].description, MAX_DESC, stdin);

    //去掉输入末尾的换行符
    //删不删好像无所谓，删了好看些
    size_t len = strlen(tasks[task_count].description);
    if (len > 0 && tasks[task_count].description[len - 1] == '\n') {
        tasks[task_count].description[len - 1] = '\0';
    }

    //设置为未完成
    tasks[task_count].completed = 0;

    //总数加一
    task_count++;

    printf("已添加待办事项。\n");
}