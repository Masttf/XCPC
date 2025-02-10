	.file	"C.cpp"
 # GNU C++17 (x86_64-posix-seh-rev1, Built by MinGW-W64 project) version 11.2.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 11.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=core2 -march=nocona -fstack-protector-strong
	.text
	.globl	_Z3funj
	.def	_Z3funj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3funj
_Z3funj:
.LFB0:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)	 # x, x
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:3: 	if(x==0)
	cmpl	$0, 16(%rbp)	 #, x
	jne	.L2	 #,
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:4: 		return x;
	movl	16(%rbp), %eax	 # x, _4
	jmp	.L3	 #
.L2:
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:5: 	unsigned z =x>>1;
	movl	16(%rbp), %eax	 # x, tmp91
	shrl	%eax	 # tmp90
	movl	%eax, -8(%rbp)	 # tmp90, z
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:6: 	int result = fun(z);
	movl	-8(%rbp), %eax	 # z, tmp92
	movl	%eax, %ecx	 # tmp92,
	call	_Z3funj	 #
	movl	%eax, -4(%rbp)	 # _10, result
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:7: 	return z+result&1;
	movl	-4(%rbp), %edx	 # result, result.0_1
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:7: 	return z+result&1;
	movl	-8(%rbp), %eax	 # z, tmp93
	addl	%edx, %eax	 # result.0_1, _2
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:7: 	return z+result&1;
	andl	$1, %eax	 #, _4
.L3:
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:9: }
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:11: {
	call	__main	 #
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:12: 	unsigned  x = 0x1234;
	movl	$4660, -8(%rbp)	 #, x
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:13: 	int r = fun(x);
	movl	-8(%rbp), %eax	 # x, tmp85
	movl	%eax, %ecx	 # tmp85,
	call	_Z3funj	 #
	movl	%eax, -4(%rbp)	 # _4, r
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:14: 	return 0;	
	movl	$0, %eax	 #, _6
 # D:\Sublime\Mycode\codeforces\CF383\C.cpp:15: }
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 11.2.0"
