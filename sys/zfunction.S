		.global	zfunction
zfunction:
		#Prologue
		pushl	%ebp
		movl	%esp,					%ebp

		#Function Body
		movl	8(%esp),			%eax
		ANDl	$0xffc01fff,	%eax
		shl		$4,						%eax

		#Epilogue
		movl 	%ebp,					%esp
		popl	%ebp
		ret
