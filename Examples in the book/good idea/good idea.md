## 摘录

> **本文档总结了整本书中好的建议，有批注，也有做题技巧，这些东西很实用，站在巨佬们的肩膀上，尽早的掌握这些窍门有利于持久性学习。**

### 第一章 程序设计入门

##### 关于经验

- 在学习编程时，“明知故犯”是有益的，起码你知道了错误时的现象，当真的不小心犯错时，可以通过现象猜测到可能出错的原因。（P4）
- 算法竞赛的题目应当是相当严密的，各种情况下的输出都有严格规定，如果在比赛中发现题目有漏洞，应向相关人员询问，不要认为自己的看法就是绝对正确。如果是网络竞赛，可以向组织者发信或者在论坛提问，拨打热线。（P5）
- 多数竞赛采用黑盒测试，即只考察程序解决问题的能力，而不关心采用了什么方法，我们的目标是解决问题，而不是比谁写的算法看上去更高级。要学会保持简单而不是去展示编程技巧 Keep it simple and stupid 。**（P9重要）**
- 重视实验，哪怕不清楚背后的道理，至少要清楚现象。（P16小结）
- 学会模仿，把实验的焦点集中在最有趣的部分，如果直观的解决方案行的通，就不要去着急深究背后的原理，也不必过多的思考“为什么要这样”，这种策略不一定要执行很久，当自己拥有了一定的理解和学习能力后，再去学的透彻，不必操之过急。（p16小结）

##### 关于技巧

- 在各大比赛中，选手程序的执行和判定是自动完成的，没有人工干预，这意味着你要遵循一定的游戏规则，比如在用户输入之前打印提示信息（例如`"Please input n:"`），这种操作会给判题系统带来误会，也就是会被当做输出数据的一部分，导致丢分。

  和上边类似要注意的还有：

  - 不要让程序按任意键退出（例如调用`system("pause")`，或者添加一个多余的 `getchar()` ），这是多余的做法。

  - 在一般情况下，程序不能直接读取键盘或者控制屏幕，所以不要盲目使用 `getch()` `getche()` `gotoxy()` `clrscr()` 这些函数。 
  - 程序的输出格式是很重要的，几乎所有的算法题对输出格式都有一定要求，看清格式要求再输出。
  - **在算法竞赛中，每行输出均应以回车符结束，包括最后一行，除非特别说明，每行的行首不应该有空格，但行末通常可以有多余空格。另外输出的每两个数或者字符串之间应以单个空格隔开。**（P5）
  - **总结：其实我们只做三件事情：读入数据，计算结果，打印输出。不要打印提示信息，不要在输出后暂停程序，不要想着去用代码去实现画图或者访问网络这些与算法无关的任务。**（P6）

- 尽量用 `const` 关键字声明常数。有的同学喜欢用 `math.h` 中的常量 `M_PI` ,但这个常数其实不属于ANSI C标准。（P6）

- 输出结果如果遇到 `1.#INF / inf`，就检查是否发生了运算结果溢出除零，而遇到 `1.#IND / nan`，就检查是否发生非法的运算。（P14数据类型实验）

### 第二章 循环结构程序设计

##### 关于经验

- 尽量缩短变量的额定义范围，例如在for循环的初始化部分定义变量  `for(int i = 0 ; i<n ;i++){...}`（19

- 为了使程序更容易理解，便于梳理思路，推荐使用“伪代码”来描述和思考算法。（P20

- 不要忘记测试，一个看上去正确的程序也存在隐藏的错误，比如**数据溢出问题**，这种坑并不少见。（P23

- 变量在未赋值之前的值是不确定的，也就是说不一定等于0。（P28

- 如果系统给的数据不合规范，程序鲁棒性的强弱就体现了出来，好的选手会考虑系统的失误或者漏洞，在比赛中尽可能的求稳求快。（P33

  

##### 关于技巧

- 程序经过大量计算后，浮点数可能会出现误差，在进行浮点数比较时要考虑到这种情况，以书中的`floor()`函数为例，为了减小误差的影响，一般改成四舍五入，即`floor(x+0.5)`   (P21

- long long 的输入格式符，在不同平台是不一样的，例如在 MinGW gcc 中是 `%I64d`  , 而在 VC2008 中就是 `%lld` , 这个问题最直接的办法是用C++的输入输出来解决，如果一定要用C的语法，书中提供了这样的操作：

  ```c
  int c = 0;
  scanf("%d",&c);
  long long n = c;
  ```

  （P24）

- 要计算只包含加，减，乘法 的整数表达式除以正整数n的余数，可以在每步计算后对n取余，结果不变。（P26)

- 在程序结束之前，调用clock()函数可以得到整个程序运行的时间：

  ```c
  printf("%f",(double)clock()/CLOCKS_PER_SEC);//除以CLOCKS_PER_SEC得到秒数
  ```

  但这种做法有一个问题是会把等待用户输入数据的时间也算上，所以又出现了一个被称为“**管道**”的小技巧：
  直接在win下执行命令 `echo 20 | abc` 来运行程序，20是用户要输入的某个值，abc 就是程序名字。

  linux 平台下则是 `echo 20 | ./abc` （P27）

  