# LeetCode
## 一、说明

沈小辰的刷题之旅~

把这件事当成是终身事业来抓，优先采用go语言版本，有时间再补全其他的语言版本。

> - 所有的版本的目录结构以及命名方式需保持一致。
> - 所有跟算法相关的代码都放在这里面。
>

## 二、详细要求

### 1、文件目录结构

```
--leetCode
----LetcodeGo
--------base
--------exam
--------leetcode
--------temp
----LetcodeCplusplus
--------base
--------exam
--------leetcode
--------temp
----LetcodeJava
--------base
--------exam
--------leetcode
--------temp
----LetcodePython
--------base
--------exam
--------leetcode
--------temp
--README.md
```

### 2、文件的命名规范

目录：各语言的子目录 `leetcode`。
格式：`leetcode_题号_英文名_中文名.后缀`

要求：

> 1、英文名称之间用下划线`_`连接。
> 2、特殊符号如`（）`则去掉，举例：`String to Integer (atoi)`  的文件命名为：`String_to_Integer_atoi`
> 3、题号保留4位整数，不够的补0。

举例：
题号：1
英文名：Two Sum
中文名：两数之和

> `leetcode_0001_Two_Sum_两数之和.go`       //go版本
> `leetcode_0001_Two_Sum_两数之和.java`   //java版本

### 3、文件内容示例

注：使用插件，IDEA&GOLAND（`leetcode editor`，作者：`shuzijun`）	

**CodeFileName**：

`leetcode_$!velocityTool.leftPadZeros(${question.frontendQuestionId},4)_$!velocityTool.camelCaseName(${question.titleSlug})_${question.title}`	

**文件名称占位符**：

```
${question.title}	题目标题	示例:两数之和
${question.titleSlug}	题目标记	示例:two-sum
${question.frontendQuestionId}	题目编号
${question.content}	题目描述
${question.code}	题目代码
$!velocityTool.camelCaseName(str)	转换字符为驼峰样式
$!velocityTool.snakeCaseName(str)	转换字符为蛇形样式
$!velocityTool.leftPadZeros(str,n)	pad sting with zero make str length at least n.
$!velocityTool.date()	获取当前时间
```

#### 1）java语言版本

**TempFilePath**：`D:\leetcode\LeetcodeJavaPlus\src\main\java`

**CodeTemplate**：

```java
// Date: $!velocityTool.date()

${question.content}

package leetcode.editor.cn;
//Java：${question.title}
public class P${question.frontendQuestionId}$!velocityTool.camelCaseName(${question.titleSlug}){
    public static void main(String[] args) {
        Solution solution = new P$!{question.frontendQuestionId}$!velocityTool.camelCaseName(${question.titleSlug})().new Solution();
        // TO TEST
    }
    ${question.code}
}
```

#### 2）go语言版本

**TempFilePath**：`D:\leetcode\LeetcodeGo`

**CodeTemplate**：

```go
${question.content}
// 题目名称：${question.title}
// 作者：selonsy 时间：$!velocityTool.date()
/*
解题思路：
*/
package main
import "fmt"
func main(){
    // TODO:
    
    fmt.Print("done")
}

${question.code}
```

