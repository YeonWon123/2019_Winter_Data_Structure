// F. 피보나치 수
// Top-Down 방식 Recursion
// 중복계산을 하지 않으려고, 어딘가에 메모해두는 Memoization 기법 사용

#include <iostream>
using namespace std;

int n, d[50] = {0, 1};
int fibo(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    if(d[n] != 0)
        return d[n];
    d[n] = fibo(n - 2) + fibo(n - 1);
    return d[n];
}

int main() {
    cin >> n;
    cout << fibo(n);
}
