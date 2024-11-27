#include <bits/stdc++.h>

#ifndef __khoahoc__cpp__
#define __khoahoc__cpp__

using namespace std;
class khoahoc
{
private:
    string mkh;
    string ten;
    int stc;
    int ssv;
    string gvpt;

public:
    khoahoc() {}
    khoahoc(string ma, string tenkhoahoc, int sotinchi, int sosinhvien, string giangvien)
    {
        mkh = ma;
        ten = tenkhoahoc;
        stc = sotinchi;
        ssv = sosinhvien;
        gvpt = giangvien;
    }
    string getmkh() { return mkh; }
    string getten() { return ten; }
    int getstc() { return stc; }
    int getssv() { return ssv; }
    string getgvpt() { return gvpt; }
    void setstc(int sotinchi) { stc = sotinchi; }
    void setssv(int sosinhvien) { ssv = sosinhvien; }
    void setgvpt(string gv) { gvpt = gv; }

    friend istream &operator>>(istream &is, khoahoc &k)
    {

        cout << "nhap ma khoa hoc: ";
        getline(is, k.mkh);
        cout << "nhap ten khoa hoc: ";
        getline(is, k.ten);
        cout << "nhap so tin chi: ";
        is >> k.stc;
        cout << "nhap so sinh vien da dang ki: ";
        is >> k.ssv;
        cout << "nhap gian vien phu trach khoa hoc: ";
        is.ignore();
        getline(is, k.gvpt);
        return is;
    }
    friend ostream &operator<<(ostream &os, khoahoc &k)
    {

        os << left << setw(15) << k.mkh
           << setw(50) << k.ten
           << setw(15) << k.stc
           << setw(20) << k.ssv
           << k.gvpt << endl;
        return os;
    }
    bool operator<(const khoahoc &k)
    {
        return stc < k.stc;
    }

    bool operator>(const khoahoc &k)
    {
        return stc > k.stc;
    }
};
bool sosanhstc(khoahoc &a, khoahoc &b)
{
    return a.getstc() < b.getstc();
}
bool sosanhssv(khoahoc &a, khoahoc &b)
{
    return a.getssv() < b.getssv();
}
bool sosanhmkh(khoahoc &a, khoahoc &b)
{
    return a.getmkh() < b.getmkh();
}
#endif