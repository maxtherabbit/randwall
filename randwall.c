#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <wdefwin.h>

int main(int argc, char *argv[])
{
    unsigned short size = 0;
    unsigned char numDigits = 0;
    unsigned char currentPaper = 0;
    unsigned char maxPapers;
    unsigned char newPaper;
    unsigned char index;
    char wallpaper[255];

    srand(time(0));

    if (argc!=2)
    {
        printf("Invoke with exactly one argument - the total number of wallpapers!\n");
        return -1;
    }

    maxPapers = atoi(argv[1]);

    if (!maxPapers)
    {
        printf("Argument must be a number (total wallpapers)!");
        return -1;
    }
    printf("Total wallpapers is %u\n", maxPapers);
    
    size = GetProfileString("Desktop", "Wallpaper", NULL, wallpaper, 255);

    if ((!size) || (size > 252) || (tolower(wallpaper[size-1]) != 'p'))
    {
        printf("Invalid wallpaper or path too long!\n");
        return -1;
    }   
    printf("Current wallpaper is:\n%s\n", wallpaper);

    index = size - 5;
    
    while (isdigit(wallpaper[index]))
    {
        numDigits++;
        index--;
    }
    index++;

    if (numDigits)
        currentPaper = atoi(wallpaper+index);

    do
        newPaper = rand()%maxPapers + 1;
    while (newPaper == currentPaper);
    
    sprintf(wallpaper+index, "%u.BMP", newPaper);
    printf("Next wallpaper is:\n%s\n", wallpaper);

    WriteProfileString("Desktop", "Wallpaper", wallpaper);
    
    _dwShutDown();
    return 0;
}
