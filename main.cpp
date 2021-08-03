#include"RBTree.h"
#include"RBTree.cpp"
#include<iostream>

using namespace std;

void test01()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //int a[3] = {3, 2, 1};
    RBTree<int> tree;
    for(int i=0; i<10; i++)
    {
        tree.Insert(a[i]);
        //cout<<"1"<<endl;
    }
    cout<<"²åÈë³É¹¦!"<<endl<<endl;

    tree.PrintRoot();

    tree.PrintLDR();

}

int main()
{
    test01();
}