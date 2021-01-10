.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0086000
/* 389850 E0086000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 389854 E0086004 AFB00028 */  sw        $s0, 0x28($sp)
/* 389858 E0086008 0080802D */  daddu     $s0, $a0, $zero
/* 38985C E008600C F7B40050 */  sdc1      $f20, 0x50($sp)
/* 389860 E0086010 4485A000 */  mtc1      $a1, $f20
/* 389864 E0086014 3C055555 */  lui       $a1, 0x5555
/* 389868 E0086018 34A55556 */  ori       $a1, $a1, 0x5556
/* 38986C E008601C F7B60058 */  sdc1      $f22, 0x58($sp)
/* 389870 E0086020 4486B000 */  mtc1      $a2, $f22
/* 389874 E0086024 27A40010 */  addiu     $a0, $sp, 0x10
/* 389878 E0086028 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 38987C E008602C 4487C000 */  mtc1      $a3, $f24
/* 389880 E0086030 8FA3007C */  lw        $v1, 0x7c($sp)
/* 389884 E0086034 3C02E008 */  lui       $v0, %hi(func_E0086270)
/* 389888 E0086038 24426270 */  addiu     $v0, $v0, %lo(func_E0086270)
/* 38988C E008603C AFA20018 */  sw        $v0, 0x18($sp)
/* 389890 E0086040 3C02E008 */  lui       $v0, %hi(func_E0086278)
/* 389894 E0086044 24426278 */  addiu     $v0, $v0, %lo(func_E0086278)
/* 389898 E0086048 AFA2001C */  sw        $v0, 0x1c($sp)
/* 38989C E008604C 3C02E008 */  lui       $v0, %hi(func_E0086390)
/* 3898A0 E0086050 24426390 */  addiu     $v0, $v0, %lo(func_E0086390)
/* 3898A4 E0086054 AFBF0048 */  sw        $ra, 0x48($sp)
/* 3898A8 E0086058 AFB70044 */  sw        $s7, 0x44($sp)
/* 3898AC E008605C AFB60040 */  sw        $s6, 0x40($sp)
/* 3898B0 E0086060 AFB5003C */  sw        $s5, 0x3c($sp)
/* 3898B4 E0086064 AFB40038 */  sw        $s4, 0x38($sp)
/* 3898B8 E0086068 AFB30034 */  sw        $s3, 0x34($sp)
/* 3898BC E008606C AFB20030 */  sw        $s2, 0x30($sp)
/* 3898C0 E0086070 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3898C4 E0086074 AFA00010 */  sw        $zero, 0x10($sp)
/* 3898C8 E0086078 AFA20020 */  sw        $v0, 0x20($sp)
/* 3898CC E008607C 00031080 */  sll       $v0, $v1, 2
/* 3898D0 E0086080 00431021 */  addu      $v0, $v0, $v1
/* 3898D4 E0086084 24420014 */  addiu     $v0, $v0, 0x14
/* 3898D8 E0086088 3C03E008 */  lui       $v1, %hi(func_E0086398)
/* 3898DC E008608C 24636398 */  addiu     $v1, $v1, %lo(func_E0086398)
/* 3898E0 E0086090 00450018 */  mult      $v0, $a1
/* 3898E4 E0086094 AFA30024 */  sw        $v1, 0x24($sp)
/* 3898E8 E0086098 24030043 */  addiu     $v1, $zero, 0x43
/* 3898EC E008609C 000217C3 */  sra       $v0, $v0, 0x1f
/* 3898F0 E00860A0 AFA30014 */  sw        $v1, 0x14($sp)
/* 3898F4 E00860A4 00004010 */  mfhi      $t0
/* 3898F8 E00860A8 01021023 */  subu      $v0, $t0, $v0
/* 3898FC E00860AC 0C080124 */  jal       func_E0200490
/* 389900 E00860B0 24550001 */   addiu    $s5, $v0, 1
/* 389904 E00860B4 00152100 */  sll       $a0, $s5, 4
/* 389908 E00860B8 00952021 */  addu      $a0, $a0, $s5
/* 38990C E00860BC 00042080 */  sll       $a0, $a0, 2
/* 389910 E00860C0 0040B02D */  daddu     $s6, $v0, $zero
/* 389914 E00860C4 0C08012C */  jal       func_E02004B0
/* 389918 E00860C8 AED50008 */   sw       $s5, 8($s6)
/* 38991C E00860CC 0040882D */  daddu     $s1, $v0, $zero
/* 389920 E00860D0 16200003 */  bnez      $s1, .LE00860E0
/* 389924 E00860D4 AED1000C */   sw       $s1, 0xc($s6)
.LE00860D8:
/* 389928 E00860D8 08021836 */  j         .LE00860D8
/* 38992C E00860DC 00000000 */   nop      
.LE00860E0:
/* 389930 E00860E0 AE300000 */  sw        $s0, ($s1)
/* 389934 E00860E4 E6340004 */  swc1      $f20, 4($s1)
/* 389938 E00860E8 E6360008 */  swc1      $f22, 8($s1)
/* 38993C E00860EC E638000C */  swc1      $f24, 0xc($s1)
/* 389940 E00860F0 3C02E008 */  lui       $v0, %hi(D_E0086AC0)
/* 389944 E00860F4 00501021 */  addu      $v0, $v0, $s0
/* 389948 E00860F8 90426AC0 */  lbu       $v0, %lo(D_E0086AC0)($v0)
/* 38994C E00860FC AE200034 */  sw        $zero, 0x34($s1)
/* 389950 E0086100 AE200038 */  sw        $zero, 0x38($s1)
/* 389954 E0086104 AE220030 */  sw        $v0, 0x30($s1)
/* 389958 E0086108 24020001 */  addiu     $v0, $zero, 1
/* 38995C E008610C 1202000C */  beq       $s0, $v0, .LE0086140
/* 389960 E0086110 2A020002 */   slti     $v0, $s0, 2
/* 389964 E0086114 10400012 */  beqz      $v0, .LE0086160
/* 389968 E0086118 240200FF */   addiu    $v0, $zero, 0xff
/* 38996C E008611C 16000011 */  bnez      $s0, .LE0086164
/* 389970 E0086120 240300C8 */   addiu    $v1, $zero, 0xc8
/* 389974 E0086124 240200FF */  addiu     $v0, $zero, 0xff
/* 389978 E0086128 A222003C */  sb        $v0, 0x3c($s1)
/* 38997C E008612C A222003D */  sb        $v0, 0x3d($s1)
/* 389980 E0086130 A222003E */  sb        $v0, 0x3e($s1)
/* 389984 E0086134 A222003F */  sb        $v0, 0x3f($s1)
/* 389988 E0086138 0802185F */  j         .LE008617C
/* 38998C E008613C A2220040 */   sb       $v0, 0x40($s1)
.LE0086140:
/* 389990 E0086140 240200FF */  addiu     $v0, $zero, 0xff
/* 389994 E0086144 A222003C */  sb        $v0, 0x3c($s1)
/* 389998 E0086148 A222003D */  sb        $v0, 0x3d($s1)
/* 38999C E008614C A220003E */  sb        $zero, 0x3e($s1)
/* 3899A0 E0086150 A222003F */  sb        $v0, 0x3f($s1)
/* 3899A4 E0086154 A2200040 */  sb        $zero, 0x40($s1)
/* 3899A8 E0086158 08021860 */  j         .LE0086180
/* 3899AC E008615C A2200041 */   sb       $zero, 0x41($s1)
.LE0086160:
/* 3899B0 E0086160 240300C8 */  addiu     $v1, $zero, 0xc8
.LE0086164:
/* 3899B4 E0086164 A222003C */  sb        $v0, 0x3c($s1)
/* 3899B8 E0086168 A222003D */  sb        $v0, 0x3d($s1)
/* 3899BC E008616C A2220040 */  sb        $v0, 0x40($s1)
/* 3899C0 E0086170 240200E6 */  addiu     $v0, $zero, 0xe6
/* 3899C4 E0086174 A220003E */  sb        $zero, 0x3e($s1)
/* 3899C8 E0086178 A223003F */  sb        $v1, 0x3f($s1)
.LE008617C:
/* 3899CC E008617C A2220041 */  sb        $v0, 0x41($s1)
.LE0086180:
/* 3899D0 E0086180 24130001 */  addiu     $s3, $zero, 1
/* 3899D4 E0086184 C7A00078 */  lwc1      $f0, 0x78($sp)
/* 3899D8 E0086188 0275102A */  slt       $v0, $s3, $s5
/* 3899DC E008618C E6200028 */  swc1      $f0, 0x28($s1)
/* 3899E0 E0086190 10400028 */  beqz      $v0, .LE0086234
/* 3899E4 E0086194 26310044 */   addiu    $s1, $s1, 0x44
/* 3899E8 E0086198 26B4FFFF */  addiu     $s4, $s5, -1
/* 3899EC E008619C 241700FF */  addiu     $s7, $zero, 0xff
/* 3899F0 E00861A0 2630002C */  addiu     $s0, $s1, 0x2c
/* 3899F4 E00861A4 24120168 */  addiu     $s2, $zero, 0x168
.LE00861A8:
/* 3899F8 E00861A8 16800002 */  bnez      $s4, .LE00861B4
/* 3899FC E00861AC 0254001A */   div      $zero, $s2, $s4
/* 389A00 E00861B0 0007000D */  break     7
.LE00861B4:
/* 389A04 E00861B4 2401FFFF */   addiu    $at, $zero, -1
/* 389A08 E00861B8 16810004 */  bne       $s4, $at, .LE00861CC
/* 389A0C E00861BC 3C018000 */   lui      $at, 0x8000
/* 389A10 E00861C0 16410002 */  bne       $s2, $at, .LE00861CC
/* 389A14 E00861C4 00000000 */   nop      
/* 389A18 E00861C8 0006000D */  break     6
.LE00861CC:
/* 389A1C E00861CC 00001812 */   mflo     $v1
/* 389A20 E00861D0 24040167 */  addiu     $a0, $zero, 0x167
/* 389A24 E00861D4 26520168 */  addiu     $s2, $s2, 0x168
/* 389A28 E00861D8 4483A000 */  mtc1      $v1, $f20
/* 389A2C E00861DC 00000000 */  nop       
/* 389A30 E00861E0 4680A520 */  cvt.s.w   $f20, $f20
/* 389A34 E00861E4 0C080138 */  jal       func_E02004E0
/* 389A38 E00861E8 26730001 */   addiu    $s3, $s3, 1
/* 389A3C E00861EC 44820000 */  mtc1      $v0, $f0
/* 389A40 E00861F0 00000000 */  nop       
/* 389A44 E00861F4 46800020 */  cvt.s.w   $f0, $f0
/* 389A48 E00861F8 AE00FFD8 */  sw        $zero, -0x28($s0)
/* 389A4C E00861FC AE00FFDC */  sw        $zero, -0x24($s0)
/* 389A50 E0086200 AE00FFE0 */  sw        $zero, -0x20($s0)
/* 389A54 E0086204 AE00FFE4 */  sw        $zero, -0x1c($s0)
/* 389A58 E0086208 AE00FFE8 */  sw        $zero, -0x18($s0)
/* 389A5C E008620C AE00FFF4 */  sw        $zero, -0xc($s0)
/* 389A60 E0086210 AE200000 */  sw        $zero, ($s1)
/* 389A64 E0086214 E614FFF0 */  swc1      $f20, -0x10($s0)
/* 389A68 E0086218 E600FFF8 */  swc1      $f0, -8($s0)
/* 389A6C E008621C AE00FFE4 */  sw        $zero, -0x1c($s0)
/* 389A70 E0086220 AE170000 */  sw        $s7, ($s0)
/* 389A74 E0086224 26100044 */  addiu     $s0, $s0, 0x44
/* 389A78 E0086228 0275102A */  slt       $v0, $s3, $s5
/* 389A7C E008622C 1440FFDE */  bnez      $v0, .LE00861A8
/* 389A80 E0086230 26310044 */   addiu    $s1, $s1, 0x44
.LE0086234:
/* 389A84 E0086234 02C0102D */  daddu     $v0, $s6, $zero
/* 389A88 E0086238 8FBF0048 */  lw        $ra, 0x48($sp)
/* 389A8C E008623C 8FB70044 */  lw        $s7, 0x44($sp)
/* 389A90 E0086240 8FB60040 */  lw        $s6, 0x40($sp)
/* 389A94 E0086244 8FB5003C */  lw        $s5, 0x3c($sp)
/* 389A98 E0086248 8FB40038 */  lw        $s4, 0x38($sp)
/* 389A9C E008624C 8FB30034 */  lw        $s3, 0x34($sp)
/* 389AA0 E0086250 8FB20030 */  lw        $s2, 0x30($sp)
/* 389AA4 E0086254 8FB1002C */  lw        $s1, 0x2c($sp)
/* 389AA8 E0086258 8FB00028 */  lw        $s0, 0x28($sp)
/* 389AAC E008625C D7B80060 */  ldc1      $f24, 0x60($sp)
/* 389AB0 E0086260 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 389AB4 E0086264 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 389AB8 E0086268 03E00008 */  jr        $ra
/* 389ABC E008626C 27BD0068 */   addiu    $sp, $sp, 0x68
