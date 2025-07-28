# CILFront
A command-line frontend library written in C++.
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
> An easy command-line frontend library.
---
## Features
- Nothing
---
## Warning
- ⚠️ The library is not mature yet.
- ⚠️ This library has only been tested on Windows. Linux and macOS compatibility is not guaranteed.
---
## Usage
```
#include "CILFront.hpp"
```
## Examples
Here’s a quick example to get started:
```cpp
#include "CILFront.hpp"
using namespace CILF;

int main() {
    InitWindow(40, 20);
    SetFPS(60);
    Clear(' ');
    DrawText(5, 4, "Hello, CILFront!");
    EndDrawing();
    return 0;
}
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
