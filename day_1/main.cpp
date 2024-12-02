#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<unordered_map>
constexpr int N=1000;
int main (int argc, char *argv[]) {
  std::ifstream inputFile("input.txt");
  std::ofstream outputFile("output.txt");
  std::string ln;
  int n1,n2;
  std::vector<int> a,b;
  while(inputFile >> n1 >> n2){
    a.push_back(n1);
    b.push_back(n2);
  }
  inputFile.close();
  std::sort(a.begin(),a.end());
  std::sort(b.begin(),b.end());
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=std::abs(a[i]-b[i]);
  }
  outputFile<<sum<<std::endl; //output for part 1 
  std::unordered_map<int,int> freq;
  for(int i:b){
    freq[i]++;
  }
  sum=0;
  for(int i:a){
    sum+=i*freq[i];
  }
  outputFile<<sum<<std::endl; //output for part 2
  return 0;
}
