# include<stdio.h>
# include<stdlib.h>
# include<math.h>

int *binaryadd(int, int*, int*, int*, int); /* funtion to add to binay numbers */

int *twoscmp(int n2, int d[32]) //function to find twos complement of a number 
{
int i,  carry,  *ptr, *c;
ptr = (int *)malloc(32*sizeof(int));
c = (int *)malloc(32*sizeof(int));
if(ptr == NULL) {printf("\nERROR\n"); exit(0);}
if(c == NULL) {printf("\nERROR\n"); exit(0);}

i=0;
while(n2!=0)
{
        ptr[i]=n2 % 2; /* converting number to its binary equivalent */
        n2/=2;
        i++;
}

//taking 1's complement
for(i = 0; i < 32; ++i)
{
	if(ptr[i] == 0) 
		ptr[i]=1;
	else 
		ptr[i]=0;
}

i=0;
carry=0;
//taking 2's complement
c = binaryadd(i, ptr, d, c, carry);
return c;
}


void reset(int d[], int n)
{
int i;
for(i=0; i<32; i++)
	d[i] = 0;
}


void main(int argc, char *argv[])
{
system("clear");
int n1, n2, i=0, carry=0, temp;
int  x, y, d[32], rev_a[32], rev_b[32];

int *a = (int *) malloc(32*sizeof(int));
	if(a == NULL) {printf("\nERROR\n"); exit(0);}

int *b = (int *) malloc(32*sizeof(int));
	if(b == NULL) {printf("\nERROR\n"); exit(0);}

int *c = (int *) malloc(32*sizeof(int));
	if(c == NULL) {printf("\nERROR\n"); exit(0);}

int j;
FILE *file1, *file2;

//setting d to 1
for(i=0; i<32; i++)
{
	if(i == 0)
		d[i] = 1;
	else
		d[i] = 0;
}

file1 = fopen(argv[1], "r");
file2 = fopen(argv[2], "r");

while(1)
{
//resetting the intermediate arrays
reset(a,32);
reset(b,32);
reset(rev_a,32);
reset(rev_b,32);
temp=0;

fscanf(file1, "%d", &n1);
fscanf(file2, "%d", &n2);
if(feof(file1) && feof(file2))
	break;

//backing up the numbers for future use
x=n1;
y=n2;

//Dealing with the 1st number
if(n1 < 0)
{
        a = twoscmp(abs(n1), d);
        for(i=31, j=0; i>=0; i--, j++)
        {
                rev_a[j] = a[i];
        }

}
else
{
        i=0;
        while(n1!=0) // converting 1st number to its binary equivalent 
        {
                a[i]=n1 % 2;
                n1/=2;
                i++;
        }

        for(i=31, j=0; i>=0; i--, j++)
        {
                rev_a[j] = a[i];
        }
}

//Dealing with the 2nd number
if(!(abs(n2) & (abs(n2) - 1)) && abs(n2)) //checking 2nd operand for power of 2
{
if(n2 > 32768)
{
	printf("Enter 2nd operand between 2^0 to 2^15\n");
	printf("Now skiping present addtion\n");
	continue;
}

if(n2 < 0)
{
        b = twoscmp(abs(n2), d);
        for(i=31, j=0; i>=0; i--, j++)
        {
                rev_b[j] = b[i];
        }
}

else
{
        i=0;
        while(n2!=0) // converting 2nd number to its binary equivalent  
        {
                b[i]=n2 % 2;
                n2/=2;
                i++;
        }

        for(i=31, j=0; i>=0; i--, j++)
        {
                rev_b[j] = b[i];
        }
}
}//checking if ends

else
{
	printf("\n2nd Operand is not a power of 2, check b1.dat\n");
	printf("Skiping present addition\n");
	continue;
}

i = 0;
carry = 0;
c = binaryadd(i, rev_a, rev_b, c, carry); //function called for binary add 
for(i=0;i<32;i++)
{
        temp = temp + (c[31-i]*(int)pow(2,i)); //calculating decimal equivalent
}

printf("\nreverse binary addition of %d and %d is %d\n", x, y, temp);

}//while ends

fclose(file1);
fclose(file2);

free(a);
free(b);
free(c);


}//main ends


int *binaryadd(int i, int *m, int *n, int *c, int carry)
{

if(*m==1 && *n==1 && carry==1)
{
        c[i]=1;
        carry=1;
}

else if(*m==1 && *n==1 && carry==0)
{
        c[i]=0;
        carry=1;
}

else if(*m==0 && *n==1 && carry==0)
{
        c[i]=1;
        carry=0;
}

else if(*m==0 && *n==1 && carry==1)
{
         c[i]=0;
         carry=1;
}

else if(*m==1 && *n==0 && carry==0)
{
         c[i]=1;
         carry=0;
}

else if(*m==1 && *n==0 && carry==1)
{
         c[i]=0;
         carry=1;
}

else if(*m==0 && *n==0 && carry==0)
{
         c[i]=0;
         carry=0;
}

else if(*m==0 && *n==0 && carry==1)
{
         c[i]=1;
         carry=0;
}

i++;
m++;
n++;

if(i<32) /* Base value of recursion */
        binaryadd(i,m,n,c,carry); /* recursion till we reach 32 bit of number */
return c;
}
