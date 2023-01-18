#include <iostream>
#include <string>
using namespace std;

class Room;
class Friend
{
public:
    void visit(Room *r);
};

class OtherFriend
{
public:
    void visit(Room *r);
};

class Room
{
private:
    friend void privatePermissions(Room *r); // ȫ�ֺ�������Ԫ
    friend class Friend;                     // ������Ԫ
    friend void OtherFriend::visit(Room *r); // ��Ա��������Ԫ

    string bedroom;

public:
    string livingroom;

    Room(string p1, string p2) : livingroom(p1), bedroom(p2) {}
    void Look()
    {
        cout << bedroom << endl;
    }
};

void Friend::visit(Room *r)
{
    cout << "������Ԫ,����:" << r->bedroom << endl;
    r->bedroom += "(����ʹ�)";
}

void OtherFriend::visit(Room *r)
{
    cout << "��Ա��������Ԫ,����:" << r->bedroom << endl;
    r->bedroom += "(��Ա�������ʹ�)";
}

void privatePermissions(Room *r)
{
    cout << "ȫ�ֺ�������Ԫ,����:" << r->bedroom << endl;
    r->bedroom += "(ȫ�ֺ������ʹ�)";
}
int main(void)
{
    Room r("����", "����");
    privatePermissions(&r);
    Friend().visit(&r);
    OtherFriend().visit(&r);
    r.Look();
    return 0;
}