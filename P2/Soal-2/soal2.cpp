#include <iostream>
#include <string>

class Vocaloid {
protected:
    std::string nama;
    int accuracy;
    int stamina;
public:
    Vocaloid(std::string nama, int accuracy, int stamina)
        : nama(nama), accuracy(accuracy), stamina(stamina) {}
    virtual void serang(Vocaloid& target) = 0;
    bool isAlive() const {
        return stamina > 0;
    }
    void printStatus() const {
        std::cout << nama << " has " << stamina << " stamina remaining." << std::endl;
    }
    std::string getNama() const {
        return nama;
    }
    int& getStamina() {
        return stamina;
    } 
};

class FirstVocaloid : public Vocaloid {
public:
    FirstVocaloid(std::string nama, int accuracy, int stamina)
        : Vocaloid(nama, accuracy, stamina) {}
    void serang(Vocaloid& target) override {
        target.getStamina() -= accuracy;
        if (target.getStamina() < 0) {
            target.getStamina() = 0;
        }
    }
};

class SecondVocaloid : public Vocaloid {
public:
    SecondVocaloid(std::string nama, int accuracy, int stamina)
        : Vocaloid(nama, accuracy, stamina) {}
    void serang(Vocaloid& target) override {
        target.getStamina() -= accuracy;
        if (target.getStamina() < 0) {
            target.getStamina() = 0;
        }
    }
};

int main() {
    // Input data untuk FirstVocaloid
    std::string nama1, nama2;
    int acc1, stam1, acc2, stam2;
    std::string firstOrSecond;

    std::cout << "Enter FirstVocaloid name, accuracy, and stamina: ";
    std::cin >> nama1 >> acc1 >> stam1;
    std::cout << "Enter SecondVocaloid name, accuracy, and stamina: ";
    std::cin >> nama2 >> acc2 >> stam2;
    std::cout << "Who attacks first (first/second)? ";
    std::cin >> firstOrSecond;

    // Buat objek Vocaloid
    FirstVocaloid v1(nama1, acc1, stam1);
    SecondVocaloid v2(nama2, acc2, stam2);

    // Tentukan siapa yang menyerang terlebih dahulu
    Vocaloid* attacker = nullptr;
    Vocaloid* defender = nullptr;

    if (firstOrSecond == "first") {
        attacker = &v1;
        defender = &v2;
    } else {
        attacker = &v2;
        defender = &v1;
    }

    // Cetak status awal
    v1.printStatus();
    v2.printStatus();

    // Simulasi perkelahian
    while (v1.isAlive() && v2.isAlive()) {
        // Serangan
        attacker->serang(*defender);
        std::cout << attacker->getNama() << " attacks " << defender->getNama() << "!" << std::endl;

        // Cetak status stamina setelah serangan
        v1.printStatus();
        v2.printStatus();

        // Ganti giliran
        std::swap(attacker, defender);
    }

    // Cetak pemenang
    if (v1.isAlive()) {
        std::cout << v1.getNama() << " wins the contest!" << std::endl;
    } else {
        std::cout << v2.getNama() << " wins the contest!" << std::endl;
    }

    return 0;
}
