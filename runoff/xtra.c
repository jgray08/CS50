
    int towin = ceil(candidate_count / 2) + 1;
    int max = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }




    for (int i = 0; i < candidate_count; i++)
    {
    }







    //




    bool print_winner(void)
{
    int max = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }
    if (max > (candidate_count / 2)) // is the most votes a majority?
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (candidates[i].votes == max)
            {

                printf("%s\n", candidates[i].name); // print winner
                return true;
            }
        }
    }
    return false;
}