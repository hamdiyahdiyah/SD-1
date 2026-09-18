#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
};

Node* head = NULL;

void tampilkan() {
    Node* bantu = head;

    cout << "Linked List: ";
    if (bantu == NULL) {
        cout << "Kosong";
    } else {
        while (bantu != NULL) {
            cout << bantu->nilai;
            if (bantu->next != NULL)
                cout << " -> ";
            bantu = bantu->next;
        }
    }
    cout << endl;
}

void tambahAwal(int nilai) {
    Node* baru = new Node;
    baru->nilai = nilai;
    baru->next = head;
    head = baru;
}

void tambahAkhir(int nilai) {
    Node* baru = new Node;
    baru->nilai = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void tambahSetelah(int nilaiBaru, int nilaiTujuan) {
    Node* bantu = head;

    while (bantu != NULL && bantu->nilai != nilaiTujuan) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Nilai " << nilaiTujuan << " tidak ditemukan.\n";
        return;
    }

    Node* baru = new Node;
    baru->nilai = nilaiBaru;
    baru->next = bantu->next;
    bantu->next = baru;
}

void hapusNilai(int nilai) {
    if (head == NULL) {
        cout << "Linked List masih kosong.\n";
        return;
    }

    if (head->nilai == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Nilai " << nilai << " berhasil dihapus.\n";
        return;
    }

    Node* bantu = head;

    while (bantu->next != NULL && bantu->next->nilai != nilai) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "Nilai " << nilai << " tidak ditemukan.\n";
    } else {
        Node* hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
        cout << "Nilai " << nilai << " berhasil dihapus.\n";
    }
}

int main() {
    int pilihan, nilai, nilaiTujuan;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di Awal\n";
        cout << "2. Tambah di Akhir\n";
        cout << "3. Tambah Setelah Nilai Tertentu\n";
        cout << "4. Hapus Berdasarkan Nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                tambahAwal(nilai);
                tampilkan();
                break;

            case 2:
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                tambahAkhir(nilai);
                tampilkan();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin disisipkan setelahnya: ";
                cin >> nilaiTujuan;
                tambahSetelah(nilai, nilaiTujuan);
                tampilkan();
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusNilai(nilai);
                tampilkan();
                break;

            case 5:
                tampilkan();
                break;

            case 6:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak tersedia.\n";
        }

    } while (pilihan != 6);

    return 0;
}