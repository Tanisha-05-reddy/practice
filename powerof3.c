bool isPowerOfThree(int n) {
    if (n<=0)
    return false;
    if ((int)pow(3,19)%n==0)
    return true;
    else
    return false;
}