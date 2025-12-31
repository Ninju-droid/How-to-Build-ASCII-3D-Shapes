# 🎭 The Art of Obfuscation: Code that Shapes Itself

In this section, we explore **Obfuscated C Code**. This is the practice of writing code that is deliberately confusing or, in our case, formatted to look like the very object it is rendering.

---

## 1. What is Obfuscation?
"Obfuscate" means to make something unclear or hard to understand. In programming, we achieve this by:
1. **Removing White Space:** C doesn't care about spaces or newlines (mostly).
2. **Short Variable Names:** Using `i`, `j`, `A`, `B` instead of `index` or `angle`.
3. **Creative Formatting:** Arranging the text of the code into a visual shape (like a circle or a donut).

---

## 2. How the "Shaped Code" Works
The compiler reads your code as a single long stream of instructions. To the compiler, these two snippets are identical:

**Standard Format:**
```c
int x = 10;
int y = 20;
printf("%d", x + y);