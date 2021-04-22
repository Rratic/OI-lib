## 应用
1. 进行算法功能演示
2. 造数据、写熟知程序时直接调用
3. 翻源代码学习（全部开源！）
4. 拿去写博客（MIT许可证！）
5. 刷题（注释有推荐对应题（注：请自己写一遍））

## 使用方法
1. 建议把`src/`中的代码复制到您装标准库的文件夹（也可以`#include ""`引用，但不建议）
2. 使用“OI万能头”`#include <OIalgo.h>`+`using namespace OIalgo;`
3. 代码使用C++11，请配置参数`-std=c++11`
4. 与`vscode`、`洛谷`配套食用更佳

示例：
```cpp
#include <OI/tree/BinaryTree.h>
using namespace OIalgo;
int main(){
    BinaryTree<10010,ull>a;// 定义一个最大长度10010，类型为unsigned long long的二叉树
    a.init(3);// 初始化
    a.create(1,true,2);// 创建根节点的右孩子，值为2
    cout<<a.height();// 树的高度
    return 0;
}
```

## 寻求帮助
* 请善用您编辑器的搜索功能
* [结构说明](docs/structure.md)
* [代码中使用的OI不太常用的语法](docs/grammar.md)
* [来github仓库提问](https://github.com/OIalgorithm/OI-lib)
* [常见问题Q&A](docs/QA.md)

## 进行贡献
* [了解代码格式标准](docs/format.md)
* [增加新功能需要改变的文件](docs/change.md)
* [模板](docs/h-template.md)
* [开发者测试](docs/template.md)
