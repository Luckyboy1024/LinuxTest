#!/bin/sh

if [ $# -lt 1  ] ; then
	echo "FileName to create is required"
	exit 1
fi
FileName=$1
if [ -e $FileName  ]; then
	vim $FileName
	exit 1
fi
echo " 
#include <stdio.h>

int main()
{
	return 0; 
}

" > $FileName

#echo "#include <stdio.h>" > $FileName 
#echo "" >> $FileName 
#echo "int main()" >> $FileName 
#echo "{" >> $FileName 
#echo "    return 0;" >> $FileName 
#echo "}" >> $FileName 
vim $FileName 

exit 0
