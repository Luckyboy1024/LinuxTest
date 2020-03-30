 
#!/bin/sh  

if [ $# -lt 1   ] ; then 
	echo FileName to create is required

	exit 1
fi
FileName=$1
if [ -e $FileName   ]; then
	vim $FileName
	exit 1
fi
echo "#include <stdio.h>

int main()
{
	return 0; 
}
			
" > $FileName
vim $FileName

exit 0
	
