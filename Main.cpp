#include <iostream>
#include "Vector2.h"

using namespace std;

int main() {
    Vector2 v1(28,38);
    Vector2 v2(2,8);

    Vector2 v3=v1+v2;
    v3.dump();
    return 0;
}

