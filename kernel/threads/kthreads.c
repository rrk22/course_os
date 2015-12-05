/*
 * kthreads.c
 *
 *  Created on: Apr 23, 2015
 *      Author: mwkurian
 */

#include "kthread.h"
#include "scheduler.h"
#include "process.h"
#include <global_defs.h>
#include <vm.h>
#include "mmap.h"

typedef void (*kthread_callback_handler)();

//typedef enum THREAD_STATE;

/*kthread_handle* kthread_create(kthread_callback_handler cb_handler)
{
	kthread_handle * kthread = kmalloc(sizeof(kthread_handle));
	kthread->cb_handler = cb_handler;
	return kthread;
}*/

uint32_t kthread_start(kthread_handle * kthread)
{
	sched_task * task = sched_create_task_from_kthread(kthread, 10);
	sched_add_task(task);
	return 0;
}

kthread_handle* k_thread_creates(long var1, kthread_callback_handler func, long var3){
	struct vas *cur_vas = vm_get_current_vas();
	vm_use_kernel_vas();
	os_printf("k_thread_creates");
	kthread_handle * kthread = kmalloc(sizeof(kthread_handle));
	mmap(kthread);
	//kthread->cb_handler = cb_handler;
	//kthread->func = *func;
	//kthread->var1 = var1;
	vm_enable_vas(cur_vas);
	return kthread;
}

