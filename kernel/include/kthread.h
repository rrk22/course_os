/*
 * kthread.h
 *
 *  Created on: Apr 23, 2015
 *      Author: mwkurian
 */
#include "process.h"
#ifndef KERNEL_INCLUDE_KTHREAD_H_
#define KERNEL_INCLUDE_KTHREAD_H_

typedef void (*kthread_callback_handler)();

typedef struct kthread_handle {
    uint32_t parent_pid;
    int niceness;
    int state;
    kthread_callback_handler cb_handler;

	//ID data
	char* name; /* for debugging purposes */
	uint32_t TID;
	uint32_t starting_address;
	uint32_t process_number; // is this a mapping to actual executable image? or does it describe total number of processes?
	uint32_t user_id;
	uint32_t group_id;
	uint32_t parent_id;
	uint32_t (*function)();
	uint32_t has_executed;
	struct vas* stored_vas;
	uint32_t start;
	uint32_t len;
	//CPU state data
	PROCESS_STATE current_state;
	pcb *pcb_p;
	uint32_t thread_stack_base;
	uint32_t stack_top;
	uint32_t thread_state;
	/*
	 * r0-r3 are the argument and scratch registers; r0-r1 are also the result registers
	 * r4-r8 are callee-save registers
	 * r9 might be a callee-save register or not (on some variants of AAPCS it is a special register)
	 * r10-r11 are callee-save registers
	 * r12-r15 are special registers
	 * 37 REGISTERS IN TOTAL: 31 GPRs, 6 SRs
	 */

	// WE ARE GOING TO TRY TO IMPLEMENT SETJMP/LONGJMP INSTEAD OF MANUALLY DEALING WITH THESE VALUES
	// uint32_t PC;
	// uint32_t SP;
	// uint32_t CPSR; //current prog status register
	// uint32_t SPSR; //saved prog status register when execption occurs
	//unbanked register
	uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R4;
	uint32_t R5;
	uint32_t R6;
	uint32_t R7;

	//banked registers
	uint32_t R8;
	uint32_t R9;
	uint32_t R10;
	uint32_t R11;
	uint32_t R12;
	uint32_t R13; //corresponds to the SP; do we need both?
	uint32_t R14;
	uint32_t R15; //corresponds to the PC; do we need both?

	//Control data
	//int priority_value;
	//uint32_t elapsed_time;
	//uint32_t EFLAG;
	//uint32_t* process_relations
	//uint32_t total_cpu_time;

//CPU state data
	uint32_t SPSR;
	uint32_t PC;

//Control data
	int priority_value;
	uint32_t elapsed_time;
	uint32_t EFLAG;
	uint32_t* process_relations;

	uint32_t total_cpu_time;

	void* heap_p;

} kthread_handle;

/*typedef struct tcb
{


} tcb;*/




kthread_handle* k_thread_creates(long var1, kthread_callback_handler cb_handler, long var2);




void init_thread_heap(tcb* tcb_p);
void init_thread_stack(tcb* tcb_p);

#endif /* KERNEL_INCLUDE_KTHREAD_H_ */
