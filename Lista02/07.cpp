#include <bits/stdc++.h>
using namespace std;

int PISO_RAIZ(int i, int j, int N) {
  if (i <= j) {
    int mid = (i + j) / 2;
    if ((mid * mid <= N) && ((mid + 1) * (mid + 1) > N)) {
      return mid;
    } else if (mid * mid < N) {
      return PISO_RAIZ(mid + 1, j, N);
    } else {
      return PISO_RAIZ(i, mid - 1, N);
    }
  }
  return i;
}
int main() {
  int N = 27;
  cout << PISO_RAIZ(0, N, N) << endl;
  return 0;
}
