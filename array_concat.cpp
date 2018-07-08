#include <iostream>
#include <string>

int main()
{
  int arr1[] = {1, 2, 3};
  int arr2[] = {3, 4, 6};

  std::basic_string<int> s1(arr1, 3);
  std::basic_string<int> s2(arr2, 3);

  std::basic_string<int> concat(s1 + s2);

  for (std::basic_string<int>::const_iterator i(concat.begin());
    i != concat.end();
    ++i)
  {
    std::cout << *i << " ";
  }

  std::cout << std::endl;

  return 0;
}
