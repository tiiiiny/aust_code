/* 
*表驱动法，又称之为表驱动、表驱动方法。表驱动方法是一种使你可以在表中查找信息，而不必用很多的逻辑语句（if或Case）来把它们找出来的方法。以下的demo，把map抽象成表，在map中查找信息，而省去不必要的逻辑语句。
*优化前：
if (param.equals(value1)) {
    doAction1(someParams);
} else if (param.equals(value2)) {
    doAction2(someParams);
} else if (param.equals(value3)) {
    doAction3(someParams);
}
// ...

y优化后：
// Map<String, Function<void(int)>> actionMappings = new HashMap<>(); // 这里泛型 String 是为方便演示，实际可替换为你需要的类型
Map<?, Function<?> action> actionMappings = new HashMap<>(); // 这里泛型 ? 是为方便演示，实际可替换为你需要的类型

// 初始化
actionMappings.put(value1, (someParams) -> { doAction1(someParams)});
actionMappings.put(value2, (someParams) -> { doAction2(someParams)});
actionMappings.put(value3, (someParams) -> { doAction3(someParams)});

// 省略多余逻辑语句
actionMappings.get(param).apply(someParams);

*作者：捡田螺的小男孩
*链接：https://juejin.cn/post/6844904083665453063
*来源：稀土掘金
*著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */


#include <iostream>
#include <unordered_map>
#include <functional>

// 定义函数指针类型
typedef void (*ActionFunc)(int);

// 定义一个函数，用于执行具体的动作
void doAction1(int param) {
    std::cout << "Executing action 1 with param " << param << std::endl;
}

void doAction2(int param) {
    std::cout << "Executing action 2 with param " << param << std::endl;
}

void doAction3(int param) {
    std::cout << "Executing action 3 with param " << param << std::endl;
}

int main() {
    // 创建一个unordered_map，用于存储值和对应的函数指针
    std::unordered_map<int, ActionFunc> actionMappings = {
        {1, &doAction1},
        {2, &doAction2},
        {3, &doAction3}
    };

    int param = 2; // 要执行的动作对应的值
    int someParams = 100; // 其他参数，例如参数值，你可以根据具体需要自定义

    // 查找并执行动作
    auto it = actionMappings.find(param);
    if (it != actionMappings.end()) {
        // 如果找到对应的动作，则调用相应的函数指针执行动作
        it->second(someParams);
    } else {
        std::cout << "No action found for param " << param << std::endl;
    }

    return 0;
}
