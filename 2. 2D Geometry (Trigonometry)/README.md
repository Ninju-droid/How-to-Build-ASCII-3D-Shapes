# 📐 Theory: 2D Geometry and Trigonometry

In the previous step, we learned how to plot points. Now, we use mathematics to create shapes. To build a 3D engine, the most important tool in our kit is **Trigonometry**.

---

## 1. Why Trigonometry?
In computer graphics, we often need to calculate the positions of points around a center. 
* To draw a circle, we need points that stay at a constant distance (radius) from a center.
* To rotate an object, we need to calculate its new position as it moves along an arc.

We do this using **Sine (`sin`)** and **Cosine (`cos`)**.

---

## 2. The Unit Circle
The Unit Circle is a circle with a radius of 1. It is the map we use to find coordinates based on an angle ($\theta$).

* **X-coordinate:** Calculated using `cos(theta)`
* **Y-coordinate:** Calculated using `sin(theta)`



[Image of unit circle with sine and cosine coordinates]


### The Parametric Equation of a Circle
To draw a circle of any size at any position:
1. **$x = \text{center\_x} + (\text{radius} \cdot \cos(\theta))$**
2. **$y = \text{center\_y} + (\text{radius} \cdot \sin(\theta))$**

By looping $\theta$ from $0$ to $2\pi$ (roughly $6.28$ radians), we calculate every point on the edge of the circle.

---

## 3. Radians vs. Degrees
Computers do not use degrees ($0^\circ$ to $360^\circ$). They use **Radians**.
* $180^\circ = \pi$ radians (approx. $3.14$)
* $360^\circ = 2\pi$ radians (approx. $6.28$)

**The Loop Logic:**
```c
for (float theta = 0; theta < 6.28; theta += 0.1) {
    float x = radius * cos(theta);
    float y = radius * sin(theta);
    // Plot (x, y)
}