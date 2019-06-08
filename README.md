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
Generalized reverse-carry addition algorithm is implemented in a C program that meets the following criteria 

#### Criteria
1. Implemented algorithm is non-saturating, handles overflow/underflow conditions.  
2. The program will be compiled with gcc and executed on the command-line.
3. The program will take two test-input files as input arguments (mapped to argv[1], argv[2]), each file will contain a column vector of integer formatted data. Paired test-input files will have the  same number of elements; corresponding elements are operands to the reverse-carry addition  operation (see Example folder). 
4. The  program  prints  integer  formatted  output  (one  value  per  line)  to  stdout  (use  redirection to save to file, if desired).    
5. One operand will always be an exact  power-of-two  in the range of  2^n  where  n = {0, 1, 2, 3,…,15}, the other operand will be  in the  range of [0, 2^31-1].  
6. Complexity is O(N) (see Logic & Analysis section in README).   
