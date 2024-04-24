#!/bin/bash

# What day of the week task :)

tries=3

while [ $tries -gt 0 ]
do

	echo "Please Enter the day (Mon, Tue, Wed, Thu, Fri, Sat, Sun):"
	read day

	if [ "$day" != "Mon" ] && [ "$day" != "Tue" ] && [ "$day" != "Wed" ] && [ "$day" != "Thu" ] && [ "$day" != "Fri" ] && [ "$day" != "Sat" ] && [ "$day" != "Sun" ]; then
		if [ "$tries" -gt 0 ]; then
			tries=$((tries - 1))
			echo "Wrong input, number of tries left = $tries"
			echo " "
		fi

		if [ "$tries" == 0 ]; then
			exit 1
		fi
	else
		break
	fi
done


echo "Please Enter number of days:"
read num

declare -A Day_to_num
Day_to_num=([Mon]=1 [Tue]=2 [Wed]=3 [Thu]=4 [Fri]=5 [Sat]=6 [Sun]=0)

declare -A Num_to_day
Num_to_day=([1]=Mon [2]=Tue [3]=Wed [4]=Thu [5]=Fri [6]=Sat [0]=Sun)

temp=${Day_to_num[$day]}

ans=$(((temp+num) % 7))

echo "That would be" ${Num_to_day[$ans]}

unset Day_to_num
unset Num_to_day

echo ${Day_to_num[$day]}
