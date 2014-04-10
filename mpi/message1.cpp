#include <mpi/mpi.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int myid; // 当前进程的编号
    int numprocs; // 当前进程的名称
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Get_processor_name(processor_name,&namelen);
    int i;
    for(i=0; i<4; ++i){
        cout<<"I'm"<<myid<<", sending "<<i<<endl;
        sleep(1);
        if(0 == myid && 0 == i){
            MPI_Barrier(MPI_COMM_WORLD); //进程0将一直等待，直到其他并行进程执行结束
        }
    }
    MPI_Finalize(); //由于未执行MPI_Finalize，进程0无法感知到其他进程已退出
    return 0;
}
