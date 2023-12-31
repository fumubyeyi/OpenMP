#include <iostream>
#include <omp.h>

using namespace std;

#define THREAD_NUM 8

int main (){

  omp_set_num_threads(THREAD_NUM);
  int nthreads; 

#pragma omp parallel 
  {
    int id = omp_get_thread_num();
    nthreads = omp_get_num_threads();

#pragma omp critical
    cout << "Hello, from thread " << id << " out of " << nthreads << " threads.\n" << endl;

  }
  return 0;
}
