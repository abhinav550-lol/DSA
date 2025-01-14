//alternate swapped array
#include <iostream>
using namespace std;

int main()
{
  int size;
  cout << "Enter size :";
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < size; i++)
  {
    if (i + 2 > size)
    {
      break;
    }
    int temp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = temp;
    i++;
  }
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}