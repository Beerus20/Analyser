#!/bin/bash

FILE=$1
TOTAL=$2
BAR_WIDTH=50
COUNT=$(ls -1 "$FILE" | wc -l)

if [ $COUNT -le $TOTAL ]; then
    filled=$(( $COUNT * BAR_WIDTH / $TOTAL))
    empty=$(( BAR_WIDTH - filled ))
    bar=$(printf "%0.s#" $(seq 1 $filled))
    if [ $COUNT -eq $TOTAL ]; then
        space=$(printf "%0.s" $(seq 1 $empty))
    else
        space=$(printf "%0.s-" $(seq 1 $empty))
    fi
    printf "\r[\e[1;94m%s\e[31m%s\e[0m] %d%% " "$bar" "$space" "$(($filled * 100 / $BAR_WIDTH))"
else
	echo -e "\n"
fi
