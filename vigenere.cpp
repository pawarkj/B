#include <iostream>
#include <string>
using namespace std;
class Vigenere {
   public:
      string k;
   Vigenere(string k) {
      for (int i = 0; i < k.size(); ++i) {
         if (k[i] >= 'A' && k[i] <= 'Z')
            this->k += k[i];
         else if (k[i] >= 'a' && k[i] <= 'z')
            this->k += k[i] + 'A' - 'a';
      }
   }
   string encryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c + k[j] - 2 * 'A') % 26 + 'A'; 
         j = (j + 1) % k.length();
      }
      return output;
   }
   string decryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c - k[j] + 26) % 26 + 'A';
         j = (j + 1) % k.length();
      }
      return output;
   }
};
int main() {
   Vigenere v("WALCHAND");
   string plainText ="";
   cout << "Enter plain text: ";
   cin >> plainText;
   string encrypt = v.encryption(plainText);
   string decrypt = v.decryption(encrypt);
   cout << "Encrypted Message: " << encrypt << endl;
   
   cout << "Decrypted Message: " << decrypt << endl;
}

