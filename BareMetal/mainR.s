
main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <idle_task>:
   0:	e7fe      	b.n	0 <idle_task>
   2:	bf00      	nop

00000004 <task1_handler>:
   4:	b508      	push	{r3, lr}
   6:	4c07      	ldr	r4, [pc, #28]	; (24 <task1_handler+0x20>)
   8:	200c      	movs	r0, #12
   a:	f7ff fffe 	bl	0 <led_on>
   e:	4620      	mov	r0, r4
  10:	f7ff fffe 	bl	0 <delay>
  14:	200c      	movs	r0, #12
  16:	f7ff fffe 	bl	0 <led_off>
  1a:	4620      	mov	r0, r4
  1c:	f7ff fffe 	bl	0 <delay>
  20:	e7f2      	b.n	8 <task1_handler+0x4>
  22:	bf00      	nop
  24:	001312d0 	.word	0x001312d0

00000028 <task2_handler>:
  28:	b508      	push	{r3, lr}
  2a:	4c07      	ldr	r4, [pc, #28]	; (48 <task2_handler+0x20>)
  2c:	200d      	movs	r0, #13
  2e:	f7ff fffe 	bl	0 <led_on>
  32:	4620      	mov	r0, r4
  34:	f7ff fffe 	bl	0 <delay>
  38:	200d      	movs	r0, #13
  3a:	f7ff fffe 	bl	0 <led_off>
  3e:	4620      	mov	r0, r4
  40:	f7ff fffe 	bl	0 <delay>
  44:	e7f2      	b.n	2c <task2_handler+0x4>
  46:	bf00      	nop
  48:	00098968 	.word	0x00098968

0000004c <task3_handler>:
  4c:	b508      	push	{r3, lr}
  4e:	4c07      	ldr	r4, [pc, #28]	; (6c <task3_handler+0x20>)
  50:	200f      	movs	r0, #15
  52:	f7ff fffe 	bl	0 <led_on>
  56:	4620      	mov	r0, r4
  58:	f7ff fffe 	bl	0 <delay>
  5c:	200f      	movs	r0, #15
  5e:	f7ff fffe 	bl	0 <led_off>
  62:	4620      	mov	r0, r4
  64:	f7ff fffe 	bl	0 <delay>
  68:	e7f2      	b.n	50 <task3_handler+0x4>
  6a:	bf00      	nop
  6c:	0004c4b4 	.word	0x0004c4b4

00000070 <task4_handler>:
  70:	b508      	push	{r3, lr}
  72:	4c07      	ldr	r4, [pc, #28]	; (90 <task4_handler+0x20>)
  74:	200e      	movs	r0, #14
  76:	f7ff fffe 	bl	0 <led_on>
  7a:	4620      	mov	r0, r4
  7c:	f7ff fffe 	bl	0 <delay>
  80:	200e      	movs	r0, #14
  82:	f7ff fffe 	bl	0 <led_off>
  86:	4620      	mov	r0, r4
  88:	f7ff fffe 	bl	0 <delay>
  8c:	e7f2      	b.n	74 <task4_handler+0x4>
  8e:	bf00      	nop
  90:	0002625a 	.word	0x0002625a

00000094 <memcpTmp>:
  94:	b112      	cbz	r2, 9c <memcpTmp+0x8>
  96:	0092      	lsls	r2, r2, #2
  98:	f7ff bffe 	b.w	0 <memcpy>
  9c:	4770      	bx	lr
  9e:	bf00      	nop

000000a0 <init_systick_timer>:
  a0:	4906      	ldr	r1, [pc, #24]	; (bc <init_systick_timer+0x1c>)
  a2:	4b07      	ldr	r3, [pc, #28]	; (c0 <init_systick_timer+0x20>)
  a4:	680a      	ldr	r2, [r1, #0]
  a6:	fbb3 f3f0 	udiv	r3, r3, r0
  aa:	b410      	push	{r4}
  ac:	4c05      	ldr	r4, [pc, #20]	; (c4 <init_systick_timer+0x24>)
  ae:	f042 0207 	orr.w	r2, r2, #7
  b2:	3b01      	subs	r3, #1
  b4:	6023      	str	r3, [r4, #0]
  b6:	bc10      	pop	{r4}
  b8:	600a      	str	r2, [r1, #0]
  ba:	4770      	bx	lr
  bc:	e000e010 	.word	0xe000e010
  c0:	00f42400 	.word	0x00f42400
  c4:	e000e014 	.word	0xe000e014

000000c8 <init_scheduler_stack>:
  c8:	f380 8808 	msr	MSP, r0
  cc:	4770      	bx	lr
  ce:	bf00      	nop

000000d0 <init_tasks_stack>:
  d0:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
  d4:	4947      	ldr	r1, [pc, #284]	; (1f4 <init_tasks_stack+0x124>)
  d6:	4c48      	ldr	r4, [pc, #288]	; (1f8 <init_tasks_stack+0x128>)
  d8:	4848      	ldr	r0, [pc, #288]	; (1fc <init_tasks_stack+0x12c>)
  da:	4b49      	ldr	r3, [pc, #292]	; (200 <init_tasks_stack+0x130>)
  dc:	f840 3c08 	str.w	r3, [r0, #-8]
  e0:	f04f 7680 	mov.w	r6, #16777216	; 0x1000000
  e4:	f840 6c04 	str.w	r6, [r0, #-4]
  e8:	4a46      	ldr	r2, [pc, #280]	; (204 <init_tasks_stack+0x134>)
  ea:	60e3      	str	r3, [r4, #12]
  ec:	f06f 0502 	mvn.w	r5, #2
  f0:	2300      	movs	r3, #0
  f2:	468c      	mov	ip, r1
  f4:	f8df e118 	ldr.w	lr, [pc, #280]	; 210 <init_tasks_stack+0x140>
  f8:	4f43      	ldr	r7, [pc, #268]	; (208 <init_tasks_stack+0x138>)
  fa:	f8df 8118 	ldr.w	r8, [pc, #280]	; 214 <init_tasks_stack+0x144>
  fe:	e940 3504 	strd	r3, r5, [r0, #-16]
 102:	e940 3306 	strd	r3, r3, [r0, #-24]
 106:	e940 3308 	strd	r3, r3, [r0, #-32]
 10a:	e940 330a 	strd	r3, r3, [r0, #-40]	; 0x28
 10e:	e940 330c 	strd	r3, r3, [r0, #-48]	; 0x30
 112:	e940 330e 	strd	r3, r3, [r0, #-56]	; 0x38
 116:	e940 3310 	strd	r3, r3, [r0, #-64]	; 0x40
 11a:	f8c4 e000 	str.w	lr, [r4]
 11e:	483b      	ldr	r0, [pc, #236]	; (20c <init_tasks_stack+0x13c>)
 120:	f8df e0f4 	ldr.w	lr, [pc, #244]	; 218 <init_tasks_stack+0x148>
 124:	61e7      	str	r7, [r4, #28]
 126:	7223      	strb	r3, [r4, #8]
 128:	7623      	strb	r3, [r4, #24]
 12a:	f884 3028 	strb.w	r3, [r4, #40]	; 0x28
 12e:	f884 3038 	strb.w	r3, [r4, #56]	; 0x38
 132:	f884 3048 	strb.w	r3, [r4, #72]	; 0x48
 136:	f841 7c08 	str.w	r7, [r1, #-8]
 13a:	f841 6c04 	str.w	r6, [r1, #-4]
 13e:	f841 3c14 	str.w	r3, [r1, #-20]
 142:	e941 3504 	strd	r3, r5, [r1, #-16]
 146:	4617      	mov	r7, r2
 148:	62e0      	str	r0, [r4, #44]	; 0x2c
 14a:	f8c4 803c 	str.w	r8, [r4, #60]	; 0x3c
 14e:	f8c4 e04c 	str.w	lr, [r4, #76]	; 0x4c
 152:	e941 3307 	strd	r3, r3, [r1, #-28]
 156:	e941 3309 	strd	r3, r3, [r1, #-36]	; 0x24
 15a:	e941 330b 	strd	r3, r3, [r1, #-44]	; 0x2c
 15e:	e941 330d 	strd	r3, r3, [r1, #-52]	; 0x34
 162:	e941 330f 	strd	r3, r3, [r1, #-60]	; 0x3c
 166:	f84c 3d40 	str.w	r3, [ip, #-64]!
 16a:	f5a1 6100 	sub.w	r1, r1, #2048	; 0x800
 16e:	f842 0c08 	str.w	r0, [r2, #-8]
 172:	f8c4 c010 	str.w	ip, [r4, #16]
 176:	4608      	mov	r0, r1
 178:	f842 6c04 	str.w	r6, [r2, #-4]
 17c:	f842 3c3c 	str.w	r3, [r2, #-60]
 180:	e942 3504 	strd	r3, r5, [r2, #-16]
 184:	e942 3306 	strd	r3, r3, [r2, #-24]
 188:	e942 3308 	strd	r3, r3, [r2, #-32]
 18c:	e942 330a 	strd	r3, r3, [r2, #-40]	; 0x28
 190:	e942 330c 	strd	r3, r3, [r2, #-48]	; 0x30
 194:	e942 330e 	strd	r3, r3, [r2, #-56]	; 0x38
 198:	f847 3d40 	str.w	r3, [r7, #-64]!
 19c:	f5a2 6200 	sub.w	r2, r2, #2048	; 0x800
 1a0:	6227      	str	r7, [r4, #32]
 1a2:	e941 8602 	strd	r8, r6, [r1, #-8]
 1a6:	e941 3504 	strd	r3, r5, [r1, #-16]
 1aa:	e941 3306 	strd	r3, r3, [r1, #-24]
 1ae:	e941 3308 	strd	r3, r3, [r1, #-32]
 1b2:	e941 330a 	strd	r3, r3, [r1, #-40]	; 0x28
 1b6:	e941 330c 	strd	r3, r3, [r1, #-48]	; 0x30
 1ba:	e941 330e 	strd	r3, r3, [r1, #-56]	; 0x38
 1be:	f841 3c3c 	str.w	r3, [r1, #-60]
 1c2:	f840 3d40 	str.w	r3, [r0, #-64]!
 1c6:	4611      	mov	r1, r2
 1c8:	f842 6c04 	str.w	r6, [r2, #-4]
 1cc:	6320      	str	r0, [r4, #48]	; 0x30
 1ce:	e942 5e03 	strd	r5, lr, [r2, #-12]
 1d2:	e942 3305 	strd	r3, r3, [r2, #-20]
 1d6:	e942 3307 	strd	r3, r3, [r2, #-28]
 1da:	e942 3309 	strd	r3, r3, [r2, #-36]	; 0x24
 1de:	e942 330b 	strd	r3, r3, [r2, #-44]	; 0x2c
 1e2:	e942 330d 	strd	r3, r3, [r2, #-52]	; 0x34
 1e6:	e942 330f 	strd	r3, r3, [r2, #-60]	; 0x3c
 1ea:	f841 3d40 	str.w	r3, [r1, #-64]!
 1ee:	6421      	str	r1, [r4, #64]	; 0x40
 1f0:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
 1f4:	20020000 	.word	0x20020000
 1f8:	00000000 	.word	0x00000000
 1fc:	2001f000 	.word	0x2001f000
 200:	00000000 	.word	0x00000000
 204:	2001fc00 	.word	0x2001fc00
	...
 210:	2001efc0 	.word	0x2001efc0
	...

0000021c <enable_processor_faults>:
 21c:	4a02      	ldr	r2, [pc, #8]	; (228 <enable_processor_faults+0xc>)
 21e:	6813      	ldr	r3, [r2, #0]
 220:	f443 23e0 	orr.w	r3, r3, #458752	; 0x70000
 224:	6013      	str	r3, [r2, #0]
 226:	4770      	bx	lr
 228:	e000ed24 	.word	0xe000ed24

0000022c <get_psp_value>:
 22c:	4b02      	ldr	r3, [pc, #8]	; (238 <get_psp_value+0xc>)
 22e:	4a03      	ldr	r2, [pc, #12]	; (23c <get_psp_value+0x10>)
 230:	781b      	ldrb	r3, [r3, #0]
 232:	011b      	lsls	r3, r3, #4
 234:	58d0      	ldr	r0, [r2, r3]
 236:	4770      	bx	lr
	...

00000240 <save_psp_value>:
 240:	4b02      	ldr	r3, [pc, #8]	; (24c <save_psp_value+0xc>)
 242:	4a03      	ldr	r2, [pc, #12]	; (250 <save_psp_value+0x10>)
 244:	781b      	ldrb	r3, [r3, #0]
 246:	011b      	lsls	r3, r3, #4
 248:	50d0      	str	r0, [r2, r3]
 24a:	4770      	bx	lr
	...

00000254 <update_next_task>:
 254:	b430      	push	{r4, r5}
 256:	493b      	ldr	r1, [pc, #236]	; (344 <update_next_task+0xf0>)
 258:	4c3b      	ldr	r4, [pc, #236]	; (348 <update_next_task+0xf4>)
 25a:	780b      	ldrb	r3, [r1, #0]
 25c:	4a3b      	ldr	r2, [pc, #236]	; (34c <update_next_task+0xf8>)
 25e:	3301      	adds	r3, #1
 260:	b2db      	uxtb	r3, r3
 262:	fba4 0503 	umull	r0, r5, r4, r3
 266:	f005 00fc 	and.w	r0, r5, #252	; 0xfc
 26a:	eb00 0095 	add.w	r0, r0, r5, lsr #2
 26e:	1a1b      	subs	r3, r3, r0
 270:	b2db      	uxtb	r3, r3
 272:	eb02 1003 	add.w	r0, r2, r3, lsl #4
 276:	7a00      	ldrb	r0, [r0, #8]
 278:	b9f0      	cbnz	r0, 2b8 <update_next_task+0x64>
 27a:	b9d3      	cbnz	r3, 2b2 <update_next_task+0x5e>
 27c:	7e13      	ldrb	r3, [r2, #24]
 27e:	2b00      	cmp	r3, #0
 280:	d042      	beq.n	308 <update_next_task+0xb4>
 282:	f892 3028 	ldrb.w	r3, [r2, #40]	; 0x28
 286:	2b00      	cmp	r3, #0
 288:	d05a      	beq.n	340 <update_next_task+0xec>
 28a:	2302      	movs	r3, #2
 28c:	482e      	ldr	r0, [pc, #184]	; (348 <update_next_task+0xf4>)
 28e:	3301      	adds	r3, #1
 290:	b2db      	uxtb	r3, r3
 292:	fba0 4003 	umull	r4, r0, r0, r3
 296:	f000 04fc 	and.w	r4, r0, #252	; 0xfc
 29a:	eb04 0090 	add.w	r0, r4, r0, lsr #2
 29e:	1a1b      	subs	r3, r3, r0
 2a0:	b2db      	uxtb	r3, r3
 2a2:	eb02 1003 	add.w	r0, r2, r3, lsl #4
 2a6:	7a00      	ldrb	r0, [r0, #8]
 2a8:	b9e8      	cbnz	r0, 2e6 <update_next_task+0x92>
 2aa:	b913      	cbnz	r3, 2b2 <update_next_task+0x5e>
 2ac:	7e13      	ldrb	r3, [r2, #24]
 2ae:	b35b      	cbz	r3, 308 <update_next_task+0xb4>
 2b0:	2300      	movs	r3, #0
 2b2:	700b      	strb	r3, [r1, #0]
 2b4:	bc30      	pop	{r4, r5}
 2b6:	4770      	bx	lr
 2b8:	3301      	adds	r3, #1
 2ba:	b2db      	uxtb	r3, r3
 2bc:	fba4 0503 	umull	r0, r5, r4, r3
 2c0:	f005 00fc 	and.w	r0, r5, #252	; 0xfc
 2c4:	eb00 0095 	add.w	r0, r0, r5, lsr #2
 2c8:	1a1b      	subs	r3, r3, r0
 2ca:	b2db      	uxtb	r3, r3
 2cc:	eb02 1003 	add.w	r0, r2, r3, lsl #4
 2d0:	7a00      	ldrb	r0, [r0, #8]
 2d2:	b9e8      	cbnz	r0, 310 <update_next_task+0xbc>
 2d4:	2b00      	cmp	r3, #0
 2d6:	d1ec      	bne.n	2b2 <update_next_task+0x5e>
 2d8:	7e13      	ldrb	r3, [r2, #24]
 2da:	b1ab      	cbz	r3, 308 <update_next_task+0xb4>
 2dc:	f892 3028 	ldrb.w	r3, [r2, #40]	; 0x28
 2e0:	2b00      	cmp	r3, #0
 2e2:	d02d      	beq.n	340 <update_next_task+0xec>
 2e4:	2302      	movs	r3, #2
 2e6:	4818      	ldr	r0, [pc, #96]	; (348 <update_next_task+0xf4>)
 2e8:	3301      	adds	r3, #1
 2ea:	b2db      	uxtb	r3, r3
 2ec:	fba0 4003 	umull	r4, r0, r0, r3
 2f0:	f000 04fc 	and.w	r4, r0, #252	; 0xfc
 2f4:	eb04 0090 	add.w	r0, r4, r0, lsr #2
 2f8:	1a1b      	subs	r3, r3, r0
 2fa:	b2db      	uxtb	r3, r3
 2fc:	eb02 1203 	add.w	r2, r2, r3, lsl #4
 300:	7a12      	ldrb	r2, [r2, #8]
 302:	2a00      	cmp	r2, #0
 304:	d0d5      	beq.n	2b2 <update_next_task+0x5e>
 306:	e7d3      	b.n	2b0 <update_next_task+0x5c>
 308:	2301      	movs	r3, #1
 30a:	700b      	strb	r3, [r1, #0]
 30c:	bc30      	pop	{r4, r5}
 30e:	4770      	bx	lr
 310:	3301      	adds	r3, #1
 312:	b2db      	uxtb	r3, r3
 314:	fba4 0403 	umull	r0, r4, r4, r3
 318:	f004 00fc 	and.w	r0, r4, #252	; 0xfc
 31c:	eb00 0494 	add.w	r4, r0, r4, lsr #2
 320:	1b1b      	subs	r3, r3, r4
 322:	b2db      	uxtb	r3, r3
 324:	eb02 1003 	add.w	r0, r2, r3, lsl #4
 328:	7a00      	ldrb	r0, [r0, #8]
 32a:	2800      	cmp	r0, #0
 32c:	d1ae      	bne.n	28c <update_next_task+0x38>
 32e:	2b00      	cmp	r3, #0
 330:	d1bf      	bne.n	2b2 <update_next_task+0x5e>
 332:	7e13      	ldrb	r3, [r2, #24]
 334:	2b00      	cmp	r3, #0
 336:	d0e7      	beq.n	308 <update_next_task+0xb4>
 338:	f892 3028 	ldrb.w	r3, [r2, #40]	; 0x28
 33c:	2b00      	cmp	r3, #0
 33e:	d1b7      	bne.n	2b0 <update_next_task+0x5c>
 340:	2302      	movs	r3, #2
 342:	e7b6      	b.n	2b2 <update_next_task+0x5e>
 344:	00000000 	.word	0x00000000
 348:	cccccccd 	.word	0xcccccccd
 34c:	00000000 	.word	0x00000000

00000350 <switch_sp_to_psp>:
 350:	b500      	push	{lr}
 352:	f7ff fffe 	bl	22c <get_psp_value>
 356:	f380 8809 	msr	PSP, r0
 35a:	f85d eb04 	ldr.w	lr, [sp], #4
 35e:	f04f 0002 	mov.w	r0, #2
 362:	f380 8814 	msr	CONTROL, r0
 366:	4770      	bx	lr

00000368 <schedule>:
 368:	4a02      	ldr	r2, [pc, #8]	; (374 <schedule+0xc>)
 36a:	6813      	ldr	r3, [r2, #0]
 36c:	f043 5380 	orr.w	r3, r3, #268435456	; 0x10000000
 370:	6013      	str	r3, [r2, #0]
 372:	4770      	bx	lr
 374:	e000ed04 	.word	0xe000ed04

00000378 <task_delay>:
 378:	f04f 0001 	mov.w	r0, #1
 37c:	f380 8810 	msr	PRIMASK, r0
 380:	4b0e      	ldr	r3, [pc, #56]	; (3bc <task_delay+0x44>)
 382:	781a      	ldrb	r2, [r3, #0]
 384:	b1a2      	cbz	r2, 3b0 <task_delay+0x38>
 386:	490e      	ldr	r1, [pc, #56]	; (3c0 <task_delay+0x48>)
 388:	4b0e      	ldr	r3, [pc, #56]	; (3c4 <task_delay+0x4c>)
 38a:	6809      	ldr	r1, [r1, #0]
 38c:	eb03 1302 	add.w	r3, r3, r2, lsl #4
 390:	b410      	push	{r4}
 392:	4408      	add	r0, r1
 394:	4c0c      	ldr	r4, [pc, #48]	; (3c8 <task_delay+0x50>)
 396:	6058      	str	r0, [r3, #4]
 398:	22ff      	movs	r2, #255	; 0xff
 39a:	721a      	strb	r2, [r3, #8]
 39c:	6823      	ldr	r3, [r4, #0]
 39e:	f043 5380 	orr.w	r3, r3, #268435456	; 0x10000000
 3a2:	6023      	str	r3, [r4, #0]
 3a4:	f04f 0000 	mov.w	r0, #0
 3a8:	f380 8810 	msr	PRIMASK, r0
 3ac:	bc10      	pop	{r4}
 3ae:	4770      	bx	lr
 3b0:	f04f 0000 	mov.w	r0, #0
 3b4:	f380 8810 	msr	PRIMASK, r0
 3b8:	4770      	bx	lr
 3ba:	bf00      	nop
	...
 3c8:	e000ed04 	.word	0xe000ed04

000003cc <PendSV_Handler>:
 3cc:	f3ef 8009 	mrs	r0, PSP
 3d0:	e920 0ff0 	stmdb	r0!, {r4, r5, r6, r7, r8, r9, sl, fp}
 3d4:	b500      	push	{lr}
 3d6:	f7ff fffe 	bl	240 <save_psp_value>
 3da:	f7ff fffe 	bl	254 <update_next_task>
 3de:	f7ff fffe 	bl	22c <get_psp_value>
 3e2:	e8b0 0ff0 	ldmia.w	r0!, {r4, r5, r6, r7, r8, r9, sl, fp}
 3e6:	f380 8809 	msr	PSP, r0
 3ea:	f85d eb04 	ldr.w	lr, [sp], #4
 3ee:	4770      	bx	lr

000003f0 <update_global_tick_count>:
 3f0:	4a02      	ldr	r2, [pc, #8]	; (3fc <update_global_tick_count+0xc>)
 3f2:	6813      	ldr	r3, [r2, #0]
 3f4:	3301      	adds	r3, #1
 3f6:	6013      	str	r3, [r2, #0]
 3f8:	4770      	bx	lr
 3fa:	bf00      	nop
 3fc:	00000000 	.word	0x00000000

00000400 <unblock_tasks>:
 400:	4b12      	ldr	r3, [pc, #72]	; (44c <unblock_tasks+0x4c>)
 402:	4a13      	ldr	r2, [pc, #76]	; (450 <unblock_tasks+0x50>)
 404:	7e19      	ldrb	r1, [r3, #24]
 406:	6812      	ldr	r2, [r2, #0]
 408:	b121      	cbz	r1, 414 <unblock_tasks+0x14>
 40a:	6959      	ldr	r1, [r3, #20]
 40c:	428a      	cmp	r2, r1
 40e:	bf04      	itt	eq
 410:	2100      	moveq	r1, #0
 412:	7619      	strbeq	r1, [r3, #24]
 414:	f893 1028 	ldrb.w	r1, [r3, #40]	; 0x28
 418:	b129      	cbz	r1, 426 <unblock_tasks+0x26>
 41a:	6a59      	ldr	r1, [r3, #36]	; 0x24
 41c:	428a      	cmp	r2, r1
 41e:	bf04      	itt	eq
 420:	2100      	moveq	r1, #0
 422:	f883 1028 	strbeq.w	r1, [r3, #40]	; 0x28
 426:	f893 1038 	ldrb.w	r1, [r3, #56]	; 0x38
 42a:	b129      	cbz	r1, 438 <unblock_tasks+0x38>
 42c:	6b59      	ldr	r1, [r3, #52]	; 0x34
 42e:	428a      	cmp	r2, r1
 430:	bf04      	itt	eq
 432:	2100      	moveq	r1, #0
 434:	f883 1038 	strbeq.w	r1, [r3, #56]	; 0x38
 438:	f893 1048 	ldrb.w	r1, [r3, #72]	; 0x48
 43c:	b129      	cbz	r1, 44a <unblock_tasks+0x4a>
 43e:	6c59      	ldr	r1, [r3, #68]	; 0x44
 440:	4291      	cmp	r1, r2
 442:	bf04      	itt	eq
 444:	2200      	moveq	r2, #0
 446:	f883 2048 	strbeq.w	r2, [r3, #72]	; 0x48
 44a:	4770      	bx	lr
	...

00000454 <SysTick_Handler>:
 454:	4916      	ldr	r1, [pc, #88]	; (4b0 <SysTick_Handler+0x5c>)
 456:	4b17      	ldr	r3, [pc, #92]	; (4b4 <SysTick_Handler+0x60>)
 458:	680a      	ldr	r2, [r1, #0]
 45a:	7e18      	ldrb	r0, [r3, #24]
 45c:	3201      	adds	r2, #1
 45e:	600a      	str	r2, [r1, #0]
 460:	b120      	cbz	r0, 46c <SysTick_Handler+0x18>
 462:	6959      	ldr	r1, [r3, #20]
 464:	428a      	cmp	r2, r1
 466:	bf04      	itt	eq
 468:	2100      	moveq	r1, #0
 46a:	7619      	strbeq	r1, [r3, #24]
 46c:	f893 1028 	ldrb.w	r1, [r3, #40]	; 0x28
 470:	b129      	cbz	r1, 47e <SysTick_Handler+0x2a>
 472:	6a59      	ldr	r1, [r3, #36]	; 0x24
 474:	428a      	cmp	r2, r1
 476:	bf04      	itt	eq
 478:	2100      	moveq	r1, #0
 47a:	f883 1028 	strbeq.w	r1, [r3, #40]	; 0x28
 47e:	f893 1038 	ldrb.w	r1, [r3, #56]	; 0x38
 482:	b129      	cbz	r1, 490 <SysTick_Handler+0x3c>
 484:	6b59      	ldr	r1, [r3, #52]	; 0x34
 486:	428a      	cmp	r2, r1
 488:	bf04      	itt	eq
 48a:	2100      	moveq	r1, #0
 48c:	f883 1038 	strbeq.w	r1, [r3, #56]	; 0x38
 490:	f893 1048 	ldrb.w	r1, [r3, #72]	; 0x48
 494:	b129      	cbz	r1, 4a2 <SysTick_Handler+0x4e>
 496:	6c59      	ldr	r1, [r3, #68]	; 0x44
 498:	4291      	cmp	r1, r2
 49a:	bf04      	itt	eq
 49c:	2200      	moveq	r2, #0
 49e:	f883 2048 	strbeq.w	r2, [r3, #72]	; 0x48
 4a2:	4a05      	ldr	r2, [pc, #20]	; (4b8 <SysTick_Handler+0x64>)
 4a4:	6813      	ldr	r3, [r2, #0]
 4a6:	f043 5380 	orr.w	r3, r3, #268435456	; 0x10000000
 4aa:	6013      	str	r3, [r2, #0]
 4ac:	4770      	bx	lr
 4ae:	bf00      	nop
	...
 4b8:	e000ed04 	.word	0xe000ed04

000004bc <HardFault_Handler>:
 4bc:	b508      	push	{r3, lr}
 4be:	4802      	ldr	r0, [pc, #8]	; (4c8 <HardFault_Handler+0xc>)
 4c0:	f7ff fffe 	bl	0 <puts>
 4c4:	e7fe      	b.n	4c4 <HardFault_Handler+0x8>
 4c6:	bf00      	nop
 4c8:	00000000 	.word	0x00000000

000004cc <MemManage_Handler>:
 4cc:	b508      	push	{r3, lr}
 4ce:	4802      	ldr	r0, [pc, #8]	; (4d8 <MemManage_Handler+0xc>)
 4d0:	f7ff fffe 	bl	0 <puts>
 4d4:	e7fe      	b.n	4d4 <MemManage_Handler+0x8>
 4d6:	bf00      	nop
 4d8:	00000018 	.word	0x00000018

000004dc <BusFault_Handler>:
 4dc:	b508      	push	{r3, lr}
 4de:	4802      	ldr	r0, [pc, #8]	; (4e8 <BusFault_Handler+0xc>)
 4e0:	f7ff fffe 	bl	0 <puts>
 4e4:	e7fe      	b.n	4e4 <BusFault_Handler+0x8>
 4e6:	bf00      	nop
 4e8:	00000030 	.word	0x00000030

Disassembly of section .text.startup:

00000000 <main>:
   0:	4a0c      	ldr	r2, [pc, #48]	; (34 <main+0x34>)
   2:	480d      	ldr	r0, [pc, #52]	; (38 <main+0x38>)
   4:	b508      	push	{r3, lr}
   6:	6813      	ldr	r3, [r2, #0]
   8:	f443 23e0 	orr.w	r3, r3, #458752	; 0x70000
   c:	6013      	str	r3, [r2, #0]
   e:	f7ff fffe 	bl	c8 <init_scheduler_stack>
  12:	f7ff fffe 	bl	d0 <init_tasks_stack>
  16:	f7ff fffe 	bl	0 <led_init_all>
  1a:	4a08      	ldr	r2, [pc, #32]	; (3c <main+0x3c>)
  1c:	4908      	ldr	r1, [pc, #32]	; (40 <main+0x40>)
  1e:	6813      	ldr	r3, [r2, #0]
  20:	f643 607f 	movw	r0, #15999	; 0x3e7f
  24:	f043 0307 	orr.w	r3, r3, #7
  28:	6013      	str	r3, [r2, #0]
  2a:	6008      	str	r0, [r1, #0]
  2c:	f7ff fffe 	bl	350 <switch_sp_to_psp>
  30:	f7ff fffe 	bl	4 <main+0x4>
  34:	e000ed24 	.word	0xe000ed24
  38:	2001ec00 	.word	0x2001ec00
  3c:	e000e010 	.word	0xe000e010
  40:	e000e014 	.word	0xe000e014
