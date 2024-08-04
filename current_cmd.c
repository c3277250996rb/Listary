#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("�÷�: %s <·��>\n", argv[0]);
        return 1;
    }

    char path[256];
    char newPath[256];
    char drive[32];

    // ������ִ��ʱ����Ĳ�����Ϊ·��
    strcpy(path, argv[1]);
    // ���ҵ�һ����б��
    char *firstBackslash = strchr(path, '\\');
    // �������һ����б��
    char *lastBackslash = strrchr(path, '\\');
    // �������һ�����
    char *lastDot = strrchr(path, '.');

    int isDotLast = !(lastBackslash != NULL && (lastDot == NULL || lastBackslash > lastDot));
    if(lastDot == NULL) {isDotLast = 0;}

    if (firstBackslash != NULL) {
        // ��ȡ��һ����б��֮ǰ��·��
        strncpy(drive, path, firstBackslash - path);
        drive[firstBackslash - path] = '\0';
    } else {
        // ���û�з�б�ܣ���ʹ�õ�ǰ·��
        strcpy(drive, ".");
    }

    if(isDotLast){
        // ������һ����б�ܸ�������ȡ���һ����б��֮ǰ��·��
        strncpy(newPath, path, lastBackslash - path);
        newPath[lastBackslash - path] = '\0';
    }else{
        strcpy(newPath, path);
    }

    // ʹ��ϵͳ�����������ʾ������
    char command[512];
    sprintf(command, "%s && start cmd /k cd \"%s\"", drive, newPath);
    system(command);

    return 0;
}
