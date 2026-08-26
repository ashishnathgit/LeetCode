#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> x = {11, 20, 10};
  for (int nums : x) {
    cout << nums << " ";
  }
  cout << "hello";
  return 0;
}
