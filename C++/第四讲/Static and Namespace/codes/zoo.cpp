#include<iostream>
using namespace std;
int generateID() {
    static int ID = 1;  // 可改成 "static int ID;" 再次运行
    return ID++;
}
void Dog() {
    cout << "There is a puppy! Its ID is " << generateID() << endl;
}
void Cat() {
    cout << "Here is a kitty! Its ID is " << generateID() << endl;
}
int main() {
    Dog();
    Cat();
    for (int i = 0; i < 5; i++) {
        cout << generateID() << endl;
    }
    return 0;
}