#include <stdio.h>
#include <string.h>

const int line_width = 1024;

void swap(int size, char *line) {
    int i = 0, j;
    char b;
    while (i < size) {
        while (line[i] == ' ')
            i++;
        j = i + 1;
        while (line[j] == ' ')
            j++;
        if (j >= size) 
            break;
        b = line[i];
        line[i] = line[j];
        line[j] = b;
        i = j + 1;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[] = "input.txt";
    char outputFileName[] = "output.txt";

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла %s.\n", inputFileName);
        return 1;
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Ошибка открытия файла %s.\n", outputFileName);
        fclose(inputFile);
        return 1;
    }


    char line[line_width];
    while (fgets(line, line_width, inputFile) != NULL) {
        int size = strlen(line);
        swap(size, line);
        fprintf(outputFile, "%s", line);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Результат записан в файл %s.\n", outputFileName);

    return 0;
}
