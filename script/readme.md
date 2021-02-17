##  Script --- 脚本
####   此目录中存放的是本人编写的
####   仅用于 Linux bash 中的一些脚本

shell 脚本：
1.创建文件：必须以 .sh 结尾，例：test.sh
2.文件内第一行：#!/bin/bash   ----->这是Shell脚本的bash编译器，/bin/bash 很明显是目录
3.运行 shell
  [1].先运行解释器(例:bash)，再运行 shell 文件: $ bash test.sh
  [2].通过 $ chmod u+x test.sh 给这个文件加可执行权限，直接运行 $ ./test.sh 即可，"这种方式较常用"
4.脚本中写什么？
  [1].直接写指令，当脚本运行起来，文件内的指令将依次被执行
