	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_afisare                        ; -- Begin function afisare
	.p2align	2
_afisare:                               ; @afisare
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_fibo                           ; -- Begin function fibo
	.p2align	2
_fibo:                                  ; @fibo
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	w0, [sp, #8]
	str	wzr, [sp, #4]
	ldr	w8, [sp, #8]
	subs	w8, w8, #1
	cset	w8, eq
	tbnz	w8, #0, LBB1_2
	b	LBB1_1
LBB1_1:
	ldr	w8, [sp, #8]
	subs	w8, w8, #2
	cset	w8, ne
	tbnz	w8, #0, LBB1_3
	b	LBB1_2
LBB1_2:
	mov	w8, #1                          ; =0x1
	stur	w8, [x29, #-4]
	b	LBB1_4
LBB1_3:
	ldr	w8, [sp, #8]
	subs	w0, w8, #1
	bl	_fibo
	str	w0, [sp]                        ; 4-byte Folded Spill
	ldr	w8, [sp, #8]
	subs	w0, w8, #2
	bl	_fibo
	mov	x8, x0
	ldr	w0, [sp]                        ; 4-byte Folded Reload
	add	w8, w0, w8
	str	w8, [sp, #4]
	ldr	w8, [sp, #4]
	stur	w8, [x29, #-4]
	b	LBB1_4
LBB1_4:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"ceva diferit de abcd"

.subsections_via_symbols
