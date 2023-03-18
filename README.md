# Brainfuck

This is my take at the [`brainfuck`](https://en.wikipedia.org/wiki/Brainfuck) programming language. I would like to build an interpreter and a compiler for it (well, calling it a compiler is a bit of a stretch, but I'll get to that later).

## Specification

`brainfuck` is a very simple language. It consists of an instruction tape and a data tape, which are adressed by a pointer. For most of the time, the instruction pointer is incremented after each instruction is executed. The data tape has 30 000 cells, initialized to zero, each of which is a signed 8-bit integer. The instruction tape is a string of characters, which are the instructions. The instructions are as follows:

- `>`: Increment the data pointer.
- `<`: Decrement the data pointer.
- `+`: Increment the value at the data pointer.
- `-`: Decrement the value at the data pointer.
- `.`: Output the value at the data pointer (as an ASCII character).
- `,`: Input a value and store it at the data pointer.
- `[`: If the value at the data pointer is zero, jump to the instruction after the matching `]`.
- `]`: If the value at the data pointer is nonzero, jump to the instruction after the matching `[`.
- Other characters are ignored, which is useful for comments.

If the user inputs only a newline, the value at the data pointer is set to zero.

## Interpreter

When run, the interpreter will first read the program from a file. This file's path is, by default, './program.bf', but can be changed by passing the path as the first argument. The interpreter will then execute the program, and output the result.

The compiler doesn't check for code validity (a code is invalid if it has unmatched brackets), which might cause crashes if the program is not correct. Furthermore, the program is ended if any of the pointers falls outside of their range.

## Sources

https://en.wikipedia.org/wiki/Brainfuck
https://esolangs.org/wiki/Brainfuck