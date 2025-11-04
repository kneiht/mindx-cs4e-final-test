#include <iostream>
using namespace std;

// Hàm tính tổng ước
long long tongUoc(long long n) {
    // Cho tổng = 0
    long long tong = 0;

    // Xem từng số từ 1 đến n có phải là ước của n không
    // Nếu có thì thêm vào tổng
    for (long long i = 1; i <= n; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }

    // Trả về tổng
    return tong;
}

int main() {
    // Nhập số lượng test case
    int T;
    cout << "Nhập số lượng test case (1≤n≤100): ";
    cin >> T;
    
    // Vòng lặp for để nhập từng test case
    for (int i = 0; i < T; i++) {
        cout << "- Test case " << i + 1 << ": ";
        long long n;
        cin >> n;
        cout << " => Tổng ước của " << n << " là " << tongUoc(n) << endl;
    }
    
    return 0;
}

