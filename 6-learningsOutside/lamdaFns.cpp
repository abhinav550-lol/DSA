#include <iostream>
using namespace std;

int main() {
    auto add = [](int &sum, int x ,int y){
        sum = x + y;
        x = 0;
        y = 0;
    };

    auto add2 = [](int x  ,int y) -> int{
        return x + y;
    };

    int res= 0 ;
    int x = 4;
    int y = 5;
    add(res, x , y);
    cout << res << ' ' << x << ' ' << y << endl;
    cout << add2(x ,y) ;
    return 0;
}