#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mips.h"



unsigned int* instr_memory;
unsigned int* data_memory;
void mips_cpu(int,int *);
unsigned int stringBin(char *bin)
{
    char *b;
    unsigned int n,bit;

    b = bin;
    n = 0;

    while( *b != '\n' )
    {
        n <<= 1;
        bit = *b=='1' ? 1 : 0;
        if(bit)
            n |= 0x0001;
        b++;
        if( *b=='\0')
            break;
    }
    //printf("%u\n",n);
    return(n);
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
			printf("Please provide the instructions file\n");
			exit(1);
	}

    //FILE *asm_instr;
    FILE *asm_instr = fopen(argv[1],"r");
    //Here we first initialize the instruction memory & data memory & registers

    int reg[REGISTERS_NUMBER];
    for(int i=0;i<REGISTERS_NUMBER;i++){
        reg[i]=0;
    }
    
    instr_memory = (int*)malloc((INSTR_SIZE_BITS*INSTR_MEMORY_LINES)/4);
    
    data_memory = (int*)malloc((DATA_MEMORY_SIZE)/4);
    //each asm instruction converted to binary is written in to instr memory.
    char mystring[34];
    //char* mystring_1;
    unsigned int i=0;
    unsigned int v;
    while(fgets(mystring,34,asm_instr)) {
        v = stringBin(mystring);
        instr_memory[i] = v;
        i+=1;
    }
    for(i=0;i<INSTR_MEMORY_LINES;i++) {
        mips_cpu(i,reg);
    }
    for(i=0;i<REGISTERS_NUMBER;i++) {
        printf("reg_%d = %d\n",i,reg[i]);
    }
    fclose(asm_instr);
    return 0;
}

void mips_cpu (int pc,int* registers) {
    //step 1
    //instruction fetch from instruction memory
    unsigned int instruction;
    instruction = instr_memory[pc];
    //step 2
    //instruction decode 
    unsigned int opcode,rs,rs_1,rt,rt_1,rd,rd_1,shamt,shamt_1,func,func_1;
    short int imm;
    opcode = instruction >> 26;
    rs_1   = instruction >> 21;
    rs     = rs_1 &(0X1F);
    rt_1   = instruction >> 16;
    rt     = rt_1&(0X1F);
    rd_1   = instruction >> 11;
    rd     = rd_1&(0X1F);
    shamt_1 = instruction >> 6;
    shamt   = shamt_1 &(0X1F);
    func    = instruction &(0X3F);
    imm     = instruction&(0XFFFF); 
    printf("opcode_%d = %d\n",pc,opcode);
    printf("rs_%d     = %d\n",pc,rs);
    printf("rt_%d     = %d\n",pc,rt);
    printf("rd_%d     = %d\n",pc,rd);
    printf("shamt_%d  = %d\n",pc,shamt);
    printf("func_%d   = %d\n",pc,func);
    printf("imm_%d    = %d\n",pc,imm);
    //step 2.5
    //extracting reg values;
    int register_1,register_2,destination_register,memory_output;

    register_1=registers[rs];
    register_2=registers[rt];
    //step 3
    //ALU
    if(opcode==R_INST) {
        if(func==SLL) {
            destination_register = register_2 << shamt;
        }
        else if((func==SRL)||(func==SRA)) {
            destination_register = register_2 >> shamt;
        }
        else if(func==SLLV) {
            destination_register = register_2 << register_1;
        }
        else if((func==SRLV)||(func==SRAV)) {
            destination_register = register_2 >> register_1;
        }
        else if(func==ADD) {
            destination_register = register_1+register_2;
        }
        else if(func==ADDU) {
            destination_register = (unsigned int) register_1 + (unsigned int) register_2;
        }
        else if(func==SUB) {
            destination_register = register_1-register_2;
        }
        else if(func==SUBU) {
            destination_register = (unsigned int)register_1-(unsigned int)register_2;
        }
        else if(func==AND) {
            destination_register = register_1&register_2;
        }
        else if(func==OR) {
            destination_register = register_1|register_2;
        }
        else if(func==NOR) {
            destination_register = ~(register_1|register_2);
        }
        else if(func==SLT) {
            destination_register = register_1<register_2;
        }
        else if(func==SLTU) {
            destination_register = (unsigned int)register_1<(unsigned int)register_2;
        }
        else {
            destination_register = 0;
        }
        

    }else {
        if((opcode==ADDI)||(opcode==LB)||(opcode==LH)||(opcode==LW)||(opcode==LHU)||(opcode==LBU)||(opcode==SB)||(opcode==SH)||(opcode==SW)) {
            destination_register = register_1+(int) imm;
        }
        else if(opcode==ADDIU) {
            destination_register = (unsigned int)(register_1+(int) imm);
        }
        else if(opcode==ANDI) {
            destination_register = register_1&(int)imm;
        }
        else if(opcode==ORI) {
            destination_register = register_1|(int)imm;
        }
        else if(opcode==SLTI) {
            destination_register = register_1<(int) imm;
        }
        else if(opcode==SLTIU) {
            destination_register = (unsigned int)register_1<(unsigned int)imm;
        }
        else if(opcode==LUI) {
            destination_register =  imm << 16;
        }
        else {
            destination_register = 0;
        }
    }

    //step4 
    //Memory rd/wr
    if(opcode==LB) {
        memory_output = (data_memory[destination_register]) & 0XFF;
    } 
    else if(opcode==LH) {
        memory_output = (data_memory[destination_register]) & 0XFFFF;
    }
    else if(opcode==LW) {
        memory_output = (data_memory[destination_register]);
    }
    else if(opcode==LBU) {
        memory_output = (data_memory[destination_register]) & 0X000000FF;
    } 
    else if(opcode==LHU) {
        memory_output = (data_memory[destination_register]) & 0X0000FFFF;
    }
    else if(opcode==SB) {
        data_memory[destination_register] = registers[rt] & 0X000000FF;
    } 
    else if(opcode==SH) {
        data_memory[destination_register] = registers[rt] & 0X0000FFFF;
    }
    else if(opcode==LW) {
        data_memory[destination_register] = registers[rt];
    }

    //step5
    //Register_WB
    if((opcode==R_INST)&&(func >= 0)&&(func<=43)) {
        registers[rd] = destination_register;
    }
    else if ((opcode>=8)&&(opcode<=15)) {
        registers[rt] = destination_register;
    }
    else if((opcode>=32)&&(opcode<=37)) {
        registers[rt] = memory_output;
    }
}


