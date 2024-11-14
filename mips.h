/*
MIT License

Copyright (c) 2024 Elsie Rezinold Y

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#define INSTR_SIZE_BITS 32
#define INSTR_MEMORY_LINES 93
#define DATA_MEMORY_SIZE 32*1024
#define REGISTERS_NUMBER 32

#define R_INST 0
#define SLL 0
#define SRL 2
#define SRA 3
#define SLLV 4
#define SRLV 6
#define SRAV 7
#define ADD 32
#define ADDU 33
#define SUB 34
#define SUBU 35
#define AND 36
#define OR 37
#define XOR 38
#define NOR 39
#define SLT 42
#define SLTU 43
#define ADDI   8
#define ADDIU  9
#define SLTI  10 
#define SLTIU 11
#define ANDI  12
#define ORI   13
#define XORI  14
#define LUI   15
#define LB    32
#define LH    33
#define LW    34
#define LBU   36
#define LHU   37
#define SB    40
#define SH    41
#define SW    43


