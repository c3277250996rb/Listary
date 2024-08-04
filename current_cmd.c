#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("用法: %s <路径>\n", argv[0]);
        return 1;
    }

    char path[256];
    char newPath[256];
    char drive[32];

    // 将程序执行时输入的参数作为路径
    strcpy(path, argv[1]);
    // 查找第一个反斜杠
    char *firstBackslash = strchr(path, '\\');
    // 查找最后一个反斜杠
    char *lastBackslash = strrchr(path, '\\');
    // 查找最后一个点号
    char *lastDot = strrchr(path, '.');

    int isDotLast = !(lastBackslash != NULL && (lastDot == NULL || lastBackslash > lastDot));
    if(lastDot == NULL) {isDotLast = 0;}

    if (firstBackslash != NULL) {
        // 提取第一个反斜杠之前的路径
        strncpy(drive, path, firstBackslash - path);
        drive[firstBackslash - path] = '\0';
    } else {
        // 如果没有反斜杠，则使用当前路径
        strcpy(drive, ".");
    }

    if(isDotLast){
        // 如果最后一个反斜杠更靠后，提取最后一个反斜杠之前的路径
        strncpy(newPath, path, lastBackslash - path);
        newPath[lastBackslash - path] = '\0';
    }else{
        strcpy(newPath, path);
    }

    // 使用系统命令打开命令提示符窗口
    char command[512];
    sprintf(command, "%s && start cmd /k cd \"%s\"", drive, newPath);
    system(command);

    return 0;
}
