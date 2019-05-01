find . -name "*.cor" -exec rm {} \;
rm error_file
touch error_file
find . -name "*.s" -exec valgrind ./asm {}  \; 2>> error_file
rm my_res
touch my_res
find . -name "*.cor" -exec hexdump {} \; >> my_res
find . -name "*.cor" -exec rm {} \;
find . -name "*.s" -exec ./asm_og {} \;
rm og_res
touch og_res
find . -name "*.cor" -exec hexdump {} \; >> og_res
cat error_file | grep "blocks" | grep "e" | grep "d" | grep "y" | grep -v "supp"
diff og_res my_res
