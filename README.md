# 史上最恶心的语言：Hooch (beta)

PS：由于Markdown不支持这种恶心的语言，本篇中所有代码高亮都是错的。

### 1. 关于实现

极其恶心的实现。“编（翻）译器”将会将这些代码 $\mathtt{Hooch}$ 代码翻译成 C++，然后通过 MinGW-G++ 进行编译。

编译指令：`g++ -std=c++11 -O2`

如果要下载翻译器，请跳转到第 3 部分。

由于这种恶心的语言是跟 C++ 互通的，所以 C++ 的某些语句可以直接照搬在这里面。

### 2. 关于语法

#### I. `init` 语句

该语句将初始化 $\mathtt{Hooch}$，导入所需要的 C++ 库。类似于：

```cpp
#include<bits/stdc++.h>
using namespace std;
```

#### II. `cpp` 语句

该语句将会执行语句块内的 C++ 代码。$\mathtt{Hooch}$ 中，所有语句块必须至少有三行。每个语句块包括语句头（用以标识语句的作用）、主语句块（语句块内的语句）和语句尾（`end` 语句）。例如如下代码，除了会导入 C++ 标准库外，还会导入 `windows.h`：

```
init
cpp
	#include<windows.h>
end
```

#### III. `var` 语句

该语句将会定义一个或多个变量或数组。`var` 后面跟着类型名。$\mathtt{Hooch}$ 中的类型名有：

```
有符号整数：short int long llong
无符号整数：ushort uint ulong ullong
浮点数：float double ldouble
其他：char bool
特殊：void
STL：string vector<> set<> ....
```

以上的类型操作均与 C++ 中一样（包括 `string`，同样也有 `substr()` `find()` `size()` `clear()` 等操作，其他 STL 操作方法也与 C++ 相同）。

数组的操作与 C++ 同样。例如以下代码，定义了一个变量 `n` 和数组 `a[]`：

```
var int n,a[100005]
```

注意：在 $\mathtt{Hooch}$ 中，所有语句都是以 \r\n 或 \n 为结尾的，而非分号。这就导致一条语句不能像 C++ 那样疯狂拆分或压行。

#### IV. `func` 语句

该语句定义一个函数，在 `func` 后面跟函数的返回值类型，接着是函数名，用括号括起参数，然后就是主语句块，以 `end` 结尾。例如下面代码，定义了一个变量交换函数：

```
@ 这是一个注释，在at符后面要有一个空格，且必须独立成行（恶心）
func void _swap(int &a,int &b)
 var int t = a
 a = b
 b = t
end
```

此外，关于主函数，$\mathtt{Hooch}$ 中主函数名为 `hooch()`，返回值必须为 `int`。并且，你不能定义任何一个名字为 `main()` `WinMain()` 等的函数。

#### V. `input` `output` 语句

输入输出的内容用分号分隔，换行结束。这两个语句采用流输入，如果想快一点，可以用 `cpp` 语句，然后用 `scanf()` `printf()` 输入输出。例如：

```
input a;b;c;d
@ 慢版本
cpp
 scanf("%d%d%d%d",&a,&b,&c,&d);
 //快版本（注意：在cpp语句块内的注释要用C++的两杠）
end
```

同时，在输出时，`output` 也可以输出 endl，如果要保留小数输出，可以用 `cpp` 语句块 `printf`。

注意：如果你不用 cpp 语句块，想直接调用 printf，请用 `shout` 语句。例如：

```
shout printf("Hooch\n")
```

#### VI. `return` 语句

除了没有分号以外，跟 C++ 一模一样。

#### VII. `for` `loop_while` 语句

`for` 的用法，除了没有大小括号外，跟 C++ 一模一样

```
input n
for int i = 1;i <= n;i++
 shout printf("%d\n",i)
end
```

而 `loop_while` 相当于 C++ 中的 `while`：

```
loop_while 1
 output "hooch"
end
```

有一个很恶心的一点。如果你用 `output` 输出带有分号的字符串，会出问题！

#### VIII. `if` 语句

格式：`if 条件 then`，例如：

```
if a < b then
 shout printf("hooch")
end
```

关于 `shout` 语句，这个语句可以用在赋值语句、无返回值的函数调用前（或无需返回值，例如上述代码）。如果你的语句中有空格，你可以不用 `shout` 语句，但如果你的语句中没有空格，那么就必须使用 `shout` 语句。事实上，`shout` 是 `call` 的恶心转化。例如：

```
shout a=b
@ 没有空格，要用shout
b = t
@ 有空格，不用shout
t = b
```

~~注意：$\mathtt{beta}$ 版本暂不支持 `else`，待更新！~~

好消息：现在支持 `elseif` 和 `else` 了。请注意：`if` `elseif` `else` 各自是语句块，每一个都要打 `end`。例如：

```
if 1 > 2 then
end
elseif 1 < 2 then
end
else
end
```

#### IX. `exithq`

程序的最后，用一个 `exithq` 结尾，并且加上一个空行：

```
exithq

```

用以标识程序结尾。

### 3. 关于使用

[Download here](https://github.com/TaroDog/Hooch_lang/archive/refs/heads/master.zip)

hoc -> cpp 转化层开源。（GitHub）

使用：

翻译器为 `pcomp.exe`，而更高级的编译由 MinGW 实现（谁愿意花那么多时间去写一个编译器？）

总的生成器为 `hoo.exe`，你可以传入三个参数：

`hoo source_file cpp_file output_file`

+ `source_file` $\mathtt{Hooch}$ 代码文件，建议的扩展名为 `*.hoc`
+ `cpp_file` 中途生成的 C++ 程序的名字。该参数似乎没什么大用，反正这个中途程序会被删掉。所以这个参数可以随便填。
+ `output_file` 输出文件名。例如：`a.exe`。

以下是正确示范：

`hoo hooch.hoc wench.cpp binch.exe`

然后就没有然后了。

PS: 如有建议，可以到 GitHub 上 issue，或私信。
# $\Huge{\mathtt{THE}\space\mathtt{END}}$

## Update

### 2022/8/18 20:46

在 $\mathtt{Hooch}$ 中，`fkhooch` 相当于 `break;`，`sthooch` 相当于 `continue`。


### 2022/8/19 10:12

$\mathtt{Hooch}$ 支持 class，但不支持 struct。类以 `class` 定义，同样以 `end` 结尾。中间部分同样也有 `private` `public` `protected` 标签，但是不用打冒号，只需要换行。$\mathtt{Hooch}$ 中派生类和成员函数定义方法与 C++ 类似。如：

```
class wench
 private
  var int a
 public
  func ; wench()
   output "hooch";endl
  end
  @ 构造函数和析构函数前面要加一个分号，而且要用空格前后分开。
end
func void wench::lalala()
 output "lalala";endl
end
@ 成员函数
class wench : public binch
 @ 定义派生类
end
```
