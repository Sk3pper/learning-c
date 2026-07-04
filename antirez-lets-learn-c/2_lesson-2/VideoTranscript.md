# Video Transcript

## The Canonical "Hello World" and `stdio.h`

It's nice and quiet here in the office on a Saturday, with no one around. It's the perfect time to start the second episode of the C course. We left off where we showed the function prototype that could be replaced with an `#include` directive. I've put the `#include` back in because this is the canonical way C is written. So, what's in `stdio.h`? It contains the standard functions from the C standard library that handle input/output. It's an abbreviation for **standard I/O**. Now that we've covered the `#include` directive, you'll see that even in this simple program, there are still a lot of mysteries. Just to understand "Hello World," we need to tackle other concepts.

***

## Anatomy of the `main` Function

To begin with, let's look at how the `main` function is defined: `int main(void)`. Then we have the opening and closing curly braces, which contain the function's definition—its implementation. The `int` before the function name is the return type. It tells us that the `main` function returns an integer value. The parentheses contain the input arguments that the `main` function accepts. In this case, `void` means the `main` function doesn't accept any arguments.

In theory, this might be allowed in modern C, specifically from C99 onwards, to leave the parentheses empty. In fact, let's see what happens if I compile it... it doesn't give me any warnings. An important thing to note: the flags I passed to the compiler enable warnings. So, even if the compiler doesn't find an error that blocks compilation, warnings serve as alerts. Even if the program can be compiled, the compiler might notice issues that could indicate a potential programming error, so it gives us these warnings to help us avoid mistakes. However, I prefer to explicitly write `void` to make it clear that the function takes no arguments.

***

## Defining and Using a Custom Function

Let's look at a different example. I always write function names and comments in English when I program—I think it's good practice, so we'll do it in this course too. So, let's define a function: `int sum(int a, int b)`.

The `sum` function returns an integer because `int` is written before the function name. We'll see the data types C offers later, but for now, just know that `int` is an integer. The function takes an integer `a` as its first argument, followed by a comma to separate the arguments, and then a second integer, `b`. The implementation of this `sum` function is just a single `return` statement, which contains an expression. The `return` statement immediately passes control back to the caller, and the value it returns must be consistent with the function's declared return type. Since the function returns an `int` and `a + b` is the sum of two integers (which results in an `int`), everything works correctly. This function is well-written.

I want you to pay attention to `a + b`. This is an **expression**. C uses expressions in many situations. This is a very simple expression; they can be much more complicated, but they are all still considered expressions. The `return` statement works with expressions, just as expressions are used in other contexts, for example, in the conditions of an `if` statement or a `while` loop. We can now use this `sum` function in our program.

***

## Formatted Output with `printf`

So, instead of just printing "Hello World," I can modify my `printf` statement. I can write `"%d"` in the string and then, as another argument, call `sum(10, 20)`. Let's compile the program and see what it does, and then I'll explain how it works. The output is: "Hello World 30". Indeed, the `sum` function returned an integer, which is the sum of 10 and 20.

To begin with, `printf` is short for "**print formatted**," because it prints data in a specified format. As the first argument, I pass a format string. This string specifies that the output should contain the characters "World" followed by an integer. The `"%d"` is a format specifier that indicates where an integer should be printed.

***

## Variadic Functions and Common Pitfalls

The `printf` function is a **variadic function**, meaning it can take a variable number of arguments. The implementation of `printf` sees the `"%d"` and knows that it needs to look for an additional argument that was passed to the function. This all happens at a low level through memory manipulation in a compiled language. It's not like in Python or other high-level languages where an array of arguments might be passed to the function. We'll look at variadic functions in more detail later in the course. For now, what's important to understand is that it accepts multiple arguments. I could add another `"%d"` and pass another value, like `50`.

The output would be `30 50`. But now I'll show you what happens if I provide a format string that specifies two integers are needed, but I only pass one argument—the return value of `sum(10, 20)`. When I compile this, the compiler gives me a warning. `gcc` tells me that a format specifier is not matched by a corresponding argument. If I run this program anyway, it prints zero, but it could have printed anything. The program's behavior is **undefined** because there's an error. It could very well have crashed.

***

## The Special Role of `main`

There's another interesting detail in this small program. The function called `main` is special because it doesn't need to be called by any other function in your code. We had to explicitly call our `sum` function, otherwise it would never have been invoked. `main`, on the other hand, is the **starting point** of every C program. When a C program is executed, it begins at `main`.

Furthermore, it's very important to know that you cannot write top-level statements outside of a function. I can't just write `printf("hello");` here in the global scope and expect it to work. If I do, I get an error. And what's more, if I rename `main` to something else, like `Pippo`, and compile it, the linker will complain. It will tell me it can't find the `main` symbol, which it needs as the starting point for execution. So, the `main` function is essential.

***

## Variables: Declaration, Initialization, and Assignment

But we're not done yet. Let's explore integers in a more meaningful way. Instead of using our `sum` function, let's write the logic directly in `main` using a different approach. I'll write: `int a = 10; int b = 20; int c = a + b;`. Then, I'll print the result: `printf("Hello %d", c);`. I compile and run this, and the output is `Hello 30`.

Let's see what happened. The keyword `int` is used in two different ways here. In the function signature, `int main`, it defines the return type. But here, `int a = 10;`, it's being used to **declare** a variable. Variables in C must always be declared with their type. It's not enough to write `a = 10` and expect C to figure out that `a` is an integer. C doesn't do that kind of type inference. While some modern languages do, I prefer explicit types. It requires less cognitive effort to see the type, the variable name, and the assignment all explicitly stated.

Here, I've created three variables: `a`, `b`, and `c`. The first two are **initialized** with values. The third, `c`, is initialized with an expression. This shows that expressions can be used not only in `return` statements but also during variable initialization.

I could also do this slightly differently: first declare `int a, b, c;`, and then on separate lines, assign values like `a = 10;`, `b = 20;`, and `c = a + b;`. The program still works the same way. The difference is that this is no longer initialization. Initialization is when a value is assigned at the same time the variable is defined. What we're doing here are separate **assignment** statements. The key difference is that after I've assigned `10` to `a`, I can reassign it a new value, like `11`, or even the result of an expression like `5 + 7`, and the compiler will be perfectly fine with it.

***

## Local Variables and Scope

The variables I created inside `main` are **local variables**. This is a very important concept. Let's go back to our `sum` function to illustrate this. Inside `sum`, I can create a local variable: `int c = a + b;` and then `return c;`. The program still works and prints `30`.

When the `printf` in `main` is called, it must first resolve its arguments. Since the return value of `sum` is needed, the `sum` function is executed first, and only then is `printf` executed. The variable `c` inside `sum` is a local variable. This means it is created every time the `sum` function is called. When the function is called, space for `c` is allocated. The value of `a + b` is assigned to it, and then the value of `c` is returned. At the moment `sum` returns control back to `main`, the variable `c` no longer exists. Its value is **destroyed**; it's gone. That memory can then be reused for other function calls.

The lifetime of `c` is limited to the execution of the function. When the function returns, `c` is gone, and we can no longer rely on it (for instance, by using its address through a pointer, which is a more advanced topic).

Furthermore, the function arguments, `a` and `b`, are also local variables. The difference is that they are automatically created and initialized with the values passed into the function call (e.g., `10` and `20`). So, when the `sum` function returns, three variables are actually destroyed: `a`, `b`, and `c`. This is a very important concept to understand.

***

## The `main` Function's Return Value

Let's return to our "Hello World" program. As you can see, the `main` function has a return value. At first glance, this might seem strange, since `main` is the entry point and isn't called by another function in our code. So what's the point? The return value of `main` is used to signal the program's exit status to the **operating system**. By convention on Unix-like systems, if the program returns **zero**, it means it executed successfully. If it returns a **non-zero value** (like 1, 2, or 3 to indicate different errors), it means it encountered a problem and failed.

***

##  Practical Use of Exit Status in the Shell

Let me show you why this is useful. I'll compile and run the program. I don't see the return value directly, but I can check it. In the Unix shell, the special variable `$?` holds the exit status of the last command.

Let's try it. I'll change the function to `return 1;`. Now if I run `./a.out` and then `echo $?`, it prints `1`. If I change it back to `return 0;`, it will print `0`. This value is accessible.

Here's a practical example. In Unix, you can chain commands using `&&` (logical AND), like this: `./a.out && ls`. The `&&` operator works with short-circuit logic. This means the command on the right (`ls`) will only be executed if the command on the left (`./a.out`) is successful (i.e., returns `0`). If `./a.out` returns a non-zero value (signaling an error), the shell stops and does not execute `ls`. You can see that if the program returns `1`, `ls` is not executed. But if it returns `0`, because `./a.out` executed successfully, the shell proceeds to run `ls`. This is one of the main reasons why the return value from `main` is so useful for scripting and automation.
