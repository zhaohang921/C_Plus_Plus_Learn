#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void hanoiTower(int n,int x,int y,int z)
{
    if(n>0)
    {
        hanoiTower(n-1,x,z,y);
        cout<<"Move top disk from tower"<<x<<"to top of tower "<<y<<endl;
        hanoiTower(n-1,z,y,x);
    }
}

template<typename T>
class print
{
public:
    void operator()(const T& elem)
    {
        cout<<elem<<' ';
    }
};

int main()
{

    cout << "Hello World!" << endl;
    int ia[6]={1,2,3,4,5,6};
    vector<int>iv(ia,ia+6);
    for_each(iv.begin(),iv.end(),print<int>());


    return 0;
}



