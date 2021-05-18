# push_swap - sorting with two stackes

![Nyan Cat's reverse moon walk](https://github.com/sscottie/push_swap/blob/master/lib/visualisator/nyany.gif)

Main idea to sort the arrray of ints with minimal count of commands;

C, HTML, CSS, JavaScript are used.
**Warning: MacOs only!**

## Usage

* git-clone
* terminal-> cd /cloned_repo/ -> make
* use it!

There are 3 binary:
* push_swap
* checker
* preparator (bonus)

use ./push_swap <int arguments to sort>
output: list of commands to sort the int progression;

use ./push_swap <int args> | ./checker <same int args> to check, is that sorted.
Output: if sorted returns OK, else KO;

## Commands

* **sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* **sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* **ss** : sa and sb at the same time.
* **pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* **pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* **ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* **rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* **rr** : ra and rb at the same time.
* **rra** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* **rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* **rrr** : rra and rrb at the same time.

## Scripts

Useful scripts attached: 
* randomizer.sh - generates random ints between n1 and n2, and writes it in env value $ARG.
  * to generate: write in terminal . ./randomizer.sh n1 n2
* visualizer.sh - generates random ints, uses push_swap binary, and sends output into JavaScript's code
  * to watch kitties: ./visualizer.sh n1 n2
  * also works with existing $ARG: ./visualizer

Enjoy Nyan Cat's fly!
