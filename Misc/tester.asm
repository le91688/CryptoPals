
tester.c.o:     file format elf64-x86-64


Disassembly of section .init:

0000000000400418 <_init>:
  400418:	48 83 ec 08          	sub    $0x8,%rsp
  40041c:	48 8b 05 d5 0b 20 00 	mov    0x200bd5(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  400423:	48 85 c0             	test   %rax,%rax
  400426:	74 05                	je     40042d <_init+0x15>
  400428:	e8 53 00 00 00       	callq  400480 <__gmon_start__@plt>
  40042d:	48 83 c4 08          	add    $0x8,%rsp
  400431:	c3                   	retq   

Disassembly of section .plt:

0000000000400440 <puts@plt-0x10>:
  400440:	ff 35 c2 0b 20 00    	pushq  0x200bc2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400446:	ff 25 c4 0b 20 00    	jmpq   *0x200bc4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40044c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400450 <puts@plt>:
  400450:	ff 25 c2 0b 20 00    	jmpq   *0x200bc2(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400456:	68 00 00 00 00       	pushq  $0x0
  40045b:	e9 e0 ff ff ff       	jmpq   400440 <_init+0x28>

0000000000400460 <printf@plt>:
  400460:	ff 25 ba 0b 20 00    	jmpq   *0x200bba(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400466:	68 01 00 00 00       	pushq  $0x1
  40046b:	e9 d0 ff ff ff       	jmpq   400440 <_init+0x28>

0000000000400470 <__libc_start_main@plt>:
  400470:	ff 25 b2 0b 20 00    	jmpq   *0x200bb2(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400476:	68 02 00 00 00       	pushq  $0x2
  40047b:	e9 c0 ff ff ff       	jmpq   400440 <_init+0x28>

0000000000400480 <__gmon_start__@plt>:
  400480:	ff 25 aa 0b 20 00    	jmpq   *0x200baa(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400486:	68 03 00 00 00       	pushq  $0x3
  40048b:	e9 b0 ff ff ff       	jmpq   400440 <_init+0x28>

Disassembly of section .text:

0000000000400490 <_start>:
  400490:	31 ed                	xor    %ebp,%ebp
  400492:	49 89 d1             	mov    %rdx,%r9
  400495:	5e                   	pop    %rsi
  400496:	48 89 e2             	mov    %rsp,%rdx
  400499:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40049d:	50                   	push   %rax
  40049e:	54                   	push   %rsp
  40049f:	49 c7 c0 90 06 40 00 	mov    $0x400690,%r8
  4004a6:	48 c7 c1 20 06 40 00 	mov    $0x400620,%rcx
  4004ad:	48 c7 c7 7d 05 40 00 	mov    $0x40057d,%rdi
  4004b4:	e8 b7 ff ff ff       	callq  400470 <__libc_start_main@plt>
  4004b9:	f4                   	hlt    
  4004ba:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004004c0 <deregister_tm_clones>:
  4004c0:	b8 4f 10 60 00       	mov    $0x60104f,%eax
  4004c5:	55                   	push   %rbp
  4004c6:	48 2d 48 10 60 00    	sub    $0x601048,%rax
  4004cc:	48 83 f8 0e          	cmp    $0xe,%rax
  4004d0:	48 89 e5             	mov    %rsp,%rbp
  4004d3:	77 02                	ja     4004d7 <deregister_tm_clones+0x17>
  4004d5:	5d                   	pop    %rbp
  4004d6:	c3                   	retq   
  4004d7:	b8 00 00 00 00       	mov    $0x0,%eax
  4004dc:	48 85 c0             	test   %rax,%rax
  4004df:	74 f4                	je     4004d5 <deregister_tm_clones+0x15>
  4004e1:	5d                   	pop    %rbp
  4004e2:	bf 48 10 60 00       	mov    $0x601048,%edi
  4004e7:	ff e0                	jmpq   *%rax
  4004e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004f0 <register_tm_clones>:
  4004f0:	b8 48 10 60 00       	mov    $0x601048,%eax
  4004f5:	55                   	push   %rbp
  4004f6:	48 2d 48 10 60 00    	sub    $0x601048,%rax
  4004fc:	48 c1 f8 03          	sar    $0x3,%rax
  400500:	48 89 e5             	mov    %rsp,%rbp
  400503:	48 89 c2             	mov    %rax,%rdx
  400506:	48 c1 ea 3f          	shr    $0x3f,%rdx
  40050a:	48 01 d0             	add    %rdx,%rax
  40050d:	48 d1 f8             	sar    %rax
  400510:	75 02                	jne    400514 <register_tm_clones+0x24>
  400512:	5d                   	pop    %rbp
  400513:	c3                   	retq   
  400514:	ba 00 00 00 00       	mov    $0x0,%edx
  400519:	48 85 d2             	test   %rdx,%rdx
  40051c:	74 f4                	je     400512 <register_tm_clones+0x22>
  40051e:	5d                   	pop    %rbp
  40051f:	48 89 c6             	mov    %rax,%rsi
  400522:	bf 48 10 60 00       	mov    $0x601048,%edi
  400527:	ff e2                	jmpq   *%rdx
  400529:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400530 <__do_global_dtors_aux>:
  400530:	80 3d 11 0b 20 00 00 	cmpb   $0x0,0x200b11(%rip)        # 601048 <__TMC_END__>
  400537:	75 11                	jne    40054a <__do_global_dtors_aux+0x1a>
  400539:	55                   	push   %rbp
  40053a:	48 89 e5             	mov    %rsp,%rbp
  40053d:	e8 7e ff ff ff       	callq  4004c0 <deregister_tm_clones>
  400542:	5d                   	pop    %rbp
  400543:	c6 05 fe 0a 20 00 01 	movb   $0x1,0x200afe(%rip)        # 601048 <__TMC_END__>
  40054a:	f3 c3                	repz retq 
  40054c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400550 <frame_dummy>:
  400550:	48 83 3d c8 08 20 00 	cmpq   $0x0,0x2008c8(%rip)        # 600e20 <__JCR_END__>
  400557:	00 
  400558:	74 1e                	je     400578 <frame_dummy+0x28>
  40055a:	b8 00 00 00 00       	mov    $0x0,%eax
  40055f:	48 85 c0             	test   %rax,%rax
  400562:	74 14                	je     400578 <frame_dummy+0x28>
  400564:	55                   	push   %rbp
  400565:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  40056a:	48 89 e5             	mov    %rsp,%rbp
  40056d:	ff d0                	callq  *%rax
  40056f:	5d                   	pop    %rbp
  400570:	e9 7b ff ff ff       	jmpq   4004f0 <register_tm_clones>
  400575:	0f 1f 00             	nopl   (%rax)
  400578:	e9 73 ff ff ff       	jmpq   4004f0 <register_tm_clones>

000000000040057d <main>:
  40057d:	55                   	push   %rbp
  40057e:	48 89 e5             	mov    %rsp,%rbp
  400581:	48 83 ec 20          	sub    $0x20,%rsp
  400585:	c7 45 ec 01 00 00 00 	movl   $0x1,-0x14(%rbp)
  40058c:	c7 45 e8 00 00 00 01 	movl   $0x1000000,-0x18(%rbp)
  400593:	c7 45 f0 01 00 00 00 	movl   $0x1,-0x10(%rbp)
  40059a:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
  40059e:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  4005a2:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4005a6:	48 89 c6             	mov    %rax,%rsi
  4005a9:	bf a4 06 40 00       	mov    $0x4006a4,%edi
  4005ae:	b8 00 00 00 00       	mov    $0x0,%eax
  4005b3:	e8 a8 fe ff ff       	callq  400460 <printf@plt>
  4005b8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4005bc:	8b 00                	mov    (%rax),%eax
  4005be:	88 45 e7             	mov    %al,-0x19(%rbp)
  4005c1:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4005c5:	8b 00                	mov    (%rax),%eax
  4005c7:	89 45 f4             	mov    %eax,-0xc(%rbp)
  4005ca:	0f be 45 e7          	movsbl -0x19(%rbp),%eax
  4005ce:	89 c6                	mov    %eax,%esi
  4005d0:	bf b0 06 40 00       	mov    $0x4006b0,%edi
  4005d5:	b8 00 00 00 00       	mov    $0x0,%eax
  4005da:	e8 81 fe ff ff       	callq  400460 <printf@plt>
  4005df:	8b 45 f4             	mov    -0xc(%rbp),%eax
  4005e2:	89 c6                	mov    %eax,%esi
  4005e4:	bf bd 06 40 00       	mov    $0x4006bd,%edi
  4005e9:	b8 00 00 00 00       	mov    $0x0,%eax
  4005ee:	e8 6d fe ff ff       	callq  400460 <printf@plt>
  4005f3:	80 7d e7 00          	cmpb   $0x0,-0x19(%rbp)
  4005f7:	75 0c                	jne    400605 <main+0x88>
  4005f9:	bf cb 06 40 00       	mov    $0x4006cb,%edi
  4005fe:	e8 4d fe ff ff       	callq  400450 <puts@plt>
  400603:	eb 0a                	jmp    40060f <main+0x92>
  400605:	bf da 06 40 00       	mov    $0x4006da,%edi
  40060a:	e8 41 fe ff ff       	callq  400450 <puts@plt>
  40060f:	c9                   	leaveq 
  400610:	c3                   	retq   
  400611:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400618:	00 00 00 
  40061b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000400620 <__libc_csu_init>:
  400620:	41 57                	push   %r15
  400622:	41 89 ff             	mov    %edi,%r15d
  400625:	41 56                	push   %r14
  400627:	49 89 f6             	mov    %rsi,%r14
  40062a:	41 55                	push   %r13
  40062c:	49 89 d5             	mov    %rdx,%r13
  40062f:	41 54                	push   %r12
  400631:	4c 8d 25 d8 07 20 00 	lea    0x2007d8(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  400638:	55                   	push   %rbp
  400639:	48 8d 2d d8 07 20 00 	lea    0x2007d8(%rip),%rbp        # 600e18 <__init_array_end>
  400640:	53                   	push   %rbx
  400641:	4c 29 e5             	sub    %r12,%rbp
  400644:	31 db                	xor    %ebx,%ebx
  400646:	48 c1 fd 03          	sar    $0x3,%rbp
  40064a:	48 83 ec 08          	sub    $0x8,%rsp
  40064e:	e8 c5 fd ff ff       	callq  400418 <_init>
  400653:	48 85 ed             	test   %rbp,%rbp
  400656:	74 1e                	je     400676 <__libc_csu_init+0x56>
  400658:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40065f:	00 
  400660:	4c 89 ea             	mov    %r13,%rdx
  400663:	4c 89 f6             	mov    %r14,%rsi
  400666:	44 89 ff             	mov    %r15d,%edi
  400669:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40066d:	48 83 c3 01          	add    $0x1,%rbx
  400671:	48 39 eb             	cmp    %rbp,%rbx
  400674:	75 ea                	jne    400660 <__libc_csu_init+0x40>
  400676:	48 83 c4 08          	add    $0x8,%rsp
  40067a:	5b                   	pop    %rbx
  40067b:	5d                   	pop    %rbp
  40067c:	41 5c                	pop    %r12
  40067e:	41 5d                	pop    %r13
  400680:	41 5e                	pop    %r14
  400682:	41 5f                	pop    %r15
  400684:	c3                   	retq   
  400685:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  40068c:	00 00 00 00 

0000000000400690 <__libc_csu_fini>:
  400690:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400694 <_fini>:
  400694:	48 83 ec 08          	sub    $0x8,%rsp
  400698:	48 83 c4 08          	add    $0x8,%rsp
  40069c:	c3                   	retq   
