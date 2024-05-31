#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
          int semid;
          char pathname[] = "for_ipc.ipc";
          key_t key;
          struct sembuf mybuf;
          if((key = ftok(pathname, 0)) < 0) {
                  printf("ne ydalos' generate key ipc\n");
                  exit(-1);
          }
          if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
                    printf("ne ydalos' get diskriptor massive semarfoz");
                    exit(-1);
          }
          mybuf.sem_op = 1;
          mybuf.sem_flg = 0;
          mybuf.sem_num = 0;
          printf(" unlock tekyshwgo procecca\n");
          if(semop(semid,&mybuf, 1) < 0) {
               printf("ne ydalos' vepolnit' operac nad semafonom\n");
               exit(-1);
          }
          printf("znachenie semafora edit one\n");
          return 0;
}

