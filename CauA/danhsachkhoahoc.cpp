#include <bits/stdc++.h>
#include "khoahoc.cpp"

#ifndef __danhsachkhoahoc__cpp__
#define __danhsachkhoahoc__cpp__

using namespace std;

class dskhoahoc : public khoahoc
{
    list<khoahoc> kh;

public:
    bool isempty()
    {
        return kh.empty();
    }
    void dockhoahoc(string makh, string ten, int stc, int sosv, string gvpt)
    {
        khoahoc k(makh, ten, stc, sosv, gvpt);
        kh.push_back(k);
    }
    void themkhoahoc()
    {
        khoahoc k;
        cin >> k;
        kh.push_back(k);
    }

    int timkhoahoctheoma(const string &makh)
    {
        int check = 0;
        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getmkh() == makh)
            {
                check = 1;
                cout << "khoa hoc ban can  la: ";
                cout << *it;
            }
        }
        if (check == 0)
        {
            cout << "ko tim thay!" << endl;
            return 1;
        }
        return 0;
    }
    void timkhoahoctheoten(const string &ten)
    {
        int check = 0;
        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getten() == ten)
            {
                check = 1;
                cout << "khoa hoc ban can  la: ";
                cout << *it;
            }
        }
        if (check == 0)
        {
            cout << "ko tim thay!" << endl;
        }
    }
    void suakhoahoc(string mkh, int stcm, int ssvm, string gvptm)
    {

        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getmkh() == mkh)
            {
                if (stcm != -1)
                {
                    it->setstc(stcm);
                }
                if (ssvm != -1)
                {
                    it->setssv(ssvm);
                }
                if (gvptm != "0")
                {
                    it->setgvpt(gvptm);
                }
            }
        }

        cout << "da sua khoa hoc!" << endl;
    }
    void timmax()
    {
        int max = -1;

        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getstc() > max)
            {
                max = it->getstc();
            }
        }
        cout << "cac khoa hoc co so tin chi lon nhat la: " << endl;
        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getstc() == max)
            {
                cout << *it;
            }
        }
    }
    void timmaxsv()
    {
        int max = -1;

        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getssv() > max)
            {
                max = it->getssv();
            }
        }
        cout << "cac khoa hoc co so sinh vien lon nhat la: " << endl;
        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getssv() == max)
            {
                cout << *it;
            }
        }
    }
    void timmin()
    {
        int min = kh.begin()->getstc();

        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getstc() < min)
            {
                min = it->getstc();
            }
        }
        cout << "cac khoa hoc co so tin chi nho nhat la: " << endl;
        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getstc() == min)
            {
                cout << *it;
            }
        }
    }
    void timminsv()
    {
        int min = kh.begin()->getssv();

        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getssv() < min)
            {
                min = it->getssv();
            }
        }
        cout << "cac khoa hoc co so sinh vien it nhat la: " << endl;
        for (auto it = kh.begin(); it != kh.end(); ++it)
        {
            if (it->getssv() == min)
            {
                cout << *it;
            }
        }
    }
    void xoakhoahoc(const string &makh)
    {
        int check = 0;
        for (auto it = kh.begin(); it != kh.end();)
        {
            if (it->getmkh() == makh)
            {
                it = kh.erase(it);
                check = 1;
            }
            else
            {
                ++it;
            }
        }
        if (check == 0)
        {
            cout << " khong tim thay khoa hoc" << endl;
        }
        else
        {
            cout << "khoa hoc da duoc xoa thanh cong" << endl;
        }
    }
    void xxkhtheotc()
    {
        kh.sort(sosanhstc);
    }
    void xxkhtheossv()
    {
        kh.sort(sosanhssv);
    }
    void xxkhtheoten()
    {
        kh.sort(sosanhmkh);
    }
    friend ostream &operator<<(ostream &os, dskhoahoc &a)
    {
        for (auto it = a.kh.begin(); it != a.kh.end(); ++it)
        {
            os << *it;
        }
        return os;
    }
    void docfile(char *fName)
    {
        if (fopen(fName, "r"))
        {
            cout << "Doc file thanh cong\n";
            ifstream fi(fName);
            string makh, ten, gvpt;
            int stc, ssv;
            while (fi >> makh >> ten >> stc >> ssv >> gvpt)
            {
                dockhoahoc(makh, ten, stc, ssv, gvpt);
            }
        }
        else
        {
            cout << "Khong tim thay file\n";
        }
    }
    void xoads()
    {
        kh.clear();
        cout << "tat ca khoa hoc da duoc xoa thanh cong\n";
    }
};
#endif