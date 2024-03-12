#include "BST.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;
double bstASL=0;
int binarysearch(const vector<int> &arr, int i, int j, int target) {
  int times = 0;
  int n = arr.size();
  while (i <= j) {
    // int mid=(i+j)/2;
    times++;
    int mid = i + ((j - i) >> 1);
    if (arr[mid] < target) {
      i = mid + 1;
      continue;
    }
    if (arr[mid] == target) {
      bstASL+=times;
      return mid;
    } else {
      j = mid - 1;
      continue;
    }
  }
  bstASL+=times;
   return -1;
}
std::vector<int> generateRandomData(int size) {
  std::vector<int> data;
  std::mt19937 generator(time(nullptr)); // 使用当前时间作为随机数生成器的种子
  std::uniform_int_distribution<int> distribution(0, INT_MAX);

  for (int i = 0; i < size; ++i) {
    data.push_back(distribution(generator)); // 生成一个随机数并添加到序列中
  }

  return data;
}

double caculateBstASL(const vector<int> &arr) {
  double bstASL;
  BinarySearchTree bst;
  for (auto i : arr) {
    bst.insert(i); // 把数据集中的元素全部插入bst中
  }


  for (int i = 0; i < arr.size(); i++) {
    bst.asl=0;
    bst.search(arr[i]);
    //  cout << bst.asl << '\n';
     bstASL+=bst.asl;
  }
  return bstASL/arr.size();
}
double caculateBinarySearcgASL( vector<int> &arr) {
  bstASL=0;
  sort(arr.begin(),arr.end());
  for (int i = 0; i < arr.size(); i++) {
    binarysearch(arr, 0, arr.size(), arr[i]) ;
  }
  return bstASL/arr.size();
}
void evalutate() {
  ofstream outputBanarySearch("binarySearchASL.txt");
  ofstream outputBST("BSTASL.txt");
  vector<double> size{10,100,300,500,800,1000,2000,3000,4000,5000,6000,7000,9000,12000,15000,18000,20000,30000,50000,90000,1e5,5e5,1e6,5e6,1e7};
  vector<vector<int>> data;
  for (int i = 0; i < size.size(); i++) {
    data.push_back(generateRandomData(size[i]));
    // caculateBinarySearcgASL(data[i]);
    // cout<<caculateBstASL(data[i])<<' ';
    outputBST << caculateBstASL(data[i]) << ' ';
    outputBanarySearch << caculateBinarySearcgASL(data[i])<<' ';
  }
  outputBanarySearch.close();
  outputBST.close();
}
int main() {
  evalutate();
  return 0;
}
