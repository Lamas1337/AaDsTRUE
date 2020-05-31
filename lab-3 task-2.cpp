#include <iostream> 
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int i, * mas, * mas1, M, N, tmp, S, sum = 0, j;
    // ввод монет покупателя
    cout << "Количество монет покупателя: ";
    cin >> N;
    mas1 = new int[N];
    for (i = 0; i < N; i++)
    {
        cout << "B(" << i + 1 << ")= ";
        cin >> mas1[i];
        sum += mas1[i];
    }
    mas = new int[sum + 1];
    mas[0] = 1;
    for (i = 0; i <= sum; i++)
        mas[i] = 0;
    for (i = 0; i < N; i++)
    {
        for (j = sum - 1; j >= 0; j--)
            if (mas[j] == 1 && j + mas1[i] <= sum)
                mas[j + mas1[i]] = 1;
        mas[mas1[i]] = 1;
    }
    // ввод монет продавца
    cout << "Количество монет продавца: ";
    cin >> M;
    for (i = 0; i < M; i++)
    {
        cout << "B(" << i + 1 << ")= ";
        cin >> tmp;
        for (j = 0; j <= sum; j++)
            if (mas[j] && j - tmp >= 0)
                mas[j - tmp] = 1;
    }
    cout << "Сумма покупки: ";
    cin >> S;
    // Проверка на возможность покупки
    if (S<0 || S>sum)
        cout << "покупка невозможна" << endl;
    else
        if (mas[S] == 0)
            cout << "покупка невозможна" << endl;
        else
            cout << "покупка возможна" << endl;
    delete[] mas1;
    delete[] mas;
    return 0;
}