#!/bin/bash

if [[ $1 ]] && [[ $2 ]]; then
	. ./randomizer.sh $1 $2
fi
../preparator -a $ARG > ../lib/visualisator/input.js
../push_swap $ARG | ../preparator -c $ARG > ../lib/visualisator/commands.js
open -a "Safari" ../lib/visualisator/index.html