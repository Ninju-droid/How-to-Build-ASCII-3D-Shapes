# 🎥 Theory: Perspective Projection (Adding Depth)

In 2D, a point $(5, 5)$ is always at $(5, 5)$. In 3D, we must account for the **Z-axis** (depth). To make an object look "3D" on a flat terminal, we use **Perspective Projection**.

---

## 1. The Goal: Making Far Objects Smaller
The fundamental rule of 3D vision is: **The further away an object is, the smaller it appears.**

To simulate this, we use the math of **Similar Triangles**. If you imagine a line from your eye to a 3D point, that line passes through your "screen" at a specific spot.



---

## 2. The Projection Formula
To find the screen position $(xp, yp)$ of a 3D point $(x, y, z)$, we use the following formula:

$$xp = \frac{x \cdot K1}{z + K2}$$
$$yp = \frac{y \cdot K1}{z + K2}$$

### Breaking down the Variables:
* **$x, y, z$:** The actual coordinates of the point in 3D space.
* **$K1$ (Focal Length):** This represents the "zoom" or distance from your eye to the screen. A larger $K1$ makes the object appear bigger.
* **$K2$ (Viewer Distance):** This is how far the "camera" is from the center of your 3D world $(0,0,0)$. This prevents the denominator from ever becoming zero.



---

## 3. Why it Works (The Math of $1/z$)
Notice that $z$ is in the **denominator**. 
* As a point moves further away, **$z$ increases**.
* When you divide by a larger number, the result (**$xp$**) becomes **smaller**.
* This naturally pushes points toward the center of the screen as they move away, creating a "vanishing point."

---

## 4. The "One Over Z" ($ooz$)
In high-performance graphics code (like `donut.c`), you will often see a variable called `ooz`. 
`float ooz = 1.0 / (z + K2);`

Instead of dividing $x$ and $y$ separately, we calculate `ooz` once and then multiply:
`int xp = (int)(width/2 + x * K1 * ooz);`

**Why?** In computer processing, multiplication is much faster than division. Calculating `1/z` once saves a lot of processing power.

---

## 5. Summary: 2D vs 3D Logic

| Feature | 2D Approach | 3D Approach |
| :--- | :--- | :--- |
| **Coordinates** | $(x, y)$ | $(x, y, z)$ |
| **Position** | Fixed | Depends on Depth ($z$) |
| **Scaling** | Manual | Automatic (via division by $z$) |

---

### Key Takeaway
Projection is the "lens" of your engine. Without it, your shapes will stay flat. With it, you create a window into a 3D world.