# .bashrc

color_prompt=yes

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

if [ "$color_prompt" = yes  ]; then
#PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '

#-> ${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u @ \h\[\033[00m\] \d [\t] : \[\033[01;34m\]\w\[\033[00m\]
PS1='
\[\033[01;31m\]# \[\033[00m\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u\[\033[00m\] @ \[\033[01;32m\]linux\[\033[00m\] in \[\033[01;34m\]\w\[\033[00m\] [\t]
\[\033[01;35m\]\$ '
else
#PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$'
PS1='
${debian_chroot:+($debian_chroot)}\u@\h \d [\t] : \w
\$ '
fi

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=


# ####################

cdls()
{
	cd "$1";
	ls -l;
}

myrm()
{
	# 如果要清理回收站：cd ~/rubbish 然后 mv ./* /tmp/ 
	HOME=${HOME}
	RUBBISH="$HOME/rubbish"
	TMP=/tmp 
	if [[ ! -d $RUBBISH ]] ; then 
		mkdir $RUBBISH 
	fi 
	for i in "$@"
	do
		CUT_NAME=${i/%$"/"/""}
		FILENAME=$CUT_NAME-`date +"%Y%m%d-%H%M%S"`
		mv $CUT_NAME $FILENAME 
		if [[ -d "$FILENAME" ]] ; then 
			tar -cf "$FILENAME.tar" "$FILENAME"
			mv "$FILENAME.tar" $RUBBISH 
			mv $FILENAME $TMP 
		else 
			mv $FILENAME $RUBBISH 
		fi 
	done
}

# User specific aliases and functions


alias la='set *;echo "There is $# Files!";set --;ls -a --color=tty' #让ls命令支持显示文件数量和隐藏文件
alias cl='clear'
alias cd='cdls'
alias rm='myrm'
alias grep='grep --color=auto'

source /opt/rh/devtoolset-4/enable

