#include <iostream>
#include <mpi/mpi.h>

using namespace std;

int main(int argv,char* argc[]){
    MPI_Init(&argv, &argc);
    cout<<"hello world"<<endl;
    MPI_Finalize();
    return 0;
}
