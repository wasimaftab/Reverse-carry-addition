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
