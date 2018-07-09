#include <iostream>

using namespace std;

int main()
{
    int questions;
    int counter = 0;
    cin >> questions;
    char user[questions - 1];
    char correct[questions - 1];
    for (int x = 0; x < questions; x++)
        cin >> user[x];
    for (int x = 0; x < questions; x++)
        cin >> correct[x];
    for (int x = 0; x < questions; x++)
        if (correct[x] == user[x])
            counter++;
    cout <<counter;
}
