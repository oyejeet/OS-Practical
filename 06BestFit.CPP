#include <iostream>
using namespace std;

void BestFit(int np, int nb, int processes[], int partitions[], int partitionAllocated[]){
  int index, i;

  for(int i=0; i<np; i++){
    index = -1;

    for(int j=0; j<nb; j++){
      if(partitionAllocated[j] == 0 && partitions[j] >= processes[i]){
        if(index == -1 || partitions[j] < partitions[index]){
          index = j;
        }
      }
    }
    if(index != -1){
      partitionAllocated[index] = 1;
      cout << "Process " << i+1 << " is allocated to partition of size " << partitions[index] << endl;
    }
    else{
      cout << "Process " << i+1 << " is not allocated with any memory " << endl;
    }
  }
}

int main(){
  int nb = 5;
  int partitions[] = {100, 200, 300, 400, 450};

  int partitionAllocated[5] = {0};

  int np = 4;

  int processes[] = {412, 414, 450, 300};

  BestFit(np, nb, processes, partitions, partitionAllocated);
  
  return 0;
}