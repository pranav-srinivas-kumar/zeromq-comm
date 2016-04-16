#include <iostream>
#include <string>
#include "operation.hpp"

void timer_function() {
  std::cout << "Timer" << std::endl;
}

void subscriber_function(std::string message) {
  std::cout << "Subscriber " << message << std::endl;
}

int main() {

  Operation timer_operation("timer_operation", 50, timer_function);
  Operation subscriber_operation("subscriber_operation", 60, 
				 std::bind(subscriber_function, "received_message"));

  timer_operation.execute();
  subscriber_operation.execute();

  return 0;
}