	.arch msp430g2553

	.global delay

	.extern delCyc

delay:

	mov #0, r15		

	mov r12, r14	



top:

	cmp r14, r15

	jc out

	call #delCyc

	add #1, r15

	jmp top

out:

	ret



	
