
main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	b480      	push	{r7}
   2:	b083      	sub	sp, #12
   4:	af00      	add	r7, sp, #0
   6:	2303      	movs	r3, #3
   8:	71fb      	strb	r3, [r7, #7]
   a:	2300      	movs	r3, #0
   c:	4618      	mov	r0, r3
   e:	370c      	adds	r7, #12
  10:	46bd      	mov	sp, r7
  12:	bc80      	pop	{r7}
  14:	4770      	bx	lr
