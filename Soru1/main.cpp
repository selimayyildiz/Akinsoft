//Selim Ayyıldız 08.08.2024
//Hedef konum mesafesi
#include <iostream>
#include <random>
using namespace std;
int func(int y) {
    random_device rd;
    int x;
    while (true) {
        x = rd() % 21;  
        if ((x < y - 5 || x > y + 5)) { // Bir sonraki adımın bir önceki adımdan 5 birim uzak olmasını kontrol etme
            break;
        }
    }
    return x;
}
int mainfunc(){
    int cevre = 2 * 3.14 * 3.2;
    cout << "Cevre: " << cevre << endl;
    random_device rd;
    int x = rd() % 20;
    int noktalar[10];
    noktalar[0] = x;
    cout << "Mini Adanin Gezintisi: [";
    for (int i = 0; i < 10; ++i) {
        noktalar[i] = func(noktalar[i - 1]);
        cout << noktalar[i];
        if(i<9){
            cout << ",";
        }
    }
    cout << "]"; 
    return 0;
}
int main() {
    mainfunc();
    return 0;
}