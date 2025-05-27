#include <iostream>
#include <string>

class AnggotaTim {
protected:
    std::string nama;
    std::string peran;
    int gajiPokok;

public:
   
    AnggotaTim() : nama(""), peran(""), gajiPokok(0) {}

    AnggotaTim(std::string n, std::string p, int gp) {
        nama = n;
        peran = p;
        gajiPokok = gp;
    }

    virtual int hitungGajiTotal() {
        return gajiPokok;
    }

    void printInfo() {
        std::cout << "Gaji total " << nama << " (" << peran << ") adalah $" << hitungGajiTotal() << std::endl;
    }
};

class Pembalap : public AnggotaTim {
private:
    int jumlahPodium;

public:
  
    Pembalap() : AnggotaTim() {}

  
    Pembalap(std::string n, int gp, int pod) : AnggotaTim(n, "pembalap", gp) {
        jumlahPodium = pod;
    }

    int hitungGajiTotal() override {
        return gajiPokok + (jumlahPodium * 20000);
    }

    void printInfo() {
        std::cout << "Gaji total " << nama << " (" << peran << ") adalah $" << hitungGajiTotal() << std::endl;
    }
};

class Crew : public AnggotaTim {
private:
    int jumlahRace;

public:
    
    Crew() : AnggotaTim() {}

   
    Crew(std::string n, int gp, int r) : AnggotaTim(n, "crew", gp) {
        jumlahRace = r;
    }

    int hitungGajiTotal() override {
        return gajiPokok + (jumlahRace * 1000);
    }

    void printInfo() {
        std::cout << "Gaji total " << nama << " (" << peran << ") adalah $" << hitungGajiTotal() << std::endl;
    }
};

int main() {
    int jumlahAnggota;
    std::cout << "jumlah anggota tim : ";
    std::cin >> jumlahAnggota;
    std::string nama, peran;
    int gajiPokok, dataTambahan;
    Pembalap pembalaps[100];
    Crew crews[100];
    int idxPembalap = 0, idxCrew = 0;
    for (int i = 1; i <= jumlahAnggota; i++) {
        std::cout << " === INPUT DATA ANGGOTA TIM KE-" << i << " ===" << std::endl;
        std::cout << "nama : ";
        std::cin >> nama;
        std::cout << "peran : ";
        std::cin >> peran;
        std::cout << "gaji pokok : ";
        std::cin >> gajiPokok;
        if (peran == "pembalap") {
            std::cout << "jumlah podium : ";
            std::cin >> dataTambahan;
            pembalaps[idxPembalap] = Pembalap(nama, gajiPokok, dataTambahan);
            idxPembalap++;
        } else {
            std::cout << "jumlah race : ";
            std::cin >> dataTambahan;
            crews[idxCrew] = Crew(nama, gajiPokok, dataTambahan);
            idxCrew++;
        }
    }
    for (int i = 0; i < idxPembalap; i++) {
        pembalaps[i].printInfo();
    }
    for (int i = 0; i < idxCrew; i++) {
        crews[i].printInfo();
    }
    return 0;
}
