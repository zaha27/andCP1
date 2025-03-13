	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
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
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	ldr	w8, [sp, #8]
	subs	w8, w8, #2
	cset	w8, ne
	tbnz	w8, #0, LBB0_3
	b	LBB0_2
LBB0_2:
	mov	w8, #1                          ; =0x1
	stur	w8, [x29, #-4]
	b	LBB0_4
LBB0_3:
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
	b	LBB0_4
LBB0_4:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0                          ; =0x0
	str	w8, [sp, #16]                   ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	sub	x8, x29, #8
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	stur	wzr, [x29, #-8]
	stur	wzr, [x29, #-12]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_scanf
	ldur	w0, [x29, #-8]
	bl	_fibo
	stur	w0, [x29, #-12]
	ldur	w9, [x29, #-12]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	ldr	w0, [sp, #16]                   ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"n = "

l_.str.1:                               ; @.str.1
	.asciz	"%d"

l_.str.2:                               ; @.str.2
	.asciz	"r = %d"

.subsections_via_symbols
