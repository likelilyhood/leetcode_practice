#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hexToInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return c - 'a' + 10;
}

char intToHex(int x)
{
    if (x < 10)
        return '0' + x;
    else
        return 'A' + x - 10;
}

int main()
{
    int n;
    cin >> n;

    vector<string> key(n);
    vector<string> value(n);

    for (int i = 0; i < n; i++)
    {
        cin >> key[i] >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        string s = key[i];

        // 重复 key，直到长度达到 value 的长度
        while (key[i].length() < value[i].length())
        {
            key[i] += s;
        }

        // 如果超过，则截断
        key[i] = key[i].substr(0, value[i].length());

        // 逐个十六进制位异或
        for (int j = 0; j < value[i].length(); j++)
        {
            int a = hexToInt(key[i][j]);
            int b = hexToInt(value[i][j]);

            cout << intToHex(a ^ b);
        }

        cout << endl;
    }

    return 0;
}