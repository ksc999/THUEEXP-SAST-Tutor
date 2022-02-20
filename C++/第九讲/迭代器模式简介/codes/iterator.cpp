#include <iostream>
#include <vector>
#include <iterator>
#include <cstring>
using namespace std;

int main() {
  vector<int> vec = {1, 2, 3, 4, 5};

  cout << "use iterator:" << endl;
  for (auto iter1 = vec.begin(); iter1 != vec.end(); iter1++)
    cout << *iter1 << " ";
    
  cout << endl << "use reverse iterator:" << endl;
  for (auto iter2 = vec.crbegin(); iter2 != vec.crend(); iter2++)
    cout << *iter2 << " ";
}