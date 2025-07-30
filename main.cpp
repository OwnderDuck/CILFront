#include"CILFront.hpp"
using namespace std;
using namespace CILF;
int main(){
	InitWindow(GetWidth(),GetHeight());
	while(1){
		Clear(' ');
		
		DrawLine(0, 0,screenWidth-1,screenHeight-1,'\\');
		DrawLine(0,screenHeight-1,screenWidth-1,0,'/');
		DrawBox(0,0,screenWidth-1,screenHeight-1,'+','\r');
		DrawLine(0,0,screenWidth/2,0,'>');
		DrawLine(screenWidth/2,0,screenWidth-1,0,'<');
		DrawText((screenWidth-strlen("CILFront"))/2,0,"CILFront");
		DrawBox(screenWidth*0.4,screenHeight*0.4,screenWidth*0.6,screenHeight*0.6,'#','>');
		DrawText(screenWidth*0.4+1,screenHeight*0.4+1," Hello,  ");
		DrawText(screenWidth*0.4+1,screenHeight*0.4+2," CILFront!!!  ");
		DrawBox(screenWidth*0.4+1, screenHeight *0.4+3, screenWidth *0.6-1, screenHeight * 0.4+4, '<', '<');
		DrawText(screenWidth*0.4+10,screenHeight*0.4+5,"   -OwnderDuck");
		EndDrawing();
	}
	return 0;
}
