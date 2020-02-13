#include<math.h>
#include<stdio.h>
long a,b,c[4];
void input();
void input()
{
	int i;
    FILE *pf;
    pf=fopen("D:\\TEMP\\a_example","r");
    fscanf(pf,"%ld %ld\n",&a,&b);
    for(i=0;i<b;i++)
    {
        fscanf(pf,"%ld ",&c[i]);
    }
    fclose(pf);
}
void main()
{
    input();
    int i,j;
    long difference=a,comb=pow(2,b),result;
    long sum;
    short binary[b],result_arry[b];
    for(i=1;i<=comb;i++)
    {
        int num=i;
        sum=0;
        for(j=b-1;j>=0;j--)
        {
            binary[j]=num%2;
            num=num/2;
        }
        for(j=0;j<b;j++)
        {
            printf("%d",binary[j]);
        }
        printf("\n");
        for(j=0;j<b;j++)
        {
            sum=sum+(binary[j]*c[j]);
        }
        if((difference>(a-sum))&&(sum<=a))
        {
            difference=a-sum;
            result=sum;
            for(j=0;j<b;j++)
            {
                result_arry[j]=binary[j];
            }
        }
    }
    /*for(int j=0;j<b;j++)
    {
        printf("%d",result_arry[j]);
    }*/
    printf("\n%ld",result);
}
