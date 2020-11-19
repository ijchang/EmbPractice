	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%x\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$-1, %edx
	movl	$1, %edi
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rsi
	call	__printf_chk@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.text
	.p2align 4
	.globl	swap
	.type	swap, @function
swap:
.LFB24:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	movw	%di, -2(%rsp)
	shrl	$16, %eax
	movw	%ax, -4(%rsp)
	movl	-4(%rsp), %eax
	ret
	.cfi_endproc
.LFE24:
	.size	swap, .-swap
	.p2align 4
	.globl	copy_array
	.type	copy_array, @function
copy_array:
.LFB25:
	.cfi_startproc
	endbr64
	movq	%rsi, %r8
	movq	%rdx, %rsi
	testl	%edi, %edi
	jle	.L5
	leal	-1(%rdi), %edx
	movq	%r8, %rdi
	movslq	%edx, %rdx
	addq	$1, %rdx
	jmp	memcpy@PLT
	.p2align 4,,10
	.p2align 3
.L5:
	ret
	.cfi_endproc
.LFE25:
	.size	copy_array, .-copy_array
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
