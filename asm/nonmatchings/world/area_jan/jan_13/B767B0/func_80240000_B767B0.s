.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B767B0
/* B767B0 80240000 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B767B4 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* B767B8 80240008 3C118024 */  lui       $s1, %hi(func_80240850_AEDC60)
/* B767BC 8024000C 26310850 */  addiu     $s1, $s1, %lo(func_80240850_AEDC60)
/* B767C0 80240010 AFBF0020 */  sw        $ra, 0x20($sp)
/* B767C4 80240014 AFB3001C */  sw        $s3, 0x1c($sp)
/* B767C8 80240018 AFB20018 */  sw        $s2, 0x18($sp)
/* B767CC 8024001C AFB00010 */  sw        $s0, 0x10($sp)
/* B767D0 80240020 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* B767D4 80240024 F7B80038 */  sdc1      $f24, 0x38($sp)
/* B767D8 80240028 F7B60030 */  sdc1      $f22, 0x30($sp)
/* B767DC 8024002C F7B40028 */  sdc1      $f20, 0x28($sp)
/* B767E0 80240030 96220000 */  lhu       $v0, ($s1)
/* B767E4 80240034 3C018024 */  lui       $at, %hi(func_80243880_95EA80)
/* B767E8 80240038 D4203880 */  ldc1      $f0, %lo(func_80243880_95EA80)($at)
/* B767EC 8024003C 44826000 */  mtc1      $v0, $f12
/* B767F0 80240040 00000000 */  nop       
/* B767F4 80240044 46806320 */  cvt.s.w   $f12, $f12
/* B767F8 80240048 46006321 */  cvt.d.s   $f12, $f12
/* B767FC 8024004C 46206302 */  mul.d     $f12, $f12, $f0
/* B76800 80240050 00000000 */  nop       
/* B76804 80240054 0C00A85B */  jal       sin_rad
/* B76808 80240058 46206320 */   cvt.s.d  $f12, $f12
/* B7680C 8024005C 96220000 */  lhu       $v0, ($s1)
/* B76810 80240060 3C018024 */  lui       $at, %hi(D_80243888)
/* B76814 80240064 D4363888 */  ldc1      $f22, %lo(D_80243888)($at)
/* B76818 80240068 44826000 */  mtc1      $v0, $f12
/* B7681C 8024006C 00000000 */  nop       
/* B76820 80240070 46806320 */  cvt.s.w   $f12, $f12
/* B76824 80240074 46006321 */  cvt.d.s   $f12, $f12
/* B76828 80240078 46366302 */  mul.d     $f12, $f12, $f22
/* B7682C 8024007C 00000000 */  nop       
/* B76830 80240080 3C013F80 */  lui       $at, 0x3f80
/* B76834 80240084 4481D000 */  mtc1      $at, $f26
/* B76838 80240088 00000000 */  nop       
/* B7683C 8024008C 461A0500 */  add.s     $f20, $f0, $f26
/* B76840 80240090 3C018024 */  lui       $at, %hi(D_80243890)
/* B76844 80240094 D4383890 */  ldc1      $f24, %lo(D_80243890)($at)
/* B76848 80240098 4600A521 */  cvt.d.s   $f20, $f20
/* B7684C 8024009C 4638A502 */  mul.d     $f20, $f20, $f24
/* B76850 802400A0 00000000 */  nop       
/* B76854 802400A4 3C018024 */  lui       $at, %hi(func_80243898)
/* B76858 802400A8 D4203898 */  ldc1      $f0, %lo(func_80243898)($at)
/* B7685C 802400AC 4620A500 */  add.d     $f20, $f20, $f0
/* B76860 802400B0 0C00A85B */  jal       sin_rad
/* B76864 802400B4 46206320 */   cvt.s.d  $f12, $f12
/* B76868 802400B8 461A0000 */  add.s     $f0, $f0, $f26
/* B7686C 802400BC 46000021 */  cvt.d.s   $f0, $f0
/* B76870 802400C0 46360002 */  mul.d     $f0, $f0, $f22
/* B76874 802400C4 00000000 */  nop       
/* B76878 802400C8 4620A500 */  add.d     $f20, $f20, $f0
/* B7687C 802400CC 3C130001 */  lui       $s3, 1
/* B76880 802400D0 4620A520 */  cvt.s.d   $f20, $f20
/* B76884 802400D4 4600A021 */  cvt.d.s   $f0, $f20
/* B76888 802400D8 46380002 */  mul.d     $f0, $f0, $f24
/* B7688C 802400DC 00000000 */  nop       
/* B76890 802400E0 36731630 */  ori       $s3, $s3, 0x1630
/* B76894 802400E4 3C12800A */  lui       $s2, %hi(D_8009A674)
/* B76898 802400E8 2652A674 */  addiu     $s2, $s2, %lo(D_8009A674)
/* B7689C 802400EC 3C108007 */  lui       $s0, %hi(D_800741F0)
/* B768A0 802400F0 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* B768A4 802400F4 3C013FE0 */  lui       $at, 0x3fe0
/* B768A8 802400F8 44811800 */  mtc1      $at, $f3
/* B768AC 802400FC 44801000 */  mtc1      $zero, $f2
/* B768B0 80240100 96040000 */  lhu       $a0, ($s0)
/* B768B4 80240104 8E420000 */  lw        $v0, ($s2)
/* B768B8 80240108 00042180 */  sll       $a0, $a0, 6
/* B768BC 8024010C 46220000 */  add.d     $f0, $f0, $f2
/* B768C0 80240110 00932021 */  addu      $a0, $a0, $s3
/* B768C4 80240114 00442021 */  addu      $a0, $v0, $a0
/* B768C8 80240118 46200020 */  cvt.s.d   $f0, $f0
/* B768CC 8024011C 44050000 */  mfc1      $a1, $f0
/* B768D0 80240120 4406A000 */  mfc1      $a2, $f20
/* B768D4 80240124 0C019DC0 */  jal       guScale
/* B768D8 80240128 00A0382D */   daddu    $a3, $a1, $zero
/* B768DC 8024012C 3C05DA38 */  lui       $a1, 0xda38
/* B768E0 80240130 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* B768E4 80240134 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* B768E8 80240138 34A50001 */  ori       $a1, $a1, 1
/* B768EC 8024013C 8C820000 */  lw        $v0, ($a0)
/* B768F0 80240140 96030000 */  lhu       $v1, ($s0)
/* B768F4 80240144 0040302D */  daddu     $a2, $v0, $zero
/* B768F8 80240148 24420008 */  addiu     $v0, $v0, 8
/* B768FC 8024014C AC820000 */  sw        $v0, ($a0)
/* B76900 80240150 24620001 */  addiu     $v0, $v1, 1
/* B76904 80240154 3063FFFF */  andi      $v1, $v1, 0xffff
/* B76908 80240158 00031980 */  sll       $v1, $v1, 6
/* B7690C 8024015C 00731821 */  addu      $v1, $v1, $s3
/* B76910 80240160 ACC50000 */  sw        $a1, ($a2)
/* B76914 80240164 A6020000 */  sh        $v0, ($s0)
/* B76918 80240168 8E420000 */  lw        $v0, ($s2)
/* B7691C 8024016C 96240000 */  lhu       $a0, ($s1)
/* B76920 80240170 00431021 */  addu      $v0, $v0, $v1
/* B76924 80240174 24840001 */  addiu     $a0, $a0, 1
/* B76928 80240178 ACC20004 */  sw        $v0, 4($a2)
/* B7692C 8024017C A6240000 */  sh        $a0, ($s1)
/* B76930 80240180 8FBF0020 */  lw        $ra, 0x20($sp)
/* B76934 80240184 8FB3001C */  lw        $s3, 0x1c($sp)
/* B76938 80240188 8FB20018 */  lw        $s2, 0x18($sp)
/* B7693C 8024018C 8FB10014 */  lw        $s1, 0x14($sp)
/* B76940 80240190 8FB00010 */  lw        $s0, 0x10($sp)
/* B76944 80240194 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* B76948 80240198 D7B80038 */  ldc1      $f24, 0x38($sp)
/* B7694C 8024019C D7B60030 */  ldc1      $f22, 0x30($sp)
/* B76950 802401A0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B76954 802401A4 03E00008 */  jr        $ra
/* B76958 802401A8 27BD0048 */   addiu    $sp, $sp, 0x48
