bool isPalindrome(int x) {
    int remainder,temp;
    long int y = 0;
    temp = x;

    while(x>0)
    {
        remainder=x%10;
        y=y*10+remainder;
        x/=10;
    }
    if(temp==y)
    {
        return true;
    }
    else
    {
        return false;
    }
}