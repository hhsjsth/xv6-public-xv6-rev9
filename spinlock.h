// Mutual exclusion lock.
struct spinlock {
  uint locked; // Is the lock held?

  // For debugging:
  char *name;      // Name of lock.
  struct cpu *cpu; // The cpu holding the lock.
  uint pcs[10];    // The call stack (an array of program counters)
                   // that locked the lock.
};
int sh_var_for_sem_demo;

#define SEM_MAX_NUM 128    //信号量总数
extern int sem_used_count; //当前在用信号量数目
struct sem {
  struct spinlock lock; //内核自旋锁
  int resource_count;   //资源计数
  int *procs;           //阻塞进程号
  int allocated;        //是否被分配使用: 1 已分配， 0 未分配
};
extern struct sem sems[SEM_MAX_NUM]; //系统可有 SEM_MAX_NUM 个信号量