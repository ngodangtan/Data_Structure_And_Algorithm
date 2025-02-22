//
// Created by Felix Ngo on 17/2/25.
//

#include <iostream>
using namespace std;

struct ToaDo {
  float x;
  float y;
};

void inToaDo(ToaDo a) {
  cout << "x: " << a.x << endl;
  cout << "y: " << a.y << endl;
}

void inToaDo2(ToaDo* a) {
  // cout << "x: " << a->x << endl;
  // cout << "y: " << a->y << endl;

  cout << "x: " << (*a).x << endl;
  cout << "y: " << (*a).y << endl;
}

int main() {
  int x = 5;
  ToaDo a = {6, 7};

  inToaDo(a);
  ToaDo* p = new ToaDo;
  *p = a;
  inToaDo2(p);
  return 0;
}