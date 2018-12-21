void shellsort(int left,int right,int *a)
{
    int increment = right - left +1;
    int temp=0;
    while(increment>1)
    {
        increment = increment/3+1;
        for(int i=left+increment;i<=right;i++)
        {
            if(a[i-increment]>a[i])
            {
                temp = a[i];
                int j = i-increment;
                while(j>=left&&a[j]>temp)
                {
                    a[j+increment] = a[j];
                    j -= increment;
                }
                a[j+increment] = temp;
            }
        }
    }
    return;
}
