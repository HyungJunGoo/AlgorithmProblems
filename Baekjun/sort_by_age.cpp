#include <bits/stdc++.h>
using namespace std;

struct account{
    int age;
    string name;
};
bool mysort(const account &a, const account &b){
    return a.age < b.age;
}

int main()
{
    int N;
    cin >> N;
    vector<account> people(N);
    for(int i=0;i<N;i++){
        int age;
        string name;
        cin >> age >> name;
        people[i].age = age;
        people[i].name = name;
    }
    stable_sort(people.begin(), people.end(), mysort);
    for(int i=0; i<N; i++)
        cout << people[i].age << " " << people[i].name << endl;
    return 0;
}