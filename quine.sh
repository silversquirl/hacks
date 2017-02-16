program=(program=\( $'printf \'%s\' "${program[0]}"\nprintf \'%q \' "${program[@]}"\nprintf \')\\n%s\' "${program[1]}"' )
printf '%s' "${program[0]}"
printf '%q ' "${program[@]}"
printf ')\n%s' "${program[1]}"
