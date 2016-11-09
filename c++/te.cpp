#include <iostream>
#include <array>

using namespace std;

array<int,3> res;

array<int,3> test(array<int,3> a){
  for (int i=0;i<3;i++){
    a[i] += 1;
  }
  return a;
}
int main(void)
{
  array<int,3> ar2{1,2,3};
  res = test(ar2);
  for (int i=0;i<3;i++){
    cout<<res[i]<<endl;
  }
}
