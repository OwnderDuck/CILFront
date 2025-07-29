# CILFront
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A command-line frontend library written in C++.\
C++命令行前端库。

> An easy command-line frontend library.\
> 一个简单C++命令行前端库。
---
## Features/特性
- "The character '\r' is used to represent transparency./用'\r'代表透明色。
- Nothing./没有。
---
## Warning/警告
- The library is not mature yet./该库不够成熟。
- This library has only been tested on Windows. Linux and macOS compatibility is not guaranteed./该库仅在 Windows 上进行了测试。不保证 Linux 和 macOS 的兼容性。
- Some functions lack bounds checking./某些函数缺少边界检查。
- Certain functions are deprecated; please refer to the [Docs](docs.md) for more information./部分函数已弃用，详情见[文档](docs.md)。
- Support for non-ASCII characters is not guaranteed./不保证对非ASCII字符的支持性。
---
## Usage/用法
`#include "CILFront.hpp"`
## Examples/示例
Here’s a quick example to get started:\
这是一个快速入门示例：
```cpp
#include"CILFront.hpp"
using namespace std;
using namespace CILF;
int main(){
	InitWindow(GetWidth(),GetHeight());
	while(1){
		Clear(' ');
		DrawLine(0, 0,GetWidth()-1,GetHeight()-1,'\\');
		DrawLine(0,GetHeight()-1,GetWidth()-1,0,'/');
		DrawBox(0,0,GetWidth()-1,GetHeight()-1,'+','\r');
		DrawLine(0,0,GetWidth()/2,0,'>');
		DrawLine(GetWidth()/2,0,GetWidth()-1,0,'<');
		DrawText((GetWidth()-strlen("CILFront"))/2,0,"CILFront");
		DrawBox(GetWidth()*0.4,GetHeight()*0.4,GetWidth()*0.6,GetHeight()*0.6,'#','>');
		DrawText(GetWidth()*0.4+1,GetHeight()*0.4+1," Hello,  ");
		DrawText(GetWidth()*0.4+1,GetHeight()*0.4+2," CILFront!!!  ");
		DrawBox(GetWidth()*0.4+1, GetHeight() *0.4+3, GetWidth() *0.6-1, GetHeight() * 0.4+4, '<', '<');
		DrawText(GetWidth()*0.4+10,GetHeight()*0.4+5,"   -OwnderDuck");
		EndDrawing();
	}
	return 0;
}
```
Here’s what it looks like:\
它看起来像这样：
```
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CILFront<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
+  \\\\                                                                                                          ////  +
+      \\\\                                                                                                  ////      +
+          \\\\                                                                                          ////          +
+              \\\\                                                                                  ////              +
+                  \\\\                                                                          ////                  +
+                      \\\\                                                                  ////                      +
+                          \\\\                                                          ////                          +
+                              \\\\                                                  ////                              +
+                                  \\\\                                          ////                                  +
+                                      \\\\\                                /////                                      +
+                                           \\\\                        ////                                           +
+                                               #########################                                              +
+                                               # Hello,  >>>>>>>>>>>>>>#                                              +
+                                               # CILFront!!!  >>>>>>>>>#                                              +
+                                               #<<<<<<<<<<<<<<<<<<<<<<<#                                              +
+                                               #<<<<<<<<<<<<<<<<<<<<<<<#                                              +
+                                               #>>>>>>>>>   -OwnderDuck#                                              +
+                                           ////#########################\\\                                           +
+                                      /////                                \\\\\                                      +
+                                  ////                                          \\\\                                  +
+                              ////                                                  \\\\                              +
+                          ////                                                          \\\\                          +
+                      ////                                                                  \\\\                      +
+                  ////                                                                          \\\\                  +
+              ////                                                                                  \\\\              +
+          ////                                                                                          \\\\          +
+      ////                                                                                                  \\\\      +
+  ////                                                                                                          \\\\  +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
```
---
## API Reference/API 参考
see [Docs](docs.md)\
看 [文档](docs.md)
---
## License
This project is licensed under the **MIT License** — see [LICENSE](LICENSE) for full terms.
### Platform Dependencies
- **Windows API headers** – governed by Microsoft Windows SDK License  
- **POSIX headers** (`unistd.h`, `term.h`, etc.) – typically BSD/MIT-style system licenses  
- **C/C++ Standard Library** – provided by the compiler runtime
### Copyright
Copyright (c) 2025 OwnderDuck
## Future Plans / 未来计划
- Optimize graphics rendering performance./图形绘制性能优化。
- Internationalize documentation./文档国际化。
- Provide a more comprehensive API./提供更丰富的 API。
- Fix all warnings./修复所有警告。
