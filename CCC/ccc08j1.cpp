#include <bits/stdc++.h>

using namespace std;

int main()
{
    double w, h;
    scanf("%lf %lf", &w, &h);
    auto bmi = w/h/h;
    if (bmi < 18.5)
        printf("Underweight\n");
    else if (bmi > 25)
        printf("Overweight\n");
    else 
        printf("Normal weight\n");
}

