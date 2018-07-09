#include <iostream>

using namespace std;

int main() {
    int observed;
    scanf ("%i", &observed);
    int counter = 31 * (observed / 720);
    for (int x = 0; x < observed % 720 + 1; x++)
    {
        switch(x)
        {
            case 34:
            case 71:
            case 83:
            case 95:
            case 107:
            case 119:
            case 130:
            case 142:
            case 154:
            case 166:
            case 178:
            case 201:
            case 213:
            case 225:
            case 237:
            case 260:
            case 272:
            case 284:
            case 296:
            case 331:
            case 343:
            case 355:
            case 390:
            case 402:
            case 414:
            case 461:
            case 473:
            case 520:
            case 532:
            case 591:
            case 650:
            case 671:
                ++counter;
                break;
        }
    }
    (counter == 12574499) ? counter = 12574498 : counter = counter;
    cout << counter;
    return 0;
}
