#ifndef OI_PRINTSTYLED
#define OI_PRINTSTYLED
#include "../base/base.h"
namespace OIalgo{
/*
名字来源于julia语言的printstyled函数
部分操作系统可能不支持
参考文献：
1. [vt100](http://ascii-table.com/ansi-escape-sequences-vt-100.php)
2. [windows的支持](https://docs.microsoft.com/zh-CN/windows/console/console-virtual-terminal-sequences)
*/
void PrintStyledInit(){
#ifdef _WIN32
    system("");// windows特性
#endif
}

enum PrintStyledColor{
/*
D=Dark,L=light ; F=font-color,B=background-color
*/
    PLAIN=0,
    DF_BLACK=30,
    DF_RED,
    DF_GREEN,
    DF_YELLOW,
    DF_BLUE,
    DF_MAGENTA,// 紫红
    DF_CYAN,// 青
    DF_WHITE,
    F_EXPAND,// 前景扩展色
    F_DEFAULT,// 前景默认色
    DB_BLACK=40,
    DB_RED,
    DB_GREEN,
    DB_YELLOW,
    DB_BLUE,
    DB_MAGENTA,
    DB_CYAN,
    DB_WHITE,
    B_EXPAND,// 背景扩展色
    B_DEFAULT,// 背景默认色
    LF_BLACK=90,
    LF_RED,
    LF_GREEN,
    LF_YELLOW,
    LF_BLUE,
    LF_MAGENTA,
    LF_CYAN,
    LF_WHITE,
    LB_BLACK=100,
    LB_RED,
    LB_GREEN,
    LB_YELLOW,
    LB_BLUE,
    LB_MAGENTA,
    LB_CYAN,
    LB_WHITE,
};

void SetPrintStyled(PrintStyledColor x){
    cout<<"\033["<<u_to_string<PrintStyledColor>(x)<<"m";
}

void PrintStyled(string text,PrintStyledColor color){
    SetPrintStyled(color);
    cout<<text;
    SetPrintStyled(PLAIN);
}

// 常见控制台跨平台工具
void ClearScreen(){
#ifdef _WIN32
    system("cls");
#endif
#ifndef _WIN32
    system("clear");
#endif
}

void CharsetUtf8(){
#ifdef _WIN32
    system("chcp 65001");
#endif
}

};
#endif
