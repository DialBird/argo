#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void do_stack(){
  puts("this is stack");
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  s.pop();
}

void do_queue(){
  puts("this is queue");
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  printf("%d\n", q.front());
  q.pop();
  printf("%d\n", q.front());
  q.pop();
  printf("%d\n", q.front());
  q.pop();
}

int main(int argc, char *argv[]){
  do_stack();
  do_queue();
  return 0;
}
