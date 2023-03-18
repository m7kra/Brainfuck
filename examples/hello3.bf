A more efficient hello world which uses the previous values instead of resetting
them to 0 each time a character is printed

Note the usage of the data pointer to move forward when printing space and ! (because
incrementing 32 times is faster than decrementing 57 times)

Can be used to test:
* Incrementing data pointer
* Decrementing data pointer
* Incrementing data
* Decrementing data
* Outputting data

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++. Prints out H (ASCII 72)
---. Prints out E
+++++++. Prints out L
. Prints out L
+++. Prints out O
>++++++++++++++++++++++++++++++++. Prints out space
<
++++++++. Prints out W
--------. Prints out O
+++. Prints out R
------. Prints out L
--------. Prints out D
>+. Prints out !