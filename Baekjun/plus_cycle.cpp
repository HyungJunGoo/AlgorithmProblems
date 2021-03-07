    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        int N ;
        cin >> N;
        int a,b;
        a = N/10;
        b = N%10;
        int temp = (b*10)+(a+b)%10;
        int num = 1;
        while(temp != N){
            num++;
            a = temp / 10;
            b = temp % 10;
            temp = (b*10) + (a+b)%10;

        }
        cout << num << endl;
        return 0;
    }