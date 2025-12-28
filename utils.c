int    ft_atoi(const char nptr)
{
    int    min;
    int    result;

    min = 1;
    result = 0;
    while (nptr == ' '  (nptr >= 9 &&nptr <= 13))
        nptr++;
    if (*nptr == '-'  nptr == '+')
    {
        if (nptr == '-')
            min = -1;
        nptr++;
    }
    while (nptr >= '0' &&nptr <= '9')
    {
        result = 10;
        result +=nptr - 48;
        nptr++;
    }
    return (result * min);
}
