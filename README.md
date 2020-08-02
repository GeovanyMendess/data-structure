<!-- PROJECT LOGO -->
<br />
<p align="center">
  
  <img src="./assets/data-structure-icon.png" alt="Data structure icon" width="150" height="150">
  

  <h3 align="center">Best-README-Template</h3>
  
</p>

# Data Structures

This repo is a collection of data structures built in C. Now it includes stack, queue, linked-list, binary-tree and red-black-tree. I'll update this repo constantly with other structures and improving the documentation with details of operations used in each one.

## Justification

The goal in the beginning was to make a review of the content studied at my second period in the university (UNIFEI - University Federal of Itajubá). The laanguage chosen was C because it allows to manipulate the memory adresses and I wanted to review operations involving pointers too. This repo can also help beginners in programming cause the operations mentioned before are usefull to improve the understanding of programming logic.

## Usage

It's included a Makerfile and a command for each structure and each one generates an executable file. Choose the respective structure the following command.

Stack:
```
make stack -B
```
Queue:
```
make queue -B
```
Linked List:
```
make linked-list -B
```
Binary Tree:
```
make binary-tree -B
```
Red Black Tree:
```
make rb-tree -B
```
Then, execute the following command to execute the executable generated:
```
./main
```
The tag `-B` forces the Makerfile to generate a new main. It's not necessary if you just want to execute the codes, but changes may be it necessary.
A menu was built with (ASCII characters) for each structure and the functions are intuitives ("Insert Element", "Remove Element", ...). Some function aren't being used at main and they have been created to help  internal functions. 

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## References
Algorithms Theory and Practice from Thomas H. Cormen, portuguese edition.

## License
[PUBLIC](https://choosealicense.com/licenses/unlicense/)

