#include <stdio.h>

int isDominant(int m,int n,float a[m][n])
{
    float s=0.0,s1=0.0;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
        if(i==j)
            s+=abs(a[i][j]);//adding diagonal elements
        else
            s1+=abs(a[i][j]);//adding non-diagonal elements
        }
    }
    printf("\n\n |a[i][i]|              = \t%f",s);
    printf("\n\n %c|a[i][j]|(i != j)    = \t%f",484,s1);
    if(s>s1)//checking if the matrix is diagonally dominant
        return 1;
    else
        return 0;
}

int main()
{
    int m,n;
    printf("Enter row size      :   ");
    scanf("%d",&m);
    printf("Enter column size   :   ");
    scanf("%d",&n);
    float a[m][n];
    float out[3][10];
    //inputting matrix
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("Enter value at A[%d][%d]    :   ",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    if(isDominant(m,n,a)==1)
    {
        
        printf("\n\nSince,  |a[i][i]|   <   %c|a[i][j]|(i != j)",484);
        printf("\n\n>>>>> Gauss-Jacobi Method cann't be applied since Matrix is not Diagonally Dominant <<<<<");
    }
    else
    {
        printf("\n\nSince,  |a[i][i]|   >   %c|a[i][j]|(i != j)",484);
        printf("\n\n>>>>> Matrix is diagonally dominant <<<<<");
        float x=0.0,y=0.0,z=0.0,x1=0.0,y1=0.0,z1=0.0;
        for(int i=0;i<10;++i)
        {
            printf("\n\n>>>>> ITERATION %d (for k = %d) <<<<<",i+1,i);

            x1=(a[0][n-1]-y*a[0][1]-z*a[0][2])/a[0][0];
            y1=(a[1][n-1]-x*a[1][0]-z*a[1][2])/a[1][1];
            z1=(a[2][n-1]-x*a[2][0]-y*a[2][1])/a[2][2];
            printf("\n\n=> x(%d)   = (%.2f - %.2f * %.2f - %.2f * %.2f)/%.2f = %.4f",i,a[0][n-1],y,a[0][1],z,a[0][2],a[0][0],x1);
            printf("\n\n=> y(%d)   = (%.2f - %.2f * %.2f - %.2f * %.2f)/%.2f = %.4f",i,a[1][n-1],x,a[1][0],z,a[1][2],a[1][1],y1);
            printf("\n\n=> z(%d)   = (%.2f - %.2f * %.2f - %.2f * %.2f)/%.2f = %.4f",i,a[2][n-1],x,a[2][0],y,a[2][1],a[2][2],z1);
            x=x1,y=y1,z=z1;
            out[0][i]=x;
            out[1][i]=y;
            out[2][i]=z;
        }

        printf("\n\nx\t");
            for(int j=0;j<10;++j)
            {
                printf("%.2f\t",out[0][j]);
            }
        printf("\n\ny\t");
            for(int j=0;j<10;++j)
            {
                printf("%.2f\t",out[1][j]);
            }
        printf("\n\nz\t");
            for(int j=0;j<10;++j)
            {
                printf("%.2f\t",out[2][j]);
            }

    }
    return 0;
}
