#!/bin/bash
out="out.txt"
> "$out"  
sum=0
count=0

for file in measured/measurements*.txt; do
    # Skip if no matching files
    [ -e "$file" ] || continue

    # Extract lines containing TEMPERATURE 
    grep -Ei 'TEMPERATURE' "$file" >> "$out"

    # Extract numeric temperature values 
    temps=$(grep -i 'TEMPERATURE' "$file" | awk '{print $2}')

    for t in $temps; do
        # Skip non-numeric lines
        if [[ $t =~ ^[0-9.]+$ ]]; then
            sum=$(echo "$sum + $t" | bc -l)
            count=$((count + 1))
        fi
    done
done

if (( count > 0 )); then
    avg=$(echo "$sum / $count" | bc -l)
    echo "Average temperature: $avg"
else
    echo "No temperature data found — cannot compute average."
fi
