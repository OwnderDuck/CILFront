# CILFront
A command-line frontend library written in C++.
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
> An easy command-line frontend library.
---
## Features
- Nothing.
---
## Warning
- ⚠️ The library is not mature yet.
- ⚠️ This library has only been tested on Windows. Linux and macOS compatibility is not guaranteed.
- ⚠️ Some functions may suffer from boundary-related issues as they currently lack bounds checking.
---
## Usage
`#include "CILFront.hpp"`
## Examples
Here’s a quick example to get started:
```cpp
#include"CILFront.hpp"
using namespace std;
using namespace CILF;
int main(){
	InitWindow(GetWidth(),GetHeight());
	while(1){
		Clear(' ');
		DrawLine(0,0,GetWidth()-1,GetHeight()-1,'\\');
		DrawLine(0,GetHeight()-1,GetWidth()-1,0,'/');
		DrawBox(0,0,GetWidth()-1,GetHeight()-1,'+','\r');
		DrawTitle("CILFront",'-');
		DrawBox(GetWidth()*0.4,GetHeight()*0.4,GetWidth()*0.6,GetHeight()*0.6,'#','>');
		DrawText(GetWidth()*0.4+1,GetHeight()*0.4+2," Hello,  ");
		DrawText(GetWidth() *0.4+1,GetHeight()*0.4+4," CILFront!!!  ");
		DrawBox(GetWidth()*0.4+1,GetHeight()*0.4+6,GetWidth()*0.6-1,GetHeight()*0.4+8,'<','<');
		DrawText(GetWidth()*0.4+10,GetHeight()*0.4+10,"   -OwnderDuck");
		EndDrawing();
	}
	return 0;
}
```
Here’s what it looks like:
```
--------------------------------------------------------CILFron---------------------------------------------------------
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
## API Reference
see [API docs](API.md)
---
## License
This project is licensed under the **MIT License** — see [LICENSE](LICENSE) for full terms.
### Platform Dependencies
- **Windows API headers** – governed by Microsoft Windows SDK License  
- **POSIX headers** (`unistd.h`, `term.h`, etc.) – typically BSD/MIT-style system licenses  
- **C/C++ Standard Library** – provided by the compiler runtime
### Copyright
Copyright (c) 2025 OwnderDuck
