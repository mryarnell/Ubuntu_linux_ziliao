HOST# chmod:
修改文件夹及其子文件夹的权限

-rw------- (600) -- 只有属主有读写权限。  
-rw-r--r-- (644) -- 只有属主有读写权限；而属组用户和其他用户只有读权限。  
-rwx------ (700) -- 只有属主有读、写、执行权限。  
-rwxr-xr-x (755) -- 属主有读、写、执行权限；而属组用户和其他用户只有读、执行权限。  
-rwx--x--x (711) -- 属主有读、写、执行权限；而属组用户和其他用户只有执行权限。  
-rw-rw-rw- (666) -- 所有用户都有文件读、写权限。这种做法不可取。  
-rwxrwxrwx (777) -- 所有用户都有读、写、执行权限。更不可取的做法。 

加入-R 参数，就可以将读写权限传递给子文件夹
例如chmod -R  777  /home/mypackage
那么mypackage 文件夹和它下面的所有子文件夹的属性都变成了777.

//--------------------------------------------------------------------
HOST# ssh
连接开发板
ssh root@192.168.1.102

//--------------------------------------------------------------------
解压
命令格式：tar -zxvf 【压缩包文件名.tar.gz】 -C  【路径】/
注释：解压.tar.gz格式到指定的目录下
例如：tar -zxvf japan.tar.gz -C /tmp/

tar -xvf file.tar //解压 tar包

tar -xzvf file.tar.gz //解压tar.gz

tar xjvf file.tar.bz2   //解压 tar.bz2

tar -xZvf file.tar.Z   //解压tar.Z

unrar e file.rar //解压rar

unzip file.zip //解压zip

1 将tgz文件解压到指定目录
tar   zxvf    test.tgz  -C  指定目录
比如将/source/kernel.tgz解压到  /source/linux-2.6.29 目录
tar  zxvf  /source/kernel.tgz  -C /source/ linux-2.6.29

//--------------------------------------------------------------------
HOST# scp
在虚拟机上新建文件，并且拷贝文件到开发板文件系统下，执行如下命令：
scp （文件路径） root@192.168.1.102:/目标路径

拷贝文件夹
scp -r (文件夹路径) root@192.168.1.102:/目标路径

//--------------------------------------------------------------------
HOST# rm
删除文件
rm 文件路径

rm -rf 
删除目录及其子目录
rm -rf 文件目录路径

//--------------------------------------------------------------------
HOST# mv
移动或更名现有的文件或目录。
mv 
文件

mv -f /
目录

//---------------------------------------------------------------------
在开发板中当前执行以下命令挂载 (nfs 服务器)共享目录到开发板的/nfs 目录：
Target# mount -t nfs -o nolock 192.168.1.107:/home/tl /nfs

卸载开发板的 nfs 挂载目录
执行以下命令离开开发板/nfs 目录，并卸载 nfs 挂载目录：
Target# cd
Target# umount /nfs/

//---------------------------------------------------------------------
HOST# ps	列出该用户进程
HOST# ps -e 列出所有用户进程

//------------------vim编辑器-----------------------------------------
HOST# vi /
vi编辑器
按ESC键 跳到命令模式，然后：
:w   保存文件但不退出vi
:w file 将修改另外保存到file中，不退出vi
:w!   强制保存，不推出vi
:wq  保存文件并退出vi
:wq! 强制保存文件，并退出vi
q:  不保存文件，退出vi
:q! 不保存文件，强制退出vi
:e! 放弃所有修改，从上次保存文件开始再编辑
:set nu 显示行号
注意：冒号也要输进去

//-------------------vim编辑器------------------------------------------
垂直分割
vim编辑器

:vsplit
或者
:vsplit two.c
在 窗 口 间 跳 转

由于你可以用垂直分割和水平分割命令打开任意多的窗口，你就能够任意设置窗口的布局。接着，你可以用下面的命令在窗口之间跳转：

CTRL-W h 跳转到左边的窗口
CTRL-W j 跳转到下面的窗口
CTRL-W k 跳转到上面的窗口
CTRL-W l 跳转到右边的窗口

CTRL-W t 跳转到最顶上的窗口
CTRL-W b 跳转到最底下的窗口
:set hls 打开高亮  gd选中单词显示高亮   n  查找下一个

//-------------------vim编辑器------------------------------------------
移动光标类命令
h ：光标左移一个字符
l ：光标右移一个字符
space：光标右移一个字符
Backspace：光标左移一个字符
k或Ctrl+p：光标上移一行
j或Ctrl+n ：光标下移一行
Enter ：光标下移一行
w或W ：光标右移一个字至字首
b或B ：光标左移一个字至字首
e或E ：光标右移一个字至字尾
) ：光标移至句尾
( ：光标移至句首
}：光标移至段落开头
{：光标移至段落结尾
nG：光标移至第n行首
n+：光标下移n行
n-：光标上移n行
n$：光标移至第n行尾
H ：光标移至屏幕顶行
M ：光标移至屏幕中间行
L ：光标移至屏幕最后行
0：（注意是数字零）光标移至当前行首
$：光标移至当前行尾
n+        //向下跳n行
n-         //向上跳n行
nG        //跳到行号为n的行
G           //跳至文件的底部
//---------------------------------------------------------------------
重启 Samba。执行如下命令：
Host# sudo restart smbd && sudo restart nmbd

//---------------------------------------------------------------------
HOST# terr -L 3
显示目录树状图

//---------------------------------------------------------------------
udhcpc
获取IP地址

//---------------------------------------------------------------------
HOST# cp
把*.c 和*.h 文件拷贝到新建的工程 host 目录下，然后在 host 目录下可以看到文件已
拷贝成功。
HOST# cp *.[ch] /home/tl/project/messageq/host/

//----------------------tftp-----------------------------------------
进入tftp模式HOST# sudo tftp localhost
重新启动tftp服务
HOST# sudo service tftpd-hpa restart

//---------------------命令历史-------------------------------------
HOST# history

HOST# ！命令编号（就可以运行命令历史列表中选择的命令）

//---------------------设置分辨率-------------------------------------
xrandr --output Virtual1 --mode 1360x768
xrandr --output Virtual1 --mode 1680x1050

//---------------------修改环境变量-------------------------------------
HOST# cd /etc/profile
	增加:export PATH=$PATH:(路径)
		例如:export PATH=$PATH:/usr/local/arm-gdb/bin
	或者：
		PATH="$PATH:/home/tl/python/sdk/Python-2.7.13"
		export PATH
	
//---------------------呼出嵌入终端-------------------------------------
在Ubuntu下安装byobu的命令为
　　sudo apt-get install screen byobu
启动byobu
HOST# byobu

//---------------------安装deb软件-----------------------------------------
通过deb包安装软件：
sudo dpkg -i package_file.deb

卸载:

sudo dpkg -r package_name

注意，卸载时候是package_file.deb对应的package name
若不知道package name，可以通过

dpkg -l查找，若要查找对应的package，可以加通配符，如查找包含fox的package

dpkg -l *fox*即可

查到以后，可以运行

dpkg -r package_name卸载


//---------------------find查找-------------------------------------
HOST# sudo find . -name 'build_x64.sh' //搜索./build_x64.sh

//---------------------上传rz命令-------------------------------------
Ubuntu安装rz，sz工具
HOST# sudo apt-get install lrzsz
在SecureCRT超级终端下
执行
HOST# rz //会上传文件到本地目录

//---------------------手动配置网卡IP-------------------------------------
HOST# sudo ifconfig eth0 192.168.1.7

//---------------------Git添加跟踪文件-----------------------------------------
HOST# git add filename.txt
HOST# git status				//查看添加的文件/变更的情况
HOST# git commit filename.txt	//提交修改满意的文件
HOST# git log					//查看历史版本描述
HOST# git reset --hard	fileID	//回到指定的历史版本（还是在Master分支）
HOST# git branch				//查看当前在哪个分支
HOST# git checkout [fileID/master]	//切换分支	//切换版本（会来开Master分支，也就是说，目录中跟踪过的文件也会变成当时的样子）
HOST# git reflog 				//查看历史git命令
//添加远程仓库
HOST# git remote add origin git@github.com:mryarnell/gitskills.git
//第一次推送到远程仓库
HOST# git push -u origin master
//第一次推送过后，推送到远程仓库
HOST# git push origin master
//从远程库克隆到本地库
HOST# git clone git@github.com:mryarnell/gitskills.git
//查看远程库
HOST# git remote -v
//从远程库获取更新到本地，需要2步
第一步：git fetch origin master		//获取
第二步：git merge origin/master		//合并
//比较本地的仓库和远程参考的区别
HOST# git log -p master.. origin/master

//---------------------mysql-----------------------------------------
mysql的目录在：/var/lib/mysql/
登陆mysql
	host# mysql -h 域名 -u 'username' -p
	Enter password:'password'
	例子：
	host# mysql -h localhost -u root -p
	Enter password:aa
创建一个数据库
	mysql> create database if not exists 'databasename';
	例子：
	mysql> create database if not exists tynyarnell;
删除一个数据库
	mysql> 
	例子：
	mysql> drop database if not exists tynyarnell;
显示当前所有的数据库
	mysql> show databases；
选择一个库作为默认数据库
	mysql> use 'databasename';

SQL (Structured Query Language)

DDL
	mysql> create database if not exists 'databasename';
	mysql> use 'databasename'
	不够精确：create table ['databasename'.]'tablename' 
	
	mysql> drop database if not exists 'databasename';
	mysql> drop table if not exists 'tablename';
	
DML
	mysql> insert into users(id,name) values('1','zhangsan');
	mysql> vpdate users set name='aa',age='10' where id='1';
	mysql> delete from 'tablename' where id='2';
	
DQL
	mysql> select * from 'tablename';

DCL
	mysql> \s						#看状态
	mysql> show databases; 			#看所有库
	mysql> show tables;				#看所有表
	mysql> desc	'tablename';		#看表结构
	mysql> show variables			#配置文件中的变量
	
数据值和列类型
	1字节	tinyint
	2字节	smallint
	3字节	mediumint
	4字节	int
	8字节	bigint
	4字节	FLOAT
	8字节	DOUBLE
	

帮助的使用
1.帮助能给我们提供什么内容
	mysql> ？ contents
			？+命令


			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			







	
	
	
	
	
	
	
	
	
	