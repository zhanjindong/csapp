### read和write函数是最基本的系统IO
ssize_t read(int fd, void *buf, size_t count)//-1:error;0:eof;>0:实际传递的字节数

ssize_t write(int fd, const void *buf, size_t count)//-1:error;>0:实际传递的字节数

### 不足值
当read和write实际作传送的字节数比应用程序要求的少：

1）读时遇到EOF;

2）从终端读取文本行（比如键盘）；

3）读和写网络套接字：因为存在缓冲或网络延迟导致的。

### EOF
EOF并不是一个字符，而是内核检测到一个条件。阮一峰的博文：http://www.ruanyifeng.com/blog/2011/11/eof.html

### rio I/O包

自动处理不足值：

ssize_t rio_readn(int fd, void *usrbuf, size_t n)

ssize_t rio_writen(int fd, void *usrbuf, size_t n)

带缓冲的I/O

`rio_t`结构，用于缓存数据

	void rio_readinitb(rio_t *rp, int fd)将rio_t和文件句柄绑定在一起

read函数

	ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)

基于rio_read实现：

带缓冲版本的rio_readn:ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n)

带缓冲版本的“读取一个文本行”：ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)

### 读取文件元数据
stat和fstat

存储文件元数据的结构体：stat

	void stat(const char *filename, struct stat *buf)

	void fstat(int fd, struct stat *buf)

### 文件共享
文件描述符表：每个进程都有一个文件描述符表：stdin,stdout,stderr

打开文件表：所有进程共享，这里有“引用计数”的概念，文件位置...

v-node表：所有进程共享，包含stat结构中的信息

注意:linux中没有v-node表的概念，linux中的inode是存储在磁盘中的，而v-node是进程启动才有是存储在内存中的，linux中与其对应的概念是entry。

文件共享：

一个文件描述符指向一个打开文件表中的项，但打开文件表中不同的项可以指向同一个v-node.因为每个文件描述符可以有不同的文件位置，所有可以分别从不同的位置操作文件。

fork的子进程会拥有父进程文件描述符的副本。

### I/O重定向
就是重定向文件描述符指向打开文件表中的位置。

	int dup2(int oldfd,int newfd)


### 硬链接和软连接（Linux,inode）
硬链接：两个文件指向同一个inode，删除一个文件不会影响另一个文件。

软连接：一个文件的内容是另一个文件，两个inode不一样，删除源文件链接文件无效。




