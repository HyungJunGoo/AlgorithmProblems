#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    int min_x = abs(x-w);
    if(min_x > x)
        min_x = x;
    
    int _min = abs(y-h);
    if(_min > y)
        _min = y;
    if(min_x < _min)
        cout << min_x << endl;
    else
        cout << _min << endl;
    return 0;
}