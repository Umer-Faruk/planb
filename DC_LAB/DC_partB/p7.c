
#include<stdio.h>

#include<mpi.h>
#include<string.h>
#define BUFFER_SIZE 32

//  MPI data type:  MPI_INT, MPI_CHAR

// MPI_Send(value or massage to be send, size of message,data type  od message, recever rank id, uniqu tage ,MPI_COMM_WORLD);
// MPI_Recv(recevung message, size of reseving message,data type ,sender rank, unique tage same as sender,MPI_COMM_WORLD,&status);

int main(int argc, char* argv[])
{
	int rank,numprocs,tag=0,root=3,temp=1;
	char msg[BUFFER_SIZE];
	MPI_Init(&argc,&argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	if(rank==0)
	{
		strcpy(msg,"Hello");
          MPI_Send(msg,BUFFER_SIZE,MPI_CHAR,1,tag,MPI_COMM_WORLD);

          int x=10;
          MPI_Send(&x,1,MPI_INT,2,1,MPI_COMM_WORLD);
		
          
	}
	else if (rank == 1)
	{
		MPI_Recv(msg,BUFFER_SIZE,MPI_CHAR,0,tag,MPI_COMM_WORLD,&status);
		printf("\n%s  recve by  process  rank %d  and sent from process with rank %d\n",msg,rank,root);
	}
     else if(rank == 2){
          int y;
          MPI_Recv(&y,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
          printf("%d receve by process %d",y,rank);
     }
	MPI_Finalize();
}