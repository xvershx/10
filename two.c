#include <stdio.h>
#include <string.h>

const int line_width = 1024;

void delspace(int size, char *line) {
    int i = 0, j = 0;
    char pred = '\0';
    while (i < size) {
       
        if (j == 0 && line[i] == ' ') {
            i++;
            continue;
        }
      
        if (pred == ' ' && line[i] == ' ') {
            i++;
            continue;
        }
     
        line[j++] = line[i++];
 
        pred = line[j-1];
    }

    line[j] = '\0';
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[] = "tinput.txt";
    char outputFileName[] = "toutput.txt";

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
        delspace(size, line);
        fprintf(outputFile, "%s", line);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Результат записан в файл %s.\n", outputFileName);

    return 0;
}
