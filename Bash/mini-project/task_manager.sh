#!/bin/sh

filename="tasks.txt"

add_task(){ 
	num_lines=$(wc -l <"$filename")
	if [ "$num_lines" = 0 ]; then
		echo "Description |  Status" >> "$filename"
	fi
	echo "Please Enter the Description of the task, 30 characters max:"
	read desc
	length=${#desc}
	if [ "$length" -le 30 ]; then
		echo "$desc | Not_Completed" >> "$filename"
	else
		echo "Long Description!!"
	fi
}

delete_task(){
	num_lines=$(wc -l <"$filename")
	if [ "$num_lines" = 0 ]; then
		echo "File is Empty!!, Please add a task first"
		return
	fi
	view_task
	echo "Please Enter the number of the task you want to delete:(all -> A)"
	read num
	if [ "$num" = "A" ]; then
		truncate -s 0 "$filename"
	else
		if [ "$num" -le "$num_lines" ] && [ "$num" -gt 0 ]; then
			sed -i "${num}d" "$filename"
		else
			echo "Wrong line number!!"
		fi
	fi
}

mark_task(){
	num_lines=$(wc -l <"$filename")
        if [ "$num_lines" = 0 ]; then
                echo "File is Empty!!, Please add a task first"
                return
        fi
	view_task
        echo "Please Enter the number of the task you want to Mark Completed:"
        read num
	if [ "$num" -le "$num_lines" ] && [ "$num" -gt 0 ]; then
		awk -F'|' -v r=$num 'BEGIN {OFS = FS} NR==r {$2=" Completed"}1' "$filename" > temp && mv temp "$filename"
        else
                echo "Wrong line number!!"
        fi

}

view_task(){
	num_lines=$(wc -l <"$filename")
        if [ "$num_lines" = 0 ]; then
                echo "File is Empty!!, Please add a task first"
                return
        fi
	awk -F'|' '{printf " %-5s %-30s %-10s\n", NR, $1, $2}' "$filename" 
}


tries=3

while [ $tries -gt 0 ]
do
	echo "Please Enter your command (Add Task -> A, View tasks -> V, Mark a task -> M, Delete a task(s) -> D, Exit -> E)"
	read cmd

	if [ "$cmd" != "A" ] && [ "$cmd" != "V" ] && [ "$cmd" != "M" ] && [ "$cmd" != "D" ] && [ "$cmd" != "E" ]; then
		tries=$((tries - 1))
		echo "Wrong command, number of tries left" $tries
		echo " "
	else
		tries=3
	fi	

	if [ "$cmd" = "E" ]; then
		exit 1
	elif [ "$cmd" = "A" ]; then
		add_task
	elif [ "$cmd" = "V" ]; then
		view_task
	elif [ "$cmd" = "M" ]; then
		mark_task
	elif [ "$cmd" = "D" ]; then
		delete_task
	fi



done
