# for

[for 语句 (C++) | Microsoft Learn](https://learn.microsoft.com/zh-cn/cpp/cpp/for-statement-cpp?view=msvc-170)

## **语法**

> `for ( init-expression ; cond-expression ; loop-expression ) statement`
> 

## for 循环元素

| 语法名称 | 执行时间 | 说明 |
| --- | --- | --- |
| init-expression
初始化表达式 | 在 for 语句的任何其他元素之前，init-expression 仅执行一次。 控制权然后传递给 cond-expression。 | 通常用来初始化循环索引。 它可以包含表达式或声明。 |
| cond-expression
条件表达式 | 在执行 statement 的每次迭代之前，包括第一次迭代。 | 计算结果为整数型或明确转换为整数型的类类型的表达式。 通常用于测试循环终止条件。 |
| statement
语句块 | 只在 cond-expression 的计算结果为 true（非零）时执行。 | 每次循环时所执行的语句块 |
| loop-expression
循环表达式 | 在 statement 的每次迭代结束时。 执行 loop-expression 后，将计算 cond-expression。 | 通常用于循环索引递增。 |

当 *`statement`* 内的 `break`、`return` 或 `goto`（转到 **`for`** 循环外的标记语句）执行时，**`for`** 循环将终止。 **`for`** 循环中的 `continue` 语句仅终止当前迭代。

如果省略 *`cond-expression`*，则将其视为 **`true`**，如果没有 *`statement`* 中的 **`break`**、**`return`** 或 **`goto`**，**`for`** 循环将不会终止。

## 示例

```cpp
for (int i = 0; i < 10; ++i)
{
    printf("%d", i);
}
```

**可理解为:**

```cpp
init_expression://初始化表达式
    int i = 0;
    goto cond_expression;
statement:      //语句块
{
    printf("%d\n", i);
}
loop_expression://循环表达式
    ++i;
cond_expression://条件表达式
    if (i < 10)
    {
        goto statement;
    }
```

# 基于范围的 for 语句

[基于范围的 for 语句 (C++) | Microsoft Learn](https://learn.microsoft.com/zh-cn/cpp/cpp/range-based-for-statement-cpp?view=msvc-170)

## **语法**

> `for ( for-range-declaration:expression)  statement`
> 

## **注解**

使用基于范围的 **`for`** 语句构造必须在“范围”中执行的循环，它定义为可循环访问的任何内容 - 例如，`std::vector` 或其范围由 `begin()` 和 `end()` 定义的任何其他 C++ 标准库序列。 `for-range-declaration` 部分中声明的名称是 **`for`** 语句的本地名称，且无法在 `expression` 或 `statement` 中重新声明它。 请注意，在语句的 `for-range-declaration` 部分中，`auto` 关键字是首选的。

## 备注

请记住这些有关基于范围的 **`for`** 的情况：

- 自动识别数组。
- 识别拥有 `.begin()` 和 `.end()` 的容器。
- 对于任何其他内容，使用依赖于自变量的查找 `begin()` 和 `end()`。

对于自定义类要有成员函数`begin()` 、`end()` 返回自定义的迭代器。

该自定义的迭代器类要支持操作符`*`、前缀`++`、`！=` 。

## 示例1

```cpp
int arr[] = {1, 2, 3, 4, 5, 6, 7};
    
    for (auto &i : arr)
    {
        i++;
        printf("%d ", i);
    }
    putchar('\n');
```

**可理解为:**

```cpp
int arr[7] = {1, 2, 3, 4, 5, 6, 7};
{
  int (&__range1)[7] = arr;
  int * __begin1 = __range1;
  int * __end1 = __range1 + 7L;
  for(; __begin1 != __end1; ++__begin1) {
    int & i = *__begin1;
    i++;
    printf("%d ", i);
  }
  
}
putchar(static_cast<int>('\n'));
```

## 示例2

```cpp
std::list<int> arr = {1, 2, 3, 4, 5, 6, 7};

for (auto &i : arr)
{
    i++;
    printf("%d ", i);
}
```

**可理解为:**

```cpp
std::list<int, std::allocator<int> > arr = std::list<int, std::allocator<int> >{std::initializer_list<int>{1, 2, 3, 4, 5, 6, 7}, std::allocator<int>()};
  
{
    std::list<int, std::allocator<int> > & __range1 = arr;
    std::_List_iterator<int> __begin1 = __range1.begin();
    std::_List_iterator<int> __end1 = __range1.end();
    for(; operator!=(__begin1, __end1); __begin1.operator++()) {
      int & i = __begin1.operator*();
      i++;
      printf("%d ", i);
    }
}
```