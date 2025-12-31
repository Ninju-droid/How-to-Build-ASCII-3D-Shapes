# 🔄 Theory: Rotation Matrices (Spinning in 3D)

Now that we can project 3D points onto a 2D screen, we need to move them. To make a cube or a donut spin, we use **Rotation Matrices**.

---

## 1. The Concept: What is Rotation?
Rotating a point means moving it along a circular path around a fixed axis. When you rotate a point, its distance from the center (radius) stays the same, but its coordinates ($x, y, z$) change based on the angle of rotation.

In 3D, we can rotate around three different axes:
* **X-axis:** The object tilts forward or backward.
* **Y-axis:** The object spins like a top or a carousel.
* **Z-axis:** The object spins like a wheel on a wall.



---

## 2. The 2D Rotation Formula
Before understanding 3D, we look at 2D. To rotate a point $(x, y)$ by an angle $\theta$:

$$x' = x \cos(\theta) - y \sin(\theta)$$
$$y' = x \sin(\theta) + y \cos(\theta)$$

This formula "mixes" the $x$ and $y$ values. As $x$ gets smaller, $y$ gets larger, keeping the point on a circular path.

---

## 3. Rotating in 3D Space
In 3D, rotating around an axis means **one coordinate stays the same** while the other two are "mixed" using the 2D formula.

### Rotation around the Y-axis (Spinning)
If we rotate around the Y-axis, the height ($y$) does not change. Only $x$ and $z$ change:
* $x' = x \cos(A) + z \sin(A)$
* $z' = -x \sin(A) + z \cos(A)$
* $y' = y$

### Rotation around the X-axis (Pitching)
If we rotate around the X-axis, the width ($x$) stays the same. Only $y$ and $z$ change:
* $y' = y \cos(B) - z \sin(B)$
* $z' = y \sin(B) + z \cos(B)$
* $x' = x$



---

## 4. Combining Rotations
To make the "tumble" effect seen in the ASCII Donut or Cube, we apply multiple rotations one after the other:
1. First, calculate $(x', y', z')$ by rotating around the **X-axis**.
2. Then, use those new coordinates to calculate $(x'', y'', z'')$ by rotating around the **Y-axis**.

**Order matters!** Rotating X then Y looks different than rotating Y then X.

---

## 5. Why the Math Looks Different in Code
In your C code, you might see variables like `nx` (new x) or `temp_x`. This is because you **cannot** update $x$ and then use the new $x$ to calculate $y$. You must use the *original* values for both calculations in a single frame:

```c
// CORRECT WAY
float new_x = x * cos(A) - y * sin(A);
float new_y = x * sin(A) + y * cos(B);
x = new_x;
y = new_y;