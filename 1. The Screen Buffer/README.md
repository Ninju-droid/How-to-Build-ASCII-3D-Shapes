# Theory: Grid Mapping and Coordinate Systems

To build a 3D engine in a text-based terminal, we must first understand how to translate mathematical coordinates into physical characters on a screen.

---

## 1. The Terminal Coordinate System

In standard mathematics (Cartesian coordinates), (0,0) is in the center. However, in computer science and terminal displays, the system follows a "top-down" logic in which :
* **Origin (0,0):** Located at the **Top-Left** corner of the window.
* **X-axis:** Increases as you move to the **right**.
* **Y-axis:** Increases as you move **downward**.

> **Note:** Because Y increases downwards, if you want to move an object "up" mathematically, you actually subtract from the Y value in your code.

---

## 2. Flattening the Grid (1D vs. 2D)

A terminal screen looks like a 2D grid of rows and columns. However, computer memory is **linear** (one long line of bytes). We use a 1D array to represent our 2D screen.

### The Problem
If we have a screen that is 80 characters wide and 40 characters high, we create an array:
`char screen[80 * 40];`

How do we tell the computer that the point at (x: 10, y: 5) is actually a specific spot in that long line?

### The Solution: The Index Formula
We use the **Row-Major Order** formula to map any 2D coordinate (x, y) to a 1D index:

**Formula:** `Index = (y * Width) + x`
**How this formula works:**
1. **(y * Width):** This tells the computer how many full rows to "skip" to get to the correct vertical level.
2. **(+ x):** This tells the computer how many steps to take horizontally within that specific row.

---

## 3. Centering the Math

Since 3D math (like rotation) centers around (0,0,0), we need to "push" our shapes into the middle of the terminal so they aren't stuck in the top-left corner.

We apply a **Translation Offset**:
* `plot_x = (width / 2) + x_calculated`
* `plot_y = (height / 2) + y_calculated`

This ensures that the (0,0) of your mathematical shape aligns with the center of your 100x50 terminal.

---

## 4. The Aspect Ratio Trap

Terminal characters are not perfect squares; they are usually **tall rectangles** (roughly a 2:1 ratio). 

If you draw a circle where the X and Y distances are mathematically equal, it will look like a tall, thin oval. To fix this, we multiply the X coordinate by a compensation factor (usually **2.0**) before plotting:

`final_x = center_x + (math_x * 2.0)`

---

## 5. The Render Loop

To create an animation, we follow these three steps in every single frame:

1. **Clear (memset):** Fill the entire 1D array with a background character (like a space `' '`). This "erases" the previous frame , for this we have to include <string.h> in our c code .
2. **Draw (Logic):** Calculate new (x, y) positions and put characters into the array using the **Index Formula**.
3. **Display (putchar):** Loop through the 1D array and print it. We use a newline check `(i % width == 0)` to start new rows. -> we use putchar() instead of printf()
 BEACAUSE :   
>I. Prints exactly one character
>II. Very thin wrapper around writing a byte to stdout
>III. No formatting, no parsing, no argument handling
