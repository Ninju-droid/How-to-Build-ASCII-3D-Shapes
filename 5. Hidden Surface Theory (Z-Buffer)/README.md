# 🛡️ Theory: The Z-Buffer (Hidden Surface Removal)

When drawing a 3D object like a solid cube, some parts are in front and some parts are behind. Without a **Z-Buffer**, the computer simply draws points in the order they are calculated, which leads to a "transparent" or "ghosting" effect.

---

## 1. The Problem: Occlusion
In the real world, solid objects block the light from objects behind them. In computer graphics, we call this **Occlusion**. 

If we calculate the back face of a cube *after* the front face, the back face will be drawn "on top" of the front, making the 3D shape look confusing and physically impossible.

---

## 2. The Solution: Depth Testing
The **Z-Buffer** (also known as a Depth Buffer) is a second array that is exactly the same size as your screen buffer. 

* **Screen Buffer:** Stores the character to be displayed (e.g., `#` or `@`).
* **Z-Buffer:** Stores the **depth** ($z$ value) of the point currently occupying that pixel.



---

## 3. The Logic: "Is it Closer?"
Every time you try to plot a point at a coordinate $(x, y)$, the Z-Buffer logic performs a check:

1. Calculate the depth of the new point ($z$).
2. Look at the value already stored in the Z-Buffer at that position.
3. **The Test:** If the new point is **closer** to the camera than the stored point:
   * Update the Screen Buffer with the new character.
   * Update the Z-Buffer with the new depth.
4. **Else:** Discard the point (it is hidden behind something else).

---

## 4. Implementation with `ooz` (One Over Z)
In many ASCII engines (like the Donut), we use `ooz = 1.0 / z` instead of the raw $z$ value. 

* A **large $z$** means the object is far away (small `ooz`).
* A **small $z$** means the object is close (large `ooz`).

**The code logic:**
```c
float ooz = 1.0 / (z + K2); // Calculate "closeness"
int pos = y * width + x;    // Find the index

if (ooz > zbuffer[pos]) {   // If this point is CLOSER than the last one...
    zbuffer[pos] = ooz;     // ...remember this new depth...
    screen[pos] = '#';      // ...and draw the character!
}