#include <iostream>
#include <string>
using namespace std;

string kalimat;
int key, pilihan;
char huruf;
char lanjut;

int main()
{
    do
    {
        cout << "===============================" << endl;
        cout << "|  PROGRAM ENKRIPSI & DEKRIPSI |" << endl;
        cout << "===============================" << endl;
        cout << "|        MASUKAN PILIHAN       |" << endl;
        cout << "| 1. ENKRIPSI                  |" << endl;
        cout << "| 2. DEKRIPSI                  |" << endl;
        cout << "| 3. KELUAR                    |" << endl;
        cout << "===============================" << endl;
        cout << "Masukan Pilihan (1-3): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "\n--- Mode Enkripsi ---\n";
            cout << "Masukkan Kalimat: ";
            getline(cin, kalimat);
            cout << "Masukkan Key: ";
            cin >> key;
            break;
        case 2:
            cout << "\n--- Mode Dekripsi ---\n";
            cout << "Masukkan Kalimat Terenkripsi: ";
            getline(cin, kalimat);
            cout << "Masukkan Key: ";
            cin >> key;
            break;
        case 3:
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan pilih 1 atau 2." << endl;
            continue;
        }

        for (int i = 0; i < kalimat.length(); i++)
        {
            huruf = kalimat[i];

            if (huruf >= 'a' && huruf <= 'z')
            {
                if (pilihan == 1)
                    huruf = (huruf - 'a' + key) % 26 + 'a';
                else
                    huruf = (huruf - 'a' - key + 26) % 26 + 'a';
            }
            else if (huruf >= 'A' && huruf <= 'Z')
            {
                if (pilihan == 1)
                    huruf = (huruf - 'A' + key) % 26 + 'A';
                else
                    huruf = (huruf - 'A' - key + 26) % 26 + 'A';
            }
            kalimat[i] = huruf;
        }

        if (pilihan == 1)
        {
            cout << "Hasil Enkripsi: " << kalimat << endl;
        }
        else if (pilihan == 2)
        {
            cout << "Hasil Dekripsi: " << kalimat << endl;
        }
        cout << "\n=============================" << endl;
        cout << "ingin melanjutkan program? (y/n): ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    cout << "Terima kasih telah menggunakan program ini!" << endl;
    return 0;
}