#include <iostream>
#include <math.h>

using namespace std;

int gcd(int x, int y)
{
    int z;
    while (1)
    {
        z = x % y;
        if (z == 0)
            return y;
        x = y;
        y = z;
    }
}

double encrypt(int ciph, double key)
{
    return pow(ciph, key);
}

double decrypt(double code, double key, long long phi)
{
    double inv_key = 1 / key;
    double de_key = fmod(inv_key, phi);
    return pow(code, de_key);
}

int main()
{
    int ciph;
    cout << "Enter message" << endl;
    cin >> ciph;

    long p, q;
    double key;
    cout << "Enter 2 primes" << endl;
    cin >> p >> q;
    cout << "Enter public key" << endl;
    cin >> key;

    long n = p * q;
    long phi = (p - 1) * (q - 1);
    int flag;

    while (key < phi)
    {
        flag = gcd(key, phi);
        if (flag == 1)
            break;
        else
            key++;
    }

    double code = encrypt(ciph, key);
    double decode = decrypt(code, key, phi);

    cout << "Encrypted Message: " << fmod(code,n) << endl;
    cout << "Decrypted Message: " << fmod(decode,n) << endl;

    return 0;
}
