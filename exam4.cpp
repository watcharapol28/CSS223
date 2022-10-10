#include<iostream>
using namespace std;


void heap(char str[], int n, int i)
{
    int m = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && str[l] > str[m]){m = l;}
    if (r < n && str[r] > str[m]){m = r;}
    if (m != i) 
    {
        char swap = str[i];
        str[i] = str[m];
        str[m] = swap;
        heap(str, n, m);
    }
}
 
void Sort(char str[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heap(str, n, i);
    }

    for (int i = n - 1; i > 0; i--) 
    {
        char swap = str[0];
        str[0] = str[i];
        str[i] = swap;
        heap(str, i, 0);
    }
}

int main()
{
    char str1[10010], str2[10010];
    cout << "\n1st String : ";
    cin >> str1;
    cout << "2nd String : ";
    cin >> str2;
    Sort(str1, strlen(str1));
    Sort(str2, strlen(str2));
    cout << "After Sort ...\n1st String : " << str1 << "\n2nd String : " << str2 << endl;
    if(strlen(str1) != strlen(str2))
    {
        cout << "String1 and String2 are not Anagram words";
    }
    else
    {
        bool check = true;
        for(int i = 0; i < strlen(str1); i++)
        {
            if(str1[i] != str2[i]){check = false; break;}
        }
        cout << "String1 and String2 are ";
        (!check)? cout << "not " : cout << "";
        cout << "Anagram words\n\n";
    }

}
