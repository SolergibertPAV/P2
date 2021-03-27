#!/bin/bash

# Be sure that this file has execution permissions:
# Use the nautilus explorer or chmod +x run_vad.sh
for num_init in 9 10; do
#for num_ms in 1 2 3 4 5 6; do
#for num_mv in 1 2 3 4 5 6; do  
#for alpha_uno in 1 2 3 4; do
#for alpha_dos in 1 2 3 4; do
# -N <number-init> -s <number-ms> -m <number-mv> -a <n-alpha1> -b <n-alpha2>
# Write here the name and path of your program and database
DB=/Users/tj/Desktop/PAV/P2/db.v4
#CMD="bin/vad -N $num_init -s $num_ms -m $num_mv -a $alpha_uno -b $alpha_dos"
CMD="bin/vad -N $num_init"

for filewav in $DB/*/*wav; do
#    echo
    echo "**************** $filewav ****************"
    if [[ ! -f $filewav ]]; then 
	    echo "Wav file not found: $filewav" >&2
	    exit 1
    fi

    filevad=${filewav/.wav/.vad}

    $CMD -i $filewav -o $filevad || exit 1

# Alternatively, uncomment to create output wave files
#    filewavOut=${filewav/.wav/.vad.wav}
#    $CMD $filewav $filevad $filewavOut || exit 1

done

scripts/vad_evaluation.pl $DB/*/*lab
done
#done
#done
#done
#done
exit 0
