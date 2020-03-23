#!/bin/bash
sleep_time=0.1        #全局变量，控制进度条速度

proc(){
    bar=""        # 初始化，Shell脚本弱类型
    lable=('|' '\\' '-' '/')    #字符间以空格间开
    index=0
    for((i = 0; i <= 100; i++))
    do 
        printf "[%-100s][%d%%][%c]\r" "$bar" "$i" "${lable[$index]}"
        sleep $sleep_time 
        bar=$bar'#'       # Shell脚本的字符串拼接,直接将字符串写在一起
        ((index++))
        ((index %= 4))
    done 
    printf "\n"
}

main(){
    printf "Please Enter Your OP# "
    read s
    case $s in 
        'start' )   
            echo "command start..."
            sleep_time=0.01    #修改全局变量，调配速度
            proc 
            ;;       
        'stop' )
            echo "command stop"    
            sleep_time=0.05    #修改全局变量，调配速度
            proc 
            ;;
        'restart' )
            echo "restarting..."
            sleep_time=0.001    #修改全局变量，调配速度
            proc 
            ;;
        * )            
            echo "default..."
            ;;
    esac 
}

main 
