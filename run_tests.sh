clear

echo
echo "Compiling ..."
echo

{
    gcc -o tests_bin tests.c src/unit_tests.c src/sorts.c src/utils.c #src/data_structures.c 
    echo "[\033[0;34mdone!\033[0m]" 

} || { 
    echo "[\033[0;31mfailed\033[0m]" 
}


echo
echo "Running ..."
echo

{
    ./tests_bin
    echo
    echo "[\033[0;34mdone!\033[0m]" 
} || {
    echo
    echo "[\033[0;31mfailed\033[0m]"
}

echo
echo "Creating animations ..."
echo

{
    python3 animations/animate.py
    echo
    echo "[\033[0;34mdone!\033[0m]" 
} || {
    echo
    echo "[\033[0;31mfailed\033[0m]"
}

