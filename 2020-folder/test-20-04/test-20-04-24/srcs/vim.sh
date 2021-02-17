############# vim.sh ############
#!/bin/sh  

srand=$(date +%s)
rand=$[ $srand%10  ]

fill()
{
	echo "#include <stdio.h>

int main()
{
	return 0; 
}

	" > $1
}

if [ $# -lt 1    ] ; then 
#   echo FileName to create is required
	fill $rand.c $1
	vim $rand.c
	exit 1
fi
FileName=$1
if [ -e $FileName    ]; then
	vim $FileName
	exit 1
fi
fill $FileName $1
vim $FileName
exit 0
	
