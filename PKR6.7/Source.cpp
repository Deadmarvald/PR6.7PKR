#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Elem* list;
    Info info;
};

void Create(char* fname)
{
    ofstream fout(fname, ios::binary);// ������� ���� ��� ������
    if (!fout)
    {
        cerr << "�������!" << fname << "'" << endl;
        return;
    }
    int value, N;
    cout << "������ ������� ��������: "; cin >> N;
    for (int i = 0; i < N; i++)
    {
        cout << "������ �������� ��� ��������: "; cin >> value;
        fout.write((char*)&value, sizeof(value));
    }
    cout << endl;
}

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    tmp->list = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void Read(char* fname, Elem*& first, Elem*& last)
{
    ifstream fin(fname, ios::binary);// ������� ���� ��� ����������
    if (!fin)
    {
        cerr << "�� ���� ����� " << fname << "'" << endl;
        return;
    }
    Info value;
    while (fin.read((char*)&value, sizeof(value)))// ���� ����� ��������� ������
    {
        enqueue(first, last, value);
    }
}

void print(Elem* first, Elem* first2)
{
    while (first != NULL)
    {
        if (first->list != NULL)
        {
            cout << "(";
            while (first2 != NULL)
            {
                cout << first2->info << " ";
                first2 = first2->link;
            }
            cout << ")";
        }
        else
        {
            cout << first->info << " ";
            first = first->link;
        }
    }
}

void DeleteEven(Elem* L)
{
    Elem* Prev = L;
    while (L != NULL)
    {
        if (!(L->info%2))
        {
            Prev->link = L->link;
            delete L;
            L = Prev;
        }
        else
        {
            Prev = L;
            L = L->link;
        }
    }
}

void Doubling(Elem* L)
{
    while (L != NULL)
    {
        L->info *= 2;
        L = L->link;
    }
}

/*void Addlist(Elem* L1, Elem* L2, int value)
{
    int count = 0;
    while (L1 != NULL)
    {
        count++;
        if (count == value)
        {
            L1->list = L2;
            L1 = L1->link;
        }
        else
        {
            L1 = L1->link;
        }
    }
}*/

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;

    Elem* first2 = NULL,
        * last2 = NULL;

    char fname[61];
    int choice, N, value, K;

    do
    {
        cout << " [0] - ��������� ������" << endl;
        cout << " [1] - �������� ����" << endl;
        cout << " [2] - ������� ���������� � �����" << endl;
        cout << " [3] - �������� ������" << endl;
        cout << " [4] - �������� ��������, �������� ���� � ������� ������� �� ������� ������ ��������" << endl;
        cout << " [5] - �������� �������� � ������ �������" << endl << endl;
        cout << "������ ��������: "; cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cin.get();
            cin.sync();
            cout << "������ ��� �����: "; cin.getline(fname, 61);
            Create(fname);
            break;
        case 2:
            cin.get();
            cin.sync();
            cout << "������ ��� �����: "; cin.getline(fname, 61);
            Read(fname, first, last);
            break;
        case 3:
            print(first, first2);
            cout << endl;
            break;
        case 4:
            DeleteEven(first);
            Doubling(first);
            break;
        case 5:
            cout << "������ ������� �������� ��������: "; cin >> N;

            for (int i = 0; i < N; i++)
            {
                cout << "������ �������� ��� ��������: "; cin >> value;
                enqueue(first2, last2, value);
            }

            cout << "������ � ��� ���� ������ �������� ��������: "; cin >> K;

            //Addlist(first, first2, K);

            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (choice != 0);


    system("pause");
    return 0;
}