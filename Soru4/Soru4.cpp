//Selim Ayyýldýz 10.08.2024
//Metin þifreleme
#include <iostream>   
#include <fstream>    
#include <string> 
#include <algorithm> 
#include <cmath> 
using namespace std; 
string txtGet(string satir){
    ifstream dosya("metin.txt");//metin.txt dosyasini cagirma
    getline(dosya, satir);//dosyayi satir degiskenine atama
    cout << satir << endl;
    satir.erase(remove(satir.begin(),satir.end(),' '),satir.end());//bosluklari silme
    dosya.close(); 
    return satir;
}
int main() {
    string satir = txtGet(satir);
    int m,n,y = 0;
    double x;
    x = sqrt(satir.length()); // satir uzunlugunun kok degerini alma
    m = x+1, n = x+1;
    cout << "m degeri :" << m <<"\t n degeri: "<< n <<  endl; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            cout << satir[y];
            y++;
        }
        cout  << endl;
    }
    return 0;
}
