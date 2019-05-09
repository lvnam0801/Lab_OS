#include <linux/kernel.h>   // printk
#include <linux/sched.h>    // struct task_struct, find_task_by_vpid()
#include <linux/linkage.h>  // asmlinkage
#include <asm/current.h>    // struct task_struct* current
#include <linux/errno.h>    // EINVAL
#include <linux/syscalls.h> // SYSCALL_DEFINEx()
#include <linux/uaccess.h>  // copy_to_user(), ?(copy_from_user)
#include <linux/list.h>     // list_empty()
#include <linux/string.h>   // strcpy()

struct proc_info {  //info about a single process
    pid_t pid;      //pid of the process
    char name [16]; //file name of the program executed
};

struct procinfos {                      //info about processes we need
    long studentID;                     //for the assignment testing
    struct proc_info proc;              // process with pid or current process
    struct proc_info parent_proc;       // parent process
    struct proc_info oldest_child_proc; // oldest child process
};



//asmlinkage long sys_get_proc_info(pid_t u_pid , struct procinfos * info) 
SYSCALL_DEFINE2(get_proc_info, int, pid, struct procinfos*, info)   // sys_get_proc_info
{   

    // *--------------------- INITIALIZE --------------------
        // task_struct : pid (process ID), comm(name of process)
    struct task_struct  * proc = NULL,                  // current process                   
                        * parent_proc = NULL,           // parent process
                        * oldest_child_proc = NULL;     // oldest child process

    struct procinfos kinfo;  //initialize kernel variable
    // *-----------------------------------------------------

    kinfo.studentID = 1712237;
    printk("%i", 1712237);

    // ? copy_from_user()

    // *-------------- CURRENT PROCESS------------------------------

    if(pid == -1)                                           // get current process to proc
        proc = current;
    else if(pid == 0)
        proc = find_task_by_vpid(2)->parent;                // get task_struct process 0 into current proc
    else 
        proc = find_task_by_vpid(pid);                      // find process by pid
        
    if(!proc) 
        return EINVAL;                              

    kinfo.proc.pid = proc->pid;
    strcpy(kinfo.proc.name ,proc->comm);
    
    // *-------------------------------------------------------------
  


    // *---------------PARENT PROCESS--------------------------------

    parent_proc = proc->parent;
    if(parent_proc == NULL || pid == 0){
        kinfo.parent_proc.pid = -1;
        strcpy(kinfo.parent_proc.name, "NULL");
    }
    else{
        kinfo.parent_proc.pid = parent_proc->pid;
        strcpy(kinfo.parent_proc.name,  parent_proc->comm);
    }

    // *--------------------------------------------------------------


    // *-------------- OLDEST_CHILDREN_PROCESS------------------------
    //if(!list_first_entry_or_null(&proc->children, struct task_struct, sibling)){    // list_first_entry_or_null : oldest_child_proc
    
    if(list_empty(&proc->children)) {                                                 
        kinfo.oldest_child_proc.pid = -1;
        strcpy(kinfo.oldest_child_proc.name, "NULL");
    }
    else{
        oldest_child_proc = list_first_entry(&proc->children, struct task_struct, sibling);
        kinfo.oldest_child_proc.pid = oldest_child_proc->pid;
        strcpy(kinfo.oldest_child_proc.name, oldest_child_proc->comm);
    }

    // *---------------------------------------------------------------

    copy_to_user(info, &kinfo, sizeof(struct procinfos));       // copy data to user space

    return 0;
}



