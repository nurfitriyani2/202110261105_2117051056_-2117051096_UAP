#include <iostream>//header agar cout dan cin bisa berjalan
#include <conio.h>//header agar fungsi getch bisa berjalan
#include <windows.h>//untuk menampilkan system (memberikan warna baik pada teks maupun background)

#define batas_atas 2
#define batas_bawah 23
#define batas_samping 2
#define batas_samping_k 78

#define caption "\t\t Mata Kuliah Dasar Pemograman \t\t\n\n"//mendefinisikan teks

using namespace std;

int iX(5), iY(5), x1 (4), y1 (4), xHapus(3), yHapus(3), veloX(1), veloY(0),ekorsX[200], ekorsY[200], nEkor = 2, start = 0, makX, makY ,level = 1 ,username;

void gotoxy(int x, int y) //untuk menempatkan koordinat kursor pada layar
{
    COORD pos ={x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//ular bergerak ke atas
void naik()
{
    veloY = -1;
    veloX = 0;
}
//ular bergerak turun
void turun()
{
    veloY = 1;
    veloX = 0;
}
//ular bergerak samping kiri
void samping()
{
    veloX = -1;
    veloY = 0;
}
//ular bergerak samping kanan
void samping_k()
{
    veloX = 1;
    veloY = 0;
}
//untuk menampilkan ular agar tubuhnya tidak panjang misal seperti 4 apabila makan 1 makanan tambah jadi 5, dst..
void hapus() 
{
    gotoxy(xHapus, yHapus);
    cout << " ";
}

void ekor()
{
    for(int j = 0; j <= 2; j++)
    {
        gotoxy(ekorsX[j], ekorsY[j]);
        cout << char(02);
    }
}

void tampil()
{
    gotoxy(iX, iY);
    cout << char(01);

    gotoxy(makX, makY);
    cout << char(06);
}

void ganti_posisi()
{
    xHapus = ekorsX[nEkor - 1];
    yHapus = ekorsY[nEkor - 1];
    for(int j = nEkor - 1; j >= 1; j--)
    {
        ekorsX[j] = ekorsX[j-1];
        ekorsY[j] = ekorsY[j-1];
    }
    ekorsX[0] = iX;
    ekorsY[0] = iY;
}

void velo()
{
    ganti_posisi();
    hapus();
    iX += veloX;
    iY += veloY;
    tampil();
    ekor();
}

bool isDestroy()
{
    if(iX == batas_samping_k) { iX = 3; gotoxy(78, iY); cout << " "; }
    if(iX == batas_samping)  { iX = 77; gotoxy(2, iY); cout << " "; }
    if(iY == batas_atas) { iY = 22; gotoxy(iX, 2); cout << " "; }
    if(iY == batas_bawah) { iY = 3; gotoxy(iX, 23); cout << " "; }
    for(int j = 0; j <= nEkor - 1; j++)
    if(ekorsX[j] == iX && ekorsY[j] == iY) return true;
    return false;
}

char getkey()
{
    for(int i = 8; i <= 222; i++)
    {
        if(GetAsyncKeyState(i) == -32767)
        {
            switch(i)
            {
            case 38 : if(veloY != 1)naik();
                        break;
            case 40 : if(veloY != -1)turun();
                        break;
            case 37 : if(veloX != 1)samping();
                        break;
            case 39 : if(veloX != -1)samping_k();
                        break;
            }
        }
    }
}

void random_makanan()
{
    makX = rand()%(batas_samping_k - 1);
    if(makX < 4) makX += 3 + (4-makX);
    makY = rand()%(batas_bawah - 1);
    if(makY < 4) makY += 3 + (4-makY);
    gotoxy(makX, makY);
    cout << char(3);
    if (nEkor%10==0)
 level=level+1;
}

bool isEaten()
{
    if(iX == makX && iY == makY)
        return true;
    else
        return false;
}

void cBorder()
{
    for(int i = 1; i <= 78; i++)
    {
        for(int j = 1; j <= 24; j += 23)
        {
            if(j > 10 || i >= 2)
            {
                gotoxy(i, j);cout << "-";
            }
        }
    }
    for(int i = 1; i <= 24; i++)
    {
        for(int k = 1; k <= 80; k += 78)
        {
            gotoxy(k, i); cout << "|";
        }
    }
}

void skor()
{
    gotoxy(3,1); cout << "Skor : ";
    gotoxy(18,1); cout << "Panjang : ";
    gotoxy(34,1); cout << "level : ";
    gotoxy(3,2); cout << "Nama : ";
    
}

void tulis_skor()
{
    gotoxy(11,1); cout << (nEkor) * 10;
    gotoxy(28,1); cout << nEkor;
    gotoxy(41,1); cout << level;
}

void inisialisasi()
{
    cBorder();
    random_makanan();
    skor();
    tulis_skor();
}

void tulisTengah(string s, int y)
{
    gotoxy(58 - (s.length() / 2), y);
    cout << s;
}

int main()
{
    system("color F9");
    int pilih;
 char user[40];

    pilih:
    system("cls");
    cout<<(caption);
    tulisTengah("~~~~Selamat Datang~~~~~",5);
    tulisTengah("di", 6);
    tulisTengah("Snake Game", 7);
    tulisTengah("~~~~~~~~~~~~~~~~~~~~~~~", 8);
    tulisTengah("================================", 9);
    tulisTengah("NAMA KELOMPOK:", 10);
    tulisTengah("================================", 11);
    tulisTengah("Nur Fitriyani : 2117051096", 12);
    tulisTengah("Ferisna Yanti Hima : 2117051056", 13);
    tulisTengah("Siti Nailissa'diyah : 202110261105", 14);
    tulisTengah("================================", 15);
    tulisTengah("pilih kode nya : 1. ", 17);
    tulisTengah("pilih kode nya : 1. untuk bermain , 2. untuk keluar", 18);
    tulisTengah("1.main",19);
    tulisTengah("2.keluar",20);
    tulisTengah("anda pilih yang mana : ",21);
    cin>>pilih;

    switch (pilih)
    {
        case 1:
                goto main;
        case 2:
                goto exit;
        default : tulisTengah("maaf tidak tersedia",25);
                goto pilih;
    }

    main:
    system("cls");
    
    tulisTengah("Masukkan Nama Pemain: ",13);
    cin >> user;
    system("cls");
    gotoxy(11,2); cout << user;
    inisialisasi();

    while(!(isDestroy()))
    {
        velo();
        getkey();
        if(isEaten())
        {
            nEkor += 2;
            random_makanan();
            tulis_skor();
        }
        Sleep(100 - (nEkor * 3));
    }
    system("cls");
    gotoxy(32,12); cout << "Skor "<< user<<":" << (nEkor - 1) * 10;
    gotoxy(25,13);
    exit:
    system("pause");
}

 

