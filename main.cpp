#include <iostream>
using namespace std;

char layar[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void tampilkanLayar(){
    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  " << layar[0][0] << "  |  " << layar[0][1] << "  |  " << layar[0][2] << "\n";
    cout << "\t\t\t_____|_____|_____\n";
    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  " << layar[1][0] << "  |  " << layar[1][1] << "  |  " << layar[1][2] << "\n";
    cout << "\t\t\t_____|_____|_____\n";
    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  " << layar[2][0] << "  |  " << layar[2][1] << "  |  " << layar[2][2] << "\n";
    cout << "\t\t\t     |     |     \n";
}

void menang(char x){
    cout << "Winner = " << x << "\n";
}

void gerakPemain(char pemain){
    cout << "Giliran " << pemain << "\n";
    int x, y;
    while (true){
        cout << "Masukkan baris dan kolom x y : ";
                    
        if (!(cin >> x >> y)) {
            cout << "Input harus berupa angka!\n";
            cin.clear();                    // hapus error state
            cin.ignore(10000, '\n');        // buang sisa input yang salah
            continue;
        }

        if (x < 1 || x > 3 || y < 1 || y > 3){
            cout << "Input harus antara 1 sampai 3!\n";
            continue;
        }

        int r = x - 1;
        int c = y - 1;

        if (layar[r][c] != ' '){
            cout << "Kotak sudah terisi!\n";
            continue;
        }

        layar[r][c] = pemain;
        break;
    }
}

void clear(char s[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            s[i][j] = ' ';
        }
    }
}

int main(){
    bool isClose = false;

    cout << "\t\t  ==============================\n";
    cout << "\t\t  =========TIC TAC TOE==========\n";
    cout << "\t\t  ==============================\n";

    cout << "\t\t     *Enter to play the game*";
    cin.get();
    cout << "\n\n";

    while (!isClose){
        clear(layar);
        bool adaPemenang = false;
        
        for (int i = 1; i <= 9; i++){
            tampilkanLayar();
            
            // Gerakkan pemain dulu
            if (i % 2 != 0){
                gerakPemain('X');
            } else {
                gerakPemain('O');
            }
            
            // === CEK MENANG SETELAH BERGERAK ===
            
            
            if (layar[0][0] != ' ' && layar[0][0] == layar[0][1] && layar[0][1] == layar[0][2]) {
                tampilkanLayar();
                menang(layar[0][0]);
                adaPemenang = true;
            }
            else if (layar[1][0] != ' ' && layar[1][0] == layar[1][1] && layar[1][1] == layar[1][2]) {
                tampilkanLayar();
                menang(layar[1][0]);
                adaPemenang = true;
            }
            else if (layar[2][0] != ' ' && layar[2][0] == layar[2][1] && layar[2][1] == layar[2][2]) {
                tampilkanLayar();
                menang(layar[2][0]);
                adaPemenang = true;
            }
            else if (layar[0][0] != ' ' && layar[0][0] == layar[1][0] && layar[1][0] == layar[2][0]) {
                tampilkanLayar();
                menang(layar[0][0]);
                adaPemenang = true;
            }
            else if (layar[0][1] != ' ' && layar[0][1] == layar[1][1] && layar[1][1] == layar[2][1]) {
                tampilkanLayar();
                menang(layar[0][1]);
                adaPemenang = true;
            }
            else if (layar[0][2] != ' ' && layar[0][2] == layar[1][2] && layar[1][2] == layar[2][2]) {
                tampilkanLayar();
                menang(layar[0][2]);
                adaPemenang = true;
            }
            else if (layar[0][0] != ' ' && layar[0][0] == layar[1][1] && layar[1][1] == layar[2][2]) {
                tampilkanLayar();
                menang(layar[0][0]);
                adaPemenang = true;
            }
            else if (layar[0][2] != ' ' && layar[0][2] == layar[1][1] && layar[1][1] == layar[2][0]) {
                tampilkanLayar();
                menang(layar[0][2]);
                adaPemenang = true;
            }
            
            if (adaPemenang) {
                break;           // keluar dari for loop kalau sudah ada pemenang
            }
        }
        
        // Setelah for loop
        if (!adaPemenang) {
            tampilkanLayar();
            cout << "Permainan berakhir seri (Draw)!\n";
        }
        
        // Tanya main lagi...
        cout << "Ingin bermain lagi? (y/n) : ";
        char lagi; cin >> lagi;
        while (lagi != 'y' && lagi != 'Y' && lagi != 'n' && lagi != 'N'){
            cout << "Masukkan input yang valid!\n";
            cout << "Ingin bermain lagi? (y/n) : ";
            cin >> lagi;
        }
        if (lagi == 'y' || lagi == 'Y'){
            isClose = false;
        } else {
            isClose = true;
        }
    }
}
