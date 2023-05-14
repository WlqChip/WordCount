#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0;

    if (argc != 3) {
        printf("参数错误\n");
        return 0;
    }

    if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-w") != 0) {
        printf("参数错误\n");
        return 0;
    }

    strcpy(filename, argv[2]);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("无法打开文件\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        charCount++;

        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == ',') {
            wordCount++;
        }
    }

    fclose(fp);

    if (strcmp(argv[1], "-c") == 0) {
        printf("字符数：%d\n", charCount);
    } else {
        printf("单词数：%d\n", wordCount+1);
    }

    return 0;
}