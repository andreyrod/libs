/*
 * Creator: Andrey da Silva Rodrigues
 * Version: 0.1
 * Date: 2018-04-18
 * License: unlicensed
 * Origem: github.com/andreyrod/libs
 */
#include "andlib.h"

char lgetch(void){
        struct termios velho, novo;
        int x;

        tcgetattr( STDIN_FILENO, &velho );
        novo= velho;
        novo.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &novo );
        x= getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &velho );
        return x;
}