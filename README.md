# Reverse-carry-addition
## Background
Reverse carry  addition  is  a  generalized  approach  for  generating  Bit reversed  indices  or  addresses, commonly used with Radix-2 Fast Fourier Transforms to "descramble" the output coefficients when the inputs are in natural order (or equivalently, to "pre scramble" the inputs so the output coefficients are in natural order).

#### Linear Array Indices                                   

| Int |Hex | Binary |
| :---:         |     :---:      |         :---: |
| 0   | 0x0     | 00    |
| 1     |0x1       | 01      |
| 2     |0x2       | 10      |
| 3     |0x3       | 11      |

#### Bit Reversed Array Indices                                  

| Binary |Hex | Int |
| :---:         |     :---:      |         :---: |
| 00   | 0x0     | 0   |
| 10     |0x2       | 2      |
| 01     |0x1       | 1      |
| 11     |0x3       | 3      |

Note the first three columns show three different representations (integer, hexadecimal, binary) of the  linear progression  of  array  indices from  0 to N-1, while the  last three  columns show the bit reversed  progression for the same representations.

For the linear progression, the increments from 0 to N-1 consist of adding a bit to the least significant  bit-position with carries propagated “forward” from right-to-left, as shown in following Table.    

| 0 to 1 |1 to 2 | 2 to 3 |
| :---:         |     :---:      |         :---: |
| 00   | 01     | 10    |
|+10   |+10    | +10 |
| 10   | 01     | 11    |

For both the forward- and reverse-carry examples above, it is only the middle column (forward 1 to 2;  reverse 2 to 1) where a carry occurs (the “1”s bits line up and the addition produces the carry).  If you  are unfamiliar with binary addition and the examples above are not clear there a many “binary addition”  tutorials available on-line that demonstrate the basics of binary addition and forward carry propagation.

#### Programming Implementation
Generalized reverse-carry addition algorithm is implemented in a C code that meets the following criteria 

#### Criteria
1. The algorithm is non-saturating i.e., handles overflow/underflow conditions.  
2. The program can be compiled with gcc and executed from the command-line.
3. The program expects two input files as input arguments (mapped to argv[1], argv[2]), each file will contain a column vector of integer formatted data. Paired test-input files will have the  same number of elements; corresponding elements are operands to the reverse-carry addition  operation (see Example folder). 
4. The  program  prints  integer  formatted  output  (one  value  per  line)  to  stdout  (use  redirection to save to file, if desired).    
5. One operand will always be an exact  power-of-two  in the range of  2<sup>n</sup>  where  n = {0, 1, 2, 3,…,15}, the other operand will be  in the  range of [0, 2<sup>31</sup>-1].   

### Logic & Analysis
1. The code takes Two files as input (argv[1], argv[2]).
2. The number of elements in both the i/p file is same as they are operands of the Reverse Binary Addition.
3. One file contains the numbers in the range [0-2<sup>31</sup>-1] and the other contains numbers of the form 2<sup>n</sup> where n= {0, 1, 2 ... 15}.
4. The program first converts both the decimal numbers into its binary equivalent and then calls the binary add subroutine which recursively adds every pair of bits of the numbers while making the carry propagate through left to right.

* In every loop the decimal to binary conversion takes O(log<sub>2</sub>n1)+ O(log<sub>2</sub>n2). Where n1, n2 are the
decimal operands.
* The recursive addition takes O(8) in the worst case for every bit pair addition. Therefore for n<sub>b</sub> pair
addition it takes O(8*n<sub>b</sub>). Where n<sub>b</sub> is maximum number of bits used in the binary representation.
* Hence, one reverse carry addition takes {O(log<sub>2</sub>n1) + O(log<sub>2</sub>n2) + O(8\*n<sub>b</sub>)}. If there are N elements in every input file, therefore total run time is N*{O(log<sub>2</sub>n1) + O(log<sub>2</sub>n2) + O(8*n<sub>b</sub>)}.
* In other words,time complexity = O(N\*log<sub>2</sub>(n1\*n2)) + O(8\*N\*n<sub>b</sub>) ....... (1)
* Considering the maximum values of n1 and n2 we have log<sub>2</sub>(n1\*n2) = c, a constant.
* Similarly we have 8*N*n<sub>b</sub> = k, another constant
* Therefore Eq. (1) becomes, time complexity = O(c\*N) + O(k\*N) ....... (2)
* R.H.S of equation (2) is nothing but O(constant\*N). Therefore the running time complexity of this Reverse-carry-addition algorithm is O(N).

### Compile & Run
compile it by running this command: **gcc -o rev_carry_add_wasim rev_carry_add_wasim.c -lm**. It witll create an object file **rev_carry_add_wasim**, which can then be run. For example using the data from Example folder, **./rev_carry_add_wasim a1.dat b1.dat**

