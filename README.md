## mips_simulator_in_C

* This repo contains "MIPS" cpu implemented in C-Language.
* Design file is "mips.c"
* Header file is "mips.h"
* This folder contains the test programs i've used for testing my model.
* There are four programs as seen.
* C model expects instructions in binary format.
* first write your program in a file similar to the programs given.
* Then through python file "convert_asm_bin.py" convert your program file to binary format.

        > python convert_asm_bin.py --asm=third_program

* output file will be created as "third_program_binary.txt" with instructions in binary format.
* Then run mips through the following command.

        > gcc mips.c
        > ./a.out third_program_binary.txt
* Four programs have been written and tested.
* New programs can be tested in the same given way.
* In R-type instructions the following instructions are supported.

|   instrunction    |   func    |   example          |
|-------------------|-----------|--------------------|
|   sll             |   0       |sll $rd,  $rt, shamt|
|   srl             |   2       |srl $rd,  $rt, shamt|
|   sra             |   3       |sra $rd,  $rt, shamt|
|   sllv            |   4       |sllv $rd,  $rt, $rs |
|   srlv            |   6       |srlv $rd,  $rt, $rs |
|   srav            |   7       |srav $rd,  $rt, $rs |
|   add             |   32      |add  $rd, $rs, $rt  |
|   addu            |   33      |addu $rd, $rs, $rt  |
|   sub             |   34      |sub  $rd, $rs, $rt  |
|   subu            |   35      |subu $rd, $rs, $rt  |
|   and             |   36      |and  $rd, $rs, $rt  |
|   or              |   37      |or   $rd, $rs, $rt  |
|   xor             |   38      |xor  $rd, $rs, $rt  |
|   nor             |   39      |nor  $rd, $rs, $rt  |
|   slt             |   42      |slt  $rd, $rs, $rt  |
|   sltu            |   43      |sltu $rd, $rs, $rt  |



* In I-type instructions the following instructions are supported.
* Opcode is > 0 for all I-type instructions.
* this type of instruction is decoded by "opcode" field.

|   instrunction    |   opcode  |   example        |
|-------------------|-----------|------------------|
|   addi            |   8       |addi  $rt, $rs,imm|
|   addiu           |   9       |addiu $rt, $rs,imm|
|   slti            |  10       |slti  $rt, $rs,imm|
|   sltiu           |  11       |sltiu $rt, $rs,imm|
|   andi            |  12       |andi  $rt, $rs,imm|
|   ori             |  13       |ori   $rt, $rs,imm|
|   xori            |  14       |xori  $rt, $rs,imm|
|   lui             |  15       |lui   $rt, imm    |
|   lb              |  32       |lb    $rt,imm($rs)| 
|   lh              |  33       |lh    $rt,imm($rs)|
|   lw              |  34       |lw    $rt,imm($rs)|  
|   lbu             |  36       |lbu   $rt,imm($rs)|    
|   lhu             |  37       |lhu   $rt,imm($rs)|    
|   sb              |  40       |sb    $rt,imm($rs)|
|   sh              |  41       |sh    $rt,imm($rs)|
|   sw              |  43       |sw    $rt,imm($rs)|
