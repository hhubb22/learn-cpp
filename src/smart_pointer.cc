#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

class Widget
{
public:
  Widget(int id) : id_(id)
  {
    std::cout << "Widget " << id_ << " created\n";
  }

  ~Widget()
  {
    std::cout << "Widget " << id_ << " destroyed\n";
  }

  void
  doWork()
  {
    std::cout << "Widget " << id_ << " working...\n";
  }

private:
  int id_;
};

std::shared_ptr<Widget> global_ptr;

void
dangerous_function(const std::shared_ptr<Widget>& ref)
{
  std::cout << "函数开始，引用计数: " << ref.use_count() << std::endl;

  // 模拟一些工作
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // 在这期间，其他线程可能重置了global_ptr
  // 如果这是最后一个shared_ptr，对象就被销毁了

  std::cout << "准备使用对象...\n";
  ref->doWork();  // 💥 可能崩溃！对象可能已被销毁
}

void
reset_global()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "重置global_ptr\n";
  global_ptr.reset();  // 销毁对象
}

int
main()
{
  global_ptr = std::make_shared<Widget>(1);

  std::thread t1(dangerous_function, std::cref(global_ptr));
  std::thread t2(reset_global);

  t1.join();
  t2.join();

  return 0;
}
