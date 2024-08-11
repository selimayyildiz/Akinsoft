// Selim Ayyıldız 10.08.2024
// Metin düzenleyici
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string text = ""; // Metni tutacak değişken
string lastText = ""; // Geri alma işlemi için son metni saklayan değişken
void appendText(const string& s) { //Metin ekleme foksiyonu
    lastText = text;
    text += s;
}
void deleteText(int k) {//Metin silme fonksiyonu
    lastText = text;
    if (k > text.size()) {
        k = text.size();
    }
    text.erase(text.size() - k, k);
}
void printText(int k) {//Metin yazdırma fonksiyonu
    if (k > text.size()) {
        k = text.size();
    }
    cout << text.substr(0, k) << endl;
}
void undoText() {//Geri alma fonksiyonu
    text = lastText;
}
void saveText(const string& filename) {//Dosya'yı kaydetme fonksiyonu
    ofstream file(filename);
    if (file.is_open()) {
        file << text;
        file.close();
    } else {
        cerr << "Dosya açılamadı: " << filename << endl;
    }
}
int main() {
    string command;
    while (true) {
        cout << "Komut girin (append, delete, print, undo, save): ";
        cin >> command;

        if (command == "append") {
            string s;
            cout << "Eklenecek metni girin: ";
            getline(cin, s);
            appendText(s);
        } else if (command == "delete") {
            int k;
            cout << "Silinecek karakter sayısını girin: ";
            cin >> k;
            deleteText(k);
        } else if (command == "print") {
            int k;
            cout << "Yazdırılacak karakter sayısını girin: ";
            cin >> k;
            printText(k);
        } else if (command == "undo") {
            undoText();
        } else if (command == "save") {
            string filename;
            cout << "Dosya adını girin: ";
            cin >> filename;
            saveText(filename);
            break;
        } else {
            cout << "Geçersiz komut." << endl;
        }
    }
    return 0;
}