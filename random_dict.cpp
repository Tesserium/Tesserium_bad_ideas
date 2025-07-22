#include<iostream>
#include<string>
using namespace std;

int bucket[300] = {0};
int random_count = 0;

int is_variant_of_random(string modnar)
{
    // stub
    // input: a string.
    // output: 0 = not a variant of random, 1 = a variant of random, other = error occured
    // if a string contains more than 4 out of the 6 letters of r a n d o m, it is considered to be a variant of random
    // use the bucket array to count
    for(int i = 0; i < modnar.length(); i++)
        bucket[modnar[i]]++;
    if(modnar['r'] + modnar['a'] + modnar['n'] + modnar['d'] + modnar['o']
        + modnar['m'] >= 4)
        cout << random_count++ << ": " << modnar << endl;

    return 0;
}

int main(int argc, char** argv)
{
    int n = 1;
    while(n < argc)
    {
        int ret = is_variant_of_random(argv[n++]);
    }

    return 0;
}
