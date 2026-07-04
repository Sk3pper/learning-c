# **Introduction: The Ephemeral Nature of Local Variables in C**

This video is additional content for the C programming series and should be watched after the second lesson. For the more demanding among you, when we discussed in the second lesson that function parameters are local variables, we also mentioned that you can define other local variables. We said that local variables are **created during a function call and destroyed when the function returns**.

This idea of variables being created and destroyed makes a lot of sense when talking about high-level languages. This isn't to say it doesn't make sense in C, but the idea is easier to visualize with a language like, for example, JavaScript. In JavaScript, we would imagine that when a function returns, any objects assigned to its local variables lose their references. If an object's reference count drops to zero—meaning it's no longer referenced by any global or local variables—the Garbage Collector will delete it because it's no longer reachable.

However, C primarily manipulates numbers, at least from what we've seen so far. So what does it mean for a local variable in C to be "created" and "destroyed"? To understand this, you need to know a bit about how a microprocessor works. In fact, we're going to do something a bit crazy today and see what happens on two different microprocessors. First, let's start with...

-----

# **The 6502 Microprocessor: A Simple Model**

...the **6502**. Let's see... here it is. The 6502 is the microprocessor from the Commodore 64, a processor that's over 40 years old. Its extreme simplicity makes it particularly useful for understanding what's happening under the hood. Also, the program I'm showing you wasn't compiled from C; I wrote it directly in assembly this afternoon.

All microprocessors, from the 6502 to the M3 in my MacBook, have two primary ways of operating on data.

First, they have a set of **registers**. Registers are small, extremely fast variables located right inside the processor's core. They can only hold numbers—either integers or, in modern processors, floating-point numbers as well. Instructions can refer directly to these registers, which are typically named with letters (like A, B, C, D) or a letter followed by a number, depending on the processor's design.

Second, besides operating on registers, processors can use instructions to move data from a **RAM location to a register**, or from a register back to RAM. Operations generally happen inside the registers, but they are often loaded from and saved to memory. Some more advanced CISC processors can even use complex instructions to move data directly from one memory location to another without using registers as an intermediate step.

The 6502 has very few registers. It has the `A` register, called the **accumulator**. For example, the instruction `LDA #50` means "load the value 50 into the A register." After loading this value, which acts as the parameter for a function like `F(50)`, it jumps to a subroutine, in this case, `JSR fill`. This `fill` function will use the value in the `A` register to write a byte of color 5 to the video memory 50 times.

On this simulator, the screen is memory-mapped. If you write to memory locations starting from hexadecimal `0x0200`, each byte corresponds to a pixel's color. Writing the value 5 in successive memory locations fills the screen with green pixels. As you can see when I execute the code, it prints 50 green pixels.

Let's see how it works. The parameter—the number of pixels to write—is passed using the `A` register.

1.  The first thing the `fill` function does is `TAX`, which means "**T**ransfer **A** to **X**." It copies the value from the `A` register to the `X` register. The `X` register is another one of the 6502's registers.
2.  The code then checks if the value is zero; if so, it exits. In our case, it's 50, so this check is ignored.
3.  Next, it loads the value 0 into the `Y` register and the value 5 into the `A` register.
4.  Wait, the `A` register now holds 5, destroying the 50 we needed for our loop count\! This is okay because we already saved the count to the `X` register with the `TAX` instruction. As you can see, registers are easily overwritten because they are, in a sense, "local" to their immediate use. You must be careful to save any register values you'll need later.

The main loop is interesting. The `Y` register is used as an index.

  * The instruction `STA $0200, Y` means "**ST**ore **A**ccumulator" at memory location `0x0200` plus the value in `Y`.
  * The first time through the loop, `Y` is 0, so it writes a green pixel (`5`) to `vidmem[0]`.
  * Then it **increments `Y`** (`INY`) to point to the next pixel location.
  * It **decrements `X`** (`DEX`), which holds our loop counter.
  * If `X` is **not yet zero** (`BNE`), it jumps back to the start of the loop. Otherwise, the function returns.

So, how does this relate to local variables? In this program, I used the `A` register as the function's argument. If this function were to call another function, that new function would likely overwrite the `A` register for its own purposes. This is how the values of local variables can be "lost" in C. Because C often uses registers for computations, the value held in a register is **ephemeral**—once the register is repurposed, the original variable effectively no longer exists.

-----

# **Function Calls and Register Management in Assembly**

Furthermore, an assembly function often calls other functions that need to use the same registers. To handle this, you must save the registers before the call and restore them afterward. This is typically done using the **stack**.

Other architectures, like the 32-bit x86 (or 386), are ideal for understanding how C compilation works and how local variables are managed. This architecture primarily uses the stack for its **function calling convention**. A calling convention is a standard that C compilers on a given architecture must follow to ensure functions pass and receive arguments consistently. This means a function compiled with one compiler can be used by a program compiled with a different one, as long as both adhere to the architecture's standard.

When I showed you in the first C lesson that you could just use a function prototype and it would work, it's because the compiler uses the prototype to understand how to call that function according to the convention. It just needs the function's address. This allows you to link code compiled by different tools at runtime, and it will all work together seamlessly.

-----

# **The x86 Architecture and the Stack**

The stack is simply a region of computer memory. For the 32-bit x86 architecture, you can imagine it as being divided into 4-byte (32-bit) slots. A special register called the **Stack Pointer** (`SP`) always points to the "top" of the stack.

There are two key instructions:

  * `push`: Takes a value (e.g., from a register) and puts it on top of the stack. It does this by first decrementing the `SP` and then writing the value to that new memory location.
  * `pop`: Takes the value from the top of the stack and loads it into a destination (e.g., a register). It then increments the `SP`.

So, if `SP` points to an address and we `push eax`, the `SP` is decremented by 4, and the value of `eax` is stored there. If we then `push ebx`, the `SP` is decremented again, and `ebx` is stored at the new top of the stack. A subsequent `pop ebx` would retrieve that value and increment `SP`, effectively removing it.

-----

# **How C Functions Use the Stack: A Practical Example**

Let's see how a C program like this might be compiled:

```c
int sum(int a, int b) {
    return a + b;
}

int main() {
    return sum(10, 20);
}
```

Here's a simplified look at the assembly generated for `main`:

1.  `push ebp`: `main` starts by saving the current **Base Pointer** (`ebp`) register onto the stack. This saves the stack frame of the function that called `main`.
2.  `mov ebp, esp`: It then copies the current stack pointer (`esp`) into `ebp`. This establishes a new, stable base pointer for `main`'s stack frame. This `ebp` will serve as a fixed reference point to access arguments and local variables.
3.  `push 20`: The second argument (20) is pushed onto the stack.
4.  `push 10`: The first argument (10) is pushed onto the stack.
5.  `call sum`: This instruction does two things. First, it pushes the **return address** (the address of the instruction *after* the `call`) onto the stack. Second, it jumps to the `sum` function's code.

Now we are inside the `sum` function. It begins with a similar prologue:

1.  `push ebp`: It saves the *caller's* `ebp` (which is `main`'s `ebp`) onto the stack.
2.  `mov ebp, esp`: It establishes its own base pointer for its own stack frame.

At this point, the stack contains the return address, the old `ebp`, and the function arguments. Relative to the new `ebp`, the function's arguments can be found at fixed positive offsets: the first argument (`a`) is at `ebp+8`, and the second argument (`b`) is at `ebp+12`.

The `sum` function then performs its logic:

  * `mov eax, [ebp+8]`: It moves the first argument (`a`) into the `eax` register.
  * `add eax, [ebp+12]`: It adds the second argument (`b`) to the `eax` register. The result of the sum is now in `eax`, which by convention is used for function return values.

Finally, the function returns:

  * `pop ebp`: This restores the caller's (`main`'s) base pointer from the stack.
  * `ret`: This pops the return address from the stack into the Program Counter, resuming execution back in `main`.

After `sum` returns, `main` cleans up the stack by adding 8 to the stack pointer (`add esp, 8`), removing the two arguments that were pushed before the call.

If the program were to call another function after `sum`, those same memory locations on the stack would be **overwritten** by the arguments and local variables of the new function call.

-----

# **Conclusion: Understanding Local Variables and Tools for Exploration**

So, this is what local variables are in C: they are either values in **temporary registers** or **temporary locations on the stack**. When a function returns, the registers are immediately reused, and the stack space is considered free to be overwritten by the next function call. This is what it means for them to be "destroyed."

I know this was a long explanation, but it's crucial to understand what's happening "under the hood." If you want to explore this further, I highly recommend two tools:

  * **Easy 6502**: A wonderful site to experiment with 6502 assembly.
  * **Compiler Explorer**: An awesome tool (godbolt.org) that lets you write C code and instantly see the assembly it generates for various architectures.

You can achieve something similar with `gcc -S` on your own machine, but that will only show the assembly for your specific architecture. In contrast, the 386 assembly, while sometimes criticized, is in my opinion one of the clearest for learning—perhaps because it's what I learned when I was young. It's much easier to read compared to modern assembly like AMD64.

Bye, everyone\!