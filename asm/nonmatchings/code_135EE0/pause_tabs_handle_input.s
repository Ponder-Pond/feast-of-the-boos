.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_handle_input
/* 138694 80245354 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 138698 80245358 AFB00010 */  sw        $s0, 0x10($sp)
/* 13869C 8024535C 0080802D */  daddu     $s0, $a0, $zero
/* 1386A0 80245360 3C030004 */  lui       $v1, 4
/* 1386A4 80245364 3C028027 */  lui       $v0, %hi(gPauseMenuHeldButtons)
/* 1386A8 80245368 8C4200C0 */  lw        $v0, %lo(gPauseMenuHeldButtons)($v0)
/* 1386AC 8024536C 34632000 */  ori       $v1, $v1, 0x2000
/* 1386B0 80245370 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1386B4 80245374 00431024 */  and       $v0, $v0, $v1
/* 1386B8 80245378 1040001D */  beqz      $v0, .L802453F0
/* 1386BC 8024537C AFB10014 */   sw       $s1, 0x14($sp)
/* 1386C0 80245380 24070005 */  addiu     $a3, $zero, 5
/* 1386C4 80245384 3C048027 */  lui       $a0, %hi(D_8027014C)
/* 1386C8 80245388 2484014C */  addiu     $a0, $a0, %lo(D_8027014C)
/* 1386CC 8024538C 3C068025 */  lui       $a2, %hi(gPauseMenuTabs)
/* 1386D0 80245390 24C6EF80 */  addiu     $a2, $a2, %lo(gPauseMenuTabs)
/* 1386D4 80245394 3C058025 */  lui       $a1, %hi(D_8024F1D0)
/* 1386D8 80245398 24A5F1D0 */  addiu     $a1, $a1, %lo(D_8024F1D0)
.L8024539C:
/* 1386DC 8024539C 92020001 */  lbu       $v0, 1($s0)
/* 1386E0 802453A0 2442FFFF */  addiu     $v0, $v0, -1
/* 1386E4 802453A4 A2020001 */  sb        $v0, 1($s0)
/* 1386E8 802453A8 00021600 */  sll       $v0, $v0, 0x18
/* 1386EC 802453AC 04410007 */  bgez      $v0, .L802453CC
/* 1386F0 802453B0 00000000 */   nop      
/* 1386F4 802453B4 A2070001 */  sb        $a3, 1($s0)
/* 1386F8 802453B8 8C830000 */  lw        $v1, ($a0)
/* 1386FC 802453BC 28620708 */  slti      $v0, $v1, 0x708
/* 138700 802453C0 10400002 */  beqz      $v0, .L802453CC
/* 138704 802453C4 24620708 */   addiu    $v0, $v1, 0x708
/* 138708 802453C8 AC820000 */  sw        $v0, ($a0)
.L802453CC:
/* 13870C 802453CC 82020001 */  lb        $v0, 1($s0)
/* 138710 802453D0 00451021 */  addu      $v0, $v0, $a1
/* 138714 802453D4 90420000 */  lbu       $v0, ($v0)
/* 138718 802453D8 00021080 */  sll       $v0, $v0, 2
/* 13871C 802453DC 00461021 */  addu      $v0, $v0, $a2
/* 138720 802453E0 8C420000 */  lw        $v0, ($v0)
/* 138724 802453E4 90420000 */  lbu       $v0, ($v0)
/* 138728 802453E8 1040FFEC */  beqz      $v0, .L8024539C
/* 13872C 802453EC 00000000 */   nop      
.L802453F0:
/* 138730 802453F0 3C030008 */  lui       $v1, 8
/* 138734 802453F4 3C028027 */  lui       $v0, %hi(gPauseMenuHeldButtons)
/* 138738 802453F8 8C4200C0 */  lw        $v0, %lo(gPauseMenuHeldButtons)($v0)
/* 13873C 802453FC 34630010 */  ori       $v1, $v1, 0x10
/* 138740 80245400 00431024 */  and       $v0, $v0, $v1
/* 138744 80245404 1040001D */  beqz      $v0, .L8024547C
/* 138748 80245408 00000000 */   nop      
/* 13874C 8024540C 3C038027 */  lui       $v1, %hi(D_8027014C)
/* 138750 80245410 2463014C */  addiu     $v1, $v1, %lo(D_8027014C)
/* 138754 80245414 3C058025 */  lui       $a1, %hi(gPauseMenuTabs)
/* 138758 80245418 24A5EF80 */  addiu     $a1, $a1, %lo(gPauseMenuTabs)
/* 13875C 8024541C 3C048025 */  lui       $a0, %hi(D_8024F1D0)
/* 138760 80245420 2484F1D0 */  addiu     $a0, $a0, %lo(D_8024F1D0)
.L80245424:
/* 138764 80245424 92020001 */  lbu       $v0, 1($s0)
/* 138768 80245428 24420001 */  addiu     $v0, $v0, 1
/* 13876C 8024542C A2020001 */  sb        $v0, 1($s0)
/* 138770 80245430 00021600 */  sll       $v0, $v0, 0x18
/* 138774 80245434 00021603 */  sra       $v0, $v0, 0x18
/* 138778 80245438 28420006 */  slti      $v0, $v0, 6
/* 13877C 8024543C 14400006 */  bnez      $v0, .L80245458
/* 138780 80245440 00000000 */   nop      
/* 138784 80245444 A2000001 */  sb        $zero, 1($s0)
/* 138788 80245448 8C620000 */  lw        $v0, ($v1)
/* 13878C 8024544C 18400002 */  blez      $v0, .L80245458
/* 138790 80245450 2442F8F8 */   addiu    $v0, $v0, -0x708
/* 138794 80245454 AC620000 */  sw        $v0, ($v1)
.L80245458:
/* 138798 80245458 82020001 */  lb        $v0, 1($s0)
/* 13879C 8024545C 00441021 */  addu      $v0, $v0, $a0
/* 1387A0 80245460 90420000 */  lbu       $v0, ($v0)
/* 1387A4 80245464 00021080 */  sll       $v0, $v0, 2
/* 1387A8 80245468 00451021 */  addu      $v0, $v0, $a1
/* 1387AC 8024546C 8C420000 */  lw        $v0, ($v0)
/* 1387B0 80245470 90420000 */  lbu       $v0, ($v0)
/* 1387B4 80245474 1040FFEB */  beqz      $v0, .L80245424
/* 1387B8 80245478 00000000 */   nop      
.L8024547C:
/* 1387BC 8024547C 3C118025 */  lui       $s1, %hi(D_8024F2E4)
/* 1387C0 80245480 2631F2E4 */  addiu     $s1, $s1, %lo(D_8024F2E4)
/* 1387C4 80245484 82030001 */  lb        $v1, 1($s0)
/* 1387C8 80245488 8E220000 */  lw        $v0, ($s1)
/* 1387CC 8024548C 10620022 */  beq       $v1, $v0, .L80245518
/* 1387D0 80245490 00000000 */   nop      
/* 1387D4 80245494 3C048025 */  lui       $a0, %hi(D_8024F1D8)
/* 1387D8 80245498 00832021 */  addu      $a0, $a0, $v1
/* 1387DC 8024549C 9084F1D8 */  lbu       $a0, %lo(D_8024F1D8)($a0)
/* 1387E0 802454A0 3C068024 */  lui       $a2, %hi(func_80243090)
/* 1387E4 802454A4 24C63090 */  addiu     $a2, $a2, %lo(func_80243090)
/* 1387E8 802454A8 0C051F92 */  jal       func_80147E48
/* 1387EC 802454AC 24050040 */   addiu    $a1, $zero, 0x40
/* 1387F0 802454B0 8E220000 */  lw        $v0, ($s1)
/* 1387F4 802454B4 3C048025 */  lui       $a0, %hi(D_8024F1D8)
/* 1387F8 802454B8 00822021 */  addu      $a0, $a0, $v0
/* 1387FC 802454BC 9084F1D8 */  lbu       $a0, %lo(D_8024F1D8)($a0)
/* 138800 802454C0 3C068024 */  lui       $a2, %hi(func_80242FF4)
/* 138804 802454C4 24C62FF4 */  addiu     $a2, $a2, %lo(func_80242FF4)
/* 138808 802454C8 0C051F92 */  jal       func_80147E48
/* 13880C 802454CC 24050040 */   addiu    $a1, $zero, 0x40
/* 138810 802454D0 3C048016 */  lui       $a0, %hi(D_8015A070)
/* 138814 802454D4 2484A070 */  addiu     $a0, $a0, %lo(D_8015A070)
/* 138818 802454D8 82020001 */  lb        $v0, 1($s0)
/* 13881C 802454DC 8E250000 */  lw        $a1, ($s1)
/* 138820 802454E0 00021140 */  sll       $v0, $v0, 5
/* 138824 802454E4 3C038016 */  lui       $v1, %hi(D_8015A07C)
/* 138828 802454E8 00621821 */  addu      $v1, $v1, $v0
/* 13882C 802454EC 8463A07C */  lh        $v1, %lo(D_8015A07C)($v1)
/* 138830 802454F0 24020019 */  addiu     $v0, $zero, 0x19
/* 138834 802454F4 A482024E */  sh        $v0, 0x24e($a0)
/* 138838 802454F8 3C018027 */  lui       $at, %hi(D_80270148)
/* 13883C 802454FC AC250148 */  sw        $a1, %lo(D_80270148)($at)
/* 138840 80245500 24630006 */  addiu     $v1, $v1, 6
/* 138844 80245504 A483024C */  sh        $v1, 0x24c($a0)
/* 138848 80245508 82020001 */  lb        $v0, 1($s0)
/* 13884C 8024550C 240400C8 */  addiu     $a0, $zero, 0xc8
/* 138850 80245510 0C05272D */  jal       play_sound
/* 138854 80245514 AE220000 */   sw       $v0, ($s1)
.L80245518:
/* 138858 80245518 3C028027 */  lui       $v0, %hi(gPauseMenuPressedButtons)
/* 13885C 8024551C 8C4200C4 */  lw        $v0, %lo(gPauseMenuPressedButtons)($v0)
/* 138860 80245520 30428000 */  andi      $v0, $v0, 0x8000
/* 138864 80245524 10400016 */  beqz      $v0, .L80245580
/* 138868 80245528 00000000 */   nop      
/* 13886C 8024552C 82020001 */  lb        $v0, 1($s0)
/* 138870 80245530 3C018025 */  lui       $at, %hi(D_8024F1D0)
/* 138874 80245534 00220821 */  addu      $at, $at, $v0
/* 138878 80245538 9022F1D0 */  lbu       $v0, %lo(D_8024F1D0)($at)
/* 13887C 8024553C 00021080 */  sll       $v0, $v0, 2
/* 138880 80245540 3C018025 */  lui       $at, %hi(gPauseMenuTabs)
/* 138884 80245544 00220821 */  addu      $at, $at, $v0
/* 138888 80245548 8C22EF80 */  lw        $v0, %lo(gPauseMenuTabs)($at)
/* 13888C 8024554C 3C118025 */  lui       $s1, %hi(D_8024F1D0)
/* 138890 80245550 2631F1D0 */  addiu     $s1, $s1, %lo(D_8024F1D0)
/* 138894 80245554 90430000 */  lbu       $v1, ($v0)
/* 138898 80245558 24020001 */  addiu     $v0, $zero, 1
/* 13889C 8024555C 14620008 */  bne       $v1, $v0, .L80245580
/* 1388A0 80245560 00000000 */   nop      
/* 1388A4 80245564 0C05272D */  jal       play_sound
/* 1388A8 80245568 240400C9 */   addiu    $a0, $zero, 0xc9
/* 1388AC 8024556C 82020001 */  lb        $v0, 1($s0)
/* 1388B0 80245570 00511021 */  addu      $v0, $v0, $s1
/* 1388B4 80245574 90420000 */  lbu       $v0, ($v0)
/* 1388B8 80245578 3C018027 */  lui       $at, %hi(gPauseMenuCurrentTab)
/* 1388BC 8024557C A02200D4 */  sb        $v0, %lo(gPauseMenuCurrentTab)($at)
.L80245580:
/* 1388C0 80245580 82020001 */  lb        $v0, 1($s0)
/* 1388C4 80245584 00021080 */  sll       $v0, $v0, 2
/* 1388C8 80245588 3C048025 */  lui       $a0, %hi(D_8024F2E8)
/* 1388CC 8024558C 00822021 */  addu      $a0, $a0, $v0
/* 1388D0 80245590 0C093BA0 */  jal       pause_get_menu_string
/* 1388D4 80245594 8C84F2E8 */   lw       $a0, %lo(D_8024F2E8)($a0)
/* 1388D8 80245598 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1388DC 8024559C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1388E0 802455A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 1388E4 802455A4 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 1388E8 802455A8 AC2200C8 */  sw        $v0, %lo(gPauseMenuCurrentDescString)($at)
/* 1388EC 802455AC 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescIconScript)
/* 1388F0 802455B0 AC2000CC */  sw        $zero, %lo(gPauseMenuCurrentDescIconScript)($at)
/* 1388F4 802455B4 03E00008 */  jr        $ra
/* 1388F8 802455B8 27BD0020 */   addiu    $sp, $sp, 0x20
