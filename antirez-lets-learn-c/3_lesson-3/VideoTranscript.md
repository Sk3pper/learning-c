### Introduction to C Programming

This is the third episode of our C programming course. Paradoxically, we're still on "Hello World," but we'll deepen deeper into it to understand more. We previously created a function called "SAM"; this time, we'll create a function called "INC," which means increment.

***

### Understanding the "INC" Function

The "INC" function will reuse the "void" keyword, similar to "main." This means the function will return an integer but won't take any input. Inside, it declares a variable "x" with a value of 1, then increments "x" by 1 using the expression "x = x + 1". Here, "x + 1" is an expression, the left side is a variable name, and the equals sign is for assignment. So, if "x" is 1, it becomes 2; if "x" is 2, it becomes 3. It's important to note that a single equals sign is for assignment, not equality. For equality checks, like in an "if" statement, you would use two equals signs ("=="). The single equals sign transfers the value on the right to the variable on the left, while "==" is for comparison.

In this case, "x" starts at 1, so it becomes 2. We then print the value of "x" using `printf`, which is a function that takes a format string and then the variables to print. It's similar to Python's f-strings. Since `printf` is a standard C function and not specially designed, it uses type specifiers. You can write whatever you want, but you need to specify the data type when printing, using different specifiers for floating-point numbers, etc.

***

### Functions with Side Effects

We'll make the `incr` function return "void" as well, meaning it doesn't return anything and takes no input. In imperative programming languages, this function has maximum value because it only has a "side effect"—it prints something to the screen. It doesn't process external data or have any effect from a functional programming perspective. It takes nothing, returns nothing; its only value is that calling it causes something to happen. If you use other imperative languages like Go, Python, or JavaScript, it won't seem strange for a function to just perform a side effect without returning anything.

***

### Local Variables

Back in `main`, we remove the `printf` and call `incr()`. We call `incr` with empty parentheses because it takes no arguments. After compiling and running, it prints 2. If we call `incr` multiple times (e.g., four times), each call creates a new local variable `x`, sets it to 1, increments it to 2, and prints 2. Then, the variable is destroyed, losing its value before the next call. This results in "2 2 2 2" being printed.

***

### Global Variables

This leads us to the concept of global variables. If we define a global variable `x` outside the `incr` function and initialize it to 0, and then remove the local `int x = 1` from `incr`, the compiler will use the global `x` when it encounters `x` in the `incr` function. The difference is that the global `x` retains its state. It's created at the beginning of the program's execution and persists as long as the program runs. So, each call to `incr` will increment the *same* `x`. This will result in "1 2 3 4" being printed after four calls.

***

### Static Variables (Local Global Variables)

There's another type of variable in C: a static variable, which is essentially a global variable defined within a function. If you declare a local variable as `static`, it becomes a global variable but is only visible within that specific function. Compiling and running the program with a static `x` initialized to 0 inside `incr` will produce the same "1 2 3 4" output as a global variable. However, if you try to print `x` from `main`, the program won't compile because `x` is only visible to the `incr` function. While it has a global lifetime, its scope is local. Static variables share the same limitations as global variables, such as not being thread-safe without synchronization mechanisms like mutexes.

***

### Pass by Value vs. Pass by Reference

Now, let's look at functions that take input and return a value. We modify `incr` to take an integer `x` as input and return an integer. Inside, it increments `x` and returns the new value. In `main`, we declare an integer `a` initialized to 10, then call `incr(a)`, and finally print `a`. You might expect `a` to be 11, but it remains 10. This is because, in C, arguments are passed by **value**, not by **reference**, by default. The function `incr` receives a *copy* of `a`, not `a` itself. The local `x` inside `incr` is a separate variable from `a` in `main`. The incremented value is returned by `incr` but not assigned back to `a`.

To update `a`, you must assign the return value of `incr` back to `a`: `a = incr(a)`. This way, `a` will be 11. Repeated calls would increment `a` further (e.g., calling it four times would make `a` 14). This is a more functional approach to incrementing. It's crucial to understand that C passes everything by value, including structures. The only way to pass a reference to modify a variable inside a function is by using **pointers**, which will be introduced soon, as they are fundamental to C programming.

***

### Basic Data Types: `int` and `float`

We've primarily seen the `int` data type. Let's introduce `float`, which represents floating-point numbers. For example, `float y = 1.234`. When printing both an `int` and a `float` using `printf` and their respective format specifiers (`%d` for `int`, `%f` for `float`), you'll see the integer and the floating-point number. By default, `float` might be printed with many trailing zeros.

***

### `printf` Formatting and Type Specifiers

`printf` has rich formatting capabilities. For instance, `%.3f` prints a float with three decimal places. You can even print an integer in hexadecimal format using `%x`. The `printf` function is powerful, and you can always refer to `man 3 printf` or an LLM for more details.

***

### C's Implicit Type Conversions and Warnings

C is a "dangerous" language. If you swap the order of the arguments and their format specifiers in `printf` (e.g., printing an `int` with `%f` and a `float` with `%d`), the program will compile with warnings but will still run, producing meaningless output. This highlights C's behavior of allowing potentially unsafe operations. The warning about `double` instead of `float` is due to C's automatic type promotions.

***

### Integer Types: `int`, `unsigned int`, `char`, `short`

Let's distinguish between `int` and `float` data types. An `int` is a whole number (positive or negative). An `unsigned int` can only be non-negative. For example, `unsigned int b = 20`. A `float` is a floating-point number, representing decimals with a certain precision. It uses a standard representation (like FP32 for floats and FP64 for doubles) consisting of a mantissa and an exponent, allowing it to represent both very small and very large numbers.

***

### Type Promotion Rules in C

The reason `printf` sometimes warns about `double` when you pass a `float` is due to C's automatic type promotion rules for variadic functions (functions that accept a variable number of arguments). When you pass an integer type smaller than an `int` (like a `char` or `short`) to a variadic function, it's automatically promoted to an `int`. Similarly, `float` arguments are promoted to `double`. This simplifies how `printf` handles different numeric types.

***

### Integer Overflow and Undefined Behavior

Now, let's consider integer overflow. A `char` typically ranges from -128 to 127. If you set `char c = 127` and then print it, you get 127. But if you set `char c = 128`, it will compile with a warning. When you print `c`, it becomes -128. This is because of wrapping around after an overflow. However, this wrapping behavior for signed integers is actually **undefined behavior** (UB) in C. This means the compiler isn't guaranteed to do any specific thing, it could crash, produce garbage, or anything else.

Interestingly, if you perform arithmetic with a `char` by first promoting it to an `int`, like `int i = c + 1`, where `c = 127`, `i` will correctly become 128 without any warning or unexpected behavior. This is because C's automatic conversion rules apply to expressions as well: smaller integer types are promoted to `int` during arithmetic.

***

### `++` Operator and Signed vs. Unsigned Integers

The `++` operator in C increments a variable (e.g., `c++` is equivalent to `c = c + 1`). If you use `c++` with a `char c = 127`, it will still wrap around to -128, but as noted, this is undefined behavior for signed integers. You must be careful to avoid overflow with signed integers.

However, for **unsigned integers**, overflow behavior is well-defined. If you declare `unsigned char c = 254` (the maximum for an 8-bit unsigned char is 255), then `c++` will first make it 255. A second `c++` will cause it to wrap around to 0, and this behavior is guaranteed by the C standard.

That concludes this episode. We'll continue discussing C data types in the next lesson.
