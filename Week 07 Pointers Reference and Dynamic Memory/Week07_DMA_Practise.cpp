#include <iostream>

using namespace std;

int main()
{
    bool* pBool = new  bool{ true };
    delete pBool;
    pBool = nullptr;

    float* pFloat = new float{ 20.5f };
    //must delete here so that this piece of information does not use up this memory
    delete pFloat;
    pFloat = nullptr;

    pFloat = new float{ 30.5f };
    delete pFloat;
    pFloat = nullptr;

    int* pInt = nullptr;
    for (int i = 0; i < 5; i++)
    {
        pInt = new int{ rand() };
        cout << *pInt << endl;
        delete pInt;
        pInt = nullptr;
    }

    // If you delete outside of the for loop above, you will only delete one pInt, causing memory leak.

}
