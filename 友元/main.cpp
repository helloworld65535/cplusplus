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
    friend void privatePermissions(Room *r); // 全局函数做友元
    friend class Friend;                     // 类做友元
    friend void OtherFriend::visit(Room *r); // 成员函数做友元

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
    cout << "类做友元,访问:" << r->bedroom << endl;
    r->bedroom += "(类访问过)";
}

void OtherFriend::visit(Room *r)
{
    cout << "成员函数做友元,访问:" << r->bedroom << endl;
    r->bedroom += "(成员函数访问过)";
}

void privatePermissions(Room *r)
{
    cout << "全局函数做友元,访问:" << r->bedroom << endl;
    r->bedroom += "(全局函数访问过)";
}
int main(void)
{
    Room r("客厅", "卧室");
    privatePermissions(&r);
    Friend().visit(&r);
    OtherFriend().visit(&r);
    r.Look();
    return 0;
}