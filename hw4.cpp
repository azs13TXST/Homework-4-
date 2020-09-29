/*
This program is meant to take a linked list and modify it based on the functions ran. Most functions have a helper function to achieve the status of tail-recursive. The pseudocode will be above each function, explaining what they are achieving.
*/
#include <iostream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

/*
SumHelper function
  Initializes int "acc" to 0
  Returns acc=(0) if the list is empty
  Returns the sum of the list values
*/
static int SumHelper(list_t list, int acc)  {
  acc = 0;
  if (list_isEmpty(list))  {
    return acc;
  }
  return SumHelper(list_rest(list), list_first(list) + acc);
}

/*
sum function
  Returns the SumHelper function
*/
int sum(list_t list)  {
  if (list_isEmpty(list))  {
    return 0;
  }
  return SumHelper(list, 0);
}

/*
ProductHelper function
  Initializes int "acc" to 1
  Returns acc=(1) if the list is empty
  Returns the product of the list values
*/
static int ProductHelper(list_t list, int acc)  {
  acc = 1;
  if (list_isEmpty(list))
    return 0;

  return ProductHelper(list_rest(list), list_first(list) * acc);
}

/*
product function
  Returns the ProductHelper function
*/
int product(list_t list)  {
  if (list_isEmpty(list))  {
    return 0;
  }
  return ProductHelper(list, 0);
}

/*
AccumulateHelper function
  Checks if the list is empty.
  Returns the set amount of the list accumulated
*/
static int AccumulateHelper(list_t list, int (*fn)(int, int), int identity)  {
  if (list_isEmpty(list))
    return fn(list_first(list));
  
  return AccumulateHelper(list_rest(list), fn, identity);
}

/*
  accumulate function
    Returns the AccumulateHelper function, using the sum function.
*/
int accumulate(list_t list, int (*fn)(int, int), int identity)  {
  return AccumulateHelper(list, sum, 0);
}

/*
  ReverseHelper function
    Checks if the list is empty
    Uses make_list to create a new list for reverse_list if empty
      Returns the new reverse_list
    If not empty, returns the current reverse_list
*/
static list_t ReverseHelper(list_t(list), list_t reverse_list)  {
  if (list_isEmpty(list))
    return reverse_list;
  if(list_rest(list) == NULL)  {
    reverse_list = list_make(list_first(list), list_t(reverse_list));
    return (ReverseHelper(list_rest(list), list_rest(reverse_list)));
  }
  return ReverseHelper(list, reverse_list);
}

/*
  reverse function
    Sets reverse_list to list_make
    Returns the ReverseHelper function with the reversed list
*/
list_t reverse(list_t list)  {
  list_t reverse_list = list_make();
  return ReverseHelper(list_t(list), reverse_list);
}

/*
AppendHelper function
  If the first element is empty, returns the second
  If the second element is empty, returns the first
  If the entire list is empty, creates a new list
    Returns the new list
  Creates a new list wih the new element
    Returns the new list
*/
static list_t AppendHelper(list_t first, list_t second, list_t new_list)  {
  if (list_isEmpty(first))  {
    return second;
  }
  if (list_isEmpty(second))  {
    return first;
  }
  if(list_isEmpty(list))  {
    new_list = list_make(list_first(first), new_list);
    return AppendHelper(list_rest(first), second, new_list);
  }
  else  {
    new_list = list_make(list_first(second), new_list);
    return AppendHelper(first, list_rest(second), new_list);
  }
}

/*
append function
  Returns the AppendHelper function with the new list
*/
list_t append(list_t first, list_t second)  {
  return AppendHelper(list_rest(first), list_rest(second), new_list);
}

/*
FilterOddHelper function
  Checks if the list if empty
    Returns new list if so
  Checks if the values in the list are divisible by 2
    Returns the ones that are
  Return the function with the new list
*/
static list_t FilterOddHelper(list_t list, list_t new_list) {
  if(list_isEmpty(list))  {
    return new_list;
  }
  if (list_first(list) % 2 == 1)  {
    new_list = list_make(list_first(list), new_list);
    return FilterOddHelper(list_rest(list), list_rest(new_list));
  }
  else
    return FilterOddHelper(list_rest(list), new_list);
}

/*
  filter_odd function
    Makes a new list
    Returns the FilterOddHelper function with the new list
*/
list_t filter_odd(list_t list)  {
  list_t new_list = list_make();
  return FilterOddHelper(list_rest(list), new_list);
}

/*
FilterEvenHelper function
  Checks if the list if empty
    Returns new list if so
  Checks if the values in the list are divisible by 2
    Returns the ones that are not
  Return the function with the new list
*/
static list_t FilterEvenHelper(list_t list, list_t new_list)  {
  if(list_isEmpty(list))  {
    return new_list;
  }
  if (list_first(list) % 2 != 1)  {
    new_list = list_make(list_first(list), new_list);
    return FilterEvenHelper(list_rest(list), list_rest(new_list));
  }
  else
    return FilterEvenHelper(list_rest(list), new_list);
}

/*
filter_even function
  Makes a new list
  Returns the FilterEvenHelper function with the new list
*/
list_t filter_even(list_t list)  {
  list_t new_list = list_make();
  return FilterEvenHelper(list_rest(list), new_list);
}

/*
FilterHelper function
  Checks if the list is empty
    Returns the new list
  Returns the new list without the target elements
*/
static list_t FilterHelper(list_t list, bool (*fn)(int)  {
  if (list_isEmpty(list))
    return new_list;
  return FilterHelper(list_rest(list), new_list, &fn)
}

/*
filter function
  Returns the FilterHelper function with the new list
*/
list_t filter(list_t list, bool (*fn)(int))  {
  return FilterHelper(list_rest(list), new_list, &fn)
}

/*
RotateHelper function
  Checks if the 2 values are the same
    Returns the list if so
  Makes a new list using the reverse function
  Returns said list
*/
static list_t RotateHelper(list_t list, int n, int acc)  {
  if (acc == n)
    return list;
  else  {
    list = list_make(list_first(list), reverse(list_rest(list)));
    return RotateHelper(list, n, acc + 1);
  }
}

/*
rotate function
  Returns the RotateHelper function with the new list
*/
list_t rotate(list_t list, unsigned int n)  {
  return RotateHelper(list, n, 0);
}

/*
InsertListHelper function
  Checks if count and n are the same
    Creates a new list using the reverse function if so
    Returns the new list
  If not, sets second and goes from there
  Returns the function with the new list
*/
static list_t InsertListHelper(list_t first, list_t second, unsigned int n, list_t new_list, int count)  {
  if (count == n)  {
    new_list = append(reverse(first), second);
    return new_list;
  }
  else  {
    second = list_make(list_first(first), second);
    return InsertListHelper(list_rest(first), second, n, new_list, count + 1);
  }
}

/*
insert_list function
  Returns the InsertListHelper function with the new list
*/
list_t insert_list(list_t first, list_t second, unsigned int n)  {
  return InsertListHelper(reverse(first), second, n, list_make(), 0);
}

/*
ChopHelper function
  Checks if the list is less than n
    Returns the list if so
  Returns the function without the chopped elements
*/
static list_t ChopHelper(list_t l, unsigned int n, list_t new_list)  {
  if(i <= n)
    return l;
  Return ChopHelper(new_list(l), n);
}

/*
chop function
  Returns the ChopHelper function with the new list
*/
list_t chop(list_t l, unsigned int n)  {
  Return ChopHelper(l, n);
}

/*
fib function
  Checks to see if n is less than 1
    Returns 1 if so
  Returns the function twice with different parameters
*/
int fib(int n)  {
  if (n <= 1)
    return 1;

  return fib(n-1) + fib(n-2);
}

/*
fib_tail function
  Initializes ints "a" and "b" to 0 and 1
  If n is 0, returns above
  If n is 1, returns based
  Returns fib_tail with the fibonacci sequence in tail-recursion
*/
int fib_tail(int n)  {
  int a = 0;
  int b = 1;

  if (n == 0)
    return a;
  if (n == 1)
    return b;
  return fib_tail(n - 1, b, a + b);
}