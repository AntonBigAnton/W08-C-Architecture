	.file	"Factorial.c"
	.text
	.type	factorial, @function
factorial: # Name for place in program: factorial function
.LFB0:
	.cfi_startproc
	# Create a new stackframe with pushq, movq and subq
	pushq	%rbp # Push the base pointer (rbp) to the stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp # Set the base pointer (rbp) to the stack pointer (rsp) 
	.cfi_def_cfa_register 6
	subq	$16, %rsp # Decrement the stack pointer (rsp) by 16, and store the result in the stack pointer (rsp): this moves the stack pointer down, to reserve space in the stack
	# Save the function's parameters
	movq	%rdi, -8(%rbp) # Save the 1st argument (n, stored in the rdi register) to the stack, at position -8 (relative to the base pointer rbp)
	movq	%rsi, -16(%rbp) # Save the 2nd argument (accumulator, stored in the rsi register) to the stack, at position -16 (relative to the base pointer rbp)
	cmpq	$1, -8(%rbp) # Compares n (stored at position -8 relative to the base pointer rbp) with 1
	ja	.L2 # Will go to section .L2 if 1 is greater than n (unsigned)
	# If not, the following commands are executed
	movl	$7, %edi # Store the value 7 to the low 32-bits addressable edi: this will change the value of rdi
	call	printStackFrames # Transfers control to the printStackFrames function
	movq	-16(%rbp), %rax # Set the return register (rax) to accumulator (stored at position -16 relative to the base pointer rbp)
	jmp	.L3 # Go to section .L3
.L2:
	# Update the parameters and call the factorial function again
	movq	-8(%rbp), %rax # Set the return register (rax) to n (stored at position -8 relative to the base pointer rbp)
	imulq	-16(%rbp), %rax # Multiply accumulator (stored at position -16 relative to the base pointer rbp) by n (stored in the return register rax), and store the result in the return register (rax)
	movq	-8(%rbp), %rdx # Set the rdx register to n (stored at position -8 relative to the base pointer rbp)
	subq	$1, %rdx # Substract 1 to n (stored in the rdx register), and store the reult in the rdx register
	movq	%rax, %rsi # Replace the value of the 2nd argument (accumulator, stored in the rsi register) with the value in the return register (rax, value = accumulator * n)
	movq	%rdx, %rdi # Replace the value of the 1st argument (n, stored in the rdi register) with the value in the rdx register (value = n-1)
	call	factorial # Transfers control to the factorial function, but with updated parameters
.L3:
	leave # Restore the values of the base pointer (rbp) and the stack pointer (rsp) at the end of the function: it "clears" the stackframe
	.cfi_def_cfa 7, 8
	ret # Return the value stored in the return register (rax)
	.cfi_endproc
.LFE0:
	.size	factorial, .-factorial
	.section	.rodata
	.align 8
.LC0:
	.string	"executeFactorial: basePointer = %lx\n"
	.align 8
.LC1:
	.string	"executeFactorial: returnAddress = %lx\n"
	.align 8
.LC2:
	.string	"executeFactorial: about to call factorial which should print the stack\n"
	.align 8
.LC3:
	.string	"executeFactorial: factorial(%lu) = %lu\n"
	.text
	.globl	executeFactorial
	.type	executeFactorial, @function
executeFactorial: # Name for place in program: executeFactorial function
.LFB1:
	.cfi_startproc
	pushq	%rbp #
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp #
	.cfi_def_cfa_register 6
	subq	$48, %rsp #
	movl	$0, %eax #
	call	getBasePointer #
	movq	%rax, -8(%rbp) #
	movq	-8(%rbp), %rax #
	movq	%rax, %rsi #
	movl	$.LC0, %edi #
	movl	$0, %eax #
	call	printf #
	movl	$0, %eax #
	call	getReturnAddress #
	movq	%rax, -16(%rbp) #
	movq	-16(%rbp), %rax #
	movq	%rax, %rsi #
	movl	$.LC1, %edi #
	movl	$0, %eax #
	call	printf #
	movl	$.LC2, %edi #
	call	puts #
	movq	$0, -24(%rbp) #
	movq	$6, -32(%rbp) #
	movq	$1, -40(%rbp) #
	movq	-40(%rbp), %rdx #
	movq	-32(%rbp), %rax #
	movq	%rdx, %rsi #
	movq	%rax, %rdi #
	call	factorial #
	movq	%rax, -24(%rbp) #
	movq	-24(%rbp), %rdx #
	movq	-32(%rbp), %rax #
	movq	%rax, %rsi #
	movl	$.LC3, %edi #
	movl	$0, %eax #
	call	printf #
	nop #
	leave #
	.cfi_def_cfa 7, 8
	ret #
	.cfi_endproc
.LFE1:
	.size	executeFactorial, .-executeFactorial
	.ident	"GCC: (GNU) 11.4.1 20230605 (Red Hat 11.4.1-2)"
	.section	.note.GNU-stack,"",@progbits
