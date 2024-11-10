#include <bits/stdc++.h>

using namespace std;

class tudien
{
    string eng;
    string vie;
    tudien *next;

public:
    tudien() { next = nullptr; }
    tudien(const string &e, const string &v)
    {
        eng = e;
        vie = v;
        next = NULL;
    }
    friend class bangtudien;
};

int hambam(string &key)
{
    int tong = 0;
    for (char c : key)
    {
        tong += (int)c;
    }
    return tong % 997;
}
class bangtudien
{
    tudien *bang[997];

public:
    bangtudien()
    {
        for (int i = 0; i < 997; i++)
        {
            bang[i] = NULL;
        }
    }

    void chen(string eng, string vie)
    {
        int bam = hambam(eng);
        tudien *a = new tudien(eng, vie);
        if (bang[bam] == NULL)
        {
            bang[bam] = a;
        }
        else
        {
            a->next = bang[bam];
            bang[bam] = a;
        }
    }

    string laynghiacuatu(string eng)
    {
        int bam = hambam(eng);
        tudien *a = bang[bam];
        while (a != NULL)
        {
            if (a->eng == eng)
            {
                return a->vie;
            }
            a = a->next;
        }
        return "ko tim thay tu trong tu dien";
    }
    void xoa(string eng)
    {
        int bam = hambam(eng);
        tudien *a = bang[bam];
        tudien *b = NULL;

        while (a != NULL)
        {
            if (a->eng == eng)
            {
                if (b == NULL)
                {
                    bang[bam] = a->next;
                }
                else
                {
                    b->next = a->next;
                }
                delete a;
                return;
            }
            b = a;
            a = a->next;
        }
    }
    void capnhat(string eng, string vie)
    {
        int bam = hambam(eng);
        tudien *a = bang[bam];
        while (a != NULL)
        {
            if (a->eng == eng)
            {
                a->vie = vie;
                return;
            }
            a = a->next;
        }
    }
    void docfile(char *fName)
    {
        if (fopen(fName, "r"))
        {
            cout << "Doc file thanh cong\n";
            ifstream fi(fName);
            string eng, vie;
            while (fi >> eng >> vie)
            {
                chen(eng, vie);
            }
        }
        else
        {
            cout << "Khong tim thay file\n";
        }
    }
    void xuatfile(char *fName)
    {
        if (fopen(fName, "w"))
        {
            cout << "Ghi file thanh cong\n";
            ofstream fo(fName);
            for (int i = 0; i < 997; i++)
            {
                tudien *a = bang[i];
                while (a != NULL)
                {
                    fo << a->eng << " " << a->vie << endl;
                    a = a->next;
                }
            }
        }
        else
        {
            cout << "Khong tim thay file\n";
        }
    }
};

int main()
{
    bangtudien tu;
    int luachon;
    string eng, vie;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. chen tu moi vao tu dien \n";
        cout << "2. tra cuu nghia cua tu \n";
        cout << "3. xoa tu khoi tu dien \n";
        cout << "4. cap nhap nghia cua tu \n";
        cout << "5. doc du lieu tu tep tin \n";
        cout << "6. xuat du lieu ra tep  tin \n";
        cout << "7. thoat\n";
        cout << "chon 1 chuc nang: ";
        cin >> luachon;

        switch (luachon)
        {
        case 1:
            cout << "nhap tu tieng anh: ";
            cin.ignore(); // Bỏ qua ký tự newline còn sót
            std::getline(cin, eng);
            cout << "nhap nghia tieng viet: ";
            std::getline(cin, vie);
            tu.chen(eng, vie);
            cout << "da them tu vao tu dien.\n";
            break;
        case 2:
            cout << "nhap tu tieng anh can tra cuu: ";
            cin.ignore();
            std::getline(cin, eng);
            vie = tu.laynghiacuatu(eng);
            if (vie == "ko tim thay tu trong tu dien")
            {
                cout << "tu vua nhap ko co trong tu dien.";
            }
            else
            {
                cout << "nghia cua tu '" << eng << "' la: " << vie << endl;
            }
            break;
        case 3:
            cout << "nhap tu tieng anh can xoa: ";
            cin >> eng;
            tu.xoa(eng);
            cout << "da xoa.\n";
            break;
        case 4:
            cout << "nhap tu tieng anh can cap nhap: ";
            cin.ignore();
            std::getline(cin, eng);
            cout << "nhap nghia tieng viet moi: ";
            std::getline(cin, vie);
            tu.capnhat(eng, vie);
            cout << "da cap nhap.\n";
            break;
        case 5:
            cout << "Nhap ten file input: ";
            char inp[50];
            cin >> inp;
            tu.docfile(inp);
            break;
        case 6:
            cout << "Nhap ten file output: ";
            char out[50];
            cin >> out;
            tu.xuatfile(out);
            break;
        case 7:
            cout << "thoat.\n";
            break;
        default:
            cout << "lua chon khong hop le! vui long chon lai.\n";
            break;
        }
    } while (luachon != 7);

    return 0;
}