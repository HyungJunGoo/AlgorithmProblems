#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> numbers(6);
    
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers[4] = 5;
    cout << numbers[0] << endl;
    cout << numbers[3] << endl;
    cout << numbers[4] << endl;
    cout << numbers[5] << endl;
    return 0;
}