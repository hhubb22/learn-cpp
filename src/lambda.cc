#include <chrono>
#include <functional>
#include <iostream>

// 使用 std::function - 有性能开销
void
processWithFunction(std::function<int(int)> func, int value)
{
  auto result = func(value);  // 虚函数调用，无法内联
}

// 使用模板参数 - 零开销
template <typename Func>
void
processWithTemplate(Func func, int value)
{
  auto result = func(value);  // 可以完全内联
}

// 测试性能差异
int
main()
{
  auto lambda = [](int x) { return x * 2; };

  // std::function 版本
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 1000000; ++i)
  {
    processWithFunction(lambda, i);
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "std::function version: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms"
            << std::endl;
  // 通常比模板版本慢 3-10 倍

  // 模板版本
  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 1000000; ++i)
  {
    processWithTemplate(lambda, i);
  }
  end = std::chrono::high_resolution_clock::now();
  std::cout << "Template version: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms"
            << std::endl;
  // 更快，可能被完全优化掉
}