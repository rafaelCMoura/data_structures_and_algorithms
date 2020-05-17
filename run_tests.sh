clear

echo
echo "Compiling ..."
echo

{
    gcc -o tests_bin tests.c src/unit_tests.c src/sorts.c #src/data_structures.c src/utils.c
    echo -e "[\033[0;34mdone!\033[0m]" 

} || { 
    echo -e "[\033[0;31mfailed\033[0m]" 
}


echo
echo "Running ..."
echo

{
    ./tests_bin
    echo
    echo -e "[\033[0;34mdone!\033[0m]" 
} || {
    echo
    echo -e "[\033[0;31mfailed\033[0m]"
}
