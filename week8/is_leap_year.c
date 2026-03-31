int is_leap_year(int year_id);

int is_leap_year(int year_id)
{
    int result = 0;

    if(year_id % 400 == 0 || year_id % 100 != 0 && year_id % 4 == 0)
    {
        result = 1;
    }

    return result;
}