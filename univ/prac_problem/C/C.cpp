#include <iostream>
#include<fstream>
#include <random>
#include<vector>
#include<algorithm>
#define SIZE 100000
using namespace std;
int main()
{
  ofstream outFile("output.txt");
  /* Seed */
  random_device rd;
  /* Random number generator */
  default_random_engine generator(rd());

  /* Distribution on which to apply the generator */
  uniform_int_distribution<long long unsigned> distribution(0x0,0x7FFFFFF);

  for (int i = 0; i < SIZE; i++) {
      unsigned long long x;
      x = distribution(generator);
      outFile<<x<<endl;
  }
  outFile.close();

  ifstream inFile("output.txt");
  vector<long long> a;
  if(inFile.is_open()){
    for(int i=0;i<SIZE;i++){
      long long x;
      inFile>>x;
      a.push_back(x);
    }
  }
  sort(a.begin(),a.end());
  ofstream out("out2.txt");
  for(int i=0;i<a.size();i++){
    out<<a[i]<<endl;
  }
  inFile.close();
  out.close();
  return 0;
}
