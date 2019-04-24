valgrind ./asm $1.s
hexdump $1.cor > my_res
./asm_og $1.s
hexdump $1.cor > og_res
if [ "$2" == "show" ]
then
	cat my_res
	echo " ----------------"
	cat og_res
else
	diff my_res og_res
fi
