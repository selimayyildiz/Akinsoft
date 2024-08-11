//Selim Ayyıldız 10.08.2024
//Toplamları tam bölünebilen çiftler
#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main() {
    int n,k,x;
    cout << "Dizinin uzunlugunu girin (2 < n < 1000): ";
    cin >> n;
    while (n <= 2 || n >= 1000) {
        cout << "Hatali girdi! Lütfen 2'den buyuk ve 1000'den kucuk bir sayi girin: ";
        cin >> n;
    }
    cout << "Pozitif tamsayi k'yi girin (1 < k < 100): ";
    cin >> k;
    while (k <= 1 || k >= 100) {
        cout << "Hatali girdi! Lütfen 1'den buyuk ve 100'den kucuk bir sayi girin: ";
        cin >> k;
    }
    vector<int> arr(n);
    random_device rd;
    for (int i = 0; i < n; ++i) {
        x = rd() % 1000 ;
        arr[i] = x;
    }
    cout << "Dizi: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    bool found = false;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((arr[i] + arr[j]) % k == 0) {
                cout << "(" << i << ", " << j << ")" << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Uygun cift bulunamadi." << endl;
    }
    return 0;
}