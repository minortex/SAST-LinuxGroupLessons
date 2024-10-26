---
theme: seriph
title: Linux 概念及基础教程
class: text-center
transition: slide-left
mdc: true
overviewSnapshots: true
---

#  Linux 概念及基础教程

软件研发部 运维组

---

# 为什么要使用 Linux ?

- 喜欢折腾
- 想要成为黑客！
- 想要深层次的学习计算机/操作系统原理
- 厌倦了 windows 的反人类设计
- 想要为开源软件做贡献 :)

## Or： 

- 需要配置各种开发环境
- 专业软件不支持 windows

*事实上，可以认为世界上的 90% 的设备都运行在 Linux 上*  

---
layout: quote
---

# Linux 历史

- Unix Family / BSD Family
- GNU - GNU is Not Unix (Richard Stallman)

1991 年，正在大学内进修的林纳斯·托瓦兹对他使用的一个类 UNIX 操作系统 MINIX 十分不满，
因为当时 MINIX 仅可用于教育但不允许任何商业用途。  
于是他在他的大学时期编写并发布了自己的操作系统，
也就是后来所谓的 “Linux 内核”，成为了如今各类 Linux 发行版的基础。  

---
layout: center
---

# Linux 哲学

- Do one thing, and do it well.
- Everything is a file.
- Keep it Simple, Stupid.

---

# 什么是操作系统?

- 运行在最底层，负责为上层应用提供接口（服务）的软件
- 负责多个应用的进程管理、硬件设备（cpu、ram、硬盘等等）的资源管理
- 负责管理应用安全权限
- ...

## Linux 设计特点

<br>

- 代码简洁，可移植性高
- 开放源代码
- 原生支持多用户
- 结构化的文件系统
- ...

---
layout: quote
---

# Windows vs. Linux

内在复杂度 vs. 外在复杂度  
习惯 Linux 操作后，你会感觉到 windows 是多么难用  
在使用的过程中，你会不可避免的遇到各种问题，
但是在解决这些问题的过程中，你会更加深入的理解操作系统及计算机的原理...  

---

# Linux 组成

内核 + 文件系统 + 各种软件包

<Transform :scale="0.73">
<img
border="rounded"
src="/linux.png"
alt=""
/>
</Transform>


---

# Linux 下的目录结构 （FHS）

Linux 下不根据磁盘来划分文件目录，而是把所有磁盘都挂载到了同一个目录下，
并依照统一的标准划分文件。  

<Transform :scale="0.7">
<img
border="rounded"
src="/fhs.jpg"
alt=""
/>
</Transform>

---
layout: quote
---

# 一切皆文件

将操作系统的 IO 操作抽象成文件操作  

万物皆可读写 ？  

从终端、打印机到鼠标、键盘，所有设备都被抽象成了一个文件  

---
layout: quote
---

# Linux 下的软件包

由于 Linux 下不同的软件包（模块）具有不同的依赖关系，  
所以需要一个工具（包管理器）来帮助你管理这些依赖  

- 千千万万的软件包组成了对应的依赖关系
- 各种软件包分而治之
- 一个模块只做一件事情 （DOADIW）
- 每个模块可维护可升级可演化

---
layout: quote
---

# Linux Distribution

基于 Linux 内核，产生了许多有名的发行版  
一个典型的发行版包括：Linux 内核，GNU 库和各种系统工具，命令行 Shell，图形界面的 X 窗口和上层的桌面环境等。
桌面环境有如 KDE 或 GNOME 等，并包含数千种应用软件。  
而不同的发行版一般有不同的包管理器工具  

<br>

其中最著名的有 deb(apt) 和 rpm(yum/dnf) 系  

- deb 系： debian、ubuntu...
- rpm 系： centos、fedora、rocky...

前往[distrowatch](https://distrowatch.com/)了解更多

---
layout: quote
---

# Linux 安装

- cygwin/mingw
- wsl (Windows Sub Linux)
- Linux 虚拟机
- ~~把 Windows 删了~~

---

# Shell (命令行环境)

最直接的和内核进行交互的方法  
有多种 shell 可以选择： bash、zsh、fish...

最基本的命令组成:

```shell
command args1 args2 args3...
```

一般来说，`-{x}`或者`--{x_fullname}`表示这个命令的选项  

## 这是怎么来的？

```c
int main (int argc, char* argv[]) {}
// argc 是你传进去的参数数量
// argv 是你传进去的参数的二级指针
```

---

# Examples

### `ls - list directory contents`

```shell
ls [OPTION]... [FILE]...

ls # 查看当前目录下的文件和文件夹
ls -l dir # 使用列表格式查看 dir 文件夹里的内容
```

### `cd - change working directory`

```shell
cd [dirName]

cd dir1  # 进入 dir1 目录
cd dir1/dir2  # 进入 dir1 下的 dir2 目录
cd ../  # 进入上一级目录
cd ./  # 进入当前目录（好像没啥用啊）
cd -  # 返回之前的一级目录
cd  # 返回当前用户的家目录
```

命令不需要背下来，只需要熟记常用的几个，其他命令都可以在需要的时候查阅 `man/tldr`

---
layout: quote
---

# 基本操作

## 文件操作

mv、cp、rm、fd、touch、mkdir...  
cat、nano、sed、awk、grep、tail、less...  

## 实用工具

ps、top、wc、xargs、ip、lsusb、curl、tar、7z...  
git、fzf、ripgrep、tldr、tmux...  

## cheatsheet

[cheatsheet](https://phoenixnap.com/kb/wp-content/uploads/2023/11/linux-commands-cheat-sheet-pdf.pdf)

---

# 环境变量

命令执行时的环境所定义的变量  
可以使用`echo ${VairableName}`查看  

## PATH

定义了存放你当前可执行文件的路径  
当你输入一个命令时，shell 会在 PATH 定义的目录下查找同名的可执行文件，
如果没找到，它就会提示类似于这样的错误信息： `zsh: command not found`  

其默认值为`/usr/bin:/usr/local/bin`  

## USER

定义了当前用户的用户名  

---
layout: quote
---

# Linux 输入输出

## `file descripter  (fd)`

每一个进程默认都有 3 个 fd，
分别对应了标准输入 0 `stdin`、标准输出 1 `stdout` 和错误输出 2 `stderr`  

## 重定向

- `>`和`>>`将标准输出重定向到指定的文件中
- `|`管道运算符将上一个命令的标准输出重定向到下一个命令的标准输入中

---

# Linux 权限管理

- 用户及用户组
- root 系统管理员

## 切换用户/以某个用户的身份执行命令

- `su` 切换用户，一般会要求输入对应用户的密码
- `sudo` 以某个用户的权限执行命令

<br>

::card
Linux 下的根用户(root)拥有对系统的最高权限，请谨慎使用！  
常见的可能对系统造成毁灭性破坏的命令:

```shell
rm -rf /  # 删除系统上所有文件，包括系统本身
dd if=/dev/urandom of=/dev/sda  # 使用随机数填满 sda 磁盘
:(){ :|: & };:  # fork bomb，通过不断 fork 自身消耗完所有的系统资源
```

::

<!--
早期的操作系统没有用户的概念（如 MS-DOS），
或者有「用户」的概念，但是几乎不区分用户的权限（如 Windows 9x）。
而现在，这不管对于服务器，还是个人用户来说，都是无法接受的。

在服务器环境中，
「用户」的概念是明确的：服务器的管理员可以为不同的使用者创建用户，分配不同的权限，保障系统的正常运行；
也可以为网络服务创建用户（此时，用户就不再是一个有血有肉的人），通过权限限制，以减小服务被攻击时对系统安全的破坏。

而对于个人用户来说，他们的设备不会有第二个人在使用。
此时，现代操作系统一般区分使用者的用户与「系统用户」，并且划分权限，
以尽可能保证系统的完整性不会因为用户的误操作或恶意程序而遭到破坏。
-->

---

# 在 Linux 下安装软件

推荐使用系统的包管理器  

## 配置南邮镜像源

[官方教程](https://mirrors.njupt.edu.cn/help/ubuntu/)

<br>

## 安装软件包

<br>

```shell
sudo apt update  # 更新本地软件包索引
sudo apt install xyz  # 安装 xyz 软件包
sudo apt search xyz  # 全局搜索某个软件包
```

---
layout: quote
---

# 开源历史和开源精神

强烈推荐阅读《大教堂与集市》~~开源软件的圣经~~，读完后，你会对开源和黑客文化有一个更深的入的理解。  

**开源 不等于 开放源代码!**

<br>

如果我说软件不一定长得像一个牛皮藓，不一定有启动摇一摇广告，
不一定把所有功能都挤在某个边边角角里？  

> “自由软件”尊重用户的自由，并且尊重整个社区。  
> 粗略来讲，一个软件如果是自由软件，
> 这意味着用户可以自由地运行，拷贝，分发，学习，修改并改进该软件。  
> 因此，“自由软件”是关乎自由的问题，与价格无关。

---

# 使用自由软件

自由软件现在更加重要  

<br>

::card
使用自由软件，用户控制程序，无论是单个用户还是集体用户。  
所以他们控制着计算机做什么（假设计算机是听话的并且按照用户的程序来执行）。  
使用专有软件，软件控制用户，而其他实体（开发者或“所有者”）控制程序。
所以专有软件赋予开发者凌驾于其用户之上的权力。  
这本身就不公平；甚而，这个权力会诱使其开发者用其他方法损害用户。  
即使专有软件不是完全的恶意，其开发者也有动机使之容易成瘾、有控制权和受操控。  
你会说，就像该文章的作者一样，开发者有道义不那么做，但是一般他们都会被利益驱使。
如果你不想看到这些，那么请确保程序被其用户控制。  
自由就意味着能够控制自己的生活。
如果你用一款软件去实现你生活中的活动，你的自由就依赖于对这款软件的控制权。
你有权拥有你所使用的软件的控制权，当你用它们来做重要事情是则更是如此。  
::

---

# 一些学习资料

有时间就要学习 xD

- [USTC Linux101](https://101.ustclug.org/)
- [进一步了解 GNU!](https://www.gnu.org/)
- [大教堂与集市](https://github.com/thuwyh/The-Cathedral-the-Bazaar-zh/blob/master/%E5%A4%A7%E6%95%99%E5%A0%82%E4%B8%8E%E9%9B%86%E5%B8%82.md)
- [Linux Atonomy](https://personalpages.manchester.ac.uk/staff/m.dodge/cybergeography/atlas/linux_anatomy.pdf)
- [The art of Commandline](https://github.com/jlevy/the-art-of-command-line/blob/master/README-zh.md)
- [missing semester](https://missing-semester-cn.github.io/)
- [linux command cheatsheet](https://phoenixnap.com/kb/wp-content/uploads/2023/11/linux-commands-cheat-sheet-pdf.pdf)

---
layout: end
---

# Thanks!

