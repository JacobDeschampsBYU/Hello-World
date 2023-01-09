#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

void getString(char * buffer, int bufSize){
    bool confirmed = false;
    int i;
    char character;
    while (!confirmed){
        i = 0;
        do{
            character = getch();
            if (character == 8 && i >= 1){
                printf("%c", '\b');
                i--;
                printf(" ");
                printf("%c", '\b');
            }
            else if(character > 31 && character < 127 && i < bufSize - 1){
                buffer[i] = character;
                i++;
                printf("%c", character);
            }
        }while (character != 13);
        buffer[i] = 0;
        if (strlen(buffer) > 0){
            confirmed = true;
            printf("\n");
        }
    }
    return;
}

void wait(void){
    char key = 0;
    while (key != 13){
        key = getch();
    }
    return;
}

void clearScreen(void){
    printf("\e[1;1H\e[2J");
    return;
}

int main(int argc, char ** argv){
    char name[50];
    puts("Please enter your name: ");
    getString(name, 50);
    clearScreen();
    char message[71] = "Well, ";
    strcat(message, name);
    strcat(message, ", Hello World!");
    puts(message);
    puts("\n\nPress [ENTER] to exit.");
    wait();
    return EXIT_SUCCESS;
}