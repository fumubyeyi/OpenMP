#include <iostream>
#include <omp.h>

using namespace std;

#define THREAD_NUM 4

int serial_sum(int n){

  int sum = 0;
  for(int i = 0; i< n; i++){
    sum += i;
  }
  return sum;
}

int parallel_sum(int n){
   
  int sum = 0;
 
  omp_set_num_threads(THREAD_NUM);
 
#pragma omp parallel for reduction (+ : sum)
  for (int i = 0; i< n ; i++){
    sum += i;
  }
  return sum;
}

int main(){

  int number;
  double start_time, end_time;

  cout << "Please enter a positive integer: ";
  cin >> number;  // get user input 
  
  if (cin.fail()){
    // Not an integer
    cout << "Please enter a postive integer" << endl;
  }
  
  start_time = omp_get_wtime();
  int serial_result = serial_sum(number);
  end_time = omp_get_wtime();

  cout << "Serial sum : " << serial_result << ", took " << (end_time - start_time) << " seconds." <<endl;

  start_time = omp_get_wtime();
  int parallel_result = parallel_sum(number);
  end_time = omp_get_wtime();

  cout << "Serial sum : " << parallel_result << ", took "<< (end_time - start_time) << " seconds." <<endl;
  

  return 0;
}
