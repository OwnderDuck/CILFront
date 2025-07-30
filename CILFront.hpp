//Copyright (c) 2025 OwnderDuck
//SPDX-License-Identifier: MIT
#include<stdio.h>
#include<iostream>
#include <sysinfoapi.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <term.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#endif
namespace CILF{
    char screenBuffer[514][514];
    int FPS=114514;
    int screenWidth=20,screenHeight=10;
    /*
    bool IsKeyPressed(int vk_code){
        return (GetAsyncKeyState(vk_code) & 0x8000)?1:0;
    }
    */
   int GetWidth() {
#ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns = 80;
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        if (GetConsoleScreenBufferInfo(hStdout, &csbi)) {
            columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        }
        return columns;
#else
        struct winsize w;
        int columns = 80;
        if(ioctl(0, TIOCGWINSZ, &w) == 0) {
            columns = w.ws_col;
        }
        return columns;
#endif
    }
    int GetHeight() {
#ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int rows = 25;
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        if (GetConsoleScreenBufferInfo(hStdout, &csbi)) {
            rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        }
        return rows;
#else
        struct winsize w;
        int rows = 25;
        if(ioctl(0, TIOCGWINSZ, &w) == 0) {
            rows = w.ws_row;
        }
        return rows;
#endif
    }
    void HideCursor(){
#ifdef _WIN32
        HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole,&cursorInfo);
        cursorInfo.bVisible=FALSE;
        SetConsoleCursorInfo(hConsole,&cursorInfo);
#else
        std::cout << "\033[?25l" << std::flush;
#endif
    }
    void MoveCursor(int x,int y) {
        
        y<<=1;
#ifdef _WIN32
	    // Windows实现
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hConsole == INVALID_HANDLE_VALUE) {
            fprintf(stderr, "无法获取控制台句柄\n");
		}
		
		COORD coord;
		coord.X = static_cast<SHORT>(x);
		coord.Y = static_cast<SHORT>(y);
		
		if (!SetConsoleCursorPosition(hConsole, coord)) {
            fprintf(stderr, "无法设置光标位置\n");
		}
#else
		// Linux/macOS实现
		std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
		std::cout.flush();
#endif
}
    void InitWindow(int initWindowScreenWidth,int initWindowScreenHeight){
        screenWidth=initWindowScreenWidth,screenHeight=initWindowScreenHeight;
        HideCursor();
        MoveCursor(0, 0);
        for(int i=0;i<GetHeight();i++){
            for(int j=0;j<GetWidth();j++){
                putchar(' ');
            }
			putchar('\n');
        }
        return ;
    }
    void SetFPS(int setFPS){
        FPS=setFPS;
    }
    /*
    bool WindowClose(){
        return IsKeyPressed(VK_ESCAPE)
    }
    */
    void Clear(char backgroundChar) {
        for(int i=0;i<screenHeight;i++){
			for(int j=0;j<screenWidth;j++){
				screenBuffer[j][i]=backgroundChar;
			}
		}
    }
    void EndDrawing(){
        MoveCursor(0, 0);
        for(int i=0;i<screenHeight-1;i++){
            for(int j=0;j<screenWidth+1;j++){
                putchar(screenBuffer[j][i]);
            }
			putchar('\n');
        }
        for(int j=0;j<screenWidth+1;j++){
            putchar(screenBuffer[j][screenHeight-1]);
        }
    }
    void DrawPixel(int x, int y, char ch) {
        screenBuffer[x][y] = ch;
    };
    void DrawBox(int x1, int y1, int x2, int y2, char boxChar,char fillChar) {
        if(boxChar!='\r'){
            for (int i = x1; i <= x2; i++) {
                screenBuffer[i][y1] = boxChar; // 上边框
                screenBuffer[i][y2] = boxChar; // 下边框
            }
            for (int j = y1; j <= y2; j++) {
                screenBuffer[x1][j] = boxChar; // 左边框
                screenBuffer[x2][j] = boxChar; // 右边框
            }
        }
        if(fillChar!='\r'){
            for (int i = x1 + 1; i < x2; i++) {
                for (int j = y1 + 1; j < y2; j++) {
                    screenBuffer[i][j] = fillChar; // 填充区域
                }
            }
        }
    }
    void DrawLine(int x1, int y1, int x2, int y2, char lineChar) {
        if (lineChar != '\r') {
            int dx = abs(x2 - x1), dy = abs(y2 - y1);
            int sx = x1 < x2 ? 1 : -1;
            int sy = y1 < y2 ? 1 : -1;
            int err = dx - dy;
            int x = x1, y = y1;
            while (true) {
                if (x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
                    screenBuffer[x][y] = lineChar;
                if (x == x2 && y == y2) break;
                int e2 = 2 * err;
                if (e2 > -dy) { err -= dy; x += sx; }
                if (e2 < dx)  { err += dx; y += sy; }
            }
        }
    }
    void DrawCircle(int centerX, int centerY, int radius, char circleChar, char fillChar) {
        if (circleChar == '\r' && fillChar == '\r') return;
        int x = 0, y = radius;
        int d = 1 - radius;
        while (y >= x) {
            // 画圆边
            if (circleChar != '\r') {
                DrawPixel(centerX + x, centerY + y, circleChar);
                DrawPixel(centerX - x, centerY + y, circleChar);
                DrawPixel(centerX + x, centerY - y, circleChar);
                DrawPixel(centerX - x, centerY - y, circleChar);
                DrawPixel(centerX + y, centerY + x, circleChar);
                DrawPixel(centerX - y, centerY + x, circleChar);
                DrawPixel(centerX + y, centerY - x, circleChar);
                DrawPixel(centerX - y, centerY - x, circleChar);
            }
            // 填充圆内部
            if (fillChar != '\r') {
                for (int i = centerX - x + 1; i < centerX + x; ++i) {
                    DrawPixel(i, centerY + y, fillChar);
                    DrawPixel(i, centerY - y, fillChar);
                }
                for (int i = centerX - y + 1; i < centerX + y; ++i) {
                    DrawPixel(i, centerY + x, fillChar);
                    DrawPixel(i, centerY - x, fillChar);
                }
            }
            if (d < 0) {
                d += 2 * x + 3;
            } else {
                d += 2 * (x - y) + 5;
                y--;
            }
            x++;
        }
    }
    void DrawText(int x, int y, std::string text){
        for (size_t i = 0; i < text.length(); i++) {
            if (x + i >= 0 && x + i < screenWidth && y >= 0 && y < screenHeight) {
                screenBuffer[x + i][y] = text[i];
            }
        }
    }
    

    
    int GetDelayTime() {
    static long long lastTime = 0;
    long long nowTime = 0;
#ifdef _WIN32
    nowTime = GetTickCount();
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    nowTime = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
#endif
    int delay = (lastTime == 0) ? 0 : static_cast<int>(nowTime - lastTime);
    lastTime = nowTime;
    return delay;
    }
}
