#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include <stdlib.h>

using namespace std;
int main(){
    char mainmenu, submenu, cont;
    signed short s1, s2, s3, s4;
    int i;
    signed int mul;
    do {
        i=0;
        s1=0;
        s2=0;
        s3=0;
        s4=0;
        
        system("cls");
        printf ("Choose an option below\n");
        printf ("1. 16-bit Integer Arithmetic Operation\n");
        printf ("2. Exit\n");
        
        cin >> mainmenu;
        
        if (mainmenu=='1') {
            system("cls");
            printf ("Menu:\n");
            printf ("Choose an option below or exit\n\n");
            printf ("1. Addition with two signed numbers, displayed in DECIMAL and HEX.\n");
            printf ("2. Subtraction with two signed numbers, displayed in DECIMAL and HEX.\n");
            printf ("3. Multiplication with two signed numbers, displayed in DECIMAL and HEX.\n");
            printf ("4. Division with two signed numbers, displayed in DECIMAL and HEX.\n");
            printf ("5. Go back to Main Menu.\n");
        }
        
        else if (mainmenu =='2') {
            return 0;
        }
        
        cin >> submenu;
        
        switch (submenu) {
            case '1':
                system("cls");
                printf("ADDITION!\n\n");
                printf("Input your first integer.\n");
                cin >> s1;
                printf("Input your second integer.\n");
                cin >> s2;
                printf("\n");
                _asm
            {
                MOV AX, s1;
                MOV BX, s2;
                ADD AX, BX;
                MOV s3, AX;
            }
                
                printf ("Your addition is %d in DECIMAL form and 0x%X HEX form!\n\n", s3, s3);
                i = 1;
                break;
            case '2':
                system("cls");
                printf("SUBTRACTION!\n\n");
                printf("Input your first integer.\n");
                cin >> s1;
                printf("Input your second integer.\n");
                cin >> s2;
                printf("\n");
                _asm
            {
                MOV AX, s1;
                MOV BX, s2;
                SUB AX, BX;
                MOV s3, AX;
            }
                
                printf ("Your subtraction is %d in DECIMAL form and 0x%X HEX form!\n\n", s3, s3);
                i = 1;
                break;
            case '3':
                system("cls");
                printf("MULTIPLICATION!\n\n");
                printf("Input your first integer.\n");
                scanf_s ("%d", &s1);
                //cin >> s1;
                printf("Input your second integer.\n");
                scanf_s ("%d", &s2);
                printf("\n");
                //cin >> s2;
                _asm
            {
                MOV AX, s1;
                MOV BX, s2;
                IMUL BX;
                MOVSX EBX, DX;
                SAL EBX, 16;
                MOVSX ECX, AX;
                OR EBX, ECX;
                MOV mul, EBX;
                //MOV s3, AX;
                //MOV s4, DX;
            }
                printf ("Your multiplication is %d in DECIMAL form!\n", mul);
                cout << "Your multiplication in HEX is " << std::hex << mul<< '\n' << '\n';
                i = 1;
                break;
            case '4':
                system("cls");
                printf("DIVISION!\n\n");
                printf("Input your first integer.\n");
                scanf_s ("%d", &s1);
                //cin >> s1;
                printf("Input your second integer.\n");
                scanf_s ("%d", &s2);
                //cin >> s2;
                printf("\n");
                _asm
            {
                MOV AX, s1;
                CWD;
                MOV BX, s2;
                IDIV BX;
                MOV s3, AX;
                MOV s4, DX;
            }
                printf ("Your quotient is %d and your remainder is %d in DECIMAL form!\n", s3, s4);
                cout << "Your quotient is "  << std::hex << s3<<" and your remainder is "<<s4<< " in HEX form!" << '\n' << '\n';
                i = 1;
                break;
            case '5':
                system("cls");
                cont = '1';
                break;
            default:
                printf("Invalid option! Program quitting.\n");
                break;
        }
        if (i == 1)
        {
            printf ("Choose an option below or exit\n\n");
            printf ("1. Perform a new operation\n");
            printf ("2. Quit program.\n");
            cin >> cont;
        }
    }
    while(cont == '1');
    
    return 0;
}