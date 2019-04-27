find . -name "*.cor" -exec rm {} \;
find . -name "*.s" -exec ./asm {} \;
rm my_res
touch my_res
find . -name "*.cor" -exec hexdump {} \; >> my_res
find . -name "*.cor" -exec rm {} \;
find . -name "*.s" -exec ./asm_og {} \;
rm og_res
touch og_res
find . -name "*.cor" -exec hexdump {} \; >> og_res
diff my_res og_res
