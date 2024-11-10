#include <bits/stdc++.h>
#include "danhsachkhoahoc.cpp"

using namespace std;
class APP : public khoahoc, public dskhoahoc
{
public:
    void showmenu()
    {
        cout << "================================================================\n";
        cout << "                    --- MENU ---\n";
        cout << "================================================================\n";
        cout << "1. them khoa hoc \n";
        cout << "2. cap nhap khoa hoc \n";
        cout << "3. tim khoa hoc \n";
        cout << "4. xap xep khoa hoc \n";
        cout << "5. doc cac khoa hoc tu tep\n";
        cout << "6. hien thi cac khoa hoc\n";
        cout << "7. xoa danh sach\n";
        cout << "8. hien thi menu\n";
        cout << "9. thoat\n";
        cout << "================================================================\n";
    }
    void runapp(dskhoahoc &dskh)
    {
        int luachon, luachoncase3, luachoncase4;
        int check;
        int soluong;
        string tenkh, makh;
        APP::showmenu();
        do
        {

            cout << "chon 1 chuc nang: ";
            cin >> luachon;
            switch (luachon)
            {
            case 1:
                cout << "nhap so luong khoa hoc can them: ";
                cin >> soluong;
                for (int i = 0; i < soluong; i++)
                {
                    dskh.themkhoahoc();
                }
                break;
            case 2:
            {
                string makh, gvptm;
                int stcm, ssvm;
                cin.ignore();
                cout << "Nhap ma khoa hoc can cap nhap: ";
                getline(cin, makh);
                check = dskh.timkhoahoctheoma(makh);
                if (check == 1)
                {
                    break;
                }
                cout << "Nhap so tin chi moi(-1 neu giu nguyen so tin chi cu): ";
                cin >> stcm;
                cout << "Nhap sinh vien moi(-1 neu giu nguyen so sinh vien cu): ";
                cin >> ssvm;
                cin.ignore();
                cout << "Nhap giang vien phu trach moi(0 neu giu nguyen giang vien phu trach cu): ";
                getline(cin, gvptm);
                dskh.suakhoahoc(makh, stcm, ssvm, gvptm);
                break;
            }
            case 3:
                do
                {
                    cout << "-tim kiem khoa hoc-\n";
                    cout << "1. tim khoa hoc theo ten\n";
                    cout << "2. tim khoa hoc theo ma\n";
                    cout << "3. tim khoa hoc co so tin chi lon nhat \n";
                    cout << "4. tim khoa hoc co so sinh vien lon nhat \n";
                    cout << "5. tim khoa hoc co so tin chi nho nhat \n";
                    cout << "6. tim khoa hoc co so sinh vien nho nhat \n";
                    cout << "7.quay lai \n";
                    cout << "\nchon mot chuc nang: ";
                    cin >> luachoncase3;
                    cin.ignore();
                    switch (luachoncase3)
                    {
                    case 1:
                        cout << "Nhap ten khoa hoc can tim: ";
                        getline(cin, tenkh);
                        dskh.timkhoahoctheoten(tenkh);
                        break;
                    case 2:
                        cout << "Nhap ma khoa hoc can tim: ";
                        getline(cin, makh);
                        dskh.timkhoahoctheoma(makh);
                        break;
                    case 3:
                        dskh.timmax();
                        break;
                    case 4:
                        dskh.timmaxsv();
                        break;
                    case 5:
                        dskh.timmin();
                        break;
                    case 6:
                        dskh.timminsv();
                        break;
                    case 7:
                        break;
                    default:
                        cout << "lua chon khong hop le! vui long chon lai.\n";
                        break;
                    }
                } while (luachoncase3 != 7);
                break;
            case 4:
                do
                {

                    cout << "-xap xep khoa hoc-\n";
                    cout << "1.xap xep khoa hoc theo so tin chi\n";
                    cout << "2.xap xep khoa hoc theo ten\n";
                    cout << "3.xap xep khoa hoc theo so sinh vien\n";
                    cout << "4.quay lai\n";
                    cout << "chon 1 chuc nang: ";
                    cin >>
                        luachoncase4;
                    switch (luachoncase4)
                    {
                    case 1:
                        dskh.xxkhtheotc();
                        cout << "xap xep thanh cong\n";
                        break;
                    case 2:
                        dskh.xxkhtheoten();
                        cout << "xap xep thanh cong\n";
                        break;
                    case 3:
                        dskh.xxkhtheossv();
                        cout << "xap xep thanh cong\n";
                        break;
                    case 4:
                        break;
                    default:
                        cout << "lua chon khong hop le! vui long chon lai.\n";
                        break;
                    }
                } while (luachoncase4 != 4);

                break;
            case 5:
                char tenfile[50];
                cout << "nhap ten file: ";
                cin >> tenfile;
                dskh.docfile(tenfile);
                break;
            case 6:
                if (dskh.isempty())
                {
                    cout << "hien khong co khoa hoc nao" << endl;
                }

                else
                {
                    cout << "cac khoa hoc dang co: " << endl;
                    cout << left << setw(15) << "Ma khoa hoc"
                         << setw(50) << "Ten khoa hoc"
                         << setw(15) << "So tin chi"
                         << setw(20) << "So sinh vien "
                         << "Giang vien phu trach" << endl;
                    cout << "========================================================================================================================" << endl;

                    cout << dskh;
                }
                break;
            case 7:
                dskh.xoads();
                break;
            case 8:
                APP::showmenu();
                break;
            case 9:
                cout << "thoat thanh cong\n";
                break;
            default:
                cout << "lua chon khong hop le! vui long chon lai.\n";
                break;
            }
        }

        while (luachon != 9);
    }
};

main()
{
    dskhoahoc dskh;

    APP app;
    app.runapp(dskh);
}