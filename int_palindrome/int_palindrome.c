int int_palindrome(int n)
{
    int ori = n;
    int rem = 0;
    int rev = 0;
    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    if (ori == rev)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
