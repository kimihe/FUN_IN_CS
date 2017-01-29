# README
更多**Computer Science**方面的文章，欢迎访问我的个人博客：[http://kimihe.com/](http://kimihe.com/)。

# CountBitOne
统计一个数二进制位中1的个数，常见的小题目。这里将会展示两种实现，第一种是常见做法，第二种需要一点技巧，但效率有了提升。

* 做法1: 不断右移统计1是否出现。 
* 做法2: 利用**x &= (x-1)**可以消除x二进制中最右边的1，如果最右边为1，则可以使其置0。该做法可以提高效率，但当二进制中所有位都是1时，与做法1中所需的循环次数一样多。 

# 代码
具体代码请见工程的**main.c**文件。