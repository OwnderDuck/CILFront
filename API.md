# 📖 API Reference

## 🌟 Initialization Functions

| Function | Description| Status |
|-|-|-|
| `void InitWindow(int width, int height)` | Initializes the screen buffer with specified dimensions and hides the cursor | ✅ Enabled |
| `void SetFPS(int fps)` | Sets the frames-per-second rate for rendering | 🚫 Disabled |

---

## 🖼 Drawing Functions

| Function | Description | Status |
|-|-|-|
| `void Clear(char backgroundChar)` | Clears the screen buffer using the provided background character | ✅ Enabled |
| `void DrawText(int x, int y, std::string text)` | Draws a string at the specified coordinates | ✅ Enabled |
| `void DrawBox(int x1, int y1, int x2, int y2, char boxChar, char fillChar)` | Draws a rectangle using border and fill characters | ✅ Enabled |
| `void DrawLine(int x1, int y1, int x2, int y2, char lineChar)` | Draws a line using Bresenham’s algorithm | ⚠️ Bug |
| `void DrawCircle(int centerX, int centerY, int radius, char circleChar, char fillChar)` | Draws a circle with optional fill | 🚫 Disabled |
| `void Title(std::string title, char fillChar)` | Prints a centered title at the top of the screen | ✅ Enabled |

---

## 📺 Rendering & Display

| Function | Description | Status |
|-|-|-|
| `void EndDrawing()` | Flushes screen buffer contents to console | ✅ Enabled |

---

## 📐 Window Utilities

| Function | Description | Status |
|-|-|-|
| `int GetWidth()` | Gets current console window width (in characters) | ✅ Enabled |
| `int GetHeight()` | Gets current console window height (adjusted for vertical scaling) | ✅ Enabled |
| `int GetDelayTime()` | Returns milliseconds since last frame | 🚫 Disabled |

---

