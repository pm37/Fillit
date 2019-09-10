# Fillit

Fillit is a recursive backtracking algorithm that fits a set of Tetriminos in the smallest possible square without rotating the Tetriminos. For more information, please [read the pdf](https://github.com/miniponps/42-Fillit/blob/master/pdf/fillit.fr.pdf).


Here is an example of valid input of 9 Tetriminos (maximum of 26 blocks):

```
....
.##.
.##.
....

...#
...#
...#
...#

....
..##
.##.
....

....
..#.
.##.
.#..

.###
...#
....
....

##..
.#..
.#..
....

....
..##
.##.
....

.#..
.##.
..#.
....

....
###.
.#..
....
```

Solution (each individual tetriminos renamed starting from A):
```
AAB.CCD
AABCCDD
FFB..D.
.FBEEE.
HF.GGE.
HHGGIII
.H...I.
```
### How to use:

Clone the repo and open it:

    git clone https://github.com/pimichau/Fillit.git
    cd Fillit
    
Then choose a map from the tests folder:

    cat tests/valid_1
    ./fillit tests/valid_1
    
For this example:

    ....
    .##.
    ..#.
    ..#.

    .##.
    ..#.
    ..#.
    ....
    
The output should be this:

    AABB
    .A.B
    .A.B
    ....
