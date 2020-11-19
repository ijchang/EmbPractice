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
	leal	-1(%rdi), %ecx
	testl	%edi, %edi
	jle	.L5
	leaq	15(%rsi), %rax
	subq	%rdx, %rax
	cmpq	$30, %rax
	jbe	.L7
	cmpl	$14, %ecx
	jbe	.L7
	movl	%edi, %r8d
	xorl	%eax, %eax
	shrl	$4, %r8d
	salq	$4, %r8
	.p2align 4,,10
	.p2align 3
.L8:
	movdqu	(%rdx,%rax), %xmm0
	movups	%xmm0, (%rsi,%rax)
	addq	$16, %rax
	cmpq	%r8, %rax
	jne	.L8
	movl	%edi, %r8d
	andl	$-16, %r8d
	movl	%r8d, %eax
	addq	%rax, %rsi
	addq	%rax, %rdx
	movl	%ecx, %eax
	subl	%r8d, %eax
	cmpl	%r8d, %edi
	je	.L5
	movzbl	(%rdx), %ecx
	movb	%cl, (%rsi)
	testl	%eax, %eax
	jle	.L5
	movzbl	1(%rdx), %ecx
	movb	%cl, 1(%rsi)
	cmpl	$1, %eax
	jle	.L5
	movzbl	2(%rdx), %ecx
	movb	%cl, 2(%rsi)
	cmpl	$2, %eax
	jle	.L5
	movzbl	3(%rdx), %ecx
	movb	%cl, 3(%rsi)
	cmpl	$3, %eax
	jle	.L5
	movzbl	4(%rdx), %ecx
	movb	%cl, 4(%rsi)
	cmpl	$4, %eax
	jle	.L5
	movzbl	5(%rdx), %ecx
	movb	%cl, 5(%rsi)
	cmpl	$5, %eax
	jle	.L5
	movzbl	6(%rdx), %ecx
	movb	%cl, 6(%rsi)
	cmpl	$6, %eax
	jle	.L5
	movzbl	7(%rdx), %ecx
	movb	%cl, 7(%rsi)
	cmpl	$7, %eax
	jle	.L5
	movzbl	8(%rdx), %ecx
	movb	%cl, 8(%rsi)
	cmpl	$8, %eax
	jle	.L5
	movzbl	9(%rdx), %ecx
	movb	%cl, 9(%rsi)
	cmpl	$9, %eax
	jle	.L5
	movzbl	10(%rdx), %ecx
	movb	%cl, 10(%rsi)
	cmpl	$10, %eax
	jle	.L5
	movzbl	11(%rdx), %ecx
	movb	%cl, 11(%rsi)
	cmpl	$11, %eax
	jle	.L5
	movzbl	12(%rdx), %ecx
	movb	%cl, 12(%rsi)
	cmpl	$12, %eax
	jle	.L5
	movzbl	13(%rdx), %ecx
	movb	%cl, 13(%rsi)
	cmpl	$13, %eax
	jle	.L5
	movzbl	14(%rdx), %eax
	movb	%al, 14(%rsi)
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	movl	%ecx, %eax
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L10:
	movzbl	(%rdx,%rcx), %edi
	movb	%dil, (%rsi,%rcx)
	movq	%rcx, %rdi
	addq	$1, %rcx
	cmpq	%rax, %rdi
	jne	.L10
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
