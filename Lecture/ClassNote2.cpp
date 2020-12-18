#include <iostream>
using namespace std;

struct Gun
{
    const char* springType;
    const char* ammoType;
    float gunLength;
};

class GunInfo
{
    public:
        void printInfo(Gun *gunStruct);
};

void GunInfo::printInfo(Gun *gunStruct)
{
    cout << gunStruct->springType << endl;
    cout << gunStruct->ammoType << endl;
    cout << gunStruct->gunLength << endl;
}


int main()
{
    Gun Rifle;
    Rifle.springType = "M220";
    Rifle.ammoType = "Heavy";
    Rifle.gunLength = 44.2;

    GunInfo printGunInfo;
    printGunInfo.printInfo(&Rifle);
    return 0;
}